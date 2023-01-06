/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:31:52 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 09:38:04 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void) {
    {
        intset m;

        track_allocator<NAMESPACE::pair<const int, std::string> > alloc = m.get_allocator();

        NAMESPACE::pair<const int, std::string>* buff = alloc.allocate(64);

        alloc.deallocate(buff, 64);
    }
    leak_checker::check_all();
}