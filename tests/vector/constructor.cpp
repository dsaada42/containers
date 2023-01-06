/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:43:34 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 08:11:34 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    SETUP_ARRAYS();
    
//----- Default Constructor -----
    {
        longvector v;
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        track_allocator<char> alloc;
        NAMESPACE::vector<char, track_allocator<char> > v(alloc);
        CHECK_AND_PRINT_VECTOR(v);
    }
//----- Size Constructor -----
    {
        intvector v(64, 1);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        intvector v(0, -1);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        strvector v(26, b_string[0]);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        strvector v(0, b_string[32]);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        try {
            const std::size_t max_size = NAMESPACE::vector<std::string>().max_size();
            NAMESPACE::vector<std::string> v(max_size + 1);

            PRINT_MSG("Allocation shouldve failed");
        } catch (std::length_error& e) {
            PRINT_MSG("Length exception");
        }
        CATCH_EXCEPTION();
    }
//----- Range Constructor -----
    {
        doublevector v(s_double, s_double + s_size);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        strvector v1(s_string, s_string + s_size);
        CHECK_AND_PRINT_VECTOR(v1);
        strvector v2(v1.begin(), v1.end());
        CHECK_AND_PRINT_VECTOR(v2);
        if (&v1[0] == &v2[0]) {
            PRINT_MSG("Copy ctor doesn't do a deep copy!");
        }
    }
    {
        std::string str = "Hello World!";
        charvector v(str.begin(), str.end());
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        std::istringstream str("");
        std::istreambuf_iterator<char> it(str), end;
        charvector v(it, end);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        std::istringstream str("1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        std::istreambuf_iterator<char> it(str), end;
        charvector v(it, end);
        CHECK_AND_PRINT_VECTOR(v);
    }
//----- Copy Constructor -----
    {
        doublevector v1(b_double, b_double + b_size);
        CHECK_AND_PRINT_VECTOR(v1);
        doublevector v2(v1);
        CHECK_AND_PRINT_VECTOR(v2);
        if (&v1[0] == &v2[0]) {
            PRINT_MSG("Copy ctor doesn't do a deep copy!");
        }
    }
    {
        strvector v1(b_string, b_string + b_size);
        CHECK_AND_PRINT_VECTOR(v1);
        strvector v2(v1);
        CHECK_AND_PRINT_VECTOR(v2);
        if (&v1[0] == &v2[0]) {
            PRINT_MSG("Copy ctor doesn't do a deep copy!");
        }
    }
    leak_checker::check_all();
}