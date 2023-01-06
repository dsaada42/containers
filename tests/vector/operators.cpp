/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:03 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:09:39 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    SETUP_ARRAYS();

//----- Operator = -----
    {
        strvector v1;
        strvector v2;

        v1 = v2;
        CHECK_AND_PRINT_VECTOR(v1);
        v2 = strvector(b_string, b_string + b_size);
        CHECK_AND_PRINT_VECTOR(v2);
        v1 = v2;
        CHECK_AND_PRINT_VECTOR(v1);
        v2 = strvector(s_string, s_string + s_size);
        CHECK_AND_PRINT_VECTOR(v2);
        v1 = v2;
        CHECK_AND_PRINT_VECTOR(v1);
    }
//----- Operator [] -----
    {
        intvector v(s_int, s_int + s_size);
        PRINT_LINE("Index 0:", v[0]);
        intvector::reference value = v[26];
        PRINT_LINE("Index 26:", value);
        value = -64;
        CHECK_AND_PRINT_VECTOR(v);
        intvector::reference value2 = v[31];
        PRINT_LINE("Index 31:", value2);
        value2 = -1;
        CHECK_AND_PRINT_VECTOR(v);
        v[14] = 0;
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        const intvector v(s_int, s_int + s_size);
        PRINT_LINE("Index 0:", v[0]);
        intvector::const_reference value = v[26];
        PRINT_LINE("Index 26:", value);
        intvector::const_reference value2 = v[31];
        PRINT_LINE("Index 31:", value2);
        CHECK_AND_PRINT_VECTOR(v);
    }
//----- Comparison Operators -----
    {
        NAMESPACE::vector<long> v1;
        NAMESPACE::vector<long> v2;

        if (v1 == v2)
            PRINT_MSG("Equal");
        if (v1 >= v2)
            PRINT_MSG("Greater than or equal");
        if (v1 > v2)
            PRINT_MSG("Greater than");
        if (v1 <= v2)
            PRINT_MSG("Less than or equal");
        if (v1 < v2)
            PRINT_MSG("Less than");
        if (v1 != v2)
            PRINT_MSG("Not equal");
    }
    {
        NAMESPACE::vector<long> v1(5, 64);
        NAMESPACE::vector<long> v2;

        if (v1 == v2)
            PRINT_MSG("Equal.");
        if (v1 >= v2)
            PRINT_MSG("Greater than or equal");
        if (v1 > v2)
            PRINT_MSG("Greater than");
        if (v1 <= v2)
            PRINT_MSG("Less than or equal");
        if (v1 < v2)
            PRINT_MSG("Less than");
        if (v1 != v2)
            PRINT_MSG("Not equal");
        
        
    }
    {
        NAMESPACE::vector<long> v1;
        NAMESPACE::vector<long> v2(5, 32);

        if (v1 == v2)
            PRINT_MSG("Equal..");
        if (v1 >= v2)
            PRINT_MSG("Greater than or equal");
        if (v1 > v2)
            PRINT_MSG("Greater than");
        if (v1 <= v2)
            PRINT_MSG("Less than or equal");
        if (v1 < v2)
            PRINT_MSG("Less than");
        if (v1 != v2)
            PRINT_MSG("Not equal");
        
    }
    {
        NAMESPACE::vector<long> v1(5, 64);
        NAMESPACE::vector<long> v2(5, 48);

        if (v1 == v2)
            PRINT_MSG("Equal...");
        if (v1 >= v2)
            PRINT_MSG("Greater than or equal");
        if (v1 > v2)
            PRINT_MSG("Greater than");
        if (v1 <= v2)
            PRINT_MSG("Less than or equal");
        if (v1 < v2)
            PRINT_MSG("Less than");
        if (v1 != v2)
            PRINT_MSG("Not equal");
        
    }
    {
        NAMESPACE::vector<long> v1(5, 64);
        NAMESPACE::vector<long> v2(5, 64);

        if (v1 == v2)
            PRINT_MSG("Equal...");
        if (v1 >= v2)
            PRINT_MSG("Greater than or equal");
        if (v1 > v2)
            PRINT_MSG("Greater than");
        if (v1 <= v2)
            PRINT_MSG("Less than or equal");
        if (v1 < v2)
            PRINT_MSG("Less than");
        if (v1 != v2)
            PRINT_MSG("Not equal");
        
    }
    {
        NAMESPACE::vector<long> v1(5, 64);
        NAMESPACE::vector<long> v2(4, 64);

        if (v1 == v2)
            PRINT_MSG("Equal....");
        if (v1 >= v2)
            PRINT_MSG("Greater than or equal");
        if (v1 > v2)
            PRINT_MSG("Greater than");
        if (v1 <= v2)
            PRINT_MSG("Less than or equal");
        if (v1 < v2)
            PRINT_MSG("Less than");
        if (v1 != v2)
            PRINT_MSG("Not equal");
        
    }
    {
        NAMESPACE::vector<long> v1(4);
        NAMESPACE::vector<long> v2(5);

        if (v1 == v2)
            PRINT_MSG("Equal.....");
        if (v1 >= v2)
            PRINT_MSG("Greater than or equal");
        if (v1 > v2)
            PRINT_MSG("Greater than");
        if (v1 <= v2)
            PRINT_MSG("Less than or equal");
        if (v1 < v2)
            PRINT_MSG("Less than");
        if (v1 != v2)
            PRINT_MSG("Not equal");   
    }
    leak_checker::check_all();
}