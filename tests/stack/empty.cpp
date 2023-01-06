/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:26:50 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 08:29:28 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_header.hpp"

int main (void){

    {
        NAMESPACE::vector< int > v(0, 123);
        intstack s(v);
        if (s.empty())
            PRINT_MSG("Empty");
        PRINT_STACK(s);
    }
    {
        NAMESPACE::vector< int > v;
        intstack s(v);
        if (s.empty())
            PRINT_MSG("Empty.");
        PRINT_STACK(s);
    }
    {
        NAMESPACE::vector< int > v(1, 64);
        intstack s(v);
        if (s.empty())
            PRINT_MSG("Empty..");
        PRINT_STACK(s);
    }
    {
        NAMESPACE::vector< int > v(42, 64);
        intstack s(v);
        if (s.empty())
            PRINT_MSG("Empty...");
        PRINT_STACK(s);
    }
    leak_checker::check_all();    
}