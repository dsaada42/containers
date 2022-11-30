#include "../includes/vector.hpp"
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>

template< typename T >
void PrintVector( const ft::vector< T >& vector){
    std::cout << "Printing vector of size " << vector.size() << std::endl;
    for (size_t i = 0; i < vector.size() ; i++)
        std::cout << "Vector elem " << i << " = " << vector[i] << std::endl;
    std::cout << "------------------------------------" << std::endl;
}
template< typename T >
void PrintVector( const std::vector< T >& vector){
    std::cout << "Printing vector of size " << vector.size() << std::endl;
    for (size_t i = 0; i < vector.size() ; i++)
        std::cout << "Vector elem " << i << " = " << vector[i] << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

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

int main(void){

    {
        std::string str = "Hello World!";

        ft::vector<char> v(str.begin(), str.end());

        PrintVector(v);
    }
    {

        std::istringstream str("");
        std::istreambuf_iterator<char> it(str), end;

        ft::vector<char> v(it, end);
        
        PrintVector(v);
    }
    {
        std::istringstream str("1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        std::istreambuf_iterator<char> it(str), end;

        ft::vector<char> v(it, end);

        PrintVector(v);
    }
}