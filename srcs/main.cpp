#include "../includes/vector.hpp"
// #include "../includes/RBTree.hpp"
// #include "../includes/RBTreev2.hpp"
#include "../includes/pair.hpp"
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>


class value_compare{
    public:
        value_compare( void ){};
        typedef ft::pair<int, std::string>  value_type;
        bool operator() (const value_type& x, const value_type& y) const{
            return (x.first < y.first);
        }
};


bool isInteger( std::string str ){
    int i = 0;
    if (str.at(i) == '-')
        i++;
    while ( i < (int) str.size())
    {
        if (isdigit(str.at(i)))
            i++;
        else
            break;
    }
    if (i != (int) str.size())
        return (false);
    return (true);
}

int main( void ){
    
    std::set<int> test;

    test.insert(10);
    test.insert(8);
    test.insert(19);
    test.insert(5);
    test.insert(9);
    test.insert(14);
    test.insert(25);
    test.insert(16);
    test.insert(3);
    test.insert(7);

    std::set<int>::iterator it;

    std::cout << "****************************************************" << std::endl;
    std::cout << "*                   Current Tree                   *" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << "************************10**************************" << std::endl;
    std::cout << "*********************  ****  ***********************" << std::endl;
    std::cout << "*******************8**********19********************" << std::endl;
    std::cout << "***************** *** ******* ** *******************" << std::endl;
    std::cout << "****************5*****9****14****25*****************" << std::endl;
    std::cout << "*************** * *********** **********************" << std::endl;
    std::cout << "**************3***7***********16********************" << std::endl;
    std::cout << "****************************************************" << std::endl;

    // it = test.end();
    // std::cout << "end it    = " << *it << std::endl;
    it = test.begin();
    std::cout << "begin it    = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it--    <==" << std::endl;
    it--;
    std::cout << "it        = " << *it << std::endl;
    // it = test.end();
    // std::cout << "==> it = end  <==" << std::endl;
    it = test.begin();
    std::cout << "==> it = begin  <==" << std::endl;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it++    <==" << std::endl;
    it++;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it++    <==" << std::endl;
    it++;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it++    <==" << std::endl;
    it++;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it++    <==" << std::endl;
    it++;
    std::cout << "it        = " << *it << std::endl;
    std::cout << "==>   it++    <==" << std::endl;
    it++;
    std::cout << "it        = " << *it << std::endl;
     std::cout << "==>   it++    <==" << std::endl;
    it++;
    std::cout << "it        = " << *it << std::endl;
     std::cout << "==>   it++    <==" << std::endl;
    it++;
    std::cout << "it        = " << *it << std::endl;
     std::cout << "==>   it++    <==" << std::endl;
    it++;
    std::cout << "it        = " << *it << std::endl;
     std::cout << "==>   it++    <==" << std::endl;
    it++;
    std::cout << "it        = " << *it << std::endl;
     std::cout << "==>   it++    <==" << std::endl;
    it++;
    std::cout << "it        = " << *it << std::endl;
     std::cout << "==>   it++    <==" << std::endl;
    it++;
    std::cout << "it        = " << *it << std::endl;
     std::cout << "==>   it++    <==" << std::endl;
    it++;
    std::cout << "it        = " << *it << std::endl;

    it = test.begin();
    std::cout << "begin it = " << *it << std::endl;
    std::cout << "it        = " << *it << std::endl;
    // std::cout << "==>   it--    <==" << std::endl;
    // it--;
    // std::cout << "it        = " << *it << std::endl;
    // std::cout << "==>   it++    <==" << std::endl;
    // it++;
    // std::cout << "it        = " << *it << std::endl;
    // std::cout << "==>   it--    <==" << std::endl;
    // it--;
    // std::cout << "it        = " << *it << std::endl;
    // std::cout << "==>   it--    <==" << std::endl;
    // it--;
    // std::cout << "it        = " << *it << std::endl;
    // std::cout << "==>   it--    <==" << std::endl;
    // it--;
    // std::cout << "it        = " << *it << std::endl;
    for (long unsigned int i = 0; i <= test.size(); i++){
        std::cout << "element " << i << " = " << *it << std::endl;
        it--;
    }
}
// int main(void){
// //SIMPLE DELETION TEST
//     {
//         std::cout << "********************************************" << std::endl;
//         std::cout << "*   Node to delete is red, no children     *" << std::endl;
//         std::cout << "********************************************" << std::endl << std::endl;

