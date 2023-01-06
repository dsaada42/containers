/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:32:09 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:48:17 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void){
    int size;
    
    size = NAMESPACE::set< unsigned char>().max_size();
    PRINT_LINE("< Unsigned Char> max size:", size);
    size = NAMESPACE::set< char>().max_size();
    PRINT_LINE("< Char> max size:", size );
    size = NAMESPACE::set< int>().max_size();
    PRINT_LINE("< Int> max size:", size );
    size = NAMESPACE::set< long>().max_size();
    PRINT_LINE("< Long> max size:", size);
    size = NAMESPACE::set< short>().max_size();
    PRINT_LINE("< Short> max size:", size);
    size = NAMESPACE::set< float>().max_size();
    PRINT_LINE("< Float> max size:", size);
    leak_checker::check_all();
}