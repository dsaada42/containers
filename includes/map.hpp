#ifndef MAP_HPP
# define MAP_HPP

namespace ft {

    template < class Key, class T,  class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> >
    class map {
        private:

        public:
            typedef Key                                                 key_type;
            typedef T                                                   mapped_type;
            typedef pair<const key_type, mapped_type>                   value_type;
            typedef Compare                                             key_compare;
            typedef                                                     value_compare;
            typedef Alloc                                               allocator_type;
            typedef allocator_type::reference                           reference;
            typedef allocator_type::const_reference                     const_reference;
            typedef allocator_type::pointer                             pointer;
            typedef allocator_type::const_pointer                       const_pointer;
            typedef                                                     iterator;
            typedef                                                     const_iterator;
            typedef reverse_iterator<iterator>                          reverse_iterator;
            typedef reverse_iterator<const_iterator>                    const_reverse_iterator;
            typedef iterator_traits<iterator>::difference_type          difference_type; //ptrdiff_t
            typedef size_t                                              size_type;      

        //***** MEMBER FUNCTIONS *****
            //___Constructors___
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
            template <class InputIterator>  map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());    
            map (const map& x);
            //___Destructor___
            ~map( void );
            //___Operator= surcharge___
            map& operator= (const map& x);

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

        //***** ELEMENT ACCESS *****
            mapped_type& operator[] (const key_type& k);
            mapped_type& at (const key_type& k);
            const mapped_type& at (const key_type& k) const;

        //***** MODIFIERS *****
            pair<iterator,bool> insert (const value_type& val);
            iterator insert (iterator position, const value_type& val);
            template <class InputIterator>  void insert (InputIterator first, InputIterator last);
            void erase (iterator position);
            size_type erase (const key_type& k);
            void erase (iterator first, iterator last);
            void swap (map& x);
            void clear( void );
            template <class... Args>  pair<iterator,bool> emplace (Args&&... args);
            template <class... Args>  iterator emplace_hint (const_iterator position, Args&&... args);

        //***** OBSERVERS *****
            key_compare key_comp() const;
            value_compare value_comp() const;

        //***** OPERATIONS *****
            iterator find (const key_type& k);
            const_iterator find (const key_type& k) const;
            size_type count (const key_type& k) const;
            iterator lower_bound (const key_type& k);
            const_iterator lower_bound (const key_type& k) const;
            iterator upper_bound (const key_type& k);
            const_iterator upper_bound (const key_type& k) const;
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
            pair<iterator,iterator> equal_range (const key_type& k);

        //***** ALLOCATOR *****
            allocator_type get_allocator() const;

    };
    
}

#endif