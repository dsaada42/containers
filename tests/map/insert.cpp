/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:36:38 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:21:12 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

#define PRINT_INS_PAIR(p)                                                                          \
    {                                                                                              \
        PRINT_PAIR_REF(*p.first);                                                                  \
        PRINT_LINE("Inserted:", p.second ? "true" : "false");                                      \
    }
    
int main(void) {
    SETUP_MAP_ARRAYS();

//----- Insert -----
    {
        typedef NAMESPACE::pair<intmap::iterator, bool> ins_pair;
        intmap m;

        ins_pair p = m.insert(NAMESPACE::make_pair(64, "64str"));
        PRINT_INS_PAIR(p);
        p = m.insert(NAMESPACE::make_pair(64, "Double"));
        PRINT_INS_PAIR(p);
        p = m.insert(NAMESPACE::make_pair(0, "0str"));
        PRINT_INS_PAIR(p);
        p = m.insert(NAMESPACE::make_pair(-23, "-23str"));
        PRINT_INS_PAIR(p);
        p = m.insert(NAMESPACE::make_pair(64, "dfgs"));
        PRINT_INS_PAIR(p);
    }
    {
        typedef NAMESPACE::pair<strmap::iterator, bool> ins_pair;
        strmap m;

        ins_pair p = m.insert(NAMESPACE::make_pair("64", "64str"));
        PRINT_INS_PAIR(p);
        p = m.insert(NAMESPACE::make_pair("64n", "Double"));
        PRINT_INS_PAIR(p);
        p = m.insert(NAMESPACE::make_pair("0n", "0str"));
        PRINT_INS_PAIR(p);
        p = m.insert(NAMESPACE::make_pair("-23n", "-23str"));
        PRINT_INS_PAIR(p);
        p = m.insert(NAMESPACE::make_pair("64n", "dfgs"));
        PRINT_INS_PAIR(p);
    }
//----- Insert hint -----
    {
        intmap m;
        intmap::iterator it = m.insert(m.end(), NAMESPACE::make_pair(64, "Gamepak"));

        PRINT_PAIR_REF(*it);
        it = m.insert(m.end(), NAMESPACE::make_pair(64, "Test"));
        PRINT_PAIR_REF(*it);
        it = m.insert(m.end(), NAMESPACE::make_pair(100, "100$"));
        PRINT_PAIR_REF(*it);
        it = m.end();
        --it;
        it = m.insert(it, NAMESPACE::make_pair(100, "12345"));
        PRINT_PAIR_REF(*it);
        it = m.insert(it, NAMESPACE::make_pair(69, "420"));
        PRINT_PAIR_REF(*it);
    }
//----- Insert range ------
    {
        strmap m;
        PRINT_ALL(m);
        m.insert(strstr_arr, strstr_arr + 5);
        PRINT_ALL(m);
        m.insert(strstr_arr + 5, strstr_arr + 14);
        PRINT_ALL(m);
        m.insert(strstr_arr, strstr_arr + 9);
        PRINT_ALL(m);
        m.insert(strstr_arr + 26, strstr_arr + strstr_size);
        PRINT_ALL(m);
        m.insert(strstr_arr + 14, strstr_arr + 26);
        PRINT_ALL(m);
    }
    {
        intmap m;
        PRINT_ALL(m);
        m.insert(intstr_arr + 16, intstr_arr + 16);
        PRINT_ALL(m);
        m.insert(intstr_arr + 1, intstr_arr + 7);
        PRINT_ALL(m);
        m.insert(intstr_arr, intstr_arr + 1);
        PRINT_ALL(m);
        m.insert(intstr_arr, intstr_arr + 17);
        PRINT_ALL(m);
        m.insert(intstr_arr, intstr_arr + intstr_size);
        PRINT_ALL(m);
    }
    leak_checker::check_all();
}