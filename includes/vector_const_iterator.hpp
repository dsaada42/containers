#ifndef VECTOR_CONST_ITERATOR_HPP
# define VECTOR_CONST_ITERATOR_HPP
# include "vector.hpp"

namespace ft{

    template < typename vector >
    class vector_const_iterator{
        public:
            typedef typename vector::value_type         value_type;
            typedef value_type&                         reference;
            typedef const value_type&                   const_reference;
            typedef value_type*                         pointer;
            typedef const value_type*                   const_pointer;
        
            pointer _ptr;

            vector_const_iterator(pointer ptr){
                _ptr = ptr;
            }

            vector_const_iterator& operator+=(const vector_const_iterator& rhs ){
                _ptr += rhs._ptr;
                return (*this);
            }
            vector_const_iterator& operator-=(const vector_const_iterator& rhs ){
                _ptr -= rhs._ptr;
                return (*this);
            }
            vector_const_iterator& operator++(){
                _ptr++;
                return (*this);
            }
            vector_const_iterator operator++(int){
                vector_const_iterator it = *this;
                ++(*this);
                return (it);
            }
            vector_const_iterator& operator--(){
                _ptr--;
                return (*this);
            }
            vector_const_iterator operator--(int){
                vector_const_iterator it = *this;
                --(*this);
                return (it);
            }
            pointer operator->(){
                return (_ptr);
            }
            const_pointer operator->() const {
                return (_ptr);
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
            bool operator==(const vector_const_iterator& rhs ) const{
                return (_ptr == rhs._ptr);
            }
            bool operator!=(const vector_const_iterator& rhs ) const{
                return (_ptr != rhs._ptr);
            }

    };
}

#endif