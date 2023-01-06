/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:38 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 10:42:23 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    
    SETUP_ARRAYS();
    //----- ASSIGN -----
    {
        charvector v;
        v.assign(0, 'c');
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(64, 'A');
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(32, '5');
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(49, '8');
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(77, '2');
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        strvector v;
        v.assign(0, "");
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(64, "vector-string");
        CHECK_AND_PRINT_VECTOR(v);
    }
    //----- ASSIGN RANGE -----
    {
        strvector v;
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(b_string, b_string + b_size);
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(s_string, s_string + s_size);
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(s_string, s_string);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        longvector v;
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(b_long, b_long + b_size);
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(s_long, s_long + s_size);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        intvector v(s_int, s_int + s_size);
        CHECK_AND_PRINT_VECTOR(v);
        v.push_back(64);
        v.assign(b_int, b_int + b_size);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        intvector v(s_int, s_int + s_size);
        CHECK_AND_PRINT_VECTOR(v);
        v.push_back(64);
        v.assign(v.begin(), v.begin() + 21);
        CHECK_AND_PRINT_VECTOR(v);
        v.push_back(64);
        v.assign(v.begin(), v.end());
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        charvector v;
        std::istringstream str("1 2 3 4 5 6 7");
        std::istreambuf_iterator<char> it(str), end;
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(it, end);
        CHECK_AND_PRINT_VECTOR(v);
    }
    //----- ASSIGN MIXED -----
    {
        strvector v;
        v.assign(b_string, b_string + b_size);
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(65, "HelloWorld");
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(s_string, s_string + s_size);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        doublevector v;
        v.assign(b_double, b_double + b_size);
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(65, 1.234567);
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(65, 8765.234567);
        CHECK_AND_PRINT_VECTOR(v);
        v.assign(s_double, s_double + s_size);
        CHECK_AND_PRINT_VECTOR(v);
    }
    leak_checker::check_all();
}