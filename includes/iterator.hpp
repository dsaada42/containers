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
	class reverse_iterator {
		public:
			typedef Iter														iterator_type;
			typedef typename ft::iterator_traits<Iter>::value_type				value_type;
			typedef typename ft::iterator_traits<Iter>::reference       		reference;
			typedef typename ft::iterator_traits<Iter>::pointer                 pointer;
			typedef typename ft::iterator_traits<Iter>::difference_type         difference_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category		iterator_category;
			// -structors
			reverse_iterator			(void)												{ _it = Iter(); }
			reverse_iterator			(typename Iter::value_type * ptr)					{ _it = Iter(ptr); }
			reverse_iterator			(const Iter & x)									{ _it = x; --_it; }
			~reverse_iterator			(void)												{}
			// Conversion
			template <class U>			friend class										reverse_iterator;
			template <class U>
			reverse_iterator			(const reverse_iterator<U> & x)						{ _it = x.getIter(); }

			// Assignment
			reverse_iterator &			operator=	(const reverse_iterator & x)			{ _it = x.getIter(); return (*this); }
			reverse_iterator &			operator+=	(int n)									{ _it -= n; return (*this); }
			reverse_iterator &			operator-=	(int n)									{ _it += n; return (*this); }
			// Comparison
			template <class U> bool		operator==	(const reverse_iterator<U> & x) const	{ return (_it == x.getIter()); }
			template <class U> bool		operator!=	(const reverse_iterator<U> & x) const	{ return (_it != x.getIter()); }
			template <class U> bool		operator<	(const reverse_iterator<U> & x) const	{ return (_it > x.getIter()); }
			template <class U> bool		operator>	(const reverse_iterator<U> & x) const	{ return (_it < x.getIter()); }
			template <class U> bool		operator<=	(const reverse_iterator<U> & x) const	{ return (_it >= x.getIter()); }
			template <class U> bool		operator>=	(const reverse_iterator<U> & x) const	{ return (_it <= x.getIter()); }
			// -crementation
			reverse_iterator &			operator++	(void)									{ --_it; return (*this); }
			reverse_iterator &			operator--	(void)									{ ++_it; return (*this); }
			reverse_iterator			operator++	(int)									{ reverse_iterator<Iter> x(*this); --_it; return (x); }
			reverse_iterator			operator--	(int)									{ reverse_iterator<Iter> x(*this); ++_it; return (x); }
			// Operation
			reverse_iterator			operator+	(int n) const							{ return (_it - n + 1); }
			reverse_iterator			operator-	(int n) const							{ return (_it + n + 1); }
			std::ptrdiff_t				operator-	(const reverse_iterator & x) const		{ return (x.getIter() - _it); }
			// Dereference
			value_type &	operator[]	(size_t n) const									{ return (*(_it - n)); }
			value_type &	operator*	(void) 												{ return (*_it); }   //j ai vire des const sans comprendre pk
			value_type *	operator->	(void) 												{ return (&(*_it)); }	//j ai vire des const sans comprendre pk
			// Member functions
			Iter						base		(void)									{ return (++Iter(_it)); }
			Iter						getIter		(void) const							{ return (_it); }
			// Non-member functions
			friend reverse_iterator		operator+	(int n, const reverse_iterator & x)		{ return (x.getIter() - n + 1); }

		private:
			Iter		_it;
	};
}

#endif