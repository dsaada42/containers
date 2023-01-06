/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:27:26 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:35:59 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

int main (void){
    CHECK_TYPEDEF(key_type);
    CHECK_TYPEDEF(mapped_type);
    CHECK_TYPEDEF(value_type);
    CHECK_TYPEDEF(allocator_type);
    CHECK_TYPEDEF(key_compare);
    CHECK_TYPEDEF(size_type);
    CHECK_TYPEDEF(difference_type);
    CHECK_TYPEDEF(pointer);
    CHECK_TYPEDEF(const_pointer);
    CHECK_TYPEDEF(iterator);
    CHECK_TYPEDEF(const_iterator);
    CHECK_TYPEDEF(reverse_iterator);
    CHECK_TYPEDEF(const_reverse_iterator);

    {
        NAMESPACE::map<int, unsigned int>::value_type b = NAMESPACE::map<int, unsigned int>::value_type(-11, 85);
        NAMESPACE::map<int, unsigned int>::reference c = b;
        NAMESPACE::map<int, unsigned int>::const_reference d = b;
        (void)b;
        (void)c;
        (void)d;
    }
    leak_checker::check_all();
}