/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_tracker.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:21:38 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/04 15:38:15 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_TRACKER_HPP
# define MEMORY_TRACKER_HPP

# include <map>
# include <set>
# include <cstddef>
# include <iostream>

class memory_tracker{
    public:
        typedef std::size_t                     size_type;
        typedef std::map<void*, size_type>      alloc_tracker_type;
        typedef std::set<void*>                 construct_tracker_type;

    public:
        static size_type                allocs_count();
        static bool                     allocs_empty();
        static void                     track_allocate(void* ptr, size_type size);
        static void                     track_deallocate(void* ptr, std::size_t size);
        static size_type                constructs_count();
        static bool                     constructs_empty();
        static bool                     track_construct(void* ptr);
        static bool                     track_destroy(void* ptr);
    private:
        static alloc_tracker_type       allocs;
        static construct_tracker_type   constructs;
};      

#endif