/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:27:17 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 08:50:27 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_header.hpp"

int main (void){

    {
        NAMESPACE::stack<long, NAMESPACE::vector<long> > s1;
        NAMESPACE::stack<long, NAMESPACE::vector<long> > s2;

        if (s1 == s2)
            PRINT_MSG("Equal");
        if (s1 != s2)
            PRINT_MSG("Not equal");
        if (s1 < s2)
            PRINT_MSG("Less");
        if (s1 <= s2)
            PRINT_MSG("Less or equal");
        if (s1 > s2)
            PRINT_MSG("Greater");
        if (s1 >= s2)
            PRINT_MSG("Greater or equal");
        PRINT_STACK(s1);
        PRINT_STACK(s2);
    }
    {
        NAMESPACE::stack<long, NAMESPACE::vector<long> > s1;
        NAMESPACE::stack<long, NAMESPACE::vector<long> > s2;

        add_values(s1, 0, 5);

        if (s1 == s2)
            PRINT_MSG("Equal");
        if (s1 != s2)
            PRINT_MSG("Not equal");
        if (s1 < s2)
            PRINT_MSG("Less");
        if (s1 <= s2)
            PRINT_MSG("Less or equal");
        if (s1 > s2)
            PRINT_MSG("Greater");
        if (s1 >= s2)
            PRINT_MSG("Greater or equal");
        PRINT_STACK(s1);
        PRINT_STACK(s2);
    }
    {
        NAMESPACE::stack<long, NAMESPACE::vector<long> > s1;
        NAMESPACE::stack<long, NAMESPACE::vector<long> > s2;

        add_values(s1, 0, 8);
        add_values(s2, 0, 9);

        if (s1 == s2)
            PRINT_MSG("Equal");
        if (s1 != s2)
            PRINT_MSG("Not equal");
        if (s1 < s2)
            PRINT_MSG("Less");
        if (s1 <= s2)
            PRINT_MSG("Less or equal");
        if (s1 > s2)
            PRINT_MSG("Greater");
        if (s1 >= s2)
            PRINT_MSG("Greater or equal");
        PRINT_STACK(s1);
        PRINT_STACK(s2);
    }
    {
        NAMESPACE::stack<long, NAMESPACE::vector<long> > s1;
        NAMESPACE::stack<long, NAMESPACE::vector<long> > s2;

        add_values(s1, 0, 9);
        add_values(s2, 0, 8);

        if (s1 == s2)
            PRINT_MSG("Equal");
        if (s1 != s2)
            PRINT_MSG("Not equal");
        if (s1 < s2)
            PRINT_MSG("Less");
        if (s1 <= s2)
            PRINT_MSG("Less or equal");
        if (s1 > s2)
            PRINT_MSG("Greater");
        if (s1 >= s2)
            PRINT_MSG("Greater or equal");
        PRINT_STACK(s1);
        PRINT_STACK(s2);
    }
    {
        NAMESPACE::stack<long, NAMESPACE::vector<long> > s1;
        NAMESPACE::stack<long, NAMESPACE::vector<long> > s2;

        add_values(s1, 1, 64);
        add_values(s2, 1, 64);

        if (s1 == s2)
            PRINT_MSG("Equal");
        if (s1 != s2)
            PRINT_MSG("Not equal");
        if (s1 < s2)
            PRINT_MSG("Less");
        if (s1 <= s2)
            PRINT_MSG("Less or equal");
        if (s1 > s2)
            PRINT_MSG("Greater");
        if (s1 >= s2)
            PRINT_MSG("Greater or equal");
    }
    {
        NAMESPACE::stack<long, NAMESPACE::vector<long> > s1;
        NAMESPACE::stack<long, NAMESPACE::vector<long> > s2;

        add_values(s1, 1, 64);
        add_values(s2, 1, 64);

        s1.top() = 21;
        
        if (s1 == s2)
            PRINT_MSG("Equal");
        if (s1 != s2)
            PRINT_MSG("Not equal");
        if (s1 < s2)
            PRINT_MSG("Less");
        if (s1 <= s2)
            PRINT_MSG("Less or equal");
        if (s1 > s2)
            PRINT_MSG("Greater");
        if (s1 >= s2)
            PRINT_MSG("Greater or equal");    
    }
    leak_checker::check_all();
}