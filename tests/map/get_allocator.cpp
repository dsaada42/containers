/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:15:42 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:22:15 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

int main (void){
    {
        intmap m;

        track_allocator<NAMESPACE::pair<const int, std::string> > alloc = m.get_allocator();

        NAMESPACE::pair<const int, std::string>* buff = alloc.allocate(64);

        alloc.deallocate(buff, 64);
    }
    leak_checker::check_all();
}