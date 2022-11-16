#ifndef VECTOR2_HPP
# define VECTOR2_HPP

template < typename T, typename Allocator = std::allocator<T> >
class vector2 {
    public:
        //(1) Default constructor. Constructs an empty container with a default-constructed allocator.
        vector();
        //(2) Constructs an empty container with the given allocator alloc.
        explicit vector( const Allocator& alloc );
        //(3) Constructs the container with count copies of elements with value value.
        explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator());
        //(4)) Constructs the container with the contents of the range [first, last).
        template< class InputIt > vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );   
        //(6) Copy constructor. Constructs the container with the copy of the contents of other.
        vector( const vector& other );

};

#endif