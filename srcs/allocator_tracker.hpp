/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator_tracker.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:18:55 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/05 11:58:23 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_TRACKER_HPP
# define ALLOCATOR_TRACKER_HPP
# include <memory>
# include "memory_tracker.hpp"

template <class T>
class track_allocator{
    public:
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef const T*                        const_pointer;
        typedef T&                              reference;
        typedef const T&                        const_reference;
        typedef std::size_t                     size_type;
        typedef std::ptrdiff_t                  difference_type;
        typedef std::allocator<T>               std_alloc;

    public:
        template <typename U>
        struct rebind {
            typedef track_allocator<U> other;
        };
        
        track_allocator()                                           {}
        track_allocator(const track_allocator &)                    {}
        template <typename U>
        track_allocator(const track_allocator<U> &)                 {}
        ~track_allocator()                                          {}

        bool operator==(const track_allocator&)                     { return true; }
        bool operator!=(const track_allocator&)                     { return false; }
        pointer         address(reference x) const                  { return (&x); }
        const_pointer   address(const_reference x)                  { return (&x); }
    //----- ALLOCATE ----- 
        pointer         allocate(size_type n, const void* hint = 0) {
            pointer ptr = std_alloc().allocate(n, hint);
            tracker.track_allocate((void*)ptr, n);
            return (ptr);
        }
    //----- DEALLOCATE -----
        void            deallocate(pointer ptr, size_type n)        {
            if (ptr == NULL)
                std::cout << "Tried to deallocate null pointer" << std::endl;
            tracker.track_deallocate(ptr, n);
            std_alloc().deallocate(ptr, n);
        }
    //----- MAX_SIZE -----
        size_type       max_size() const                            { return (std_alloc().max_size()); }
    //----- CONSTRUCT -----   
        void            construct(pointer ptr, const_reference val) {
            if (ptr == NULL)
                std::cout << "Tried to construct on null pointer" << std::endl;
            if (tracker.track_construct((void*)ptr) == false)
                std::cout << "Tried to construct on initialized memory" << std::endl;
            std_alloc().construct(ptr, val);
        }
    //----- DESTROY -----   
        void            destroy(pointer ptr)                        {
            if (ptr == NULL)
                std::cout << "Tried to destroy on null pointer" << std::endl;
            if (tracker.track_destroy((void*)ptr) == false)
                std::cout << "Tried to destroy on uninitialized memory" << std::endl;
            std_alloc().destroy(ptr);
        }
        
    private:
        memory_tracker  tracker;
};

#endif