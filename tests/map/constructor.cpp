/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:34:58 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:01:16 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

int main (void){
    SETUP_MAP_ARRAYS()
    
    //----- Default Constructor -----
    {
        intmap m;
        PRINT_ALL(m);
    }
    {
        track_allocator<NAMESPACE::pair<const std::string, std::string> > alloc;
        strmap m(std::less<std::string>(), alloc);
        PRINT_ALL(m);
    }
    //------ Copy Constructor -----
    {
        intmap m1(intstr_arr, intstr_arr + intstr_size);
        PRINT_ALL(m1);
        intmap m2(m1);
        PRINT_ALL(m2);
    }

    {
        strmap m1(strstr_arr, strstr_arr + strstr_size);
        PRINT_ALL(m1);
        strmap m2(m1);
        PRINT_ALL(m2);
    }
    //------ Range Constructor -----
    {
        track_allocator<NAMESPACE::pair<const int, std::string> > alloc;
        intmap m(intstr_arr, intstr_arr + intstr_size, std::less<int>(), alloc);
        PRINT_ALL(m);
        intmap m2(m.begin(), m.end());
        PRINT_ALL(m);
        PRINT_ALL(m2);
    }
    {
        strmap m1(strstr_arr, strstr_arr + strstr_size);
        PRINT_ALL(m1);
        strmap m2(strstr_arr, strstr_arr + strstr_size);
        PRINT_ALL(m1);
        PRINT_ALL(m2);
    }
    leak_checker::check_all();
}