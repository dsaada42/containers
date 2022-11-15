#ifndef SET_HPP
# define SET_HPP

namespace ft {

    template < class T,  class Compare = less<T>, class Alloc = allocator<T> >
    class set{
        private:

        public:
            typedef T                                               key_type;
            typedef T                                               value_type;
            typedef Compare                                         key_compare;
            typedef Compare                                         value_compare;
            typedef Alloc                                           allocator_type;
            typedef allocator_type::reference                       reference;
            typedef allocator_type::const_reference                 const_reference;
            typedef allocator_type::pointer                         pointer;
            typedef allocator_type::const_pointer                   const_pointer;
            typedef                                                 iterator;
            typedef                                                 const_iterator;
            typedef reverse_iterator<iterator>                      reverse_iterator;
            typedef const_reverse_iterator<iterator>                const_reverse_iterator;
            typedef iterator_traits<iterator>::difference_type      difference_type; //ptrdiff_t
            typedef size_t                                          size_type; //size_t
    
    //***** MEMBER FUNCTIONS *****
        //___Constructors___
        explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
        template <class InputIterator>  set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
        set (const set& x);
        //___Destructor___
        ~set();
        //___Operator= surcharge___
        set& operator= (const set& x);

    //***** ITERATORS *****
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;
        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend() const noexcept;

    //***** CAPACITY *****
        bool empty() const;
        size_type size() const;
        size_type max_size() const;

    //***** MODIFIERS *****
        pair<iterator,bool> insert (const value_type& val);
        iterator insert (iterator position, const value_type& val);
        template <class InputIterator>  void insert (InputIterator first, InputIterator last);
        void erase (iterator position);
        size_type erase (const value_type& val);
        void erase (iterator first, iterator last);
        void swap (set& x);
        void clear();
        template <class... Args>  pair<iterator,bool> emplace (Args&&... args);
        template <class... Args>  iterator emplace_hint (const_iterator position, Args&&... args);

    //***** OBSERVERS *****
        key_compare key_comp() const;
        value_compare value_comp() const;

    //***** OPERATIONS *****
        iterator find (const value_type& val) const;
        size_type count (const value_type& val) const;
        iterator lower_bound (const value_type& val) const;
        iterator upper_bound (const value_type& val) const;
        pair<iterator,iterator> equal_range (const value_type& val) const;

    //***** ALLOCATOR *****
        allocator_type get_allocator() const;

    };
}

#endif