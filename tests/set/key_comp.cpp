/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_comp.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:32:03 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 09:54:32 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void) {
    SETUP_ARRAYS();

    {
        strset m(s_string, s_string + s_size);
        strset::iterator it = m.begin();
        strset::const_iterator cit = m.begin();
        strset::key_compare comp = m.key_comp();

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
        intset m(s_int, s_int + s_size);
        intset::iterator it = m.begin();
        intset::const_iterator cit = m.begin();
        intset::key_compare comp = m.key_comp();

        if (comp(*it, *cit)) {
            PRINT_MSG("Less");
        } else {
            PRINT_MSG("Not Less");
        }
        std::advance(it, 14);
        std::advance(cit, 5);
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
    leak_checker::check_all();
}