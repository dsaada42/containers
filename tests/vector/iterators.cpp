/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:10 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:23:08 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    SETUP_ARRAYS();

//----- Iterators + operations -----
    {
        intvector v1;
        const intvector v2;

        if (v1.begin() != v1.end())
            PRINT_MSG("Iterator error");
        intvector::const_iterator it = v2.begin();
        if (it != v2.end())
            PRINT_MSG("Iterator error");
    }
    {
        intvector v(b_int, b_int + b_size);
        intvector::iterator it1 = v.begin();
        intvector::iterator it2 = it1;

        PRINT_LINE("It1:", *it1);
        PRINT_LINE("It2:", *it2);
        it1 = v.begin() + 9;
        PRINT_LINE("It1:", *it1);
        it1 = v.end() - 1;
        PRINT_LINE("It1:", *it1);
        it2 = it1;
        PRINT_LINE("It2:", *it2);
        *it1 = -1;
        CHECK_AND_PRINT_VECTOR(v);
    }
    {
        strvector v(b_string, b_string + b_size);
        strvector::iterator it = v.begin();
        strvector::const_iterator cit = v.begin() + 34;

        PRINT_LINE("It:", *it);
        PRINT_LINE("Cit:", *cit);
        it->clear();
        PRINT_LINE("Cstr:", cit->c_str());
        CHECK_AND_PRINT_VECTOR(v);
        ++it;
        ++it;
        ++it;
        ++it;
        ++it;
        ++it;
        ++it;
        it++;
        ++cit;
        cit++;
        PRINT_LINE("It:", *it);
        PRINT_LINE("It:", *it++);
        PRINT_LINE("It:", *it);
        PRINT_LINE("Cit:", *cit);
        PRINT_LINE("Cit:", *cit++);
        PRINT_LINE("Cit:", *cit);
        --it;
        it--;
        it--;
        --cit;
        --cit;
        cit--;
        PRINT_LINE("It:", *it);
        PRINT_LINE("It:", *it--);
        PRINT_LINE("It:", *it);
        PRINT_LINE("Cit:", *cit);
        PRINT_LINE("Cit:", *cit--);
        PRINT_LINE("Cit:", *cit);
        PRINT_LINE("It:", *(it + 6));
        PRINT_LINE("It:", *(42 + it));
        PRINT_LINE("It:", *(42 + it - 3));
        PRINT_LINE("It:", *(v.end() - 6));
        PRINT_LINE("Cit:", *(cit - 6));
        PRINT_LINE("Cit:", *(cit + 7));
        PRINT_LINE("Size:", v.end() - v.begin());
        it = v.begin() + 25;
        cit = v.begin() + 25;
        PRINT_LINE("It:", *it);
        PRINT_LINE("Cit:", *cit);
        it += 12;
        cit += 12;
        PRINT_LINE("It:", *it);
        PRINT_LINE("Cit:", *cit);
        it += 0;
        cit += 0;
        PRINT_LINE("It:", *it);
        PRINT_LINE("Cit:", *cit);
        it += 4;
        cit += 4;
        PRINT_LINE("It:", *it);
        PRINT_LINE("Cit:", *cit);
        it -= 0;
        cit -= 0;
        PRINT_LINE("It:", *it);
        PRINT_LINE("Cit:", *cit);
        it -= 22;
        cit -= 22;
        PRINT_LINE("It:", *it);
        PRINT_LINE("Cit:", *cit);
        PRINT_LINE("It + 10:", it[10]);
        PRINT_LINE("Cit + 10:", cit[10]);
    }
    {
        intvector v(s_int, s_int + s_size);
        intvector::iterator it = v.begin();
        intvector::const_iterator cit(it);
        (void)cit;
    }
//----- Iterators + comparisons -----
    {
        intvector v(b_int, b_int + b_size);

        intvector::iterator it = v.begin();
        intvector::iterator it2 = v.begin();
        intvector::const_iterator cit = v.begin();
        intvector::const_iterator cit2 = v.begin();

        if (it == v.begin())
            PRINT_MSG("Equal iterators")
        if (cit == v.begin())
            PRINT_MSG("Equal const iterators")
        if (cit == it)
            PRINT_MSG("Equal const iterators.")

        ++it;
        cit += 6;

        if (it != v.end())
            PRINT_MSG("Not Equal iterators")
        if (cit != v.end())
            PRINT_MSG("Not Equal const iterators")
        if (cit != it)
            PRINT_MSG("Not Equal const iterators.")

        if (it < it + 1)
            PRINT_MSG("Less than")
        if (it + 1 < it)
            PRINT_MSG("Less than.")
        if (it < it)
            PRINT_MSG("Less than..")
        if (cit < cit + 1)
            PRINT_MSG("Less than...")
        if (cit + 1 < cit)
            PRINT_MSG("Less than....")
        if (cit < cit)
            PRINT_MSG("Less than....")
        if (it2 < cit2 + 1)
            PRINT_MSG("Less than.....")
        if (it2 < cit2)
            PRINT_MSG("Less than......")

        if (it <= it + 1)
            PRINT_MSG("Less than or equal")
        if (it + 1 <= it)
            PRINT_MSG("Less than or equal.")
        if (it <= it)
            PRINT_MSG("Less than or equal..")
        if (cit <= cit + 1)
            PRINT_MSG("Less than or equal...")
        if (cit + 1 <= cit)
            PRINT_MSG("Less than or equal....")
        if (cit <= cit)
            PRINT_MSG("Less than or equal.....")
        if (it2 <= cit2 + 1)
            PRINT_MSG("Less than or equal......")
        if (it2 <= cit2)
            PRINT_MSG("Less than or equal.......")

        if (it > it + 1)
            PRINT_MSG("Greater than")
        if (it + 1 > it)
            PRINT_MSG("Greater than.")
        if (it > it)
            PRINT_MSG("Greater than..")
        if (cit > cit + 1)
            PRINT_MSG("Greater than...")
        if (cit + 1 > cit)
            PRINT_MSG("Greater than....")
        if (cit > cit)
            PRINT_MSG("Greater than....")
        if (it2 + 1 > cit2)
            PRINT_MSG("Greater than.....")
        if (it2 > cit2)
            PRINT_MSG("Greater than......")

        if (it >= it + 1)
            PRINT_MSG("Greater than or equal")
        if (it + 1 >= it)
            PRINT_MSG("Greater than or equal.")
        if (it >= it)
            PRINT_MSG("Greater than or equal..")
        if (cit >= cit + 1)
            PRINT_MSG("Greater than or equal...")
        if (cit + 1 >= cit)
            PRINT_MSG("Greater than or equal....")
        if (cit >= cit)
            PRINT_MSG("Greater than or equal.....")
        if (it2 >= cit2 + 1)
            PRINT_MSG("Greater than or equal......")
        if (it2 + 1 >= cit2)
            PRINT_MSG("Greater than or equal.......")
        if (it2 >= cit2)
            PRINT_MSG("Greater than or equal........")
    }
    leak_checker::check_all();
}