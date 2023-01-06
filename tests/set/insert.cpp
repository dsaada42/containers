/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:31:56 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 09:43:00 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

#define PRINT_INS_PAIR(p)                                                                          \
    {                                                                                              \
        PRINT_LINE("It:", *p.first);                                                               \
        PRINT_LINE("Inserted:", p.second ? "true" : "false");                                      \
    }
    
int main (void) {
    SETUP_ARRAYS();

//----- Insert -----
    {
        typedef NAMESPACE::pair<intset::iterator, bool> ins_pair;

        intset m;
        ins_pair p = m.insert(64);
        PRINT_INS_PAIR(p);
        p = m.insert(64);
        PRINT_INS_PAIR(p);
        p = m.insert(0);
        PRINT_INS_PAIR(p);
        p = m.insert(-23);
        PRINT_INS_PAIR(p);
        p = m.insert(64);
        PRINT_INS_PAIR(p);
    }
    {
        typedef NAMESPACE::pair<strset::iterator, bool> ins_pair;

        strset m;
        ins_pair p = m.insert("64");
        PRINT_INS_PAIR(p);
        p = m.insert("64n");
        PRINT_INS_PAIR(p);
        p = m.insert("0n");
        PRINT_INS_PAIR(p);
        p = m.insert("-23n");
        PRINT_INS_PAIR(p);
        p = m.insert("64n");
        PRINT_INS_PAIR(p);
    }
//----- Insert hint -----
        {
        intset m;
        intset::iterator it = m.insert(m.end(), 64);
        PRINT_LINE("It:", *it);
        it = m.insert(m.end(), 64);
        PRINT_LINE("It:", *it);
        it = m.insert(m.end(), 100);
        PRINT_LINE("It:", *it);
        it = m.end();
        --it;
        it = m.insert(it, 100);
        PRINT_LINE("It:", *it);
        it = m.insert(it, 69);
        PRINT_LINE("It:", *it);
    }
//----- Insert range -----
    {
        strset m;
        PRINT_ALL(m);
        m.insert(s_string, s_string + 5);
        PRINT_ALL(m);
        m.insert(s_string + 5, s_string + 14);
        PRINT_ALL(m);
        m.insert(s_string, s_string + 9);
        PRINT_ALL(m);
        m.insert(s_string + 26, s_string + s_size);
        PRINT_ALL(m);
        m.insert(s_string + 14, s_string + 26);
        PRINT_ALL(m);
    }
    {
        intset m;
        PRINT_ALL(m);
        m.insert(s_int + 16, s_int + 16);
        PRINT_ALL(m);
        m.insert(s_int + 1, s_int + 7);
        PRINT_ALL(m);
        m.insert(s_int, s_int + 1);
        PRINT_ALL(m);
        m.insert(s_int, s_int + 17);
        PRINT_ALL(m);
        m.insert(s_int, s_int + s_size);
        PRINT_ALL(m);
    }
    leak_checker::check_all();
}