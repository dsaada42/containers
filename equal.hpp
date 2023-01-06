/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:23:34 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 14:23:35 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft{

    template < class Input1, class Input2>
    bool equal(Input1 it1, Input1 it1end, Input2 it2, Input2 it2end){
        while (it1 != it1end){
            if (!(*it1 == *it2))
                return(false);
            it1++;
            it2++;
        }
        if (it2 != it2end)
            return (false);
        return (true);
    }
}
#endif