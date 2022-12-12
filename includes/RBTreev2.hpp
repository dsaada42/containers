/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTreev2.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:46:40 by dsaada            #+#    #+#             */
/*   Updated: 2022/12/12 11:54:32 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP
# include <iostream>
# include <iterator>
# include <memory>
# include <cstddef>
# include "RBTree_iterator.hpp"
# include "reverse_iterator.hpp"
# define RED 1
# define BLACK 0
# define LEFT true
# define RIGHT false

namespace ft {
    
    template< class Pair, class Compare = std::less< Pair >, class Alloc = std::allocator<Pair> >
    class RBTree{
        
        public:
            typedef Pair                                                value_type;
            typedef Alloc                                               allocator_type;
            typedef Compare                                             value_compare;
            typedef typename allocator_type::reference                  reference;
            typedef typename allocator_type::const_reference            const_reference;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename allocator_type::const_pointer              const_pointer;
            typedef ft::RBTree_iterator<value_type, false>              iterator;
            typedef ft::RBTree_iterator<value_type, true>               const_iterator;
            typedef ft::reverse_iterator<iterator>                      reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
            typedef std::ptrdiff_t                                      difference_type; //ptrdiff_t
            typedef std::size_t                                         size_type;      
            
        private:
            //the root of our tree
            t_node *root;
            //any leaf of our tree
            t_node *null_node;

            //----- Init node to be root or leaf -----
            void __null_node(t_node *node){
                node->key = Key();
                node->data = T();
                node->parent = 0;
                node->left = 0;
                node->right = 0;
                node->color = BLACK;
            }

            //----- Find highest of left subtree -----
            t_node  *__highest_left(t_node *node){
                t_node *tmp;

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
            t_node  *__lowest_right(t_node *node){
                t_node  *tmp;

                if (node == null_node)
                    return (null_node);
                else if (node->right == null_node)
                    return (null_node);
                tmp = node->right;
                while (tmp->left != null_node)
                    tmp = tmp->left;
                return (tmp);
            }

            void __repair_insert(t_node *node){
                t_node *uncle;
                t_node *parent;

                std::cout << "repairing insert on node " << node->key << std::endl;
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
                            rightRotate(parent->parent);// rotate right sur gp                        
                        }
                        //cas 1.2.2: LR parent is red left, node is red right
                        else{
                            leftRotate(parent);
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
                            leftRotate(parent->parent); // rotate left sur gp
                        }
                        //cas 2.2.2: RL parent is red right, node is red left
                        else{
                            rightRotate(parent);
                            __repair_insert(parent);
                        }
                    }
                }
            }

            //----- Get sibling -----
            t_node  *__get_sibling(t_node *node){
                if (node->parent == null_node)
                    return (null_node);
                else if (node == node->parent->left)
                    return (node->parent->right);
                else
                    return (node->parent->left);
            }

            //----- Repair after deletion -----
            void    __repair_delete(t_node *node){
                t_node *sibling;
                printTree();
                std::cout << "repairing deletion on node " << node->key << std::endl;
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
                    std::cout << "node " << node->key << ": Cas 1 -> S Black + 1 or more Red children" << std::endl;
                    //cas 1.a: LL Sibling is left child, sibling's left child is red
                    if (sibling == sibling->parent->left && sibling->left->color == RED){
                        std::cout << "cas 1.a: LL Sibling is left child, sibling's left child is red" << std::endl;
                        sibling->left->color = sibling->color;
                        sibling->color = node->parent->color;
                        rightRotate(node->parent);
                    }
                    //cas 1.b: LR Sibling is left child, sibling's right child is red
                    else if (sibling == sibling->parent->left && sibling->right->color == RED){
                        std::cout << "cas 1.b: LR Sibling is left child, sibling's right child is red" << std::endl;
                        leftRotate(sibling);
                        rightRotate(node->parent);
                    }
                    //cas 1.c: RR Sibling is right child, sibling's right child is red
                    else if (sibling == sibling->parent->right && sibling->right->color == RED){
                        std::cout << "cas 1.c: RR Sibling is right child, sibling's right child is red" << std::endl;
                        sibling->right->color = sibling->color;
                        sibling->color = node->parent->color;
                        leftRotate(node->parent);
                    }
                    //cas 1.d: RL Sibling is right child, sibling's left child is red
                    else if (sibling == sibling->parent->right && sibling->left->color == RED){
                        std::cout << "cas 1.d: RL Sibling is right child, sibling's left child is red" << std::endl;
                        rightRotate(sibling);
                        leftRotate(node->parent);
                    }
                }
                //cas 2: sibling black + double black children
                else if (sibling->color == BLACK && sibling->left->color == BLACK && sibling->right->color == BLACK){
                    std::cout << "cas 2: sibling black + double black children" << std::endl;
                    sibling->color = RED;
                    if (node->parent->color == BLACK)
                        __repair_delete(node->parent);
                    else
                        node->parent->color = BLACK;
                }
                //cas 3: sibling red
                else if (sibling->color == RED){ //on recolore sibling(black) et parent(red) 
                    std::cout << "cas 3: sibling red" << std::endl;
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    if (sibling == sibling->parent->right){// apres la rotation on se retrouve dans le cas 1 ou 2
                        leftRotate(node->parent);
                    }
                    else{
                        rightRotate(node->parent);
                    }
                    __repair_delete(node);
                }
                root->color = BLACK;
            }
            
            //----- Assign child to parent -----
            t_node *__assign_child_parent(t_node *node, bool left){
                t_node  *to_assign;

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
            t_node *__search_key(t_node *node, Key key){
                if (node == null_node || key == node->key)
                    return( node );
                if (key < node->key)
                    return( __search_key(node->left, key) );
                return( __search_key(node->right, key) );
            }
            
            //----- Search last occurence of key -----
            t_node *__search_last_key(Key key){
                t_node  *current;
                t_node  *node;

                node = null_node;
                current = root;
                while (current != null_node){
                    if (current->key == key)
                        node = current;
                    if (key <= current->key)
                        current = current->left;
                    else
                        current = current->right;
                }
                return (node);
            }

        public:
            RBTree( void ){
                null_node = new t_node;
                __null_node(null_node);
                root = null_node;
            }
            //----- Right Rotation -----
            void rightRotate(t_node *p){
                std::cout << "right rotation on key "<< p->key << std::endl;
                t_node *k = p->left;

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

            //----- Left Rotation -----
            void leftRotate(t_node *p){
                std::cout << "left rotation on key "<< p->key << std::endl;
                t_node *k = p->right;

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

            //----- BST normal insertion -----
            void insert(Key key){            
                t_node *tmp = root;
                t_node *p = 0;
                t_node *node = new t_node;

                //********** A REMPLACER PAR CONSTRUCTEUR  node(key, data) **********
                node->parent = 0;
                node->left = null_node;
                node->right = null_node;
                node->key = key;
                node->data = T();
                node->color = RED;
                //*******************************************************************

                if (root == null_node){// case 1: tree is empty, node becomes black root
                    node->parent = null_node;
                    node->color = BLACK;
                    root = node;
                    return;
                }
                //we search for the right spot for our key
                while (tmp != null_node){
                    p = tmp;
                    if (key < tmp->key)
                        tmp = tmp->left; 
                    else
                        tmp = tmp->right;
                }
                //assign child to parent (left or right)
                node->parent = p;
                if (key < p->key)
                    p->left = node;
                else
                    p->right = node;

                if (node->parent->color == BLACK)
                    return;

                __repair_insert(node);
            }

            
            //----- Delete element from RBT -----
            void delete_node(Key key){ 
                std::cout << "deleting node " << key << std::endl;
                t_node  *node;
                t_node  *to_delete;
                t_node  *new_node;
                int     original_color;

                //recherche du noeud identified by key 
                node = __search_last_key(key);
                if (node == null_node)
                    return;

                //save original color of node
                original_color = node->color;
                //************************* RASSEMBLER CES DEUX CAS *******************************
                //case 1 : no left child 
                if (node->left == null_node){
                    new_node = __assign_child_parent(node, RIGHT);
                    delete node;
                    if (original_color == RED)// le noeud a supprimer etait rouge, OK
                        return;
                    if (original_color == BLACK){// le noeud etait noir
                        if (new_node->color == RED){// l enfant etait rouge , good
                            new_node->color = BLACK;
                            return;   
                        }
                        else{// l enfant etait noir 
                            __repair_delete(new_node); //il faut repair double black
                            return;
                        }
                    }
                }
                //case 2 : no right child
                else if (node->right == null_node){
                    new_node = __assign_child_parent(node, LEFT);
                    delete node;
                    if (original_color == RED)// le noeud a supprimer etait rouge, OK
                        return;
                    if (original_color == BLACK){// le noeud etait noir
                        if (new_node->color == RED){// l enfant etait rouge , good
                            new_node->color = BLACK;
                            return;   
                        }
                        else{// l enfant etait noir 
                            __repair_delete(new_node); //il faut repair double black
                            return;
                        }
                    }
                }
                //*************************************************************************************
                //case 3 : both children are valid
                else{
                    to_delete = __highest_left(node);
                    std::cout << "--> deleting highest left node key: " << to_delete->key << std::endl;
                    //***** A REMPLACER PAR CONSTRUCTEUR PAR COPIE t_node * new_node(to_delete)*****
                    //******************************************************************************
                    new_node = new t_node;
                    new_node->key = to_delete->key;
                    new_node->data = to_delete->data;
                    //******************************************************************************
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
                    //on supprime l'ancien noeud
                    delete node;
                    node = new_node;
                    delete_node(to_delete->key);
                }
            }

            void    clear(void){
                if (root == null_node)
                    return;
                while( root->left != null_node ){
                    delete_node(__highest_left(root)->key);
                }
                while( root->right != null_node){
                    delete_node(__lowest_right(root)->key);
                }
                std::cout << "Only node left is root" << std::endl;
                delete_node(root->key);
            }


        //*****************  TESTING ****************************
            //----- Print Tree -----
            void __print_tree(t_node *node, std::string offset, bool end) {
                if (node != null_node) {
                std::cout<<offset;
                if (end) { 
                    std::cout<<"R----";
                    offset += "     ";
                }
                else {
                    std::cout<<"L----";
                    offset += "|    ";
                }
                std::string color = node->color?"RED":"BLACK";
                std::cout<<node->key<<"("<<color<<")"<<std::endl;
                __print_tree(node->left, offset, false);
                __print_tree(node->right, offset, true);
                }
            }

            void printTree(void){
                if (root != null_node)
                    __print_tree(root, "", true);
                else
                    std::cout << "Empty tree" << std::endl;
                std::cout << std::endl;
            }

            void printNode(t_node *node){
                std::cout << "*******************************************************************" << std::endl;
                std::cout << "*     Key = " << node->key << std::endl;
                std::cout << "*     color = ";
                if (node->color == BLACK)
                    std::cout << "BLACK" << std::endl;
                else
                    std::cout << "RED" << std::endl;
                std::cout << "*     Parent = " << node->parent->key << std::endl;
                std::cout << "*     Left = " << node->left->key << std::endl;
                std::cout << "*     Right = " << node->right->key << std::endl;
                std::cout << "*******************************************************************" << std::endl;
            }
    };

}
#endif