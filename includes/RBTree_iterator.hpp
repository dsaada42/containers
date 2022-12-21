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

        public:
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
            template <bool B>
            RBTree_iterator(RBTree_iterator<T, B> const & rhs, typename ft::enable_if<!B>::type* = 0)	{ 
                node_ptr = rhs.node_ptr;
                null_node = rhs.null_node; 
            }
            virtual ~RBTree_iterator( void ){}  
        //***** INCREMENT / DECREMENT *****
            RBTree_iterator&    operator++(){
                node *node = node_ptr;
                //cas 0: node is null_node
                if (node == null_node){ //case end()
                    //on souhaite renvoyer vers le max qui sera identifie comme null_node -> parent
                    node_ptr = null_node->parent;
                }
                //cas 1: has right child, return lowest right child
                else if (node->right != null_node){
                    node_ptr = node->right;
                    while (node_ptr->left != null_node)
                        node_ptr = node_ptr->left;
                }
                //cas 2: is highest right
                else if (__is_rightest(node) == true){
                    node_ptr = null_node; // on renvoie vers le null node (end)
                }
                //cas 3: has no right child, return first parent with node/node->parent as left child
                else if (node->right == null_node){
                    //cas 3.1: no right child, is left child
                    if (node == node->parent->left)
                        node_ptr = node->parent;
                    //cas 3.2: no right child, is right child
                    else{
                        while (node == node->parent->right){
                            node = node->parent;
                        }
                        node_ptr = node->parent; //this node is left child of his parent
                    }
                }
                return (*this);
            }
            RBTree_iterator&    operator--(){
                node *node = node_ptr;
                //cas 0: node is null_node
                if (node == null_node){ //case end()
                    //on souhaite renvoyer vers le max qui sera identifie comme null_node -> parent
                    node_ptr = null_node->parent;
                }
                //cas 1: has left child, return highest left child
                else if (node->left != null_node){
                    node_ptr = node->left;
                    while (node_ptr->right != null_node)
                        node_ptr = node_ptr->right;
                }
                //cas 2: is lowest left
                else if (__is_leftest(node) == true){
                    node_ptr = null_node;
                }
                //cas 3: has no left child, return first parent with node/node->parent as right child
                else if (node->left == null_node){
                    //cas 3.1: no left child, is right child
                    if (node == node->parent->right){
                        node_ptr = node->parent;
                    }
                    //cas 3.2: no left child, is left child
                    else{
                        while (node == node->parent->left){
                            node = node->parent;
                        }
                        node_ptr = node->parent; //this node is left child of his parent
                    }   
                }
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

        private:
            bool __is_leftest(node * node){
                if (node->parent == null_node){
                    return(true);//we are root, end of recursivity 
                }
                else if (node == node->parent->left){
                    return(__is_leftest(node->parent)); //node is left child, check for parent
                }
                else
                    return(false);//node is right child, cannot be leftest
            }
            bool __is_rightest(node *node){
                if (node->parent == null_node){
                    return(true);//we are root, end of recursivity 
                }
                else if (node == node->parent->right){
                    return(__is_rightest(node->parent)); //node is right child, check for parent
                }
                else
                    return(false);//node is right child, cannot be rightest
            }
    };    

}

#endif