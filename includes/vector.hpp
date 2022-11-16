#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft {

    template < class T, class Alloc = allocator<T> >
    class vector{

        typedef T                                       value_type;
        typedef Alloc                                   allocator_type;
        typedef allocator_type::reference               reference;
        typedef allocator_type::const_reference         const_reference;
        typedef allocator_type::pointer                 pointer;
        typedef allocator_type::const_pointer           const_pointer;
        typedef std::iterator<T>                        iterator;//random access iterator convertible to const iterator
        typedef std::iterator<const T>                  const_iterator;
        typedef reverse_iterator<iterator>              reverse_iterator;
        typedef reverse_iterator<const_iterator>        const_reverse_iterator;
        typedef ptrdiff_t                               difference_type;
        typedef size_t                                  size_type;

        private:
            T* _data;
            size_type _size = 0;
            size_type _capacity = 0;

        public:
        //*****CONSTRUCTOR DESTRUCTOR*****
            //____default constructor : constructs an empty container, no elements
            explicit vector (const allocator_type& alloc = allocator_type()); 
            //____fill constructor : constructs a container with n elements, each is a copy of val  
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); 
            //____range constructor : constructs a container with as many elements as the range [first,last)
            template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); 
            //____copy constructor___
            vector (const vector& x); 
            ~vector< T , Alloc >( void );
            //____opertor= surcharge___
            vector& operator= (const vector& x);

        //******ITERATORS*****
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            reverse_iteraor rbegin();
            const_reverse_iterator rbegin() const;
            reverse_iteraor rend();
            const_reverse_iterator rend() const;
            const_iterator cbegin() const;
            const_iterator cend() const;
            const_reverse_iterator crbegin() const;
            const_reverse_iterator crend() const;

        //*****CAPACITY*****
            size_type size() const;
            size_type max_size() const;
            void resize (size_type n, value_type val = value_type());
            size_type capacity() const;
            bool empty() const;
            void reserve (size_type n);

        //*****ELEMENT ACCESS*****
            reference operator[] (size_type n);
            const_reference operator[] (size_type n) const;
            reference at (size_type n);
            const_reference at (size_type n) const;
            reference front();
            const_reference front() const;
            reference back();
            const_reference back() const;
            value_type* data();
            const value_type* data() const;

        //*****MODIFIERS*****
            template <class InputIterator>  void assign (InputIterator first, InputIterator last);
            void assign (size_type n, const value_type& val);
            void push_back (const value_type& val);
            void pop_back();
            iterator insert (iterator position, const value_type& val); //single element
            void insert (iterator position, size_type n, const value_type& val); //fill
            template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last); // range
            iterator erase (iterator position);
            iterator erase (iterator first, iterator last);
            void swap (vector& x);
            void clear();
            
        //*****Allocator*****
            allocator_type get_allocator() const;
            
    };

    //***** Non member function overloads *****
    //___Relational operators___
    template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);	
    template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);	
    template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    //___Swap ( vector )
    template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

}

#endif