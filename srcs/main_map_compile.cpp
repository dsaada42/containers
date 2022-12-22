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

int main( void ){
    {
        std::cout << "***************************" << std::endl;
        std::cout << "   Constrcutor + insert 1  " << std::endl;
        std::cout << "***************************" << std::endl;
        ft::map<int, std::string> map_test;

        map_test.insert(ft::make_pair(1, "test"));
        std::string & str = map_test.at(1);
        std::cout << str << std::endl;
    }
    {
        std::cout << "**********************" << std::endl;
        std::cout << "  Constructor const   " << std::endl;
        std::cout << "**********************" << std::endl;

        const ft::map<int, std::string> map_test2;
        const std::string & str = map_test2.at(5);

        std::cout << str << std::endl;
    }
    {
        std::cout << "********************************************" << std::endl;
        std::cout << "  Constructor + insert 1 + copy constructor " << std::endl;
        std::cout << "********************************************" << std::endl;

        ft::map<int, std::string> temp;
        temp.insert(ft::make_pair(64, "64"));

        const ft::map<int, std::string> copy(temp);
        const std::string & str = copy.at(64);
        std::cout << str << std::endl;

    }
    {
        std::cout << "********************************************" << std::endl;
        std::cout << "  Constructor + insert 1 + assignation      " << std::endl;
        std::cout << "********************************************" << std::endl;

        ft::map<int, std::string>   temp;
        ft::map<int, std::string>   copy;

        std::cout << "temp.insert(make_pair(64, \"64\")" << std::endl;
        temp.insert(ft::make_pair(64, "64"));
        std::cout << "temp.at(64) = " << temp.at(64) << std::endl;

        std::cout << "copy = temp" << std::endl;
        copy = temp;
        std::cout << "copy.at(64) = " << copy.at(64) << std::endl;

        std::cout << "clearing content of temp" << std::endl;
        temp.clear();
        std::cout << "copy.at(64) = " << copy.at(64) << std::endl;

    }
    {
        std::cout << "********************************************" << std::endl;
        std::cout << "  Constructor + insert n + assignation      " << std::endl;
        std::cout << "********************************************" << std::endl;

        ft::map<int, std::string>           temp;
        ft::map<int, std::string>           copy;
        ft::map<int, std::string>::iterator it;
        temp.insert(ft::make_pair(64, "64"));
        temp.insert(ft::make_pair(12, "12"));
        temp.insert(ft::make_pair(158, "158"));
        temp.insert(ft::make_pair(2, "2"));
        temp.insert(ft::make_pair(15, "15"));
        temp._tree.printTree();

        std::cout << "testing ++ behavior" << std::endl;
        for (it = temp.begin(); it != temp.end() ; it++){
            std::cout << "Element " << (*it).first << "= " << (*it).second << std::endl;
            sleep(1);
        }
        std::cout << std::endl;

        std::cout << "testing -- behavior" << std::endl;
        for (it = temp.end(); it != temp.begin() ; it--){
            std::cout << "Element " << (*it).first << "= " << (*it).second << std::endl;
            sleep(1);
        }


        std::cout << "copy = temp" << std::endl;
        copy = temp;
        std::cout << "copy.at(64) = " << copy.at(64) << std::endl;

        std::cout << "clearing content of temp" << std::endl;
        temp.clear();
        std::cout << "copy.at(64) = " << copy.at(64) << std::endl;

    }

}