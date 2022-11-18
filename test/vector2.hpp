#ifndef VECTOR2_HPP
# define VECTOR2_HPP
# include <memory>

template < typename T, typename Allocator = std::allocator< T > >
class vector2 {
    public:
        typedef T                                       value_type;
        typedef Alloc                                   allocator_type;
        typedef size_t                                  size_type;
        typedef ptrdiff_t                               difference_type;
        typedef value_type&                             reference;
        typedef const value_type&                       const_reference;
        typedef allocator_type::pointer                 pointer;
        typedef allocator_type::const_pointer           const_pointer;
        typedef std::iterator<T>                        iterator;//random access iterator convertible to const iterator
        typedef std::iterator<const T>                  const_iterator;
        typedef std::reverse_iterator<iterator>         reverse_iterator;
        typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;
    
    private:
        value_type* _data;
        size_type   _size;
        size_type   __capacity;

    //***** CONSTRUCTORS *****
        //(1) Default constructor. Constructs an empty container with a default-constructed allocator.
        vector(){
            _size = 0;
            __capacity = 0;
            _data = (value_type*)::operator new(sizeof(value_type));
        }
        //(2) Constructs an empty container with the given allocator alloc.
        explicit vector( const Allocator& alloc ){}
        //(3) Constructs the container with count copies of elements with value value.
        explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()){}
        //(4)) Constructs the container with the contents of the range [first, last).
        template< class InputIt > vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ){}   
        //(6) Copy constructor. Constructs the container with the copy of the contents of other.
        vector( const vector& other ){}
    //***** DESTRUCTOR *****
        ~vector(){}
        //***** OPERATOR= *****
        vector& operator=( const vector& other ){}
    //***** ASSIGN *****
        void assign( size_type count, const T& value ){}
        template< class InputIt > void assign( InputIt first, InputIt last ){}
    //***** ELEMENT ACCESS *****
        reference at( size_type pos ){}
        const_reference at( size_type pos ) const{}
        reference operator[]( size_type pos ){}
        const_reference operator[]( size_type pos ) const{}
        reference front(){}
        const_reference front() const{}
        reference back(){}
        const_reference back() const{}
        T* data(){}
        const T* data() const{}
    //***** ITERATORS *****
        iterator begin(){}
        const_iterator begin() const{}
        iterator end(){}
        const_iterator end() const{}
        reverse_iterator rbegin(){}
        const_reverse_iterator rbegin() const{}
        reverse_iterator rend(){}
        const_reverse_iterator rend() const{}
    //***** CAPACITY *****
        bool empty() const{}
        size_type size() const{}
        size_type max_size() const{}
        void reserve( size_type new_cap ){}
        size_type capacity() const{}
    //***** MODIFIERS *****
        void clear(){}
        iterator insert( const_iterator pos, const T& value ){}
        iterator insert( const_iterator pos, size_type count, const T& value ){}
        template< class InputIt > iterator insert( const_iterator pos, InputIt first, InputIt last ){}
        iterator erase( iterator pos ){}
        iterator erase( iterator first, iterator last ){}
        void push_back( const T& value ){}
        void pop_back(){}
        void resize( size_type count ){}
        void resize( size_type count, T value = T()){}
        void swap( vector& other ){}

};

template< class T, class Alloc > bool operator==( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs ){}
template< class T, class Alloc > bool operator!=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs ){}
template< class T, class Alloc > bool operator<( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs ){}
template< class T, class Alloc > bool operator<=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs ){}
template< class T, class Alloc > bool operator>( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs ){}
template< class T, class Alloc > bool operator>=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs ){}

template< class T, class Alloc > void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs ){}

#endif