#include "../includes/vector.hpp"
#include "../includes/RBTree.hpp"
#include "../includes/pair.hpp"
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include "../includes/set.hpp"

void print_equal(std::string msg, bool yes){
    if (yes)
        std::cout << msg << " are equal" << std::endl;
    else
        std::cout << msg << " are not equal" << std::endl;
}

int main (void) {
    std::cout << std::endl << "===================  FT =====================" << std::endl << std::endl;
    {
        ft::set<std::string> my_set;

        ft::set<std::string>::reverse_iterator it = my_set.rbegin();
        ft::set<std::string>::reverse_iterator it2 = my_set.rbegin();
        ft::set<std::string>::const_reverse_iterator cit = my_set.rbegin();
        ft::set<std::string>::const_reverse_iterator cit2 = my_set.rbegin();

        my_set.insert("test 1");
        my_set.insert("test 2");
        my_set.insert("test 3");

        if (it == it2)
            print_equal("it and it2", true);
        else
            print_equal("it and it2", false);
        if (it == cit)
            print_equal("it and cit", true);
        else
            print_equal("it and cit", false);
        if (cit == cit2)
            print_equal("cit and cit2", true);
        else
            print_equal("cit and cit2", false);

        std::cout << "It = " << *it << std::endl;
        std::cout << "Cit = " << *cit << std::endl;
        // ++it;
        // ++cit;
        //std::cout << "It = " << *it << std::endl;
        //std::cout << "Cit = " << *cit << std::endl;

    }

    std::cout << std::endl << "===================  STD =====================" << std::endl << std::endl;
    {
        std::set<std::string> my_set;

        std::set<std::string>::reverse_iterator it = my_set.rbegin();
        std::set<std::string>::reverse_iterator it2 = my_set.rbegin();
        std::set<std::string>::const_reverse_iterator cit = my_set.rbegin();
        std::set<std::string>::const_reverse_iterator cit2 = my_set.rbegin();

        my_set.insert("test 1");
        my_set.insert("test 2");
        my_set.insert("test 3");
        
        if (it == it2)
            print_equal("it and it2", true);
        else
            print_equal("it and it2", false);
        if (it == cit)
            print_equal("it and cit", true);
        else
            print_equal("it and cit", false);
        if (cit == cit2)
            print_equal("cit and cit2", true);
        else
            print_equal("cit and cit2", false);

        std::cout << "It = " << *it << std::endl;
        std::cout << "Cit = " << *cit << std::endl;
        ++it;
        ++cit;
        std::cout << "It = " << *it << std::endl;
        std::cout << "Cit = " << *cit << std::endl;
    }
}