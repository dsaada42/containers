/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:31:43 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 14:33:30 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void) {
    SETUP_SET_ARRAYS();

//----- Erase ----
    {
        intset m(int_arr, int_arr + 25);
        intset::iterator it = m.begin();
        m.erase(it);
        PRINT_ALL(m);
        it = m.begin();
        std::advance(it, 21);
        m.erase(it);
        PRINT_ALL(m);
        it = m.end();
        std::advance(it, -10);
        m.erase(it);
        PRINT_ALL(m);
        it = m.end();
        std::advance(it, -3);
        m.erase(it);
        PRINT_ALL(m);
        it = m.end();
        std::advance(it, -1);
        m.erase(it);
        PRINT_ALL(m);
        it = m.begin();
        std::advance(it, 1);
        m.erase(it);
        PRINT_ALL(m);
        for (it = m.begin(); it != m.end(); it = m.begin()) {
            m.erase(it);
            PRINT_ALL(m);
        }
    }
//----- Erase Key ----
    {
        intset m;
        intset::size_type size = m.erase(64);
        PRINT_LINE("Erased?:", size);
    }
    {
        intset m(int_arr, int_arr + 16);
        intset::size_type size = m.erase(64);
        PRINT_LINE("Erased?:", size);
        m.erase(m.begin(), m.end());
        m.insert(23);
        m.insert(25);
        m.insert(1);
        m.insert(2);
        m.insert(3);
        m.insert(75);
        m.insert(30);
        m.insert(-22);
        m.insert(-23);
        m.insert(0);
        size = m.erase(64);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(0);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(75);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(1);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(2);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(3);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(23);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(23);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(30);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(-22);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(-23);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(-23);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(25);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(-23);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase(25);
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
    }
    {
        strset m;
        strset::size_type size = m.erase("");
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        m.insert("");
        m.insert("123");
        m.insert("1234");
        m.insert("123456789123456789123456789");
        m.insert("0");
        m.insert("");
        m.insert("");
        m.insert("000000000000000000000000");
        size = m.erase("1");
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase("123");
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase("123");
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase("");
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase("1234");
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase("123456789123456789123456789");
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase("000000000000000000000000");
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase("0");
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
        size = m.erase("000000000000000000000000");
        PRINT_LINE("Erased?:", size);
        PRINT_ALL(m);
    }
//----- Erase range -----
    {
        strset m;
        m.erase(m.begin(), m.end());
        PRINT_ALL(m);
        m.insert(str_arr, str_arr + str_size);
        m.erase(m.begin(), m.end());
        PRINT_ALL(m);
    }
    {
        intset m(int_arr, int_arr + int_size);
        intset::iterator it(m.begin());
        intset::iterator end(it);
        std::advance(end, 1);
        m.erase(it, end);
        PRINT_ALL(m);
        it = m.begin();
        end = it;
        std::advance(it, 24);
        std::advance(end, 30);
        m.erase(it, end);
        PRINT_ALL(m);
        it = m.begin();
        end = it;
        std::advance(it, 34);
        std::advance(end, 55);
        m.erase(it, end);
        PRINT_ALL(m);
        it = m.begin();
        end = it;
        std::advance(end, 1);
        m.erase(it, end);
        PRINT_ALL(m);
        m.erase(m.begin(), m.end());
        PRINT_ALL(m);
    }
    leak_checker::check_all();
}