/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:23:07 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:25:50 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_header.hpp"

struct abc {
    int data[1024];
    long num;
};

int main (void){
    PRINT_LINE("Unsigned Char max size:", NAMESPACE::vector<unsigned char>().max_size());
    PRINT_LINE("Char max size:", NAMESPACE::vector<char>().max_size());
    PRINT_LINE("Int max size:", NAMESPACE::vector<int>().max_size());
    PRINT_LINE("Long max size:", NAMESPACE::vector<long>().max_size());
    PRINT_LINE("Short max size:", NAMESPACE::vector<short>().max_size());
    PRINT_LINE("abc struct max size:", NAMESPACE::vector<abc>().max_size());
    PRINT_LINE("Float max size:", NAMESPACE::vector<float>().max_size());
    leak_checker::check_all();
}