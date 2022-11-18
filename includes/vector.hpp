#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "vector_iterator.hpp"
# include "vector_const_iterator.hpp"
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
            typedef ft::vector_iterator< vector<value_type> >                   iterator;
            typedef ft::vector_const_iterator< vector<const value_type> >       const_iterator;
            typedef std::reverse_iterator<iterator>                             reverse_iterator;
            typedef std::reverse_iterator<const_iterator>                       const_reverse_iterator;
            typedef ptrdiff_t                                                   difference_type;
            typedef size_t                                                      size_type;

        private:
            value_type*          _data;
            allocator_type       _alloc;
            size_type           _size;
            size_type           _capacity;
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
                _capacity = 2;
                _data = (value_type*)::operator new(2 * sizeof(value_type)); // -> better approach useing allocator
                //_data = _alloc.allocate(2);
            } 
            //____fill constructor : constructs a container with n elements, each is a copy of val  
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
                _alloc = alloc;
                _data = (value_type*)::operator new(n * sizeof(value_type)); // -> better approach useing allocator
                //_data = _alloc.allocate(n);
                _size = n;
                _capacity = n;
                //reste a associer val aux elements crees
            } 
            //____range constructor : constructs a container with as many elements as the range [first,last)
            template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
                (void)first;
                (void)last;
                (void)alloc;
            } 
            //____copy constructor___
            vector (const vector& x){
                (void)x;
            }
            ~vector< T , Alloc >( void ){
                clear();
                ::operator delete(_data);
            }
            //____opertor= surcharge___
            vector& operator= (const vector& x){
                (void)x;
                return (*this);
            }

        //******ITERATORS*****
            iterator begin(){
                return (iterator(_data));
            }
            //const_iterator begin() const{}
            iterator end(){
                return (iterator(_data + _size));
            }
            //const_iterator end() const{}
            reverse_iterator rbegin(){
                return (reverse_iterator(_data));
            }
            //const_reverse_iterator rbegin() const{}
            reverse_iterator rend(){
                return (reverse_iterator(_data + _size));
            }
            //const_reverse_iterator rend() const{}

        //*****CAPACITY*****
            size_type size() const{
                return (_size);
            }
            size_type max_size() const{
                return (_alloc.max_size());
            }
            void resize (size_type n, value_type val = value_type()){
                (void)n;
                (void)val;
            }
            size_type capacity() const{
                return (_capacity);
            }
            bool empty() const{
                if (_size == 0)
                    return (true);
                return (false);
            }
            void reserve (size_type n){
                (void)n;
            }

        //*****ELEMENT ACCESS*****
            reference operator[] (size_type n){
                return (_data[n]);
            }
            const_reference operator[] (size_type n) const{
                return (_data[n]);
            }
            reference at (size_type n){
                return (_data[n]);
            }
            const_reference at (size_type n) const{
                return (_data[n]);
            }
            reference front(){
                return (_data[0]);
            }
            const_reference front() const{
                return (_data[0]);
            }
            reference back(){
                return (_data[_size - 1]);
            }
            const_reference back() const{
                return (_data[_size - 1]);
            }
            value_type* data(){
                return (_data);
            }
            const value_type* data() const{
                return (_data);
            }

        //*****MODIFIERS*****
            //template <class InputIterator>  void assign (InputIterator first, InputIterator last){}
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
            /*
            iterator insert (iterator position, const value_type& val){} //single element
            void insert (iterator position, size_type n, const value_type& val){} //fill
            template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last){} // range
            iterator erase (iterator position){}
            iterator erase (iterator first, iterator last){}
            void swap (vector& x){}
            */
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
    /*
    //___Relational operators___
    template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){}
    template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){}
    template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){}	
    template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){}
    template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){}	
    template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){}
    //___Swap ( vector )
    template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){}
    */

}

#endif