/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:22 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 08:28:41 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){

    {
        intvector v(0, 123);
        CHECK_AND_PRINT_VECTOR(v);
        if (v.empty())
            PRINT_MSG("Empty");
    }
    {
        intvector v;
        CHECK_AND_PRINT_VECTOR(v);
        if (v.empty())
            PRINT_MSG("Empty.");
    }
    {
        intvector v(1, 64);
        CHECK_AND_PRINT_VECTOR(v);
        if (v.empty())
            PRINT_MSG("Empty..");
    }
    {
        intvector v(42, 64);
        CHECK_AND_PRINT_VECTOR(v);
        if (v.empty())
            PRINT_MSG("Empty...");
    }
    leak_checker::check_all();
}