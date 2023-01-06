/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_comp.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:36:32 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:23:42 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

int main(void) {
    SETUP_MAP_ARRAYS();

    {
        strmap m(strstr_arr, strstr_arr + strstr_size);
        strmap::iterator it = m.begin();
        strmap::const_iterator cit = m.begin();
        strmap::key_compare comp = m.key_comp();

        if (comp(it->first, cit->first)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(cit, 5);
        std::advance(it, 14);
        if (comp(it->first, cit->first)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, 7);
        std::advance(cit, 3);
        if (comp(it->first, cit->first)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, -3);
        std::advance(cit, 12);
        if (comp(it->first, cit->first)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, -1);
        std::advance(cit, 1);
        if (comp(it->first, cit->first)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
    }
    {
        intmap m(intstr_arr, intstr_arr + intstr_size);
        intmap::iterator it = m.begin();
        intmap::const_iterator cit = m.begin();
        intmap::key_compare comp = m.key_comp();

        if (comp(it->first, cit->first)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, 14);
        std::advance(cit, 5);
        if (comp(it->first, cit->first)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, 7);
        std::advance(cit, 3);
        if (comp(it->first, cit->first)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, -3);
        std::advance(cit, 12);
        if (comp(it->first, cit->first)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, -1);
        std::advance(cit, 1);
        if (comp(it->first, cit->first)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
    }
    leak_checker::check_all();
}