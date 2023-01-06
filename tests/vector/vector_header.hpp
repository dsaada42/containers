/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_header.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:19:53 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 08:14:13 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HEADER_HPP
# define VECTOR_HEADER_HPP

#include "../header.hpp"
#include "vector.hpp"
#include <vector>

#define PRINT_VECTOR(vector){                                           \
    std::cout << "==================== VECTOR ====================\n";  \
    std::cout << " size     = " << vector.size() << "\n";               \
    std::cout << "___ Elements ___\n";                                  \
    print_range(vector.begin(), vector.end());                          \
}

#define CHECK_AND_PRINT_VECTOR(vector){                             \
    if (vector.capacity() < vector.size())                          \
        std::cout << "Error: capacity < size";                      \
    else                                                            \
        std::cout << "Capacity ok";                                 \
    PRINT_FILE_LINE();                                              \
    PRINT_VECTOR(vector);                                           \
}

#define CHECK_TYPEDEF(type)                                                                        \
    {                                                                                              \
        NAMESPACE::vector<int>::type a = NAMESPACE::vector<int>::type();                           \
        (void)a;                                                                                   \
    }
    
typedef NAMESPACE::vector<std::string, track_allocator<std::string> > strvector;
typedef NAMESPACE::vector<int, track_allocator<int> > intvector;
typedef NAMESPACE::vector<long, track_allocator<long> > longvector;
typedef NAMESPACE::vector<double, track_allocator<double> > doublevector;
typedef NAMESPACE::vector<char, track_allocator<char> > charvector;

#endif