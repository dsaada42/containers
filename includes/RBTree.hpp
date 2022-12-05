#ifndef RBTREE_HPP
# define RBTREE_HPP
# define RED 1
# define BLACK 0
# define LEFT true
# define RIGHT false

template< class Key , class T >
class RBTree{
    
    typedef struct  s_node {
	    Key         key; // holds the key   (data.first as pair)
        T           data; //holds the data  (data.second as pair)
	    s_node      *parent; // pointer to the parent
	    s_node      *left; // pointer to left child
	    s_node      *right; // pointer to right child
	    int         color; // 1 -> Red, 0 -> Black

        // s_node (Key newKey, T newT ) { 
        //     key = newKey;
        //     data = newT;
        // }
        // const Key & key(){ return(key); }
        // T &         val(void){ return(data.second); }

    }               t_node;

    private:
        //the root of our tree
        t_node *root;
        //any leaf of our tree
        t_node *null_node;

        //----- Init node to be root or leaf -----
        void __null_node(t_node *parent, t_node *node){
            node->key = Key();
            node->data = T();
            node->parent = parent;
            node->left = 0;
            node->right = 0;
            node->color = BLACK;
        }

        //----- Search node by key -----
        t_node *__search_key(t_node *node, int key){
            if (node == null_node || key == node->key)
                return( node );
            if (key < node->key)
                return( __search_key(node->left, key) );
            return( __search_key(node->right, key) );
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

        //----- Repair after insertion -----
        void __repair_insert(t_node * node){
            t_node *uncle;

            while (node->parent->color == RED){
                if (node->parent == node->parent->parent->right){
                    uncle = node->parent->parent->left;

                    if (uncle->color == RED){//cas 3.1
                        uncle->color = BLACK;
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        node = node->parent->parent;
                    }
                    else {
                        if (node == node->parent->left){//cas 3.2.2
                            node = node->parent;
                            rightRotate(node);
                        }  
                        //cas 3.2.1
                        node->parent->color = BLACK;
                        node->parent->parent->color= RED;
                        leftRotate(node->parent->parent);
                    }
                }
                else {
                    uncle = node->parent->parent->right;

                    if (uncle->color == RED){//cas 3.1
                        uncle->color = BLACK;
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        node = node->parent->parent;
                    }
                    else {
                        if (node == node->parent->right){//cas 3.2.2 mirror
                            node = node->parent;
                            leftRotate(node);
                        }
                        //cas 3.2.1 mirror
                        node->parent->color = BLACK;
                        node->parent->parent->color= RED;
                        rightRotate(node->parent->parent);
                    } 
                }
                if (node == root) {
                    break;
                }
            }
            root->color = BLACK;
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

        //----- Assign child to parent -----
        void __assign_child_parent(t_node *node, bool left){
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
        }

        //----- Repair after deletion -----
        void    __repair_delete(t_node *node){
            t_node *sibling;
            std::cout << "repairing deletion on node " << node->key << std::endl;
            if (node == root)
                return;

            sibling = __get_sibling(node);
            //cas 0: sibling is leaf
            if (sibling == null_node){
                sibling->color = RED;
                if (node->parent->color == BLACK)
                    __repair_delete(node->parent);
            }
            //cas 1: sibling black + at least one child red
            else if (sibling->color == BLACK && (sibling->left->color == RED || sibling->right->color == RED)){

                std::cout << "node " << node->key << ": Cas 1 -> S Black + 1 or more Red children" << std::endl;
                //cas 1.a: LL Sibling is left child, sibling's left child is red
                if (sibling == sibling->parent->left && sibling->left->color == RED){
                    rightRotate(node->parent);
                }
                //cas 1.b: LR Sibling is left child, sibling's right child is red
                else if (sibling == sibling->parent->left && sibling->right->color == RED){
                    rightRotate(sibling);
                    leftRotate(node->parent);
                }
                //cas 1.c: RR Sibling is right child, sibling's right child is red
                else if (sibling == sibling->parent->right && sibling->right->color == RED){
                    leftRotate(node->parent);
                }
                //cas 1.d: RL Sibling is right child, sibling's left child is red
                else if (sibling == sibling->parent->right && sibling->left->color == RED){
                    leftRotate(sibling);
                    rightRotate(node->parent);
                }
            }
            //cas 2: sibling black + double black children
            else if (sibling->color == BLACK && sibling->left->color == BLACK && sibling->right->color == BLACK){
                sibling->color = RED;
                if (node->parent->color == BLACK)
                    __repair_delete(node->parent);
                else
                    node->parent->color = BLACK;
            }
            //cas 3: sibling red
            else if (sibling->color == RED){ //on recolore sibling(black) et parent(red) 
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
        }
    public:
        RBTree( void ){
            null_node = new t_node;
            __null_node( 0, null_node);
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
            if (k->parent == 0) // case parent == root    //5         
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
            if (k->parent == 0) // case parent == root    //5         
                root = k;
            else if (p == k->parent->right) // si p etait right child
                k->parent->right = k;
            else    // si p etait left child
                k->parent->left = k;
            if (p->right != null_node)
                p->right->parent = p;
        }

        //----- BST normal insertion -----
        void insert(int key){            
            t_node *tmp = root;
            t_node *p = 0;
            t_node *node = new t_node;

            node->parent = 0;
            node->left = null_node;
            node->right = null_node;
            node->key = key;
            node->data = T();
            node->color = RED;

            //we search for the right spot for our key
            while (tmp != null_node){
                p = tmp;
                if (node->key < tmp->key)
                    tmp = tmp->left; 
                else
                    tmp = tmp->right;
            }

            node->parent = p;
            if (p == 0)
                root = node;
            else if (node->key < p->key)
                p->left = node;
            else
                p->right = node;

            //case 1: tree was empty, node = root
            if (node->parent == 0){
                node->color = BLACK;
                return;
            }

            //case 2: granparent is root, insert successful
            if (node->parent->parent == 0)
                return;

            std::cout << "Fixing insert" << std::endl;
            //case 3: all other possibilities need fixing
            __repair_insert(node);
        }

        //----- Delete element from RBT -----
        void delete_node(int key){
            std::cout << "deleting node " << key << std::endl;
            t_node  *node;
            t_node  *to_delete;
            t_node  *new_node;
            int     original_color;

            //recherche du noeud identified by key 
            node = __search_key(root, key);
            if (node == null_node)
                return;
            //save original color of node
            original_color = node->color;
            //case 1 : no left child 
            if (node->left == null_node){
                __assign_child_parent(node, LEFT);
            }
            //case 2 : no right child
            else if (node->right == null_node){
                __assign_child_parent(node, RIGHT);
            }
            //case 3 : both children are valid
            else{
                to_delete = __highest_left(node); //works also with lowest right
                std::cout << "--> deleting highest left node key: " << to_delete->key << std::endl;
                //***** A REMPLACER PAR CONSTRUCTEUR PAR COPIE t_node * new_node(to_delete)*****
                //******************************************************************************
                new_node = new t_node;
                new_node->key = to_delete->key;
                new_node->data = to_delete->data;
                new_node->right = to_delete->right;
                new_node->left = to_delete->left;
                new_node->parent = to_delete->parent;
                //******************************************************************************
                new_node->color = original_color;
                original_color = to_delete->color;
                //on supprime le noeud highest left (probleme car key a ete modifie)
                delete_node(to_delete->key);
                //on branche au child de droite
                new_node->right = node->right;
                new_node->right->parent = new_node;
                //on branche au child de gauche
                new_node->left = node->left;
                new_node->left->parent = new_node;
                //on branche au parent
                new_node->parent = node->parent;
                if (node->parent == null_node)
                    root = node;
                else if (node == node->parent->left)
                    new_node->parent->left = new_node;
                else
                    new_node->parent->right = new_node;
                //on supprime l'ancien noeud
                delete node;
                node = new_node;
            }
            printTree();
            // si la couleur du noeud supprime est RED, aucun risque de desequilibre
            if (original_color == BLACK)
                __repair_delete(node); //sinon repair
        }

        void    clear(void){
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
            if (root)
                __print_tree(root, "", true);
            else
                std::cout << "Empty tree" << std::endl;
            std::cout << std::endl;
        }

        void leftRotateKey(Key key){
            t_node *node;

            node = __search_key(root, key);
            if (node == null_node)
                std::cout << "Key not found" << std::endl;
            else
                leftRotate(node);
        }

        void rightRotateKey(Key key){
            t_node *node;

            node = __search_key(root, key);
            if (node == null_node)
                std::cout << "Key not found" << std::endl;
            else
                rightRotate(node);
        }
};

#endif