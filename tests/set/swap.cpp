/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:32:25 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 10:00:20 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void) {
    SETUP_ARRAYS();

    {
        intset m1(s_int, s_int + 32);
        intset m2;
        NAMESPACE::swap(m1, m2);
        PRINT_ALL(m1);
        PRINT_ALL(m2);
        m1.clear();
        m1.swap(m2);
        PRINT_ALL(m1);
        PRINT_ALL(m2);
        m1.clear();
        m2.swap(m1);
        PRINT_ALL(m1);
        PRINT_ALL(m2);
        m1.insert(64);
        NAMESPACE::swap(m1, m2);
        PRINT_ALL(m1);
        PRINT_ALL(m2);
        m2.insert(s_int, s_int + s_size);
        m1.swap(m2);
        PRINT_ALL(m1);
        PRINT_ALL(m2);
        m1.clear();
        m1.swap(m2);
        m1.clear();
        m1.swap(m2);
        PRINT_ALL(m1);
        PRINT_ALL(m2);
    }
    leak_checker::check_all();
}