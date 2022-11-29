#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "vector_iterator.hpp"
# include "type_traits.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"
# include <iostream>
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

        protected:
            value_type*          _data;
            allocator_type       _alloc;
            size_type            _size;
            size_type            _capacity;

        public:
        //*****CONSTRUCTOR DESTRUCTOR*****
            //____default constructor : constructs an empty container, no elements
            explicit vector (const allocator_type& alloc = allocator_type()){
                _alloc = alloc;
                _size = 0;
                _capacity = 0;
                _data = _alloc.allocate(0);
            } 
            //____fill constructor : constructs a container with n elements, each is a copy of val  
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
                if (n > max_size())
                    throw std::length_error("vector: tried to assign past max size");                
                _alloc = alloc;
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
                 _data = _alloc.allocate(_capacity);
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
                //on libere l'espace
                clear();
                //dans le cas ou on a besoin d'une reallocation
                if (copy.size() > _capacity){
                    _alloc.deallocate(_data, _capacity);
                    _capacity = copy.capacity();
                    _data = _alloc.allocate(_capacity);
                }
                //on copie tous les elements de copy vers notre _data 
                _size = copy.size();
                for (size_type i = 0; i < _size; i++){
                    _alloc.construct(&_data[i], copy[i]);
                }
                return (*this);
            }

        //******ITERATORS*****
            iterator                begin(){ return (iterator(_data)); }
            const_iterator          begin() const{ return (const_iterator(_data)); }
            iterator                end(){ return (iterator(_data + _size)); }
            const_iterator          end() const{ return (const_iterator(_data + _size)); }
            reverse_iterator        rbegin(){ return (reverse_iterator(_data + _size - 1)); }
            const_reverse_iterator  rbegin() const{ return (const_reverse_iterator(_data + _size - 1)); }
            reverse_iterator        rend(){ return (reverse_iterator(_data - 1)); }
            const_reverse_iterator  rend() const{ return (const_reverse_iterator(_data - 1)); }

        //*****CAPACITY*****
            size_type               size() const{ return (_size); }
            size_type               max_size() const{ return (_alloc.max_size()); }
            void                    resize (size_type n, value_type val = value_type()){
                if (n > _size){
                    if (n > _capacity){
                        if (n > 2 * _capacity)
                            reserve(n);
                        else if (_capacity >= 1)
                            reserve(2 * _capacity);
                        else
                            reserve(1);
                    }
                    for (size_type i = _size; i < n; i++)
                        _alloc.construct(&_data[i], val);
                }
                else{
                    for (size_type i = n; i < _size; i++)
                        _alloc.destroy(&_data[i]);
                }
                _size = n;
            }
            size_type               capacity() const{ return (_capacity); }
            bool                    empty() const{ return (_size == 0); }
            void                    reserve (size_type n){
                if (n > max_size())
                {
                    throw std::length_error("vector: trying to reserve more than maxcap");
                }
                if (n > _capacity){
                    value_type* new_data = _alloc.allocate(n);
                    for (size_type i = 0; i < _size; i++){
                        _alloc.construct(&new_data[i], _data[i]);
                        _alloc.destroy(&_data[i]);
                    }
                    _alloc.deallocate(_data, _capacity);
                    _capacity = n;
                    _data = new_data;
                }
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
            template <class InputIt>  void assign (InputIt first, InputIt last, typename ft::enable_if<!ft::is_same<InputIt, int>::boolean>::type* = 0){
                size_type nb = 0;
                for( InputIt tmp = first; tmp != last; tmp++)
                    nb++;
                clear();
                if (nb > _capacity)
                    reserve(nb);
                for (size_type i = 0; i < nb; i++){
                    _alloc.construct(&_data[i], *first);
                    _size++;
                    first++;
                }
            }
            void assign (size_type n, const value_type& val){
                clear();
                if (n > _capacity)
                    reserve(n);
                for (size_type i = 0; i < n; i++){
                    _alloc.construct(&_data[i], val);
                    _size++;
                }
            }
            void push_back (const value_type& val){
                if (_size >= _capacity)
                    resize(_size + 1, val);
                else{
                    _alloc.construct(&_data[_size], val);
                    _size++;
                }
            }
            void pop_back(){
                if (_size > 0){
                    _size--;
                    _alloc.destroy(&_data[_size]);
                }
            }
            iterator insert (iterator position, const value_type& val){
                (void)position;
                (void)val;
                return (begin());
            } //single element
            void insert (iterator position, size_type n, const value_type& val){
                size_type pos = position - begin();

                if (_size + n > _capacity)
                    resize(_size + n);
                for (size_type i = _size - 1; i > pos + n; i--)
                    _data[i] = _data[i - n];
                for (size_type i = pos; i < pos + n; i++)
                    _data[i] = val;
            } //fill
            template <class InputIt> void insert (iterator position, InputIt first, InputIt last, typename ft::enable_if<!ft::is_same<InputIt, int>::boolean>::type* = 0){
                (void)position;
                (void)first;
                (void)last;
            } // range
            iterator erase (iterator position){
                
                for (size_type i = position - begin(); i < _size - 1; i++)
                    _data[i] = _data[i + 1];
                // //on decale tous les elements a partir de la position de 1
                // for (iterator it = position; it < end() - 1; it++) //a reecrire avec des size_type au lieu des iterateurs
                //     *it = *(it + 1);
                _size--;
                //on detruit le dernier element
                _alloc.destroy(&_data[_size]);
                return (position);
            }
            iterator erase (iterator first, iterator last){
                size_type nb = 0;

                nb = last - first;
                if (nb == 0)
                    return (first);
                //on decale tous les elements a partir de la position de last - first
                for (size_type i = first - begin(); i < _size; i++){
                    _data[i] = _data[i + nb]; 
                }
                //on supprime les nb derniers elements
                for (size_type i = _size - nb; i < _size; i++)
                    _alloc.destroy(&_data[i]);
                _size -= nb;
                
                return (first);
            }
            void swap (vector& x){
                (void)x;
            }
            void clear(){
                while (_size > 0)
                    pop_back();
            }
            
        //*****Allocator*****
            allocator_type get_allocator(void) const{
                return (allocator_type());
            }
            
    };

    //***** Non member function overloads *****
    //___Relational operators___
    template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
        return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }	
    template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
        if (rhs == lhs)
            return (true);
        return (lhs < rhs);
    }
    template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
        return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }	
    template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
        if (rhs == lhs)
            return (true);
        return (lhs > rhs);
    }
    //___Swap ( vector )
    template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
        (void)x;
        (void)y;
    }

}

#endif