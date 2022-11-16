#include "vector.hpp"
#include <vector>
#include <iostream>
#include <string>

template< typename T >
void PrintVector( const ft::vector< T >& vector){
    std::cout << "Printing vector of size " << vector.size() << std::endl;
    for (size_t i = 0; i < vector.size() ; i++)
        std::cout << "Vector elem " << i << " = " << vector[i] << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

int main( void ){
    std::vector<int> trueVector;
    ft::vector<int>  myVector;

    myVector.push_back(125);
    myVector.push_back(120);

    PrintVector( myVector );

    myVector.push_back(15);

    PrintVector( myVector );

    myVector.push_back(-254);
    myVector.push_back(5915);
    myVector.push_back(15465);

    PrintVector( myVector );

    myVector.pop_back();
    myVector.pop_back();
    myVector.pop_back();

    PrintVector( myVector );
 
    myVector.clear();

    PrintVector( myVector);

    return (0);
}