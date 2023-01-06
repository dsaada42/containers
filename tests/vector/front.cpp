/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:16 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:07:14 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    SETUP_ARRAYS();

    {
        longvector v(1, 9);
        PRINT_LINE("Front:", v.front());
        if (&v.front() != &v[0])
            PRINT_MSG("Wrong reference");
    }
    {
        longvector v(123, 543);
        PRINT_LINE("Front:", v.front());
        if (&v.front() != &v[0])
            PRINT_MSG("Wrong reference");
    }
    {
        const longvector v(1, 9);
        PRINT_LINE("Front:", v.front());
        longvector::const_reference b = v.front();
        if (&b != &v[0])
            PRINT_MSG("Wrong reference");
    }
    {
        const longvector v(123, 543);
        PRINT_LINE("Front:", v.front());
        longvector::const_reference b = v.front();
        if (&b != &v[0])
            PRINT_MSG("Wrong reference");
    }
    leak_checker::check_all();
}