//         ft::RBTree<ft::pair<int, std::string>, value_compare >tree;
//         tree.insert(ft::make_pair(7, "test7"));
//         tree.insert(ft::make_pair(6, "test6"));
//         tree.insert(ft::make_pair(10, "test10"));
//         tree.insert(ft::make_pair(11, "test11"));
//         tree.printTree();
//         tree.delete_node(ft::make_pair(11, "")); // node is red no children (leaf) 
//         tree.printTree();
//         //**** OK *****
//     }
//     {
//         std::cout << "********************************************" << std::endl;
//         std::cout << "*   Node to delete is black, no children    *" << std::endl;
//         std::cout << "********************************************" << std::endl << std::endl;
        
//         ft::RBTree<ft::pair<int, std::string>, value_compare >tree;
//         tree.insert(ft::make_pair(5, "test5"));
//         tree.insert(ft::make_pair(8, "test8"));
//         tree.insert(ft::make_pair(7, "test7"));
//         tree.insert(ft::make_pair(4, "test4"));
//         tree.printTree();
//         tree.delete_node(ft::make_pair(8, "")); // node is black, no left child (no right child also, so right child is null_node and will replace node)
//         tree.printTree();
//         //**** OK *****
//     }
//     {
//         std::cout << "********************************************" << std::endl;
//         std::cout << "* Node to delete is black, has right child *" << std::endl;
//         std::cout << "********************************************" << std::endl << std::endl;
        
//         ft::RBTree<ft::pair<int, std::string>, value_compare >tree;
//         tree.insert(ft::make_pair(5, "test5"));
//         tree.insert(ft::make_pair(8, "test8"));
//         tree.insert(ft::make_pair(7, "test7"));
//         tree.insert(ft::make_pair(6, "test6"));
//         tree.printTree();
//         tree.delete_node(ft::make_pair(5, "")); // node is black, no left child but right child
//         tree.printTree();
//         //**** OK *****
//     }
//     {
//         std::cout << "********************************************" << std::endl;
//         std::cout << "*  Node to delete is black, has left child *" << std::endl;
//         std::cout << "********************************************" << std::endl << std::endl;
        
//         ft::RBTree<ft::pair<int, std::string>, value_compare >tree;
//         tree.insert(ft::make_pair(5, "test5"));
//         tree.insert(ft::make_pair(8, "test8"));
//         tree.insert(ft::make_pair(4, "test4"));
//         tree.insert(ft::make_pair(9, "test9"));
//         tree.insert(ft::make_pair(3, "test3"));
//         tree.printTree();
//         tree.delete_node(ft::make_pair(4, "")); // node is black, has left child
//         tree.printTree();
//         //**** OK *****
//     }
// //COMPLEX DELETION TESTS
//     {
//         std::cout << "********************************************" << std::endl;
//         std::cout << "*  Node to delete is black, has 2 children *" << std::endl;
//         std::cout << "*       Left child has children            *" << std::endl;
//         std::cout << "********************************************" << std::endl << std::endl;

//         ft::RBTree<ft::pair<int, std::string>, value_compare >tree;
//         tree.insert(ft::make_pair(5, "test5"));
//         tree.insert(ft::make_pair(8, "test8"));
//         tree.insert(ft::make_pair(12, "test12"));
//         tree.insert(ft::make_pair(7, "test7"));
//         tree.insert(ft::make_pair(15, "test15"));
//         tree.insert(ft::make_pair(27, "test27"));
//         tree.insert(ft::make_pair(-7, "test-7"));
//         tree.insert(ft::make_pair(147, "test147"));
//         tree.insert(ft::make_pair(64, "test64"));
//         tree.insert(ft::make_pair(29, "test29"));
//         tree.insert(ft::make_pair(35, "test35"));
//         tree.insert(ft::make_pair(19, "test19"));
//         tree.printTree();
        
