/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:28 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 10:52:25 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    {
        intvector v;

        CHECK_AND_PRINT_VECTOR(v);
        v.clear();
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        intvector v(1, 64);

        CHECK_AND_PRINT_VECTOR(v);
        v.clear();
        CHECK_AND_PRINT_VECTOR(v);
        v.clear();
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        intvector v(64, 420);

        CHECK_AND_PRINT_VECTOR(v);
        v.clear();
        CHECK_AND_PRINT_VECTOR(v);
        v.clear();
        CHECK_AND_PRINT_VECTOR(v);
    }
    leak_checker::check_all();
}