#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP
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
            RBTree_node *parent; 
            RBTree_node *left; 
            RBTree_node *right; 
            int         color; 

            RBTree_node (void) : data(T()), parent(0), left(0), right(0), color(RED){}
            RBTree_node (T const & value ) : data(value), parent(0), left(0), right(0), color(RED) {}
            RBTree_node& operator= ( RBTree_node const & rhs )
            {
                data = rhs.data;
                parent = rhs.data;
                left = rhs.left;
                right = rhs.right;
                color = rhs.color;
                return *this;
            }
            ~RBTree_node ( void ) {};
    };

    template < class T, bool ConstB >
    class RBTree_iterator{
        public:
            typedef T                                                   value_type;
            // typedef typename ft::conditional<ConstB, const T, T>::type  value_type;
            typedef value_type&                                         reference;
            typedef const value_type &                                  const_reference;
            typedef value_type*                                         pointer;
            typedef const value_type *                                  const_pointer;
            typedef std::ptrdiff_t                                      difference_type;
            typedef std::size_t                                         size_type;
            typedef std::bidirectional_iterator_tag                     iterator_category;
            typedef RBTree_node< value_type >                           node;

        private:
            node *node_ptr;
            node *null_node;

        public:
        //***** CONSTRUCTORS / DESTRUCTOR / OPERATOR= *****
            RBTree_iterator(){
                node_ptr = NULL;
                null_node = NULL;
            }
            RBTree_iterator(node * ptr, node * leaf){
                node_ptr = ptr;
                null_node = leaf;
            }
            RBTree_iterator(RBTree_iterator const & rhs){
                node_ptr = rhs.node_ptr;
                null_node = rhs.null_node;
            }
            RBTree_iterator &   operator=(RBTree_iterator const & rhs){
                node_ptr = rhs.node_ptr;
                null_node = rhs.null_node;
                return (*this);
            }
            // template <bool B>
            // RBTree_iterator(RBTree_iterator<T, B> const & rhs, typename ft::enable_if<!B>::type* = 0)	{ 
            //     node_ptr = rhs.node_ptr;
            //     null_node = rhs.null_node; 
            // }
            virtual ~RBTree_iterator( void ){}  
        //***** INCREMENT / DECREMENT *****
            RBTree_iterator&    operator++(){
                node *node = node_ptr;
                //cas 1: has right child, return right child
                if (node->right != null_node){
                    node_ptr = node->right;
                }
                //cas 2: is highest right
                //cas 3: has no right child, return first parent with left child
                else if (node->right == null_node){
                    node = node->parent;
                    while (node->left == null_node){
                        node = node->parent;
                    }
                }
                node_ptr = node;
                return (*this);
            }
            RBTree_iterator&    operator--(){
                node *node = node_ptr;
                //cas 1: has left child, return left child
                if (node->left != null_node){
                    node_ptr = node->left;
                }
                //cas 2: is lowest left
                //cas 3: has no left child, return first parent with right child
                else if (node->left == null_node){
                    node = node->parent;
                    while (node->right == null_node){
                        node = node->parent;
                    }
                }
                node_ptr = node;
                return (*this);
            }
            RBTree_iterator     operator++(int){ RBTree_iterator it = *this; ++(*this); return (it); }
            RBTree_iterator     operator--(int){ RBTree_iterator it = *this; --(*this); return (it); }
        //***** ACCESS / DEREFERENCE *****
            pointer             operator->(){ return (&node_ptr->data); }
            const_pointer       operator->() const { return (&node_ptr->data); }
            reference           operator*(){ return (node_ptr->data); }
            const_reference     operator*() const{ return (node_ptr->data); }
        //***** COMPARISON *****
            template <bool B > bool   operator==(const RBTree_iterator<T, B> & rhs ) const{ return (node_ptr == rhs.node_ptr); }
            template <bool B > bool   operator!=(const RBTree_iterator<T, B> & rhs ) const{ return (node_ptr != rhs.node_ptr); }
    };    

}

#endif