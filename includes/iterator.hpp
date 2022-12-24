#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <cstddef>
# include <typeinfo>
# include <iterator>

namespace ft
{
	template <class it>
	class reverse_iterator {
		public:
			typedef it													iterator_type;
			typedef typename iterator_type::value_type					value_type;
			typedef typename iterator_type::reference                   reference;
			typedef typename iterator_type::pointer                     pointer;
			typedef typename iterator_type::difference_type             difference_type;
			typedef typename iterator_type::size_type                   size_type;
			typedef typename iterator_type::iterator_category			iterator_category;
			// -structors
			reverse_iterator			(void)												{ _it = it(); }
			reverse_iterator			(typename it::value_type * ptr)						{ _it = it(ptr); }
			reverse_iterator			(const it & x)										{ _it = x; --_it; }
			~reverse_iterator			(void)												{}
			// Conversion
			template <class U>			friend class										reverse_iterator;
			template <class U>
			reverse_iterator			(const reverse_iterator<U> & x)						{ _it = x.getIt(); }

			// Assignment
			reverse_iterator &			operator=	(const reverse_iterator & x)			{ _it = x.getIt(); return (*this); }
			reverse_iterator &			operator+=	(int n)									{ _it -= n; return (*this); }
			reverse_iterator &			operator-=	(int n)									{ _it += n; return (*this); }
			// Comparison
			template <class U> bool		operator==	(const reverse_iterator<U> & x) const	{ return (_it == x.getIt()); }
			template <class U> bool		operator!=	(const reverse_iterator<U> & x) const	{ return (_it != x.getIt()); }
			template <class U> bool		operator<	(const reverse_iterator<U> & x) const	{ return (_it > x.getIt()); }
			template <class U> bool		operator>	(const reverse_iterator<U> & x) const	{ return (_it < x.getIt()); }
			template <class U> bool		operator<=	(const reverse_iterator<U> & x) const	{ return (_it >= x.getIt()); }
			template <class U> bool		operator>=	(const reverse_iterator<U> & x) const	{ return (_it <= x.getIt()); }
			// -crementation
			reverse_iterator &			operator++	(void)									{ --_it; return (*this); }
			reverse_iterator &			operator--	(void)									{ ++_it; return (*this); }
			reverse_iterator			operator++	(int)									{ reverse_iterator<it> x(*this); --_it; return (x); }
			reverse_iterator			operator--	(int)									{ reverse_iterator<it> x(*this); ++_it; return (x); }
			// Operation
			reverse_iterator			operator+	(int n) const							{ return (_it - n + 1); }
			reverse_iterator			operator-	(int n) const							{ return (_it + n + 1); }
			std::ptrdiff_t				operator-	(const reverse_iterator & x) const		{ return (x.getIt() - _it); }
			// Dereference
			value_type &	operator[]	(size_t n) const						{ return (*(_it - n)); }
			value_type &	operator*	(void) 									{ return (*_it); }   //j ai vire des const sans comprendre pk
			value_type *	operator->	(void) 									{ return (&(*_it)); }	//j ai vire des const sans comprendre pk
			// Member functions
			it							base		(void)									{ return (++it(_it)); }
			it							getIt		(void) const							{ return (_it); }
			// Non-member functions
			friend reverse_iterator		operator+	(int n, const reverse_iterator & x)		{ return (x.getIt() - n + 1); }

		private:
			it		_it;
	};

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

}

#endif