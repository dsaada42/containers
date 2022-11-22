#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft{

    //Enable if
    template <bool condition, class T = void>
    struct enable_if{};
    template <class T>
    struct enable_if<true, T> { typedef T type; }; //If true we use T , otherwise nothing 
    //Conditional
    template <bool condition, class T = void , class U = void >
    struct conditional {};
    template <class T, class U>
    struct conditional<true, T, U> { typedef T type; }; //If condition is true we use T
    template <class T, class U>
    struct conditional<false, T, U> { typedef U type; }; //If condition is false we use U 
}

#endif