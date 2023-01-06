/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:22:58 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:27:33 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    {
        doublevector v;

        for (int i = 0; i < 26; ++i) {
            v.push_back(45.0123);
            CHECK_AND_PRINT_VECTOR(v);
        }
        v.push_back(6);
        CHECK_AND_PRINT_VECTOR(v);
        v.push_back(-4356.8933);
        CHECK_AND_PRINT_VECTOR(v);
    }
    leak_checker::check_all();
}