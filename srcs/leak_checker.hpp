/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_checker.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:06:28 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/04 16:08:14 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEAK_CHECKER_HPP
# define LEAK_CHECKER_HPP
# include "memory_tracker.hpp"

class leak_checker{
    public:
        static void check_leaks();
        static void check_alive_objects();
        static void check_all();
    private:
        static memory_tracker tracker;  
};

#endif