#ifndef RBTREE_HPP
# define RBTREE_HPP
# define RED 1
# define BLACK 0

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
            // cout<<root->left->data<<endl;
        }
    
    public:
        RBTree( void ){
            null_node = new t_node;
            __null_node( 0, null_node);
            root = null_node;
        }
        //----- Right Rotation -----
        void rightRotate(t_node *p){
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

        void rightRotateKey(Key key){
            t_node *node;

            node = __search_key(root, key);
            if (node == null_node)
                std::cout << "Key not found" << std::endl;
            else
                rightRotate(node);
        }
        //----- Left Rotation -----
        void leftRotate(t_node *p){
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

        void leftRotateKey(Key key){
            t_node *node;

            node = __search_key(root, key);
            if (node == null_node)
                std::cout << "Key not found" << std::endl;
            else
                leftRotate(node);
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

            //case 3: all other possibilities need fixing
            //__repair_insert(node);
        }

        void printTree(void){
            if (root)
                __print_tree(root, "", true);
            else
                std::cout << "Empty tree" << std::endl;
            std::cout << std::endl;
        }
};

#endif