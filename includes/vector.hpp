#ifndef VECTOR_HPP
# define VECTOR_HPP

template < class T, class Alloc = allocator<T> >
class vector{
    private:
        typedef T                                       value_type;
        typedef Alloc                                   allocator_type;
        typedef allocator_type::reference               reference;
        typedef allocator_type::const_reference         const_reference;
        typedef allocator_type::pointer                 pointer;
        typedef allocator_type::const_pointer           const_pointer;
        typedef iterator;
        typedef const_iterator;
        typedef reverse_iterator;
        typedef const_reverse_iterator;
        typedef difference_type;
        typedef size_type;

    public:
    //*****CONSTRUCTOR DESTRUCTOR*****
        //____default constructor : constructs an empty container, no elements
        explicit vector (const allocator_type& alloc = allocator_type()); 
        //____fill constructor : constructs a container with n elements, each is a copy of val  
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); 
        //____range constructor : constructs a container with as many elements as the range [first,last)
        template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); 
        //____copy constructor
        vector (const vector& x); 
        ~vector< T , Alloc >( void );
        //____opertor= surcharge
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
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;
        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend() const noexcept;

    //*****CAPACITY*****
        size_type size() const;
        size_type max_size() const;
        void resize (size_type n, value_type val = value_type());
        size_type capacity() const;
        bool empty() const;
        void reserve (size_type n);
        void shrink_to_fit();

    //*****ELEMENT ACCESS*****
        reference operator[] (size_type n);
        const_reference operator[] (size_type n) const;
        reference at (size_type n);
        const_reference at (size_type n) const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;
        value_type* data() noexcept;
        const value_type* data() const noexcept;

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
        template <class... Args>iterator emplace (const_iterator position, Args&&... args);
        template <class... Args>  void emplace_back (Args&&... args);

    //*****Allocator*****
        allocator_type get_allocator() const;
        
};

//***** Non member function overloads *****
relational_operators();
swap();

#endif