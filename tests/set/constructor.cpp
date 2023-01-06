/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:34:56 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 09:11:15 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void){
    SETUP_ARRAYS();

//---- Default constructor -----
    {
        intset m;

        PRINT_ALL(m);
    }
    {
        track_allocator<NAMESPACE::pair<const std::string, std::string> > alloc;
        strset m(std::less<std::string>(), alloc);

        PRINT_ALL(m);
    }
//---- Range constructor -----
    {
        track_allocator<NAMESPACE::pair<const int, std::string> > alloc;
        intset m(s_int, s_int + s_size, std::less<int>(), alloc);

        PRINT_ALL(m);
        intset m2(m.begin(), m.end());
        PRINT_ALL(m);
        PRINT_ALL(m2);
    }
    {
        strset m1(s_string, s_string + s_size);
        PRINT_ALL(m1);
        strset m2(s_string, s_string + s_size);
        PRINT_ALL(m1);
        PRINT_ALL(m2);
    }
//----- Copy constructor ----
    {
        intset m1(s_int, s_int + s_size);
        PRINT_ALL(m1);
        intset m2(m1);
        PRINT_ALL(m2);
    }
    {
        strset m1(s_string, s_string + s_size);
        PRINT_ALL(m1);
        strset m2(m1);
        PRINT_ALL(m2);
    }
    leak_checker::check_all();
}