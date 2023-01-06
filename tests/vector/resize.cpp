/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:22:53 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:30:46 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    SETUP_ARRAYS();

    {
        strvector v;
        v.resize(14, "HelloWorld");
        CHECK_AND_PRINT_VECTOR(v);
        v.resize(6, "ABC");
        CHECK_AND_PRINT_VECTOR(v);
        v.resize(14, b_string[18]);
        CHECK_AND_PRINT_VECTOR(v);
        v.resize(15, b_string[57]);
        CHECK_AND_PRINT_VECTOR(v);
        v.resize(64, "I-like-vectors");
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        NAMESPACE::vector<std::string, track_allocator<std::string> > v;

        try {
            v.resize(v.max_size() + 1);
            PRINT_MSG("Bad reserve");
        } catch (std::length_error&) {
            PRINT_MSG("Length exception");
        }
        CATCH_EXCEPTION();
    }
    leak_checker::check_all();
}