/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:00:46 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 10:05:06 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main(void){
    CHECK_TYPEDEF(key_type);
    CHECK_TYPEDEF(value_type);
    CHECK_TYPEDEF(allocator_type);
    CHECK_TYPEDEF(key_compare);
    CHECK_TYPEDEF(value_compare);
    CHECK_TYPEDEF(size_type);
    CHECK_TYPEDEF(difference_type);
    CHECK_TYPEDEF(pointer);
    CHECK_TYPEDEF(const_pointer);
    CHECK_TYPEDEF(iterator);
    CHECK_TYPEDEF(const_iterator);
    CHECK_TYPEDEF(reverse_iterator);
    CHECK_TYPEDEF(const_reverse_iterator);

    {
        NAMESPACE::set<int>::value_type b = NAMESPACE::set<int>::value_type(-11);
        NAMESPACE::set<int>::reference c = b;
        NAMESPACE::set<int>::const_reference d = b;
        (void)b;
        (void)c;
        (void)d;
    }   
    leak_checker::check_all();
}