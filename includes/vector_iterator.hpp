#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP
# include "vector.hpp"
# include <cstddef>

namespace ft{

    template < typename vector >
    class vector_iterator{
        public:
            typedef typename vector::value_type         value_type;
            typedef value_type&                         reference;
            typedef const value_type&                   const_reference;
            typedef value_type*                         pointer;
            typedef const value_type*                   const_pointer;
            typedef ptrdiff_t                           difference_type;
            typedef size_t                              size_type;

            pointer _ptr;

            vector_iterator(pointer ptr){
                _ptr = ptr;
            }
            vector_iterator& operator+=(const vector_iterator& rhs ){
                _ptr += rhs._ptr;
                return (*this);
            }
            vector_iterator& operator-=(const vector_iterator& rhs ){
                _ptr -= rhs._ptr;
                return (*this);
            }
            vector_iterator& operator++(){
                _ptr++;
                return (*this);
            }
            vector_iterator operator++(int){
                vector_iterator it = *this;
                ++(*this);
                return (it);
            }
            vector_iterator& operator--(){
                _ptr--;
                return (*this);
            }
            vector_iterator operator--(int){
                vector_iterator it = *this;
                --(*this);
                return (it);
            }
            pointer operator->(){
                return (_ptr);
            }
            const_pointer operator->() const {
                return (_ptr);
            }
            reference operator*(){
                return (*_ptr);
            }
            const_reference operator*() const{
                return (*_ptr);
            }
            reference operator[](int index){
                return (*(_ptr + index));
            }
            const_reference operator[](int index) const {
                return (*(_ptr + index));
            }
            bool operator==(const vector_iterator& rhs ) const{
                return (_ptr == rhs._ptr);
            }
            bool operator!=(const vector_iterator& rhs ) const{
                return (_ptr != rhs._ptr);
            }
            //-----------A COMPLETER --------------
            bool operator<(const vector_iterator& rhs ) const{
                (void)rhs;
                return (true); 
            }
            bool operator>(const vector_iterator& rhs ) const{
                (void)rhs;
                return (true);
            }
            bool operator<=(const vector_iterator& rhs ) const{
                (void)rhs;
                return (true); 
            }
            bool operator>=(const vector_iterator& rhs ) const{
                (void)rhs;
                return (true);
            }
            vector_iterator operator+(int rhs) const{
                return (_ptr + rhs);
            }
            vector_iterator operator-(int rhs) const{
                return (_ptr - rhs);
            }
    };
}

#endif