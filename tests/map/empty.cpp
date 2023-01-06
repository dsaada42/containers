/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:36:50 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:03:21 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

int main(void) {
    SETUP_MAP_ARRAYS();

    {
        strmap m;
        PRINT_LINE("Empty:", m.empty() ? "true" : "false");
        m.insert(NAMESPACE::make_pair("Hello", "World"));
        PRINT_LINE("Empty:", m.empty() ? "true" : "false");
        m.erase(m.begin());
        PRINT_LINE("Empty:", m.empty() ? "true" : "false");
    }
    {
        intmap m(intstr_arr, intstr_arr + intstr_size);
        PRINT_LINE("Empty:", m.empty() ? "true" : "false");
    }
    leak_checker::check_all();
}