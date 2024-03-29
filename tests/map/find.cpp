/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:36:42 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:14:45 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

int main(void){
    SETUP_MAP_ARRAYS();
    {
        strmap m(strstr_arr, strstr_arr + strstr_size);

        strmap::iterator it = m.find("ABCD");

        if (it != m.end())
            PRINT_PAIR_REF(*it);

        m.insert(NAMESPACE::make_pair("12345", "etsriueruy394w"));
        m.insert(NAMESPACE::make_pair("abcd", "sfdge4ta4tqtawefa"));
        m.insert(NAMESPACE::make_pair("123", "adfgagrawetawtawef"));
        m.insert(NAMESPACE::make_pair("1234", "asdfgaetfawfasdf"));
        m.insert(NAMESPACE::make_pair("ab", "adfawtawefgzsdfg"));
        m.insert(NAMESPACE::make_pair("yz", "gftrjr5y4agwe3ta"));
        m.insert(NAMESPACE::make_pair("64", "mhj,i;y9o67eysetrgerg"));

        it = m.find("12345");
        if (it != m.end())
            PRINT_PAIR_REF(*it);
        it = m.find("1234");
        if (it != m.end())
            PRINT_PAIR_REF(*it);
        it = m.find("123");
        if (it != m.end())
            PRINT_PAIR_REF(*it);
        it = m.find("123");
        if (it != m.end())
            PRINT_PAIR_REF(*it);
        it = m.find("z");
        if (it != m.end())
            PRINT_PAIR_REF(*it);
        const strmap cm(m);
        strmap::const_iterator cit = cm.find("ABCD");
        if (cit != cm.end())
            PRINT_PAIR_REF(*cit);
        cit = cm.find("64");
        if (cit != cm.end())
            PRINT_PAIR_REF(*cit);
        cit = m.find("12345");
        if (cit != m.end())
            PRINT_PAIR_REF(*cit);
        cit = m.find("1234");
        if (cit != m.end())
            PRINT_PAIR_REF(*cit);
        cit = m.find("123");
        if (cit != m.end())
            PRINT_PAIR_REF(*cit);
        cit = m.find("123");
        if (cit != m.end())
            PRINT_PAIR_REF(*cit);
        cit = m.find("z");
        if (cit != m.end())
            PRINT_PAIR_REF(*cit);
    }
    {
        const intmap cm;

        if (cm.find(0) != cm.end())
            PRINT_PAIR_PTR(cm.find(0));
        intmap m;
        m.insert(NAMESPACE::make_pair(123, "Hello"));
        if (m.find(0) != m.end())
            PRINT_PAIR_PTR(m.find(0));
        if (m.find(123) != m.end())
            PRINT_PAIR_PTR(m.find(123));
    }
    leak_checker::check_all();
}