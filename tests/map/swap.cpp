/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:35:44 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:27:04 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

int main(void) {
    SETUP_MAP_ARRAYS();

    {
        intmap m1(intstr_arr, intstr_arr + 32);
        intmap m2;
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
        m1.insert(NAMESPACE::make_pair(64, "N64"));
        NAMESPACE::swap(m1, m2);
        PRINT_ALL(m1);
        PRINT_ALL(m2);
        m2.insert(intstr_arr, intstr_arr + intstr_size);
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