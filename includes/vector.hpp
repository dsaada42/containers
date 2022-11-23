#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "vector_iterator.hpp"
# include "type_traits.hpp"
# include <iterator>
# include <memory>
# include <cstddef>

namespace ft {

    template < class T, class Alloc = std::allocator< T > >
    class vector {

        public:
            typedef T                                                           value_type;
            typedef Alloc                                                       allocator_type;
            typedef typename allocator_type::reference                          reference;
            typedef typename allocator_type::const_reference                    const_reference;
            typedef typename allocator_type::pointer                            pointer;
            typedef typename allocator_type::const_pointer                      const_pointer;
            typedef ft::vector_iterator<value_type, false>                      iterator;
            typedef ft::vector_iterator<value_type, true>                       const_iterator;
            typedef std::reverse_iterator<iterator>                             reverse_iterator;
            typedef std::reverse_iterator<const_iterator>                       const_reverse_iterator;
            typedef ptrdiff_t                                                   difference_type;
            typedef size_t                                                      size_type;

        private:
            value_type*          _data;
            allocator_type       _alloc;
            size_type            _size;
            size_type            _capacity;
            void ReAlloc( size_type newCapacity )
            {
                //allocate new block
                value_type* newBlock = (value_type*) ::operator new(newCapacity * sizeof(value_type)); //next step is using allocator
                //copy all existing elements in new allocated block (better to move)
                if (newCapacity < _size)
                    _size = newCapacity;
                for (size_t i = 0 ; i < _size ; i++){
                    newBlock[i] = _data[i];
                }
                //delete old block
                for (size_t i = 0; i < _size ; i++){
                    _data[i].~value_type();
                }
                ::operator delete(_data); // need to use operator delete or allocator.deallocate to avoid double free
                _data = newBlock;
                _capacity = newCapacity;
            }
        public:
        //*****CONSTRUCTOR DESTRUCTOR*****
            //____default constructor : constructs an empty container, no elements
            explicit vector (const allocator_type& alloc = allocator_type()){
                _alloc = alloc;
                _size = 0;
                _capacity = 0;
                //_data = (value_type*)::operator new(2 * sizeof(value_type)); // -> better approach useing allocator
                _data = _alloc.allocate(0);
            } 
            //____fill constructor : constructs a container with n elements, each is a copy of val  
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
                _alloc = alloc;
                //_data = (value_type*)::operator new(n * sizeof(value_type)); // -> better approach useing allocator
                _data = _alloc.allocate(n);
                _size = n;
                _capacity = n;
                for (size_type i = 0; i < n ; i++)
                    _alloc.construct(&_data[i], val);
            } 
            //____range constructor : constructs a container with as many elements as the range [first,last)
            template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),	typename ft::enable_if<!ft::is_same<InputIterator, int>::boolean>::type* = 0){
                size_type nb = 0;

                for ( InputIterator start = first; start != last; start++)
                    nb++;
                _size = nb;
                _capacity = nb;
                _alloc = alloc;
                _data = _alloc.allocate(nb);
                //On construit un objet pour chacune des valeurs d'iterateur de la range
                for (size_type i = 0; i < nb; i++){
                    _alloc.construct(&_data[i], *first);
                    first++;
                }
            } 
            //____copy constructor___
            vector (const vector& copy){
                 _alloc = copy.get_allocator();
                 _size = copy.size();
                 _capacity = copy.capacity();
                 //reste a copier tout le vector en accedant aux elements 1 par 1
                 for (size_type i = 0; i < _size; i++)
                    _alloc.construct(&_data[i], copy[i]);
            }
            ~vector< T , Alloc >( void ){
                for (size_type i = 0; i < _size ; i++){
                    _alloc.destroy(_data + i);
                }
                _alloc.deallocate(_data, _capacity);
            }
            //____opertor= surcharge___
            vector& operator= (const vector& copy){
                //clear first 

                (void)copy;
                return (*this);
            }

        //******ITERATORS*****
            iterator                begin(){ return (iterator(_data)); }
            const_iterator          begin() const{ return (const_iterator(_data)); }
            iterator                end(){ return (iterator(_data + _size)); }
            const_iterator          end() const{ return (const_iterator(_data + _size)); }
            reverse_iterator        rbegin(){ return (reverse_iterator(_data)); }
            const_reverse_iterator  rbegin() const{ return (const_reverse_iterator(_data)); }
            reverse_iterator        rend(){ return (reverse_iterator(_data + _size)); }
            const_reverse_iterator  rend() const{ return (const_reverse_iterator(_data + _size)); }

        //*****CAPACITY*****
            size_type               size() const{ return (_size); }
            size_type               max_size() const{ return (_alloc.max_size()); }
            void                    resize (size_type n, value_type val = value_type()){
                // si n > size 
                    //si n > capacity 
                        //si n > 2 x capacity or size
                            //-> reserve n
                        //si capacity or size > 0
                            //-> reserve 2 x capacity or size
                        //sinon
                            //->reserve 1
                        //-> on construit les elements de _size a n
                // si n <= size
                    //on detruit les elements de n a _size
                (void)n;
                (void)val;
            }
            size_type               capacity() const{ return (_capacity); }
            bool                    empty() const{ return (_size == 0); }
            void                    reserve (size_type n){
                (void)n;
            }

        //*****ELEMENT ACCESS*****
            reference               operator[] (size_type n){ return (_data[n]); }
            const_reference         operator[] (size_type n) const{ return (_data[n]); }
            reference               at (size_type n){
                if (n >= _size)
                    throw std::out_of_range("vector: trying to access element out of range");
                return (_data[n]);
            }
            const_reference         at (size_type n) const{
                if (n >= _size)
                    throw std::out_of_range("vector: trying to access element out of range");
                return (_data[n]);
            }
            reference               front(){ return (_data[0]); }
            const_reference         front() const{ return (_data[0]); }
            reference               back(){ return (_data[_size - 1]); }
            const_reference         back() const{ return (_data[_size - 1]); }

        //*****MODIFIERS*****
            template <class InputIterator>  void assign (InputIterator first, InputIterator last){
                (void)first;
                (void)last;
            }
            void assign (size_type n, const value_type& val){
                (void)n;
                (void)val;
            }
            void push_back (const value_type& val){
                if (_size >= _capacity)
                {
                    ReAlloc(_capacity + _capacity / 2);
                }
                _data[_size] = val;
                _size++;
            }
            void pop_back(){
                if (_size > 0){
                    _size--;
                    _data[_size].~value_type();
                    //_alloc.destroy(_data[_size]);
                }
            }
            iterator insert (iterator position, const value_type& val){
                (void)position;
                (void)val;
                return (begin());
            } //single element
            void insert (iterator position, size_type n, const value_type& val){
                (void)position;
                (void)n;
                (void)val;
            } //fill
            template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last){
                (void)position;
                (void)first;
                (void)last;
            } // range
            iterator erase (iterator position){
                (void)position;
                return (begin());
            }
            iterator erase (iterator first, iterator last){
                (void)first;
                (void)last;
                return (begin());
            }
            void swap (vector& x){
                (void)x;
            }
            void clear(){
                while (_size > 0)
                    pop_back();
            }
            
        //*****Allocator*****
            allocator_type get_allocator() const{
                return (_alloc);
            }
            
    };

    //***** Non member function overloads *****
    //___Relational operators___
    template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
        (void)lhs;
        (void)rhs;
        return (true);
    }
    template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
        (void)lhs;
        (void)rhs;
        return (true);
    }
    template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
        (void)lhs;
        (void)rhs;
        return (true);
    }	
    template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
        (void)lhs;
        (void)rhs;
        return (true);
    }
    template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
        (void)lhs;
        (void)rhs;
        return (true);
    }	
    template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
        (void)lhs;
        (void)rhs;
        return (true);
    }
    //___Swap ( vector )
    template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
        (void)x;
        (void)y;
    }

}

#endif