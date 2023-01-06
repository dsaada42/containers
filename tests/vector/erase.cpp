/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:19 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:06:07 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    SETUP_ARRAYS();

//----- Erase -----
    {
        intvector v(b_int, b_int + b_size - 5);
        intvector::iterator it = v.erase(v.begin() + 26);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        it = v.erase(it);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        it = v.erase(v.end() - 1);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        it = v.erase(v.begin());
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        intvector v(1, 5);
        intvector::iterator it = v.erase(v.begin());
        if (it != v.end())
            PRINT_MSG("Wrong iterator");
        CHECK_AND_PRINT_VECTOR(v);
    }
//----- Erase range -----
    {
        longvector v;
        v.erase(v.begin(), v.end());
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        longvector v(b_int, b_int + b_size);
        v.erase(v.end(), v.end());
        CHECK_AND_PRINT_VECTOR(v);
        v.erase(v.begin() + 5, v.begin() + 5);
        CHECK_AND_PRINT_VECTOR(v);
        v.erase(v.begin() + 26, v.end() - 1);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        intvector v(37, -5);
        v.erase(v.begin() + 1, v.begin() + 2);
        CHECK_AND_PRINT_VECTOR(v);
        v.erase(v.begin(), v.end());
        CHECK_AND_PRINT_VECTOR(v);
    }
//----- Erase mixed -----
    {
        strvector v(b_string, b_string + b_size);
        v.erase(v.begin(), v.begin());
        CHECK_AND_PRINT_VECTOR(v);
        v.erase(v.end(), v.end());
        CHECK_AND_PRINT_VECTOR(v);
        v.erase(v.begin());
        CHECK_AND_PRINT_VECTOR(v);
        v.erase(v.end() - 1);
        CHECK_AND_PRINT_VECTOR(v);
        v.erase(v.begin() + 3, v.begin() + 16);
        CHECK_AND_PRINT_VECTOR(v);
        strvector::iterator it = v.erase(v.begin() + 9);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        v.erase(v.begin(), v.end());
        CHECK_AND_PRINT_VECTOR(v);
    }
    leak_checker::check_all();
}
