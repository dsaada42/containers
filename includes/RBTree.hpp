/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:46:40 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 14:24:18 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP
# include <iostream>
# include <iterator>
# include <memory>
# include <cstddef>
# include "RBTree_iterator.hpp"
# include "iterator.hpp"
# include "type_traits.hpp"
# include "pair.hpp"
# define RED 1
# define BLACK 0
# define LEFT true
# define RIGHT false

namespace ft {
    
    template< class T, class Compare = std::less< T >, class Alloc = std::allocator< T > >
    class RBTree{
        
        public:
            typedef T                                                               value_type;
            typedef Alloc                                                           allocator_type;
            typedef Compare                                                         value_compare;
            typedef typename allocator_type::reference                              reference;
            typedef typename allocator_type::const_reference                        const_reference;
            typedef typename allocator_type::pointer                                pointer;
            typedef typename allocator_type::const_pointer                          const_pointer;
            typedef ft::RBTree_iterator<value_type, false>                          iterator;
            typedef ft::RBTree_iterator<value_type, true>                           const_iterator;
            typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                            const_reverse_iterator;
            typedef ft::RBTree_node< value_type >                                   node_type;
            typedef std::ptrdiff_t                                                  difference_type;
            typedef std::size_t                                                     size_type;
            typedef typename allocator_type::template rebind< node_type >::other    node_allocator_type;
        
        public:
            explicit RBTree( const value_compare& comp, const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc), _size(0){
                null_node = __new_node();
                null_node->color = BLACK;
                root = null_node;
            }
            RBTree (const RBTree& x): _comp(x._comp), _alloc(x._alloc){
                null_node = __new_node();
                null_node->color = BLACK;
                root = null_node;
                insert(x.begin(), x.end());
                _size = x.size();
            }
            ~RBTree( void ){
                clear();
                __delete_node(null_node);
            }
            RBTree& operator= (const RBTree& x){
                clear();
                _comp = x._comp;
                _alloc = x._alloc;
                insert(x.begin(), x.end());
                _size = x.size();
                return (*this);
            }
        //***** ITERATORS *****
            iterator                begin(){
                node_type *tmp = root;
                if (tmp != null_node){
                    while (tmp->left != null_node)
                        tmp = tmp->left;
                }
                return (iterator(tmp, null_node));
            }
            const_iterator          begin() const{
                node_type *tmp = root;
                if (tmp != null_node){
                    while (tmp->left != null_node)
                        tmp = tmp->left;
                }
                return (const_iterator(tmp, null_node));
            }
            iterator                end(){
                node_type *tmp = root;
                if (tmp != null_node){
                    while (tmp != null_node)
                        tmp = tmp->right;
                }
                return (iterator(tmp, null_node));
            }
            const_iterator          end() const{
                node_type *tmp = root;
                if (tmp != null_node){
                    while (tmp != null_node)
                        tmp = tmp->right;
                }
                return (const_iterator(tmp, null_node));
            }
            reverse_iterator        rbegin()        { return (reverse_iterator(end())); }
            const_reverse_iterator  rbegin() const  { return (const_reverse_iterator(end())); }
            reverse_iterator        rend(){ return  (reverse_iterator(begin())); }
            const_reverse_iterator  rend() const    { return (const_reverse_iterator(begin())); }
        
        //***** CAPACITY *****
            bool                    empty() const   { return (_size == 0); }
            size_type               size() const    { return (_size); }
            size_type               max_size() const{ return (_node_alloc.max_size()); }
        
        //***** ELEMENT ACCESS *****
            value_type& operator[] (const value_type& k){ return( *(insert(k).first) ); }
            value_type& at (const value_type& k){
                node_type *node;

                node = __search_last_val(k);
                if (node != null_node)
                    return(node->data);
                throw std::out_of_range("trying to access element out of range");
            }
            const value_type& at (const value_type& k) const{
                node_type *node;

                node = __search_last_val(k);
                if (node != null_node)
                    return(node->data);
                throw std::out_of_range("trying to access element out of range");
            }
        
