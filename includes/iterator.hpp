/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:23:40 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 14:23:43 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <cstddef>
# include <typeinfo>
# include <iterator>

namespace ft
{
	template <class Iter>
	class iterator_traits {
		public:
			typedef Iter									iterator_type;
			typedef typename Iter::difference_type          difference_type;
            typedef typename Iter::value_type               value_type;
            typedef typename Iter::pointer                  pointer;
            typedef typename Iter::reference                reference;
            typedef typename Iter::iterator_category        iterator_category;
	};
    
    template <class Iter>
    class iterator_traits<Iter *> {
        public:
            typedef std::ptrdiff_t                          difference_type;
            typedef Iter                                    value_type;
            typedef value_type*                             pointer;
            typedef value_type&                             reference;
            typedef std::random_access_iterator_tag         iterator_category;                                  
    };

	template <class Iter>
	class iterator_traits<const Iter *> {
        public:
            typedef std::ptrdiff_t                          difference_type;
            typedef Iter                                    value_type;
            typedef const value_type*                       pointer;
            typedef const value_type&                       reference;
            typedef std::random_access_iterator_tag         iterator_category;                                  
    };

	template < class Iterator >
	class reverse_iterator {
		public:
			typedef Iterator																iterator_type;
			typedef typename ft::iterator_traits<Iterator>::value_type						value_type;
			typedef typename ft::iterator_traits<Iterator>::reference       				reference;
			typedef typename ft::iterator_traits<Iterator>::pointer                 		pointer;
			typedef typename ft::iterator_traits<Iterator>::difference_type         		difference_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category				iterator_category;

		public:
			iterator_type		current;

		public:
			//----- Constructors -----
			reverse_iterator(){}
			explicit reverse_iterator(Iterator x): current(x){}
			template <class U> 
			reverse_iterator(const reverse_iterator<U>& u): current(u.base()){}
			~reverse_iterator			(void)								{}
			template <class U>			friend class						reverse_iterator;
			Iterator 					base() const						{return (current);}
			//----- Dereference /  Access -----
			reference 					operator*() const					{ iterator_type tmp = current; return (*--tmp);}
			pointer 					operator->() const					{ return &(operator*()); }
			reference 					operator[](difference_type n) const	{ return (base()[- n - 1]);}
			//----- Comparison -----
			template <class U> bool		operator==	(const reverse_iterator<U> & x) const	{ return (current == x.base()); }
			template <class U> bool		operator!=	(const reverse_iterator<U> & x) const	{ return (current != x.base()); }
			template <class U> bool		operator<	(const reverse_iterator<U> & x) const	{ return (current > x.base()); }
			template <class U> bool		operator>	(const reverse_iterator<U> & x) const	{ return (current < x.base()); }
			template <class U> bool		operator<=	(const reverse_iterator<U> & x) const	{ return (current >= x.base()); }
			template <class U> bool		operator>=	(const reverse_iterator<U> & x) const	{ return (current <= x.base()); }
			//----- Increment / Decrement (prefix / postfix) -----
			reverse_iterator& 			operator++()						{ --current; return (*this);}
			reverse_iterator 			operator++(int)						{ reverse_iterator temp = *this; --current; return temp;}
			reverse_iterator& 			operator--()						{ ++current; return (*this);}
			reverse_iterator 			operator--(int)						{ reverse_iterator temp = *this; ++current; return temp;}
			//----- Arithmetics ------
			reverse_iterator 			operator+ (difference_type n) const	{ return (reverse_iterator(current - n));}
			reverse_iterator& 			operator+=(difference_type n)		{ current -= n; return (*this);}
			reverse_iterator 			operator- (difference_type n) const	{ return (reverse_iterator(current + n));}
			difference_type				operator- (const reverse_iterator & x) const { return( x.base() - current);}
			reverse_iterator& 			operator-=(difference_type n)		{ current += n; return (*this);}
			friend reverse_iterator		operator+ (difference_type n, const reverse_iterator & x) { return (reverse_iterator(x.base() - n));}
	};
	
}

#endif