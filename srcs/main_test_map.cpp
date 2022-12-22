#include "../includes/vector.hpp"
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
#include <unistd.h>

int main (void){
    {
        std::map<int, std::string> map;

        map.insert(std::make_pair(1, "1"));
        map.insert(std::make_pair(2, "2"));
        map.insert(std::make_pair(3, "3"));
        map.insert(std::make_pair(4, "4"));
        map.insert(std::make_pair(5, "5"));
        map.insert(std::make_pair(6, "6"));
        map.insert(std::make_pair(7, "7"));
        map.insert(std::make_pair(8, "8"));
        map.insert(std::make_pair(9, "9"));
        map.insert(std::make_pair(10, "10"));

        std::cout << "Size of map = " << map.size() << std::endl;
    }
    {
        ft::map<int, std::string> ftmap;

        ftmap.insert(ft::make_pair(1, "1"));
        ftmap.insert(ft::make_pair(2, "2"));
        ftmap.insert(ft::make_pair(3, "3"));
        ftmap.insert(ft::make_pair(4, "4"));
        ftmap.insert(ft::make_pair(5, "5"));
        ftmap.insert(ft::make_pair(6, "6"));
        ftmap.insert(ft::make_pair(7, "7"));
        ftmap.insert(ft::make_pair(8, "8"));
        ftmap.insert(ft::make_pair(9, "9"));
        ftmap.insert(ft::make_pair(10, "10"));

        std::cout << "Size of map = " << ftmap.size() << std::endl;
    }
}