        //***** MODIFIERS *****
            iterator insert (iterator position, const value_type& val){
                (void)position;
                return (insert(val).first);
            }
            const_iterator insert (const_iterator position, const value_type& val){
                (void)position;
                return (insert(val).first);
            }
            ft::pair<iterator, bool> insert(const value_type &val){            
                node_type *tmp = root;
                node_type *p = 0;
                node_type *node = __new_node(val);
                
                node->left = null_node;
                node->right = null_node;

                if (root == null_node){// case 1: tree is empty, node becomes black root
                    node->parent = null_node;
                    node->color = BLACK;
                    root = node;
                    __update_null_node();
                    _size++;
                    return (ft::make_pair(iterator(root, null_node), true));
                }
                //we search for the right spot for our key
                p = __search_last_val(val);
                if (p != null_node){
                    __delete_node(node);    
                    return (ft::make_pair(iterator(p, null_node), false)); 
                }
                while (tmp != null_node){
                    p = tmp;
                    if (_comp(node->data , tmp->data)) //node->data.first < tmp->data.first
                        tmp = tmp->left; 
                    else
                        tmp = tmp->right;
                }
                //assign child to parent (left or right)
                node->parent = p;
                if (_comp(node->data , p->data)) // node->data.first <  p->data.first
                    p->left = node;
                else if (_comp(p->data, node->data))
                    p->right = node;
                else{// already in the tree
                    _size++;
                    __delete_node(node);
                    return (ft::make_pair(iterator(p, null_node), false));
                }
                if (node->parent->color == BLACK){
                    __update_null_node();
                    _size++;
                    return (ft::make_pair(iterator(node, null_node), true));
                }
                _size++;
                __repair_insert(node);
                __update_null_node();
                return (ft::make_pair(iterator(node, null_node), true));
            }
            template <class InputIterator>  void insert (InputIterator first, InputIterator last){
                while( first != last){
                    insert(*first++);
                }
            }
            size_type erase(const value_type & val){
                node_type  *node;
                
                node = __search_last_val(val);
                if (node != null_node){
                    erase(node);
                    return(1);    
                }
                return (0);
            }
            void erase(node_type *node){ 
                node_type  *to_delete;
                node_type  *new_node;
                int     original_color;

                original_color = node->color;
                //case 1 : no left child 
                if (node->left == null_node){
                    new_node = __assign_child_parent(node, RIGHT);
                    __delete_node(node);
                    if (original_color == BLACK){// le noeud etait noir
                        if (new_node->color == RED)// l enfant etait rouge , good
                            new_node->color = BLACK;
                        else// l enfant etait noir 
                            __repair_delete(new_node); //il faut repair double black
                    }
                    _size--;
                }
                //case 2 : no right child
                else if (node->right == null_node){
                    new_node = __assign_child_parent(node, LEFT);
                    __delete_node(node);
                    if (original_color == BLACK){// le noeud etait noir
                        if (new_node->color == RED)// l enfant etait rouge , good
                            new_node->color = BLACK;
                        else// l enfant etait noir 
                            __repair_delete(new_node); //il faut repair double black
                    }
                    _size--;
                }
                //case 3 : both children are valid
                else{
                    to_delete = __highest_left(node);
                    new_node = __new_node(to_delete->data);
                    //on branche au child de droite
                    new_node->right = node->right;
                    new_node->right->parent = new_node;
                    //on branche au child de gauche
                    new_node->left = node->left;
                    new_node->left->parent = new_node;
                    //on branche au parent
                    new_node->parent = node->parent;
                    if (node->parent == null_node)  
                        root = new_node;
                    else if (node == node->parent->left)
                        new_node->parent->left = new_node;
                    else
                        new_node->parent->right = new_node;
                    new_node->color = original_color;
                    original_color = to_delete->color;
                    __delete_node(node);
                    erase(to_delete);
                }
                __update_null_node();
            }
            void erase (iterator first, iterator last){
                while (first != last)
                    erase(*first++);
            }
            void erase (const_iterator first, const_iterator last){
                while (first != last)
                    erase(*first++);
            }
            void swap (RBTree& x){
                node_type       *tmp_root;
                node_type       *tmp_null_node;
                value_compare   tmp_comp = value_compare(_comp);
                allocator_type  tmp_alloc;
                size_type       tmp_size;

                tmp_alloc = x._alloc;
                x._alloc = _alloc;
                _alloc = tmp_alloc;

                tmp_comp = x._comp;
                x._comp = _comp;
                _comp = tmp_comp;

                tmp_root = x.root;
                x.root = root;
                root = tmp_root;

                tmp_size = x._size;
                x._size = _size;
                _size = tmp_size;

                tmp_null_node = x.null_node;
                x.null_node = null_node;
                null_node = tmp_null_node;
            }
            void    clear(void){
                if (root == null_node)
                    return;
                while( root->left != null_node ){
                    erase(__highest_left(root)->data);
                }
                while( root->right != null_node){
                    erase(__lowest_right(root)->data);
                }
                erase(root->data);
            }