//         // tree.insert(ft::make_pair(11, "test11"));
//         // tree.printTree();
//         // tree.delete_node(15);//delete with 2 valid children and 1 left child on max subleft
//         //**** OK ****

//         tree.delete_node(ft::make_pair(15, "")); // delete with 2 valid children and no child on max subleft
//         tree.printTree();
//     }   //**** OK ****
//     {
//         std::cout << "********************************************" << std::endl;
//         std::cout << "*  Node to delete is black, has 2 children *" << std::endl;
//         std::cout << "*      Left child has no children          *" << std::endl;
//         std::cout << "********************************************" << std::endl << std::endl;

//         ft::RBTree<ft::pair<int, std::string>, value_compare >tree;
//         tree.insert(ft::make_pair(8, "test8"));
//         tree.insert(ft::make_pair(5, "test5"));
//         tree.insert(ft::make_pair(12, "test12"));
//         tree.insert(ft::make_pair(11, "test11"));
//         tree.insert(ft::make_pair(25, "test25"));
//         tree.insert(ft::make_pair(17, "test17"));
//         tree.printTree();
//         tree.delete_node(ft::make_pair(8, "")); // delete node with 2 valid children, left child is only child
//         tree.printTree();

//     }   //**** OK ****

// //RED BLACK TREE INTERACTIVE TESTER
//     {
//         ft::RBTree<ft::pair<int, std::string>, value_compare >tree;

//         std::cout << "**************************************************************************************\n";
//         std::cout << "**                                                                                  **\n";
//         std::cout << "**                              RED BLACK TREE TESTER                               **\n";
//         std::cout << "**                                                                                  **\n";
//         std::cout << "**************************************************************************************\n";
//         std::cout << "**                                                                                  **\n";
//         std::cout << "**   COMMANDS:                                                                      **\n";
//         std::cout << "**                                                                                  **\n";
//         std::cout << "**     - INSERT X         (inserts int key X inside tree)                           **\n";
//         std::cout << "**     - DELETE X         (deletes int key X from tree)                             **\n";
//         std::cout << "**     - PRINT            (prints tree from root)                                   **\n";
//         std::cout << "**     - AUTOPRINT        (auto prints tree after each operation, reuse to disable) **\n";
//         std::cout << "**     - CLEAR            (clears all values inside tree)                           **\n";
//         std::cout << "**                                                                                  **\n";
//         std::cout << "**     - EXIT             (exits tester)                                            **\n";
//         std::cout << "**                                                                                  **\n";
//         std::cout << "**************************************************************************************\n";
//         std::cout << std::endl;

//         bool        running = true;
//         bool        autoprint = false;
//         std::string str;
//         int         i;

//         while (running){
//             std::cout << "< RBTree Tester >:";
//             if (!std::getline(std::cin, str)){
//                 std::cout << "\nSTDIN has been closed, exiting" << std::endl;
//                 return (0);
//             }
//             if (!str.substr(0, 6).compare("INSERT")){
//                 str = str.substr(7, str.size());
//                 if (isInteger(str)){
//                     std::cout << "Inserting value" << std::endl;                   
//                     std::istringstream (str) >> i;
//                     tree.insert(ft::make_pair(i, "test"));
//                 }
//             }
//             else if (!str.substr(0, 6).compare("DELETE")){
//                 str = str.substr(7, str.size());
//                 if (isInteger(str)){
//                     std::cout << "Deleting value" << std::endl;                   
//                     std::istringstream (str) >> i;
//                     tree.delete_node(ft::make_pair(i, ""));
//                 }
//             }
//             else if (!str.compare("PRINT")){
//                 std::cout << "Printing tree" << std::endl;
//                 tree.printTree();
//             }
//             else if (!str.substr(0, 5).compare("CLEAR")){
//                 std::cout << "CLEARING TREE" << std::endl;
//                 tree.clear();
//             }
//             else if (!str.substr(0, 4).compare("EXIT")){
//                 std::cout << "EXITING PROGRAM" << std::endl;
//                 running = false;
//             }
//             else if (!str.compare("AUTOPRINT")){
//                 if (autoprint){
//                     std::cout << "Autoprint Off" << std::endl;
//                     autoprint = false;
//                 }
//                 else{
//                     std::cout << "Autoprint On" << std::endl;
//                     autoprint = true;
//                 }
//             }
//             if (autoprint){
//                 tree.printTree();
//             }
//         }
//         tree.clear();
//     }
// }
// int main(void){
   
