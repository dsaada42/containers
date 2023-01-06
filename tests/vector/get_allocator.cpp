/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:14 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:07:52 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

int main (void){
    intvector v;

    track_allocator<int> alloc = v.get_allocator();

    int* buff = alloc.allocate(2048 * 5);
    alloc.deallocate(buff, 2048 * 5);

    std::cout << "a leak is normal here\n";
    leak_checker::check_all();
}