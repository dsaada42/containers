#ifndef MAP_HPP
# define MAP_HPP
# include "pair.hpp"
# include <iostream>
# include <iterator>
# include <memory>
# include <cstddef>
# include "equal.hpp"
# include "type_traits.hpp"
# include "reverse_iterator.hpp"

namespace ft {

    template < class Key, class T,  class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map {
        typedef struct              s_node
        {
            ft::pair<const Key, T>  _pair;
            bool                    _black;
            s_node                  *right;
            s_node                  *left;
            s_node                  *parent;

            s_node (ft::pair< const Key, T > pair){
                _pair = pair;
            }
            const Key & key(void){ return (data.first); }
            T &         val(void){ return(data.second); }
        }                           t_node;

        template< bool ConstB >
        class map_iterator {
            public:
                typedef Key                                                                     key_type;
                typedef T                                                                       mapped_type;
                typedef ft::pair< const Key, T >                                                value_type;
                typedef value_type&                                                             reference;
                typedef value_type const &                                                      const_reference;
                typedef value_type*                                                             pointer;
                typedef value_type const *                                                      const_pointer;
                typedef std::ptrdiff_t                                                          difference_type;
                typedef std::size_t                                                             size_type;
                typedef std::bidirectional_iterator_tag                                         iterator_category;
 
            private:
                value_type  *_ptr;
        };

        public:
            class                                                       value_compare;
            typedef Key                                                 key_type;
            typedef T                                                   mapped_type;
            typedef ft::pair<const key_type, mapped_type>               value_type;
            typedef Compare                                             key_compare;
            typedef Alloc                                               allocator_type;
            typedef typename allocator_type::reference                  reference;
            typedef typename allocator_type::const_reference            const_reference;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename allocator_type::const_pointer              const_pointer;
            typedef map_iterator<false>                                 iterator;
            typedef map_iterator<true>                                  const_iterator;
            typedef ft::reverse_iterator<iterator>                      reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
            typedef std::ptrdiff_t                                      difference_type; //ptrdiff_t
            typedef std::size_t                                         size_type;      

        protected:
            
            key_compare     _comp;
            allocator_type  _alloc;
            size_type       _size;
            t_node          *_root;

        //***** MEMBER FUNCTIONS *****
            //___Constructors___
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
                _comp = comp;
                _alloc = alloc;
                _size = 0;
            }
            template <class InputIt>  map (InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
                _size = 0;
                (void)first;
                (void)last;
                _comp = comp;
                _alloc = alloc;
            }    
            map (const map& x){
                _comp = x._comp;
                _alloc = x._alloc;
            }
            //___Destructor___
            ~map( void ){
                
            }
            //___Operator= surcharge___
            map& operator= (const map& x){
                _comp = x._comp;
                _alloc = x._alloc;
                return (*this);
            }


        //***** ITERATORS *****
            iterator begin(){
                return (iterator());
            }
            const_iterator begin() const{
                return (const_iterator());
            }
            iterator end(){
                return (iterator());
            }
            const_iterator end() const{
                return (const_iterator());
            }
            reverse_iterator rbegin(){
                return (reverse_iterator());
            }
            const_reverse_iterator rbegin() const{
                return (const_reverse_iterator());
            }
            reverse_iterator rend(){
                return (reverse_iterator());
            }
            const_reverse_iterator rend() const{
                return (const_reverse_iterator());
            }

        //***** CAPACITY *****
            bool empty() const{
                return (_size == 0);
            }
            size_type size() const{
                return (_size);
            }
            size_type max_size() const{
                return (_alloc.max_size());
            }

        //***** ELEMENT ACCESS *****
            mapped_type& operator[] (const key_type& k){
                (void)k;
                return(mapped_type());
            }
            mapped_type& at (const key_type& k){
                (void)k;
                return(mapped_type());
            }
            const mapped_type& at (const key_type& k) const{
                (void)k;
                return(mapped_type());
            }

        //***** MODIFIERS *****
            pair<iterator,bool> insert (const value_type& val){
                (void)val;
                return(make_pair(key_type(), mapped_type()));
            }
            iterator insert (iterator position, const value_type& val){
                (void)position;
                (void)val;
                return (begin());
            }
            template <class InputIterator>  void insert (InputIterator first, InputIterator last){
                (void)first;
                (void)last;
            }
            void erase (iterator position){
                (void)position;
            }
            size_type erase (const key_type& k){
                (void)k;
                return(0);
            }
            void erase (iterator first, iterator last){
                (void)first;
                (void)last;
            }
            void swap (map& x){
                (void)x;
            }
            void clear( void ){}

        //***** OBSERVERS *****
            key_compare key_comp() const{}
            value_compare value_comp() const{}

        //***** OPERATIONS *****
            iterator find (const key_type& k){
                (void)k;
                return(begin());
            }
            const_iterator find (const key_type& k) const{
                (void)k;
                return(begin());
            }
            size_type count (const key_type& k) const{
                (void)k;
                return(0);
            }
            iterator lower_bound (const key_type& k){
                (void)k;
                return(begin());
            }
            const_iterator lower_bound (const key_type& k) const{
                (void)k;
                return(begin());
            }
            iterator upper_bound (const key_type& k){
                (void)k;
                return(begin());
            }
            const_iterator upper_bound (const key_type& k) const{
                (void)k;
                return(begin());
            }
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
                (void)k;
                return(make_pair(key_type(), mapped_type()));
            }
            pair<iterator,iterator> equal_range (const key_type& k){
                (void)k;
                return(make_pair(key_type(), mapped_type()));
            }

        //***** ALLOCATOR *****
            allocator_type get_allocator() const{
                return (allocator_type());
            }
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
        return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); // petit probleme sur mon lexicographical compare
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        if (rhs == lhs)
            return (true);
        return (lhs < rhs);   
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        return (std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));  // petit probleme sur mon lexicographical compare   
    }
    template< class Key, class T, class Compare, class Alloc >
    bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
        if (rhs == lhs)
            return (true);
        return (lhs > rhs);    
    }  
    
    template< class Key, class T, class Compare, class Alloc >
    void swap( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs ){
        (void)rhs;
        (void)lhs;
    }
}

#endif