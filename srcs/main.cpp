#include "../includes/vector.hpp"
#include "../includes/RBTree.hpp"
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>

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

int main(void){
    {
        RBTree<int, std::string> tree;
        tree.insert(5);
        tree.insert(12);
        tree.insert(8);
        tree.insert(11);
        tree.insert(25);
        tree.insert(17);
        tree.printTree();
        tree.delete_node(8);

    }
    // {
    //     RBTree<int, std::string> tree;

    //     std::cout << "**************************************************************************************\n";
    //     std::cout << "**                                                                                  **\n";
    //     std::cout << "**                              RED BLACK TREE TESTER                               **\n";
    //     std::cout << "**                                                                                  **\n";
    //     std::cout << "**************************************************************************************\n";
    //     std::cout << "**                                                                                  **\n";
    //     std::cout << "**   COMMANDS:                                                                      **\n";
    //     std::cout << "**                                                                                  **\n";
    //     std::cout << "**     - INSERT X         (inserts int key X inside tree)                           **\n";
    //     std::cout << "**     - DELETE X         (deletes int key X from tree)                             **\n";
    //     std::cout << "**     - PRINT            (prints tree from root)                                   **\n";
    //     std::cout << "**     - AUTOPRINT        (auto prints tree after each operation, reuse to disable) **\n";
    //     std::cout << "**     - CLEAR            (clears all values inside tree)                           **\n";
    //     std::cout << "**                                                                                  **\n";
    //     std::cout << "**     - EXIT             (exits tester)                                            **\n";
    //     std::cout << "**                                                                                  **\n";
    //     std::cout << "**************************************************************************************\n";
    //     std::cout << std::endl;

    //     bool        running = true;
    //     bool        autoprint = false;
    //     std::string str;
    //     int         i;

    //     while (running){
    //         std::cout << "< RBTree Tester >:";
    //         if (!std::getline(std::cin, str)){
    //             std::cout << "\nSTDIN has been closed, exiting" << std::endl;
    //             return (0);
    //         }
    //         if (!str.substr(0, 6).compare("INSERT")){
    //             str = str.substr(7, str.size());
    //             if (isInteger(str)){
    //                 std::cout << "Inserting value" << std::endl;                   
    //                 std::istringstream (str) >> i;
    //                 tree.insert(i);
    //             }
    //         }
    //         else if (!str.substr(0, 6).compare("DELETE")){
    //             str = str.substr(7, str.size());
    //             if (isInteger(str)){
    //                 std::cout << "Deleting value" << std::endl;                   
    //                 std::istringstream (str) >> i;
    //                 tree.delete_node(i);
    //             }
    //         }
    //         else if (!str.compare("PRINT")){
    //             std::cout << "Printing tree" << std::endl;
    //             tree.printTree();
    //         }
    //         else if (!str.substr(0, 5).compare("CLEAR")){
    //             std::cout << "CLEARING TREE" << std::endl;
    //             tree.clear();
    //         }
    //         else if (!str.substr(0, 4).compare("EXIT")){
    //             std::cout << "EXITING PROGRAM" << std::endl;
    //             running = false;
    //         }
    //         else if (!str.compare("AUTOPRINT")){
    //             if (autoprint){
    //                 std::cout << "Autoprint Off" << std::endl;
    //                 autoprint = false;
    //             }
    //             else{
    //                 std::cout << "Autoprint On" << std::endl;
    //                 autoprint = true;
    //             }
    //         }
    //         if (autoprint){
    //             tree.printTree();
    //         }
    //     }
    //     tree.clear();
    // }
}
// template< typename T >
// void PrintVector( const ft::vector< T >& vector){
//     std::cout << "Printing vector of size " << vector.size() << std::endl;
//     for (size_t i = 0; i < vector.size() ; i++)
//         std::cout << "Vector elem " << i << " = " << vector[i] << std::endl;
//     std::cout << "------------------------------------" << std::endl;
// }
// template< typename T >
// void PrintVector( const std::vector< T >& vector){
//     std::cout << "Printing vector of size " << vector.size() << std::endl;
//     for (size_t i = 0; i < vector.size() ; i++)
//         std::cout << "Vector elem " << i << " = " << vector[i] << std::endl;
//     std::cout << "------------------------------------" << std::endl;
// }

// int main( void ){
//     std::cout << std::endl << "****** My vector scope *****" << std::endl << std::endl;
//     {
//         ft::vector<int>  myVector;

//         myVector.push_back(125);
//         myVector.push_back(120);
//         PrintVector( myVector );
//         myVector.push_back(15);
//         myVector.push_back(-254);
//         myVector.push_back(5915);
//         myVector.push_back(15465);
//         PrintVector( myVector );
//         myVector.erase(myVector.begin(), myVector.begin());
//         PrintVector( myVector );
//         myVector.erase(myVector.begin(), myVector.end());
//         PrintVector( myVector );

//         std::cout << "Iterator:\n";
//         for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++){
//             std::cout << *it << std::endl;
//         }
//     }

//     std::cout << std::endl << "****** True vector scope *****" << std::endl << std::endl;
//     {
//         std::vector<int>  myVector;

//         myVector.push_back(125);
//         myVector.push_back(120);
//         PrintVector( myVector );
//         myVector.push_back(15);
//         myVector.push_back(-254);
//         myVector.push_back(5915);
//         myVector.push_back(15465);
//         PrintVector( myVector );
//         myVector.erase(myVector.begin(), myVector.begin());
//         PrintVector( myVector );
//         myVector.erase(myVector.begin(), myVector.end());
//         PrintVector( myVector );

//         std::cout << "Iterator:\n";
//         for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++){
//             std::cout << *it << std::endl;
//         }
//     }

//     std::cout << std::endl << "************ END ***************" << std::endl;

//     return (0);
// }

// int main(void){

//     {
//         std::string str = "Hello World!";

//         ft::vector<char> v(str.begin(), str.end());

//         PrintVector(v);
//     }
//     {

//         std::istringstream str("");
//         std::istreambuf_iterator<char> it(str), end;

//         ft::vector<char> v(it, end);
        
//         PrintVector(v);
//     }
//     {
//         std::istringstream str("1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ");
//         std::istreambuf_iterator<char> it(str), end;

//         ft::vector<char> v(it, end);

//         PrintVector(v);
//     }
// }