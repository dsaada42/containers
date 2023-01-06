/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:13:44 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 08:52:43 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HEADER_HPP
# define STACK_HEADER_HPP

# include "../header.hpp"
# include "stack.hpp"
# include <stack>


#define CHECK_TYPEDEF(type)                                                                                                     \
    {                                                                                                                           \
        NAMESPACE::stack<int, ft::vector<int> >::type a = NAMESPACE::stack<int, ft::vector<int> >::type();                      \
        (void)a;                                                                                                                \
    }

#define PRINT_STACK(stack){                                             \
    std::cout << "==================== STACK ====================\n";   \
    std::cout << " initial size = " << stack.size() << "\n";            \
    std::cout << "__Elements__\n";                                      \
    while (!stack.empty()){                                             \
        std::cout << ' ' << stack.top();                                \
        stack.pop();                                                    \
    }                                                                   \
    std::cout << std::endl;                                             \
}

template <typename C>
void add_values(C& s, typename C::value_type value, std::size_t count)
{
    for (std::size_t i = 0; i < count; ++i, ++value) {
        s.push(value);
    }
}

template <typename C>
void add_value(C& s, typename C::value_type value, std::size_t count)
{
    for (std::size_t i = 0; i < count; ++i) {
        s.push(value);
    }
}

typedef NAMESPACE::stack<std::string, NAMESPACE::vector<std::string> > strstack;
typedef NAMESPACE::stack<int, NAMESPACE::vector< int > > intstack;
typedef NAMESPACE::stack<long, NAMESPACE::vector<long> > longstack;
typedef NAMESPACE::stack<double, NAMESPACE::vector<double> > doublestack;
typedef NAMESPACE::stack<char, NAMESPACE::vector<char> > charstack;

#endif