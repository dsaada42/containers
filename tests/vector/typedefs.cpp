/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 07:54:46 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 07:55:45 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){

    CHECK_TYPEDEF(value_type);
    CHECK_TYPEDEF(allocator_type);
    CHECK_TYPEDEF(size_type);
    CHECK_TYPEDEF(difference_type);
    CHECK_TYPEDEF(pointer);
    CHECK_TYPEDEF(const_pointer);
    CHECK_TYPEDEF(iterator);
    CHECK_TYPEDEF(const_iterator);
    CHECK_TYPEDEF(reverse_iterator);
    CHECK_TYPEDEF(const_reverse_iterator);

    {
        NAMESPACE::vector<int>::value_type a = 10;
        NAMESPACE::vector<int>::reference b = a;
        NAMESPACE::vector<int>::const_reference c = a;
        (void)a;
        (void)b;
        (void)c;
    }
    
    leak_checker::check_all();
}