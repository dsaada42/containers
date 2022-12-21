#ifndef SET_HPP
# define SET_HPP
# include "pair.hpp"
# include <iostream>
# include <iterator>
# include <memory>
# include <cstddef>
# include "equal.hpp"
# include "RBTreev2.hpp"
# include "RBTree_iterator.hpp"
# include "type_traits.hpp"
# include "reverse_iterator.hpp"

namespace ft {

    template < class T,  class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class set {
        public:
            typedef T                                                       key_type;
            typedef T                                                       value_type;
            typedef Compare                                                 key_compare;
            typedef Compare                                                 value_compare;
            typedef Alloc                                                   allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef ft::RBTree_iterator<value_type, false>                  iterator;
            typedef ft::RBTree_iterator<value_type, true>                   const_iterator;
            typedef ft::reverse_iterator<iterator>                          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
            typedef std::ptrdiff_t                                          difference_type; 
            typedef std::size_t                                             size_type;
            typedef ft::RBTree<value_type, value_compare, allocator_type>   tree_type;

    
        public:
            key_compare            _comp;
            allocator_type         _alloc;
            tree_type              _tree;

    //***** MEMBER FUNCTIONS *****
        //___Constructors___
        explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
        template <class InputIterator>  set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
        set (const set& x): _comp(x._comp), _alloc(x._alloc), _tree(x._tree){}
        //___Destructor___
        ~set( void ){}
        //___Operator= surcharge___
        set& operator= (const set& x){
            _comp = x._comp;
            _alloc = x._alloc;
            _tree = x._tree;
            return (*this);
        }

    //***** ITERATORS *****
        iterator                begin()         { return (_tree.begin()); }
        const_iterator          begin() const   { return (_tree.begin()); }
        iterator                end()           { return (_tree.end()); }
        const_iterator          end() const     { return (_tree.end()); }
        reverse_iterator        rbegin()        { return (_tree.rbegin()); }
        const_reverse_iterator  rbegin() const  { return (_tree.rbegin()); }
        reverse_iterator        rend()          { return (_tree.rend()); }
        const_reverse_iterator  rend() const    { return (_tree.rend()); }

    //***** CAPACITY *****
        bool                    empty() const   { return (_tree.empty()); }
        size_type               size() const    { return (_tree.size()); }
        size_type               max_size()const { return (_alloc.max_size()); }

    //***** MODIFIERS *****
        pair<iterator,bool> insert (const value_type& val){
            return(_tree.insert(val));
        }
        iterator insert (iterator position, const value_type& val){
            return (_tree.insert(position, val));
        }
        template <class InputIterator>  void insert (InputIterator first, InputIterator last){
            _tree.insert(first, last);
        }
        void erase (iterator position){
            _tree.erase(*position);
        }
        size_type erase (const value_type& k){
            return(_tree.erase(k));
        }
        void erase (iterator first, iterator last){
            _tree.erase(first, last);
        }
        void swap (set& x){
            (void)x;
        }
        void clear( void ){
            _tree.clear();
        }

    //***** OBSERVERS *****
        key_compare key_comp() const{ return(key_compare());}
        value_compare value_comp() const{ return(value_compare());}

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