/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:31:00 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 09:10:01 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_header.hpp"

int main (void) {
    
    SETUP_ARRAYS();

    {
        strset m;

        PRINT_ALL(m);

        m.clear();

        PRINT_ALL(m);

        m.insert(s_string, s_string + s_size);

        PRINT_ALL(m);

        m.clear();

        PRINT_ALL(m);
    }
    leak_checker::check_all();
}