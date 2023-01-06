/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:22:56 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:29:17 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    SETUP_ARRAYS();

    {
        intvector v;
        v.reserve(64);
        CHECK_AND_PRINT_VECTOR(v);
        v.reserve(64);
        CHECK_AND_PRINT_VECTOR(v);
        v.reserve(0);
        CHECK_AND_PRINT_VECTOR(v);
        v.reserve(45);
        CHECK_AND_PRINT_VECTOR(v);
        v.reserve(65);
        CHECK_AND_PRINT_VECTOR(v);
        v.reserve(79);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        intvector v(s_int, s_int + s_size);
        v.reserve(0);
        CHECK_AND_PRINT_VECTOR(v);
        v.reserve(32);
        CHECK_AND_PRINT_VECTOR(v);
        v.reserve(48);
        CHECK_AND_PRINT_VECTOR(v);
        v.reserve(1);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        NAMESPACE::vector<std::string, track_allocator<std::string> > v;
        try {
            v.reserve(v.max_size() + 1);
            PRINT_MSG("Bad reserve");
        } catch (std::length_error&) {
            PRINT_MSG("Length exception");
        }
        CATCH_EXCEPTION();
    }
    leak_checker::check_all();
}