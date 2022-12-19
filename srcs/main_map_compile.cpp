#include "../includes/vector.hpp"
// #include "../includes/RBTree.hpp"
#include "../includes/RBTreev2.hpp"
#include "../includes/pair.hpp"
#include "../includes/map.hpp"
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>

int main( void ){
    {
        ft::map<int, std::string> map_test;

        map_test.insert(ft::make_pair(1, "test"));
        std::string & str = map_test.at(1);
        std::cout << str << std::endl;

    }
    {
        const ft::map<int, std::string> map_test2;
        const std::string & str = map_test2.at(5);

        std::cout << str << std::endl;
    }
    {
        ft::map<int, std::string> temp;
        temp.insert(ft::make_pair(64, "64"));

        const ft::map<int, std::string> copy(temp);
        const std::string & str = copy.at(64);
        std::cout << str << std::endl;

    }

}