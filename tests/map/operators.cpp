/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:36:16 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:58:25 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

int main(void){
    SETUP_MAP_ARRAYS();
//------ Assignement Operator -----
    {
        intmap m1;
        intmap m2;

        m1 = m2;
        PRINT_ALL(m1);
        m2 = intmap(intstr_arr, intstr_arr + intstr_size);
        PRINT_ALL(m2);
        m1 = m2;
        PRINT_ALL(m1);
        m1 = intmap(intstr_arr, intstr_arr + 10);
        PRINT_ALL(m1);
        m2 = m1;
        PRINT_ALL(m2);
    }
    {
        strmap m1;
        strmap m2;

        m1 = m2;
        PRINT_ALL(m1);
        m2 = strmap(strstr_arr, strstr_arr + strstr_size);
        PRINT_ALL(m2);
        m1 = m2;
        PRINT_ALL(m1);
        m1 = strmap(strstr_arr, strstr_arr + 10);
        PRINT_ALL(m1);
        m2 = m1;
        PRINT_ALL(m2);
    }
//------ Comparison Operators -----
    {
        intmap m;
        intmap n;

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
        intmap m(intstr_arr, intstr_arr + 1);
        intmap n;

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
        intmap m(intstr_arr, intstr_arr + 1);
        intmap n;

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
        intmap m(intstr_arr, intstr_arr + 1);
        intmap n(intstr_arr, intstr_arr + 1);

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
        intmap m(intstr_arr, intstr_arr + intstr_size);
        intmap n(intstr_arr, intstr_arr + intstr_size);

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
        intmap m(intstr_arr, intstr_arr + 5);
        intmap n;

        n.insert(NAMESPACE::make_pair(5, "Hello"));
        n.insert(NAMESPACE::make_pair(7, "Hello"));
        n.insert(NAMESPACE::make_pair(8, "Hello"));
        n.insert(NAMESPACE::make_pair(1, "Hello"));
        n.insert(NAMESPACE::make_pair(0, "Hello"));
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
        intmap m(intstr_arr, intstr_arr + 5);
        intmap n(intstr_arr, intstr_arr + 4);

        n.insert(NAMESPACE::make_pair(5, "Hello"));
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
}