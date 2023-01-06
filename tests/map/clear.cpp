/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:37:00 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 10:58:08 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

int main(void) {
    SETUP_MAP_ARRAYS();

    {
        strmap m;
        PRINT_ALL(m);
        m.clear();
        PRINT_ALL(m);
        m.insert(strstr_arr, strstr_arr + 16);
        PRINT_ALL(m);
        m.clear();
        PRINT_ALL(m);
    }
    leak_checker::check_all();
}