/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterators.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:57:04 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 09:58:51 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main ( void) {
    SETUP_ARRAYS();

    {
        intset m;
        PRINT_ALL(m);
    }
    {
        strset m(s_string, s_string + s_size);
        strset::reverse_iterator it = m.rbegin();
        strset::reverse_iterator it2 = m.rbegin();
        strset::const_reverse_iterator cit = m.rbegin();
        strset::const_reverse_iterator cit2 = m.rbegin();
        
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
        intset::reverse_iterator it = m.rbegin();
        intset::reverse_iterator it2 = m.rbegin();
        intset::const_reverse_iterator cit = m.rbegin();
        intset::const_reverse_iterator cit2 = m.rbegin();

        for (intset::reverse_iterator i = m.rbegin(); i != m.rend(); ++i)
            PRINT_LINE("It:", *i);
        PRINT_ALL(m);
        PRINT_IT_PTR(m.rbegin());
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