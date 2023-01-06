/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:22:48 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:53:24 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    SETUP_ARRAYS();

    {
        strvector v1(s_string, s_string + s_size);
        strvector v2(b_string, b_string + b_size);

        v1.swap(v2);
        CHECK_AND_PRINT_VECTOR(v1);
        CHECK_AND_PRINT_VECTOR(v2);
        NAMESPACE::swap(v1, v2);
        CHECK_AND_PRINT_VECTOR(v1);
        CHECK_AND_PRINT_VECTOR(v2);
        v1.resize(0);
        v1.swap(v2);
        CHECK_AND_PRINT_VECTOR(v1);
        CHECK_AND_PRINT_VECTOR(v2);
        v1.resize(0);
        NAMESPACE::swap(v1, v2);
        CHECK_AND_PRINT_VECTOR(v1);
        CHECK_AND_PRINT_VECTOR(v2);
    }
    leak_checker::check_all();
}