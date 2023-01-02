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

template <typename T>
void	printSize(ft::vector<T> const &vct, bool print_content = true)
{
	const typename ft::vector<T>::size_type size = vct.size();
	const typename ft::vector<T>::size_type capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T>
void	printSize(std::vector<T> const &vct, bool print_content = true)
{
	const typename std::vector<T>::size_type size = vct.size();
	const typename std::vector<T>::size_type capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename std::vector<T>::const_iterator it = vct.begin();
		typename std::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int main (void){
    std::cout << std::endl << "===================  STD =====================" << std::endl << std::endl;
    {
        const int size = 5;
	    std::vector<int> vct(size);
	    std::vector<int>::reverse_iterator it = vct.rbegin();
	    std::vector<int>::const_reverse_iterator ite = vct.rbegin();

	    for (int i = 0; i < size; ++i)
	    	it[i] = (size - i) * 5;

        printSize(vct, true);

	    it = it + 5;
	    it = 1 + it;
	    it = it - 4;
	    std::cout << *(it += 2) << std::endl;
	    std::cout << *(it -= 1) << std::endl;

	    *(it -= 2) = 42;
	    *(it += 2) = 21;

	    std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	    std::cout << "(it == const_it): " << (ite == it) << std::endl;
	    std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	    std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

    }
    std::cout << std::endl << "===================  FT =====================" << std::endl << std::endl;
    {
        const int size = 5;
	    ft::vector<int> vct(size);
	    ft::vector<int>::reverse_iterator it = vct.rbegin();
	    ft::vector<int>::const_reverse_iterator ite = vct.rbegin();

	    for (int i = 0; i < size; ++i)
	    	it[i] = (size - i) * 5;

        printSize(vct, true);

	    it = it + 5;
	    it = 1 + it;
	    it = it - 4;
	    std::cout << *(it += 2) << std::endl;
	    std::cout << *(it -= 1) << std::endl;

	    *(it -= 2) = 42;
	    *(it += 2) = 21;

	    std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	    std::cout << "(it == const_it): " << (ite == it) << std::endl;
	    std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	    std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

    }
    
}