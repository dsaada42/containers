#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP
# include "vector.hpp"
# include "type_traits.hpp"
# include <iterator>
# include <cstddef>

namespace ft{

    template < class T, bool ConstB >
    class vector_iterator{
        public:
            typedef typename ft::conditional<ConstB, const T, T>::type  value_type;
            typedef value_type&                                         reference;
            typedef value_type const &                                  const_reference;
            typedef value_type*                                         pointer;
            typedef value_type const *                                  const_pointer;
            typedef std::ptrdiff_t                                      difference_type;
            typedef std::size_t                                         size_type;
            typedef std::random_access_iterator_tag                     iterator_category;
        
        public:
            pointer _ptr; //a changer en private + getter ?

        public:
        //***** CONSTRUCTORS / DESTRUCTOR / OPERATOR= *****
            vector_iterator(){ _ptr = NULL; }
            vector_iterator(pointer ptr){ _ptr = ptr; }
            vector_iterator(vector_iterator const & copy){ _ptr = copy._ptr; }
            vector_iterator &   operator=(vector_iterator const & copy){ _ptr = copy._ptr; return (*this); }
            virtual ~vector_iterator( void ){}
//========================= NOT MY CODE ===========================
            // Const stuff
		    template <bool B>
            vector_iterator(const vector_iterator<T, B> & x, typename ft::enable_if<!B>::type* = 0)	{ _ptr = x._ptr; }
            friend vector_iterator	    operator+(int n, const vector_iterator & x){ return (x._ptr + n); }
//=================================================================
        //***** ADD / SUBSTRACT *****
            vector_iterator&    operator+=(int rhs ){ _ptr += rhs; return (*this); }
            vector_iterator&    operator-=(int rhs ){ _ptr -= rhs; return (*this); }
            vector_iterator     operator+(int rhs) const{ vector_iterator tmp(*this); return (tmp += rhs); }
            vector_iterator     operator-(int rhs) const{ vector_iterator tmp(*this); return (tmp -= rhs); }
            difference_type     operator-(vector_iterator const & rhs) const { return (_ptr - rhs._ptr); }
        //***** INCREMENT / DECREMENT *****
            vector_iterator&    operator++(){ _ptr++; return (*this); }
            vector_iterator&    operator--(){ _ptr--; return (*this); }
            vector_iterator     operator++(int){ vector_iterator it = *this; ++(*this); return (it); }
            vector_iterator     operator--(int){ vector_iterator it = *this; --(*this); return (it); }
        //***** ACCESS / DEREFERENCE *****
            pointer             operator->(){ return (_ptr); }
            const_pointer       operator->() const { return (_ptr); }
            reference           operator*(){ return (*_ptr); }
            const_reference     operator*() const{ return (*_ptr); }
            reference           operator[](int index){ return (*(_ptr + index)); }
            const_reference     operator[](int index) const { return (*(_ptr + index)); }
        //***** COMPARISON *****
            template <bool B > bool   operator==(const vector_iterator<T, B> & rhs ) const{ return (_ptr == rhs._ptr); }
            template <bool B > bool   operator!=(const vector_iterator<T, B> & rhs ) const{ return (_ptr != rhs._ptr); }
            template <bool B > bool   operator<(const vector_iterator<T, B> & rhs ) const{ return (_ptr < rhs._ptr); }
            template <bool B > bool   operator>(const vector_iterator<T, B> & rhs ) const{ return (_ptr > rhs._ptr); }
            template <bool B > bool   operator<=(const vector_iterator<T, B> & rhs ) const{ return (_ptr <= rhs._ptr); }
            template <bool B > bool   operator>=(const vector_iterator<T, B> & rhs ) const{ return (_ptr >= rhs._ptr); }
    };
}

#endif