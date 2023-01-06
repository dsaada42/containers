/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:37:03 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 10:57:20 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

int main(void) {
    SETUP_MAP_ARRAYS();

    {
        intmap m;
        try {
            std::string& x = m.at(6);
            PRINT_LINE("At:", x);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 6);
        }
        CATCH_EXCEPTION();
    }
    {
        intmap m(intstr_arr, intstr_arr + intstr_size);
        m.insert(NAMESPACE::make_pair(64, "64"));
        try {
            std::string& x = m.at(64);

            PRINT_LINE("At:", x);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Wrong out of range exception", 64);
        }
        CATCH_EXCEPTION();
    }
    {
        strmap m(strstr_arr, strstr_arr + strstr_size);
        m.insert(NAMESPACE::make_pair("Hello", "World"));
        try {
            std::string& x = m.at("Hello");

            PRINT_LINE("At:", x);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Wrong out of range exception", "Hello");
        }
        CATCH_EXCEPTION();
    }
    {
        strmap m(strstr_arr, strstr_arr + 1);
        try {
            std::string& x = m.at("");
            PRINT_LINE("At:", x);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", "");
        }
        CATCH_EXCEPTION();
    }
    {
        const intmap m;
        try {
            const std::string& x = m.at(6);
            PRINT_LINE("At:", x);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", 6);
        }
        CATCH_EXCEPTION();
    }
    {
        intmap temp(intstr_arr, intstr_arr + intstr_size);
        temp.insert(NAMESPACE::make_pair(64, "64"));
        const intmap m(temp);
        try {
            const std::string& x = m.at(64);

            PRINT_LINE("At:", x);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Wrong out of range exception", 64);
        }
        CATCH_EXCEPTION();
    }
    {
        strmap temp(strstr_arr, strstr_arr + strstr_size);
        temp.insert(NAMESPACE::make_pair("Hello", "World"));
        const strmap m(temp);
        try {
            const std::string& x = m.at("Hello");

            PRINT_LINE("At:", x);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Wrong out of range exception", "Hello");
        }
        CATCH_EXCEPTION();
    }
    {
        const strmap m(strstr_arr, strstr_arr + 1);
        try {
            const std::string& x = m.at("");
            PRINT_LINE("At:", x);
        } catch (std::out_of_range& e) {
            PRINT_LINE("Out of range exception", "");
        }
        CATCH_EXCEPTION();
    }
    leak_checker::check_all();
}