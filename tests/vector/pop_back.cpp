/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:00 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:27:42 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    SETUP_ARRAYS();

    {
        longvector v(s_long, s_long + s_size);
        v.pop_back();
        CHECK_AND_PRINT_VECTOR(v);
        for (int i = 0; i < 10; ++i) {
            v.pop_back();
        }
        CHECK_AND_PRINT_VECTOR(v);
    }
    leak_checker::check_all();
}