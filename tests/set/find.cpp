/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:31:47 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 09:35:20 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void) {
    SETUP_ARRAYS();

    {
        strset m(s_string, s_string + s_size);

        strset::iterator it = m.find("ABCD");

        if (it != m.end()) 
            PRINT_LINE("It:", *it);

        m.insert("12345");
        m.insert("abcd");
        m.insert("123");
        m.insert("1234");
        m.insert("ab");
        m.insert("yz");
        m.insert("64");

        it = m.find("12345");
        if (it != m.end()) 
            PRINT_LINE("It:", *it);
        it = m.find("1234");
        if (it != m.end()) 
            PRINT_LINE("It:", *it);
        it = m.find("123");
        if (it != m.end()) 
            PRINT_LINE("It:", *it);
        it = m.find("123");
        if (it != m.end()) 
            PRINT_LINE("It:", *it);
        it = m.find("z");
        if (it != m.end()) 
            PRINT_LINE("It:", *it);
        const strset cm(m);
        strset::const_iterator cit = cm.find("ABCD");
        if (cit != cm.end()) 
            PRINT_LINE("It:", *cit);
        cit = cm.find("64");
        if (cit != cm.end()) 
            PRINT_LINE("It:", *cit);
        cit = m.find("12345");
        if (cit != m.end()) 
            PRINT_LINE("It:", *cit);
        cit = m.find("1234");
        if (cit != m.end()) 
            PRINT_LINE("It:", *cit);
        cit = m.find("123");
        if (cit != m.end()) 
            PRINT_LINE("It:", *cit);
        cit = m.find("123");
        if (cit != m.end()) 
            PRINT_LINE("It:", *cit);
        cit = m.find("z");
        if (cit != m.end()) 
            PRINT_LINE("It:", *cit);
    }
    {
        const intset cm;

        if (cm.find(0) != cm.end()) 
            PRINT_IT_PTR(cm.find(0));
        intset m;
        m.insert(123);
        if (m.find(0) != m.end()) 
            PRINT_IT_PTR(m.find(0));
        if (m.find(123) != m.end()) 
            PRINT_IT_PTR(m.find(123));
    }
    leak_checker::check_all();
}