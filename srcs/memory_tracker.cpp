/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_tracker.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:21:35 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/04 15:51:14 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_tracker.hpp"
 //----- ALLOCATOR TRACKER -----
std::size_t      memory_tracker::allocs_count()                              { return (allocs.size()); }
bool             memory_tracker::allocs_empty()                              { return (allocs.empty()); }
void             memory_tracker::track_allocate(void* ptr, size_type size)   { allocs.insert(std::make_pair(ptr, size));}
void             memory_tracker::track_deallocate(void* ptr, size_type size) {
    alloc_tracker_type::iterator it = allocs.find(ptr);
    if (it == allocs.end()){
        std::cout << "Tried to deallocate on uninitialized memory" << std::endl;
        return;
    }
    else if (it->second != size){
        std::cout << "Tried to deallocate on valid pointer with wrong size" << std::endl;
        return;
    }
    allocs.erase(it);
}
//----- CONSTRUCTOR TRACKER -----
std::size_t     memory_tracker::constructs_count()                          { return (constructs.size()); }
bool            memory_tracker::constructs_empty()                          { return (constructs.empty()); } 
bool            memory_tracker::track_construct(void* ptr)                  { 
    construct_tracker_type::iterator it = constructs.find(ptr);

    if (it != constructs.end())
        return (false);
    constructs.insert(ptr);
    return true;
}
bool            memory_tracker::track_destroy(void* ptr)                    {
    construct_tracker_type::iterator it = constructs.find(ptr);

    if (it == constructs.end())
        return (false);
    constructs.erase(ptr);
    return (true);
}

std::map<void*, std::size_t> memory_tracker::allocs = std::map<void*, std::size_t>();
std::set<void*> memory_tracker::constructs = std::set<void*>();