/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:34:53 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 08:24:50 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_header.hpp"

int main (void){

    SETUP_ARRAYS();
    
//----- Default Constructor -----
    {
        strstack s;
        PRINT_STACK(s);
    }
//----- Default with container argument -----
    {
        NAMESPACE::vector<std::string> vec(s_string, s_string + s_size);
        strstack s(vec);
        PRINT_STACK(s);
        PRINT_STACK(s);
    }
    {
        NAMESPACE::vector<int> vec(s_int, s_int + s_size);
        intstack s(vec);
        PRINT_STACK(s);
        PRINT_STACK(s);
    }
    {
        NAMESPACE::vector<double> vec(s_double, s_double + s_size);
        doublestack s(vec);
        PRINT_STACK(s);
        PRINT_STACK(s);
    }
    leak_checker::check_all();
}