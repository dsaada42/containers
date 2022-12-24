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
    //Is Same 
    template <class T, class U>
    struct is_same { static const bool boolean = false;}; //If two different classes, return false
    template <class T>
    struct is_same<T, T> { static const bool boolean = true;}; //If twice same type, return true
    //Is Integral
    template <class T, T val>
    struct integral_constant{
        static const T                  value = val;
        T                               value_type;
        typedef integral_constant<T, val>  type;
    };

    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>  false_type;

    template<class T> struct is_integral: public false_type {};

    template<class T> struct is_integral< const T >             :   public is_integral<T> {};
    template<class T> struct is_integral< volatile const T >    :   public is_integral<T> {};
    template<class T> struct is_integral< volatile T >          :   public is_integral<T> {};
    template<> struct is_integral< unsigned char >              :   true_type {};
    template<> struct is_integral< unsigned int >               :   true_type {};
    template<> struct is_integral< unsigned short >             :   true_type {};
    template<> struct is_integral< unsigned long >              :   true_type {};
    template<> struct is_integral< unsigned long long >         :   true_type {};
    template<> struct is_integral< signed char >                :   true_type {};
    template<> struct is_integral< const signed char >          :   true_type {};
    template<> struct is_integral< volatile signed char >       :   true_type {};
    template<> struct is_integral< const volatile signed char > :   true_type {};    
    template<> struct is_integral< char >                       :   true_type {};
    template<> struct is_integral< short >                      :   true_type {};
    template<> struct is_integral< int >                        :   true_type {};
    template<> struct is_integral< long >                       :   true_type {};
    template<> struct is_integral< long long >                  :   true_type {};
    template<> struct is_integral< bool >                       :   true_type {};

}

#endif