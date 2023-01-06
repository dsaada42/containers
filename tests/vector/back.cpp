/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:34 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 10:45:33 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    SETUP_ARRAYS();

    {
        longvector v(1, 9);

        PRINT_LINE("Back:", v.back());
        if (&v.back() != &v[0]) {
            PRINT_MSG("Wrong reference");
        }
    }
    {
        longvector v(123, 543);

        PRINT_LINE("Back:", v.back());
        if (&v.back() != &v[122]) {
            PRINT_MSG("Wrong reference");
        }
    }
    {
        const longvector v(1, 9);

        PRINT_LINE("Back:", v.back());
        longvector::const_reference b = v.back();
        if (&b != &v[0]) {
            PRINT_MSG("Wrong reference");
        }
    }
    {
        const longvector v(123, 543);

        PRINT_LINE("Back:", v.back());
        longvector::const_reference b = v.back();
        if (&b != &v[122]) {
            PRINT_MSG("Wrong reference");
        }
    }
    leak_checker::check_all();
}