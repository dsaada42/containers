/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:31:37 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 09:13:18 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void) {
    SETUP_ARRAYS();

    {
        strset m;

        PRINT_LINE("Empty:", m.empty() ? "true" : "false");
        m.insert("Hello");
        PRINT_LINE("Empty:", m.empty() ? "true" : "false");
        m.erase(m.begin());
        PRINT_LINE("Empty:", m.empty() ? "true" : "false");
    }
    {
        intset m(s_int, s_int + s_size);
        PRINT_LINE("Empty:", m.empty() ? "true" : "false");
    }
    leak_checker::check_all();
}