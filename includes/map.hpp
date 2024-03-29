/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:23:58 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 15:55:09 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include "equal.hpp"
# include "RBTree.hpp"
# include "type_traits.hpp"
# include "iterator.hpp"
# include "pair.hpp"

namespace ft {

    template < class Key, class T,  class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map {
        public:
            class                                                           value_compare;
            typedef Key                                                     key_type;
            typedef T                                                       mapped_type;
            typedef ft::pair<const key_type, mapped_type>                   value_type;
            typedef Compare                                                 key_compare;
            typedef Alloc                                                   allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef ft::RBTree_iterator<value_type, false>                  iterator;
            typedef ft::RBTree_iterator<value_type, true>                   const_iterator;
            typedef ft::reverse_iterator<iterator>                          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
            typedef std::ptrdiff_t                                          difference_type; //ptrdiff_t
            typedef std::size_t                                             size_type;
            typedef ft::RBTree<value_type, value_compare, allocator_type>   tree_type;

            class value_compare{
                friend class map;
                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
                public:
                    bool operator() (const value_type& x, const value_type& y) const {
                        return comp(x.first, y.first);
                    }
            };

        public:
            key_compare            _comp;
            allocator_type         _alloc;
            tree_type              _tree;

        public:
        //***** MEMBER FUNCTIONS *****
            //___Constructors___
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
                : _comp(comp), _alloc(alloc), _tree (value_compare(_comp), _alloc) {}
            
            template <class InputIt>  map (InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
                : _comp(comp), _alloc(alloc), _tree(value_compare(_comp), _alloc) {
                while (first != last){
                    _tree.insert(*first);
                    first++;
                }
            }    
            
            map (const map& x): _comp(x._comp), _alloc(x._alloc), _tree(x._tree){}

            ~map( void ){}

            map& operator= (const map& x){
                _comp = x._comp;
                _alloc = x._alloc;
                _tree = x._tree;
                return (*this);
            }

        //***** ITERATORS *****
            iterator                            begin()         { return (_tree.begin()); }
            const_iterator                      begin() const   { return (_tree.begin()); }
            iterator                            end()           { return (_tree.end()); }
            const_iterator                      end() const     { return (_tree.end()); }
            reverse_iterator                    rbegin()        { return (_tree.rbegin()); }
            const_reverse_iterator              rbegin() const  { return (_tree.rbegin()); }
            reverse_iterator                    rend()          { return (_tree.rend()); }
            const_reverse_iterator              rend() const    { return (_tree.rend()); }

        //***** CAPACITY *****
            bool                                empty() const   { return (_tree.empty()); }
            size_type                           size() const    { return (_tree.size()); }
            size_type                           max_size()const { return (_tree.max_size()); }

        //***** ELEMENT ACCESS *****
            mapped_type&                        operator[] (const key_type& k)  { return(_tree[ft::make_pair(k, mapped_type())].second); }
            mapped_type&                        at (const key_type& k)          { return(_tree.at(ft::make_pair(k, mapped_type())).second); }
            const mapped_type&                  at (const key_type& k) const    { return(_tree.at(ft::make_pair(k, mapped_type())).second); }

        //***** MODIFIERS *****
            pair<iterator,bool>                 insert (const value_type& val)                      { return(_tree.insert(val)); }
            iterator                            insert (iterator position, const value_type& val)   { return (_tree.insert(position, val)); }
            template <class InputIterator> void insert (InputIterator first, InputIterator last)    { _tree.insert(first, last);}
            void                                erase (iterator position)                           { _tree.erase(*position);}
            size_type                           erase (const key_type& k)                           { return(_tree.erase(ft::make_pair(k, mapped_type()))); }
            void                                erase (iterator first, iterator last)               { _tree.erase(first, last); }
            void                                clear( void )                                       { _tree.clear(); }
            void                                swap (map& x){
                allocator_type  tmp_alloc;
                key_compare     tmp_comp;

                tmp_alloc = x._alloc;
                x._alloc = _alloc;
                _alloc = tmp_alloc;

                tmp_comp = x._comp;
                x._comp = _comp;
                _comp = tmp_comp;

                _tree.swap(x._tree);
            }
            

        //***** OBSERVERS *****
            key_compare                         key_comp() const    { return(key_compare()); }
            value_compare                       value_comp() const  { return(value_compare(_comp)); }

        //***** OPERATIONS *****
            iterator                            find (const key_type& k)                { return(_tree.find(ft::make_pair(k, mapped_type()))); }
            const_iterator                      find (const key_type& k) const          { return(_tree.find(ft::make_pair(k, mapped_type()))); }
            size_type                           count (const key_type& k) const         { return(_tree.count(ft::make_pair(k, mapped_type()))); }
            iterator                            lower_bound (const key_type& k)         { return(_tree.lower_bound(ft::make_pair(k, mapped_type()))); }
            const_iterator                      lower_bound (const key_type& k) const   { return(_tree.lower_bound(ft::make_pair(k, mapped_type()))); }
            iterator                            upper_bound (const key_type& k)         { return(_tree.upper_bound(ft::make_pair(k, mapped_type()))); }
            const_iterator                      upper_bound (const key_type& k) const   { return(_tree.upper_bound(ft::make_pair(k, mapped_type()))); }
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const   { return(_tree.equal_range(ft::make_pair(k, mapped_type()))); }
            pair<iterator,iterator>             equal_range (const key_type& k)         { return(_tree.equal_range(ft::make_pair(k, mapped_type()))); }

        //***** ALLOCATOR *****
            allocator_type                      get_allocator() const                   { return (allocator_type()); }
    };
    
    template< class Key, class T, class Compare, class Alloc >
    bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));  
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        if (rhs == lhs)
            return (true);
        return (lhs < rhs);   
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        return (std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())); 
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        if (rhs == lhs)
            return (true);
        return (lhs > rhs);    
    }  
    template< class Key, class T, class Compare, class Alloc >
    void swap( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs ){
        lhs.swap(rhs);
    }
}

#endif