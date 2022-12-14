#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP
# include "RBTree.hpp"
# include "type_traits.hpp"
# include <iterator>
# include <cstddef>
# define RED 1
# define BLACK 0

namespace ft{
    template< class T >
    class RBTree_node {
        public:
            T           data;
            RBTree_node *parent; // pointer to the parent
            RBTree_node *left; // pointer to left child
            RBTree_node *right; // pointer to right child
            int         color; // 1 -> Red, 0 -> Black

            RBTree_node (void){
                data = T();
                parent = 0;
                left = 0;
                right = 0;
                color = RED;
            }
            RBTree_node (T value ) { 
                data = value;
                parent = 0;
                left = 0;
                right = 0;
                color = RED;
            }
    };

    template < class T, bool ConstB >
    class RBTree_iterator{
        public:
            typedef typename ft::conditional<ConstB, const T, T>::type  value_type;
            typedef value_type&                                         reference;
            typedef value_type const &                                  const_reference;
            typedef value_type*                                         pointer;
            typedef value_type const *                                  const_pointer;
            typedef std::ptrdiff_t                                      difference_type;
            typedef std::size_t                                         size_type;
            typedef std::bidirectional_iterator_tag                     iterator_category;
        
        // private:
        //     RBTree_node  *_node;

        // public:
        // //***** CONSTRUCTORS / DESTRUCTOR / OPERATOR= *****
        //     RBTree_iterator(){ _ptr = NULL; }
        //     RBTree_iterator(pointer ptr){ _ptr = ptr; }
        //     RBTree_iterator(RBTree_iterator const & copy){ _ptr = copy._ptr; }
        //     RBTree_iterator &   operator=(RBTree_iterator const & copy){ _ptr = copy._ptr; return (*this); }
        //     virtual ~RBTree_iterator( void ){}
        //     // Const stuff
		//     template <bool B>
        //     RBTree_iterator(const RBTree_iterator<T, B> & x, typename ft::enable_if<!B>::type* = 0)	{ _ptr = x._ptr; }
        //     friend RBTree_iterator	    operator+(int n, const RBTree_iterator & x){ return (x._ptr + n); }
        // //***** INCREMENT / DECREMENT *****
        //     RBTree_iterator&    operator++(){ _ptr++; return (*this); }
        //     RBTree_iterator&    operator--(){ _ptr--; return (*this); }
        //     RBTree_iterator     operator++(int){ RBTree_iterator it = *this; ++(*this); return (it); }
        //     RBTree_iterator     operator--(int){ RBTree_iterator it = *this; --(*this); return (it); }
        // //***** ACCESS / DEREFERENCE *****
        //     pointer             operator->(){ return (_ptr); }
        //     const_pointer       operator->() const { return (_ptr); }
        //     reference           operator*(){ return (*_ptr); }
        //     const_reference     operator*() const{ return (*_ptr); }
        // //***** COMPARISON *****
        //     template <bool B > bool   operator==(const RBTree_iterator<T, B> & rhs ) const{ return (_ptr == rhs._ptr); }
        //     template <bool B > bool   operator!=(const RBTree_iterator<T, B> & rhs ) const{ return (_ptr != rhs._ptr); }
    };    

}

#endif