// //SIMPLE DELETION TEST
//     {
//         std::cout << "********************************************" << std::endl;
//         std::cout << "*   Node to delete is red, no children     *" << std::endl;
//         std::cout << "********************************************" << std::endl << std::endl;

//         ft::RBTree<int, std::string> tree;
//         tree.insert(7);
//         tree.insert(6);
//         tree.insert(10);
//         tree.insert(11);
//         tree.printTree();
//         tree.delete_node(11); // node is red no children (leaf) 
//         tree.printTree();
//         //**** OK *****
//     }
//     {
//         std::cout << "********************************************" << std::endl;
//         std::cout << "*   Node to delete is black, no children    *" << std::endl;
//         std::cout << "********************************************" << std::endl << std::endl;
        
//         ft::RBTree<int, std::string> tree;
//         tree.insert(5);
//         tree.insert(8);
//         tree.insert(7);
//         tree.insert(4);
//         tree.printTree();
//         tree.delete_node(8); // node is black, no left child (no right child also, so right child is null_node and will replace node)
//         tree.printTree();
//         //**** OK *****
//     }
//     {
//         std::cout << "********************************************" << std::endl;
//         std::cout << "* Node to delete is black, has right child *" << std::endl;
//         std::cout << "********************************************" << std::endl << std::endl;
        
//         ft::RBTree<int, std::string> tree;
//         tree.insert(5);
//         tree.insert(8);
//         tree.insert(7);
//         tree.insert(6);
//         tree.printTree();
//         tree.delete_node(5); // node is black, no left child but right child
//         tree.printTree();
//         //**** OK *****
//     }
//     {
//         std::cout << "********************************************" << std::endl;
//         std::cout << "*  Node to delete is black, has left child *" << std::endl;
//         std::cout << "********************************************" << std::endl << std::endl;
        
//         ft::RBTree<int, std::string> tree;
//         tree.insert(5);
//         tree.insert(8);
//         tree.insert(4);
//         tree.insert(9);
//         tree.insert(3);
//         tree.printTree();
//         tree.delete_node(4); // node is black, has left child
//         tree.printTree();
//         //**** OK *****
//     }
// //COMPLEX DELETION TESTS
//     {
//         std::cout << "********************************************" << std::endl;
//         std::cout << "*  Node to delete is black, has 2 children *" << std::endl;
//         std::cout << "*       Left child has children            *" << std::endl;
//         std::cout << "********************************************" << std::endl << std::endl;

//         ft::RBTree<int, std::string> tree;
//         tree.insert(5);
//         tree.insert(8);
//         tree.insert(12);
//         tree.insert(7);
//         tree.insert(15);
//         tree.insert(27);
//         tree.insert(-7);
//         tree.insert(147);
//         tree.insert(64);
//         tree.insert(29);
//         tree.insert(35);
//         tree.insert(19);
//         tree.printTree();
        
//         // tree.insert(11);
//         // tree.printTree();
//         // tree.delete_node(15);//delete with 2 valid children and 1 left child on max subleft
//         //**** OK ****

