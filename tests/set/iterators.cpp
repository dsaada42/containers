/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:32:00 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 09:45:43 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void){
    SETUP_ARRAYS();
    {
        intset m;
        PRINT_ALL(m);
    }
    {
        strset m(s_string, s_string + s_size);

        strset::iterator it = m.begin();
        strset::iterator it2 = m.begin();
        strset::const_iterator cit = m.begin();
        strset::const_iterator cit2 = m.begin();

        if (it == it2)
            PRINT_MSG("Equal");
        if (it == cit)
            PRINT_MSG("Equal.");
        if (cit == cit2)
            PRINT_MSG("Equal..");
        if (it != it2)
            PRINT_MSG("Not Equal");
        if (it != cit)
            PRINT_MSG("Not Equal.");
        if (cit != cit2)
            PRINT_MSG("Not Equal..");
        PRINT_IT_PTR(++it);
        PRINT_IT_PTR(++cit);
        if (it == it2)
            PRINT_MSG("Equal...");
        if (it == cit)
            PRINT_MSG("Equal....");
        if (cit == cit2)
            PRINT_MSG("Equal.....");
        if (it != it2)
            PRINT_MSG("Not Equal...");
        if (it != cit)
            PRINT_MSG("Not Equal....");
        if (cit != cit2)
            PRINT_MSG("Not Equal.....");
        ++it2;
        if (it == it2)
            PRINT_MSG("Equal........");
        --it;
        --it2;
        if (it == it2)
            PRINT_MSG("Equal.........");
    }
    {
        intset m(s_int, s_int + s_size);

        intset::iterator it = m.begin();
        intset::iterator it2 = m.begin();
        intset::const_iterator cit = m.begin();
        intset::const_iterator cit2 = m.begin();

        PRINT_ALL(m);
        PRINT_IT_PTR(m.begin());
        PRINT_LINE("It:", *it);
        PRINT_IT_PTR(++it);
        PRINT_IT_PTR(it2++);
        PRINT_LINE("It:", *it++);
        PRINT_IT_PTR(cit++);
        PRINT_IT_PTR(cit2++);
        PRINT_IT_PTR(++cit);
        PRINT_IT_PTR(++cit2);
        PRINT_IT_PTR(it2);
        PRINT_IT_PTR(cit2);
        PRINT_IT_PTR(it++);
        PRINT_IT_PTR(it++);
        PRINT_IT_PTR(it++);
        PRINT_IT_PTR(it2++);
        PRINT_IT_PTR(it2++);
        PRINT_IT_PTR(++it2);
        PRINT_LINE("It:", *cit);
        PRINT_LINE("It:", *cit--);
        PRINT_LINE("It:", *it--);
        PRINT_IT_PTR(it--);
        PRINT_IT_PTR(--it);
        PRINT_IT_PTR(--cit2);
        PRINT_IT_PTR(cit2);
        PRINT_LINE("It:", *cit2);
        PRINT_LINE("It:", *it2);
        it = it2;
        PRINT_LINE("It:", *it);
        PRINT_LINE("It:", *it2);
        cit = cit2;
        PRINT_LINE("It:", *cit);
        PRINT_LINE("It:", *cit2);
    }
    leak_checker::check_all();
}