        //***** OPERATIONS *****
            iterator find (const value_type& k){
                return(iterator(__search_last_val(k), null_node));
            }
            const_iterator find (const value_type& k) const{
                return(const_iterator(__search_last_val(k), null_node));  
            }
            size_type count (const value_type& k) const{
                if (__search_last_val(k) == null_node)
                    return (0);
                return (1);
            }
            iterator lower_bound (const value_type& k){
                node_type *current;
                node_type *lower = null_node;
                
                current = root;
                
                while(current != null_node){
                    if (!_comp(current->data, k)){
                        lower = current;
                        current = current->left;
                    }
                    else
                        current = current->right;
                }
                return(iterator(lower, null_node));
            }
            const_iterator lower_bound (const value_type& k) const{
                node_type *current;
                node_type *lower = null_node;
                
                current = root;
                
                while(current != null_node){
                    if (!_comp(current->data, k)){
                        lower = current;
                        current = current->left;
                    }
                    else
                        current = current->right;
                }
                return(const_iterator(lower, null_node));
            }
            iterator upper_bound (const value_type& k){
                node_type *current;
                node_type *upper = null_node;

                current = root;
                
                while(current != null_node){
                    if (_comp(k, current->data)){
                        upper = current;
                        current = current->left;
                    }
                    else
                        current = current->right;
                }
                return(iterator(upper, null_node));
            }
            const_iterator upper_bound (const value_type& k) const{
                node_type *current;
                node_type *upper = null_node;

                current = root;
                
                while(current != null_node){
                    if (_comp(k, current->data)){
                        upper = current;
                        current = current->left;
                    }
                    else
                        current = current->right;
                }
                return(const_iterator(upper, null_node));
            }
            pair<const_iterator,const_iterator> equal_range (const value_type& k) const{
                return(ft::make_pair(lower_bound(k), upper_bound(k)));
            }
            pair<iterator,iterator> equal_range (const value_type& k){
                return(ft::make_pair(lower_bound(k), upper_bound(k)));
            }

        //***** ALLOCATOR *****
            allocator_type get_allocator() const{ return (_alloc); }
            
        private:
            node_type           *root;
            node_type           *null_node;
            value_compare       _comp;
            allocator_type      _alloc;
            node_allocator_type _node_alloc;
            size_type           _size;

