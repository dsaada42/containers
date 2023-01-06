/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 07:57:33 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 08:56:41 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_header.hpp"

int main (void){
    CHECK_TYPEDEF(value_type);
    CHECK_TYPEDEF(container_type);
    CHECK_TYPEDEF(size_type);
    leak_checker::check_all();
}