/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_header.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:14:45 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 14:31:43 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HEADER_HPP
# define SET_HEADER_HPP

# include "../header.hpp"
# include "set.hpp"
# include <set>

#define PRINT_SET(set){                                           \
    std::cout << "==================== SET ====================\n";  \
    std::cout << " size     = " << set.size() << "\n";               \
    std::cout << "___ Elements ___\n";                                  \
    print_range(set.begin(), set.end());                          \
}

#define CHECK_TYPEDEF(type)                                                                        \
    {                                                                                              \
        NAMESPACE::set<int>::type a = NAMESPACE::set<int>::type();                                 \
        (void)a;                                                                                   \
    }
    
#define PRINT_ALL(set)                                                                             \
    {                                                                                              \
        PRINT_FILE_LINE();                                                                         \
        PRINT_SET(set);                                                                            \
    }

#define PRINT_BOUND(b, end)                                                                        \
    {                                                                                              \
        if (b != end) {                                                                            \
            PRINT_LINE("Value:", *b);                                                              \
        } else {                                                                                   \
            PRINT_MSG("End iterator");                                                             \
        }                                                                                          \
        std::cout << std::endl;                                                                    \
    }

#define PRINT_EQ_RANGE(p, end)                                                                     \
    {                                                                                              \
        std::cout << "--------------------------------\n";                                         \
        PRINT_BOUND(p.first, end);                                                                 \
        PRINT_BOUND(p.second, end);                                                                \
    }

#define PRINT_IT_PTR(it)                                                                           \
    {                                                                                              \
        PRINT_LINE("It:", *(it));                                                                  \
    }

template <typename T>
void init_set_array(T* arr, std::size_t size)
{
    iota(arr, arr + size, (T)rand());
}

#define SETUP_SET_ARRAY(type, name, size)                                                              \
    type name[size];                                                                               \
    init_set_array(name, size);

#define SETUP_SET_ARRAYS()                                                                             \
    SETUP_SET_ARRAY(int, int_arr, 64);                                                                 \
    std::size_t int_size = 64;                                                                     \
    std::size_t str_size = 32;                                                                     \
    (void)int_size;                                                                                \
    (void)str_size;                                                                                \
    std::string str_arr[32] = {                                                                    \
        "QExoqp0nICr0sXsHqty2", "naax9QcpJhvaL7DezsNQ", "25ZTtB6wbptfbxM8AvHB",                    \
        "tShYNtc0MkdjqLrOatgz", "7Z3kf1Qec0NnsLSEpbOt", "WhkSNrKJC966fvjZ2Or1",                    \
        "8vlxlFRRgW7yYj4GO7dt", "5sq1aoT8zP0HaHj3nFOK", "61Dv31GYZhkgjKCErpng",                    \
        "l0IIcWWHhOcPzoxEamQM", "bE1RYclskwXlhCm46YFs", "kXeoi5qz94JYPqSDTs79",                    \
        "TFsQP1dz8VVos9KzUpY0", "b3wYQR7An193gjgYuRj3", "xSmyNsnSJ47jLqrvbpyr",                    \
        "guAIP2Wq43Gf8VhHsyu5", "yT6c2loPebHovnq9BQog", "3qvU1xcVm2g1DKFDlqh4",                    \
        "L0q8RR9P41VD4sVjdnWl", "YdjESsIZM4b1oGQPjpBe", "l1ZVQbWKw7brHUSimJgq",                    \
        "xdn0cf4vqRzpfXWtl10G", "lYnZvpqaV0s8DowMZwzV", "8P1cyKrwJNLoJyvLjYqO",                    \
        "4MhOXNbAX23CEijO5cRT", "tHe3miAwCOVQbuoLaEP2", "l6uNLsc8fiLl3eWoG6j6",                    \
        "477xt6l0lph9ALQdr4HX", "D9UJNe4s8YF02LhrwOdl", "dLCisBNOdE8yugntu6cj",                    \
        "YvY4aQFHgAuagn4dFLO1", "eGR6Dtv7LW75qlV5Fkik"                                             \
    };                                                                                             \
    (void)str_arr;


typedef NAMESPACE::set<int, std::less<int>, track_allocator<int> > intset;
typedef NAMESPACE::set<std::string, std::less<std::string>, track_allocator<std::string> > strset;


#endif


