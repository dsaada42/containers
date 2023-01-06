/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:31:33 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 09:12:12 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void) {
    SETUP_ARRAYS();

    {
        intset m(s_int, s_int + s_size);

        intset::size_type c = m.count(64);

        PRINT_LINE("Count:", c);

        c = m.count(145);

        PRINT_LINE("Count:", c);

        c = m.count(11);

        PRINT_LINE("Count:", c);

        m.insert(34);
        m.insert(2);
        m.insert(9);
        m.insert(3);
        m.insert(22);
        m.insert(10);

        c = m.count(34);

        PRINT_LINE("Count:", c);

        c = m.count(2);

        PRINT_LINE("Count:", c);

        c = m.count(9);

        PRINT_LINE("Count:", c);

        m.erase(9);

        c = m.count(9);

        PRINT_LINE("Count:", c);

        c = m.count(10);

        PRINT_LINE("Count:", c);

        c = m.count(22);

        PRINT_LINE("Count:", c);
    }
    leak_checker::check_all();
}