            //----- delete node -----
            void    __delete_node(node_type *node){
                if (node != null_node)
                    _alloc.destroy(&(node->data));
                _node_alloc.deallocate(node, 1);
            }
            //----- Allocates a node with node_alloc -----
            node_type  *__new_node(void){
                node_type   *node = _node_alloc.allocate(1);
                node->parent = 0;
                node->left = 0;
                node->right = 0;
                node->color = RED;

                return(node);
            }
            //----- Allocates a node with node_alloc and constructs data with alloc -----
            node_type  *__new_node(value_type const & val){
                node_type   *node = _node_alloc.allocate(1);
                _alloc.construct(&(node->data), val);
                node->parent = 0;
                node->left = 0;
                node->right = 0;
                node->color = RED;

                return(node);
            }            
            node_type  *__max(node_type *node) const{
                node_type *current;

                current = node;
                while (current->right != null_node)
                    current = current->right;
                return(current);
            }
            node_type  *__min(node_type *node) const{
                node_type *current;

                current = node;
                while (current->left != null_node)
                    current = current->left;
                return(current);
            }
            //---- Helper function to prevent overflow on iterator or out of bound -----
            void    __update_null_node(void){
                node_type * current;
                current = root;

                if (current == null_node){
                    null_node->parent = null_node;
                }
                else{
                    while (current->right != null_node){
                        current = current->right;
                    }
                    null_node->parent = current;
                }
            }
            //----- Helper function to find out if a  == b -----
            bool    __value_equal(value_type a, value_type b) const{
                if (_comp(a, b) == _comp(b, a))
                    return (true);
                return (false);
            }
            //----- Init node to be root or leaf -----
            void    __null_node(node_type *node){
                node->parent = 0;
                node->left = 0;
                node->right = 0;
                node->color = BLACK;
            }
            //----- Find highest of left subtree -----
            node_type  *__highest_left(node_type *node) const{
                node_type *tmp;

                if (node == null_node)
                    return (null_node);
                else if (node->left == null_node)
                    return (null_node);
                tmp = node->left;
                while (tmp->right != null_node)
                    tmp = tmp->right;
                return (tmp);
            }
            //----- Find lowest of right subtree -----
            node_type  *__lowest_right(node_type *node) const{
                node_type  *tmp;

                if (node == null_node)
                    return (null_node);
                else if (node->right == null_node)
                    return (null_node);
                tmp = node->right;
                while (tmp->left != null_node)
                    tmp = tmp->left;
                return (tmp);
            }
            //----- Repair tree properties after insertion ----- 
            void __repair_insert(node_type *node){
                node_type *uncle;
                node_type *parent;

                if (node == root){
                    root->color = BLACK;
                    return;
                }
                parent = node->parent;
                if (parent->color == BLACK)
                    return;
                //cas 1: parent is left
                if (parent == parent->parent->left){
                    uncle = parent->parent->right;
                    //cas 1.1: uncle is right red
                    if (uncle->color == RED){
                        uncle->color = BLACK; //uncle becomes black
                        parent->color = BLACK; //parent becomes black
                        parent->parent->color = RED; //gp becomes red
                        __repair_insert(parent->parent); //recursive on gp
                    }
                    //cas 1.2: uncle is right black
                    else{
                        //cas 1.2.1: LL parent is red left, node is red left 
                        if (node == parent->left){
                            parent->color = BLACK; //parent becomes black
                            parent->parent->color = RED; // gp becomes red
                            __right_rotate(parent->parent);// rotate right sur gp                        
                        }
                        //cas 1.2.2: LR parent is red left, node is red right
                        else{
                            __left_rotate(parent);
                            __repair_insert(parent);
                        }
                    }
                }
                //cas 2: parent is right
                else{
                    uncle = parent->parent->left;
                    //cas 2.1: uncle is left red
                    if (uncle->color == RED){
                        uncle->color = BLACK; //uncle becomes black
                        parent->color = BLACK; //parent becomes black
                        parent->parent->color = RED; //gp becomes red
                        __repair_insert(parent->parent); //recursive on gp
                    }
                    //cas 2.2: uncle is left black
                    else{
                        //cas 2.2.1: RR parent is red right, node is red right
                        if (node == parent->right){
                            parent->color = BLACK; //parent becomes black
                            parent->parent->color = RED; // gp becomes red
                            __left_rotate(parent->parent); // rotate left sur gp
                        }
                        //cas 2.2.2: RL parent is red right, node is red left
                        else{
                            __right_rotate(parent);
                            __repair_insert(parent);
                        }
                    }
                }
            }
            //----- Get sibling -----
            node_type  *__get_sibling(node_type *node) const{
                if (node->parent == null_node)
                    return (null_node);
                else if (node == node->parent->left)
                    return (node->parent->right);
                else
                    return (node->parent->left);
            }
            //----- Repair after deletion -----
            void    __repair_delete(node_type *node){
                node_type *sibling;
                // printTree();
                if (node == root)
                    return;

                sibling = __get_sibling(node);
                //cas 0: sibling is leaf 
                if (sibling == null_node){
                    if (node->parent->color == BLACK)
                        __repair_delete(node->parent);
                    else
                        node->parent->color = BLACK;
                }
                //cas 1: sibling black + at least one child red
                else if (sibling->color == BLACK && (sibling->left->color == RED || sibling->right->color == RED)){
                    // std::cout << "node " << node->data.first << ": Cas 1 -> S Black + 1 or more Red children" << std::endl;
                    //cas 1.a: LL Sibling is left child, sibling's left child is red
                    if (sibling == sibling->parent->left && sibling->left->color == RED){
                        // std::cout << "cas 1.a: LL Sibling is left child, sibling's left child is red" << std::endl;
                        sibling->left->color = sibling->color;
                        sibling->color = node->parent->color;
                        __right_rotate(node->parent);
                    }
                    //cas 1.b: LR Sibling is left child, sibling's right child is red
                    else if (sibling == sibling->parent->left && sibling->right->color == RED){
                        // std::cout << "cas 1.b: LR Sibling is left child, sibling's right child is red" << std::endl;
                        __left_rotate(sibling);
                        __right_rotate(node->parent);
                    }
                    //cas 1.c: RR Sibling is right child, sibling's right child is red
                    else if (sibling == sibling->parent->right && sibling->right->color == RED){
                        // std::cout << "cas 1.c: RR Sibling is right child, sibling's right child is red" << std::endl;
                        sibling->right->color = sibling->color;
                        sibling->color = node->parent->color;
                        __left_rotate(node->parent);
                    }
                    //cas 1.d: RL Sibling is right child, sibling's left child is red
                    else if (sibling == sibling->parent->right && sibling->left->color == RED){
                        // std::cout << "cas 1.d: RL Sibling is right child, sibling's left child is red" << std::endl;
                        __right_rotate(sibling);
                        __left_rotate(node->parent);
                    }
                }
                //cas 2: sibling black + double black children
                else if (sibling->color == BLACK && sibling->left->color == BLACK && sibling->right->color == BLACK){
                    // std::cout << "cas 2: sibling black + double black children" << std::endl;
                    sibling->color = RED;
                    if (node->parent->color == BLACK)
                        __repair_delete(node->parent);
                    else
                        node->parent->color = BLACK;
                }
                //cas 3: sibling red
                else if (sibling->color == RED){ //on recolore sibling(black) et parent(red) 
                    // std::cout << "cas 3: sibling red" << std::endl;
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    if (sibling == sibling->parent->right){// apres la rotation on se retrouve dans le cas 1 ou 2
                        __left_rotate(node->parent);
                    }
                    else{
                        __right_rotate(node->parent);
                    }
                    __repair_delete(node);
                }
                root->color = BLACK;
                __update_null_node();
            }
            //----- Assign child to parent -----
            node_type *__assign_child_parent(node_type *node, bool left){
                node_type  *to_assign;

                if (left == LEFT)
                    to_assign = node->left;
                else
                    to_assign = node->right;
                to_assign->parent = node->parent;
                if (node->parent == null_node)
                    root = to_assign;
                else if (node == node->parent->left) // cas ou node is left child
                    node->parent->left = to_assign;
                else                                 // cas ou node is right child
                    node->parent->right = to_assign;
                return (to_assign);
            }  
            //----- Search node by key -----
            node_type *__search_val(node_type *node, value_type val) const{
                if (node == null_node || __value_equal(val, node->data)) // if val == node->data
                    return(node);
                if (_comp(val , node->data)) // if val < node->data
                    return( __search_val(node->left, val) );
                return( __search_val(node->right, val) );
            }
            //----- Search last occurence of key -----
            node_type *__search_last_val(value_type val) const{
                node_type  *current;
                node_type  *node;

                node = null_node;
                current = root;
                while (current != null_node){
                    if (__value_equal(current->data, val)) //if val == current->data
                        node = current;
                    if (!_comp(current->data , val)) // if val <= current->data
                        current = current->left;
                    else
                        current = current->right;
                }
                return (node);
            }
            //----- Rotate right on node p -----
            void __right_rotate(node_type *p){
                node_type *k = p->left;

                k->parent = p->parent; //1
                p->parent = k; //2 
                p->left = k->right; //3
                k->right = p;//4
                if (k->parent == null_node) // case parent == root    //5         
                    root = k;
                else if (p == k->parent->right) // si p etait right child
                    k->parent->right = k;
                else    // si p etait left child
                    k->parent->left = k;
                if (p->left != null_node)
                    p->left->parent = p;
            }
            //----- Rotate left on node p -----
            void __left_rotate(node_type *p){
                node_type *k = p->right;

                k->parent = p->parent; //1
                p->parent = k; //2 
                p->right = k->left; //3
                k->left = p;//4
                if (k->parent == null_node) // case parent == root //5         
                    root = k;
                else if (p == k->parent->right) // si p etait right child
                    k->parent->right = k;
                else    // si p etait left child
                    k->parent->left = k;
                if (p->right != null_node)
                    p->right->parent = p;
            }
    };

}
#endif