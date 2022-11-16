#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <cstddef>
# include <iostream>
# include "vector_iterator.hpp"

namespace ft {

    template < class T >
    class vector{
        
        public:
            typedef T                                       value_type;
            typedef size_t                                  size_type;
            typedef value_type&                             reference;
            typedef const value_type&                       const_reference;
            typedef value_type*                             pointer;
            typedef const value_type*                       const_pointer;
            typedef vector_iterator< vector<value_type> >   iterator;//random access iterator convertible to const iterator
            //typedef vector_iterator<const value_type>       const_iterator;
            typedef std::reverse_iterator<iterator>         reverse_iterator;
            //typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;


        private:
            T* _data;
            size_type _size;
            size_type _capacity;
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
            vector ( void ){
                _size = 0;
                _capacity = 2;
                //_data = new value_type[2];
                _data = (value_type*)::operator new(2 * sizeof(value_type)); // -> better approach useing allocator
            }  
            //____copy constructor___
            vector (const vector& x){
                (void)x;
            }
            //___destructor___
            ~vector< T >( void ){
                clear(); // calls each destructor one by one 
                //delete [] _data;
                ::operator delete(_data);
            }
            //____operator= surcharge___
            vector& operator= (const vector& x){
                (void)x;
                return (*this);
            }

        //******ITERATORS*****
            iterator begin(){
                return (iterator(_data));   
            }
            iterator end(){
                return (iterator(_data + _size));
            }

        //*****CAPACITY*****
            size_type size() const{
                return(_size);
            }
            size_type max_size() const{
                return(_size);
            }
            void resize (size_type n, value_type val = value_type()){
                (void)val;
                ReAlloc(n);
            }
            size_type capacity() const{
                return(_capacity);
            }
            bool empty() const{
                if (_size == 0)
                    return (true);
                return (false);
            }
            void reserve (size_type n){
                (void)n;
            }
            void shrink_to_fit(){

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
                }
            }
            void swap (vector& x){
                (void)x;
            }
            void clear(){
                while (_size > 0)
                    pop_back();
            }
    };

    //***** Non member function overloads *****
    //___Relational operators___
    template <class T>  bool operator== (const vector<T>& lhs, const vector<T>& rhs);
    template <class T>  bool operator!= (const vector<T>& lhs, const vector<T>& rhs);
    template <class T>  bool operator<  (const vector<T>& lhs, const vector<T>& rhs);	
    template <class T>  bool operator<= (const vector<T>& lhs, const vector<T>& rhs);
    template <class T>  bool operator>  (const vector<T>& lhs, const vector<T>& rhs);	
    template <class T>  bool operator>= (const vector<T>& lhs, const vector<T>& rhs);
    //___Swap ( vector )
    template <class T>  void swap (vector<T>& x, vector<T>& y);

};

#endif