//         tree.delete_node(15); // delete with 2 valid children and no child on max subleft
//         tree.printTree();
//     }   //**** OK ****
//     {
//         std::cout << "********************************************" << std::endl;
//         std::cout << "*  Node to delete is black, has 2 children *" << std::endl;
//         std::cout << "*      Left child has no children          *" << std::endl;
//         std::cout << "********************************************" << std::endl << std::endl;

//         ft::RBTree<int, std::string> tree;
//         tree.insert(8);
//         tree.insert(5);
//         tree.insert(12);
//         tree.insert(11);
//         tree.insert(25);
//         tree.insert(17);
//         tree.printTree();
//         tree.delete_node(8); // delete node with 2 valid children, left child is only child
//         tree.printTree();

//     }   //**** OK ****

// //RED BLACK TREE INTERACTIVE TESTER
//     // {
//     //     ft::RBTree<int, std::string> tree;

//     //     std::cout << "**************************************************************************************\n";
//     //     std::cout << "**                                                                                  **\n";
//     //     std::cout << "**                              RED BLACK TREE TESTER                               **\n";
//     //     std::cout << "**                                                                                  **\n";
//     //     std::cout << "**************************************************************************************\n";
//     //     std::cout << "**                                                                                  **\n";
//     //     std::cout << "**   COMMANDS:                                                                      **\n";
//     //     std::cout << "**                                                                                  **\n";
//     //     std::cout << "**     - INSERT X         (inserts int key X inside tree)                           **\n";
//     //     std::cout << "**     - DELETE X         (deletes int key X from tree)                             **\n";
//     //     std::cout << "**     - PRINT            (prints tree from root)                                   **\n";
//     //     std::cout << "**     - AUTOPRINT        (auto prints tree after each operation, reuse to disable) **\n";
//     //     std::cout << "**     - CLEAR            (clears all values inside tree)                           **\n";
//     //     std::cout << "**                                                                                  **\n";
//     //     std::cout << "**     - EXIT             (exits tester)                                            **\n";
//     //     std::cout << "**                                                                                  **\n";
//     //     std::cout << "**************************************************************************************\n";
//     //     std::cout << std::endl;

//     //     bool        running = true;
//     //     bool        autoprint = false;
//     //     std::string str;
//     //     int         i;

//     //     while (running){
//     //         std::cout << "< RBTree Tester >:";
//     //         if (!std::getline(std::cin, str)){
//     //             std::cout << "\nSTDIN has been closed, exiting" << std::endl;
//     //             return (0);
//     //         }
//     //         if (!str.substr(0, 6).compare("INSERT")){
//     //             str = str.substr(7, str.size());
//     //             if (isInteger(str)){
//     //                 std::cout << "Inserting value" << std::endl;                   
//     //                 std::istringstream (str) >> i;
//     //                 tree.insert(i);
//     //             }
//     //         }
//     //         else if (!str.substr(0, 6).compare("DELETE")){
//     //             str = str.substr(7, str.size());
//     //             if (isInteger(str)){
//     //                 std::cout << "Deleting value" << std::endl;                   
//     //                 std::istringstream (str) >> i;
//     //                 tree.delete_node(i);
//     //             }
//     //         }
//     //         else if (!str.compare("PRINT")){
//     //             std::cout << "Printing tree" << std::endl;
//     //             tree.printTree();
//     //         }
//     //         else if (!str.substr(0, 5).compare("CLEAR")){
//     //             std::cout << "CLEARING TREE" << std::endl;
//     //             tree.clear();
//     //         }
//     //         else if (!str.substr(0, 4).compare("EXIT")){
//     //             std::cout << "EXITING PROGRAM" << std::endl;
//     //             running = false;
//     //         }
//     //         else if (!str.compare("AUTOPRINT")){
//     //             if (autoprint){
//     //                 std::cout << "Autoprint Off" << std::endl;
//     //                 autoprint = false;
//     //             }
//     //             else{
//     //                 std::cout << "Autoprint On" << std::endl;
//     //                 autoprint = true;
//     //             }
//     //         }
//     //         if (autoprint){
//     //             tree.printTree();
//     //         }
//     //     }
//     //     tree.clear();
//     // }
// }