/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:36 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 10:43:11 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){

    {
        charvector v(64, 'a');

        try {
            charvector::reference c = v.at(38);

            PRINT_LINE("At:", c);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Wrong out of range exception", 38);
        }
        CATCH_EXCEPTION();
    }
    {
        intvector v(99, 64);

        try {
            intvector::reference c = v.at(99);

            PRINT_LINE("At:", c);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 99);
        }
        CATCH_EXCEPTION();
    }
    {
        longvector v;

        try {
            longvector::reference c = v.at(0);

            PRINT_LINE("At:", c);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 0);
        }
        CATCH_EXCEPTION();
    }
    {
        const charvector v(64, 'a');

        try {
            charvector::const_reference c = v.at(38);

            PRINT_LINE("At:", c);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Wrong out of range exception", 38);
        }
        CATCH_EXCEPTION();
    }
    {
        const intvector v(99, 64);

        try {
            intvector::const_reference c = v.at(99);

            PRINT_LINE("At:", c);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 99);
        }
        CATCH_EXCEPTION();
    }
    {
        const longvector v;

        try {
            longvector::const_reference c = v.at(0);

            PRINT_LINE("At:", c);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 0);
        }
        CATCH_EXCEPTION();
    }
    leak_checker::check_all();
}