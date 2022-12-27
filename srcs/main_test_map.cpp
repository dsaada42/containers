#include "../includes/vector.hpp"
#include "../includes/RBTree.hpp"
#include "../includes/pair.hpp"
#include "../includes/map.hpp"
#include "../includes/set.hpp"
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <list>
#include <string>

#define T1 float
#define T2 std::string

std::string itos(unsigned int i) // convert int to string
{
    std::stringstream s;
    s << i;
    return s.str();
}

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
//MAP/ITE_ARROW
    // {
    //     typedef ft::pair<const T1, T2> T3;
    //     std::string                str;
    //     char                        c;
    //     std::list<T3> lst;
	//     unsigned int lst_size = 5;
	//     for (unsigned int i = 0; i < lst_size; ++i){
    //         c = i + 48;
    //         str = "test ";
    //         str += c;

	// 	    lst.push_back(T3(2.5 - i, str )); 
    //     }        
    //     ft::map<T1, T2> mp(lst.begin(), lst.end());
    //     ft::map<T1, T2>::reverse_iterator it(mp.rbegin());
    //     ft::map<T1, T2>::const_reverse_iterator ite(mp.rbegin());

    //     std::cout << it->second << std::endl;
	//     std::cout << ite->second << std::endl;
    // }
    // {
    //     typedef std::pair<const T1, T2> T3;
    //     std::string                str;
    //     char                        c; 
    //     std::list<T3> lst;
	//     unsigned int lst_size = 5;
	//     for (unsigned int i = 0; i < lst_size; ++i){
    //         c = i + 48;
    //         str = "test ";
    //         str += c;

	// 	    lst.push_back(T3(2.5 - i, str )); 
    //     }        
    //     std::map<T1, T2> mp(lst.begin(), lst.end());
    //     std::map<T1, T2>::reverse_iterator it(mp.rbegin());
    //     std::map<T1, T2>::const_reverse_iterator ite(mp.rbegin());

    //     std::cout << it->second << std::endl;
	//     std::cout << ite->second << std::endl;
    // }

//************************** SET ***********************
// 
// VALUES INSIDE SET ARE ALWAYS CONST , WOULD IT BE WITH REGULAR OR CONST ITERATOR, THEREFORE NO ASSIGNATION WHEN DEREFERENCING
//
//******************************************************
//SET/ITE_N0A
    {
        ft::set<T1> st;
        ft::set<T1>::const_iterator ite = st.begin();
        *ite = 42; //---> error
        return(0);
    }
    {
        std::set<T1> st;
        std::set<T1>::const_iterator ite = st.begin();
        *ite = 42; //---> error
    }
//SET/ITE_N0B
    {
        ft::set<T1> st;
	    ft::set<T1>::iterator ite = st.begin();

        *ite = 42; // < -- error as well ; T is always const, even with regular iterator
    }
    {
        std::set<T1> st;
	    std::set<T1>::iterator ite = st.begin();
        
        *ite = 42; // < -- error as well ; T is always const, even with regular iterator
    }

//SET ALLOWS FOR iterator to const-iterator and also const_iterator to interator
//SET/ITE_N1
    {
        ft::set<T1> const st;
        ft::set<T1>::iterator it = st.begin(); // <-- no error, actually ! set allows for const_iterator => iterator conversion

        (void)it;
    }
    {
        std::set<T1> const st;
        std::set<T1>::iterator it = st.begin(); // <-- no error, actually ! set allows for const_iterator => iterator conversion

        (void)it;
    }
    
}