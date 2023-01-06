/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:36:24 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 11:44:42 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_header.hpp"

struct abc {
    int data[1024];
    long num;
};

int main (void){
    int size;
    
    size = NAMESPACE::map<int, unsigned char>().max_size();
    PRINT_LINE("<Int, Unsigned Char> max size:", size);
    size = NAMESPACE::map<int, char>().max_size();
    PRINT_LINE("<Int, Char> max size:", size );
    size = NAMESPACE::map<int, int>().max_size();
    PRINT_LINE("<Int, Int> max size:", size );
    size = NAMESPACE::map<int, long>().max_size();
    PRINT_LINE("<Int, Long> max size:", size);
    size = NAMESPACE::map<int, short>().max_size();
    PRINT_LINE("<Int, Short> max size:", size);
    size = NAMESPACE::map<int, abc>().max_size();
    PRINT_LINE("<Int, abc struct> max size:", size);
    size = NAMESPACE::map<int, float>().max_size();
    PRINT_LINE("<Int, Float> max size:", size);
    leak_checker::check_all();
}