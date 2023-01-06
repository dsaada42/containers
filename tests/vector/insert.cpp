/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:12 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:20:13 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    SETUP_ARRAYS();

//----- Insert -----
    {
        strvector v;
        strvector::iterator it = v.insert(v.end(), b_string[54]);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        it = v.insert(v.end(), b_string[23]);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        it = v.insert(v.begin(), b_string[19]);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        it = v.insert(v.begin() + 1, b_string[0]);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        it = v.insert(v.begin() + 1, b_string[1]);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        it = v.insert(v.begin() + 2, b_string[2]);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        it = v.insert(v.begin() + 3, b_string[3]);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        it = v.insert(v.begin() + 2, b_string[4]);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        it = v.insert(v.end(), b_string[5]);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        intvector v;
        intvector::iterator it = v.insert(v.begin(), 64);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        it = v.insert(v.end(), 420);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
    }
//----- Insert size -----
    {
        intvector v;

        v.insert(v.begin(), 0, 64);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.end(), 0, 64);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.end(), 10, 64);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin(), 5, -1);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin() + 1, 1, -9);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin() + 7, 21, 88);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin(), 0, 2);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.end(), 0, 4);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.end(), 18, 420);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        strvector v(5000, "Test");
        
        try {
            v.insert(v.begin() + 115, (std::size_t)std::numeric_limits<std::ptrdiff_t>::max(),
                     "123");
        } catch (std::length_error&) {
            PRINT_MSG("Length exception");
        }
        CATCH_EXCEPTION();
    }
//----- Insert range -----
    {
        strvector v;

        v.insert(v.begin(), v.begin(), v.begin());
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin(), v.begin(), v.end());
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.end(), v.begin(), v.end());
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin(), s_string, s_string + s_size);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin(), b_string, b_string + 10);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin() + 20, b_string, b_string + b_size);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.end(), b_string + 10, b_string + 15);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        std::list<int> li(s_int, s_int + s_size);
        intvector v(5, 1);

        v.insert(v.begin() + 3, li.begin(), li.end());
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        std::istringstream str("1 2 3 4 5 6 7 8 9 0 A B C D E F");
        std::istreambuf_iterator<char> it(str), end;
        charvector v(2, 'U');

        v.insert(v.end(), it, end);
        CHECK_AND_PRINT_VECTOR(v);
    }
//----- Insert mixed -----
    {
        intvector v;

        v.insert(v.end(), s_int, s_int + s_size - 10);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin() + 5, 9, -1);
        CHECK_AND_PRINT_VECTOR(v);
        intvector::iterator it = v.insert(v.begin(), 64);
        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_VECTOR(v);
        for (int i = 0; i < 23; ++i) {
            it = v.insert(v.begin() + i + 2, i);
            PRINT_LINE("It:", *it);
            CHECK_AND_PRINT_VECTOR(v);
        }
        v.insert(v.end(), 12, 42);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin() + 12, b_int, b_int + b_size);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin(), 69);
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        strvector v;

        v.insert(v.end(), s_string, s_string + s_size);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.end() - 10, b_string, b_string + b_size);
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin(), "Hello");
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin() + 1, "World");
        CHECK_AND_PRINT_VECTOR(v);
        v.insert(v.begin() + 2, 9, "!");
        CHECK_AND_PRINT_VECTOR(v);
    }
    leak_checker::check_all();
}