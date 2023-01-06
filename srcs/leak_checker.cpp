/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_checker.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:08:26 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/04 16:09:17 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leak_checker.hpp"
#include <iostream>

void leak_checker::check_leaks()
{
    if (tracker.allocs_empty()) {
        std::cout << "========================================\n";
        std::cout << "No leak detected\n";
        std::cout << "========================================" << std::endl;
    } else {
        std::cout << "========================================\n";
        std::cout << tracker.allocs_count() << " Leak(s) detected\n";
        std::cout << "========================================" << std::endl;
    }
}

void leak_checker::check_alive_objects()
{
    if (tracker.constructs_empty()) {
        std::cout << "========================================\n";
        std::cout << "Every objects destroyed\n";
        std::cout << "========================================" << std::endl;
    } else {
        std::cout << "========================================\n";
        std::cout << tracker.constructs_count() << " Alive object(s)\n";
        std::cout << "========================================" << std::endl;
    }
}

void leak_checker::check_all()
{
    check_leaks();
    check_alive_objects();
}

memory_tracker leak_checker::tracker = memory_tracker();