/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_comp.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:35:47 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:30:21 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

int main(void) {
    SETUP_MAP_ARRAYS();

    {
        strmap m(strstr_arr, strstr_arr + strstr_size);
        strmap::iterator it = m.begin();
        strmap::const_iterator cit = m.begin();
        strmap::value_compare comp = m.value_comp();

        if (comp(*it, *cit)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(cit, 5);
        std::advance(it, 14);
        if (comp(*it, *cit)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, 7);
        std::advance(cit, 3);
        if (comp(*it, *cit)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, -3);
        std::advance(cit, 12);
        if (comp(*it, *cit)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, -1);
        std::advance(cit, 1);
        if (comp(*it, *cit)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
    }
    {
        intmap m(intstr_arr, intstr_arr + intstr_size);
        intmap::iterator it = m.begin();
        intmap::iterator it2 = m.begin();
        intmap::value_compare comp = m.value_comp();

        if (comp(*it, *it2)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, 14);
        std::advance(it2, 5);
        if (comp(*it, *it2)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, 7);
        std::advance(it2, 3);
        if (comp(*it, *it2)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, -3);
        std::advance(it2, 12);
        if (comp(*it, *it2)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, -1);
        std::advance(it2, 1);
        if (comp(*it, *it2)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
    }
    leak_checker::check_all();
}