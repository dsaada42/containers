/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:32:15 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:52:40 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void) {
    SETUP_ARRAYS();

//----- Assignement operator -----
    {
        intset m1;
        intset m2;
        m1 = m2;
        PRINT_ALL(m1);
        m2 = intset(s_int, s_int + s_size);
        PRINT_ALL(m2);
        m1 = m2;
        PRINT_ALL(m1);
        m1 = intset(s_int, s_int + 10);
        PRINT_ALL(m1);
        m2 = m1;
        PRINT_ALL(m2);
    }
    {
        strset m1;
        strset m2;

        m1 = m2;
        PRINT_ALL(m1);
        m2 = strset(s_string, s_string + s_size);
        PRINT_ALL(m2);
        m1 = m2;
        PRINT_ALL(m1);
        m1 = strset(s_string, s_string + 10);
        PRINT_ALL(m1);
        m2 = m1;
        PRINT_ALL(m2);
    }
//----- Comparison operators -----
    {
        intset m;
        intset n;

        if (m == n)
            PRINT_MSG("Equal");
        if (m > n)
            PRINT_MSG("Greater");
        if (m >= n)
            PRINT_MSG("Greater or equal");
        if (m < n)
            PRINT_MSG("Less");
        if (m <= n)
            PRINT_MSG("Less or equal");
        if (m != n)
            PRINT_MSG("Not equal");
    }
    {
        intset m(s_int, s_int + 1);
        intset n;

        if (m == n)
            PRINT_MSG("Equal.");
        if (m > n)
            PRINT_MSG("Greater");
        if (m >= n)
            PRINT_MSG("Greater or equal");
        if (m < n)
            PRINT_MSG("Less");
        if (m <= n)
            PRINT_MSG("Less or equal");
        if (m != n)
            PRINT_MSG("Not equal");
    }
    {
        intset m(s_int, s_int + 1);
        intset n;

        if (n == m)
            PRINT_MSG("Equal..");
        if (m > n)
            PRINT_MSG("Greater");
        if (m >= n)
            PRINT_MSG("Greater or equal");
        if (m < n)
            PRINT_MSG("Less");
        if (m <= n)
            PRINT_MSG("Less or equal");
        if (m != n)
            PRINT_MSG("Not equal");
    }
    {
        intset m(s_int, s_int + 1);
        intset n(s_int, s_int + 1);

        if (n == m)
            PRINT_MSG("Equal...");
        if (m > n)
            PRINT_MSG("Greater");
        if (m >= n)
            PRINT_MSG("Greater or equal");
        if (m < n)
            PRINT_MSG("Less");
        if (m <= n)
            PRINT_MSG("Less or equal");
        if (m != n)
            PRINT_MSG("Not equal");
    }
    {
        intset m(s_int, s_int + s_size);
        intset n(s_int, s_int + s_size);

        if (n == m)
            PRINT_MSG("Equal....");
        if (m > n)
            PRINT_MSG("Greater");
        if (m >= n)
            PRINT_MSG("Greater or equal");
        if (m < n)
            PRINT_MSG("Less");
        if (m <= n)
            PRINT_MSG("Less or equal");
        if (m != n)
            PRINT_MSG("Not equal");
    }
    {
        intset m(s_int, s_int + 5);
        intset n;

        n.insert(5);
        n.insert(7);
        n.insert(8);
        n.insert(1);
        n.insert(0);

        if (n == m)
            PRINT_MSG("Equal.....");
        if (m > n)
            PRINT_MSG("Greater");
        if (m >= n)
            PRINT_MSG("Greater or equal");
        if (m < n)
            PRINT_MSG("Less");
        if (m <= n)
            PRINT_MSG("Less or equal");
        if (m != n)
            PRINT_MSG("Not equal");
    }
    {
        intset m(s_int, s_int + 5);
        intset n(s_int, s_int + 4);

        n.insert(5);

        if (n == m)
            PRINT_MSG("Equal......");
        if (m > n)
            PRINT_MSG("Greater");
        if (m >= n)
            PRINT_MSG("Greater or equal");
        if (m < n)
            PRINT_MSG("Less");
        if (m <= n)
            PRINT_MSG("Less or equal");
        if (m != n)
            PRINT_MSG("Not equal");
    }
    leak_checker::check_all();
}