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
	template <class Iter, bool ConstB >
	class reverse_iterator {
		public:
			typedef Iter																iterator_type;
			typedef typename ft::iterator_traits<Iter>::value_type						value_type;
			typedef typename ft::iterator_traits<Iter>::reference       				reference;
			typedef typename ft::iterator_traits<Iter>::pointer                 		pointer;
			typedef typename ft::iterator_traits<Iter>::difference_type         		difference_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category				iterator_category;
			typedef typename ft::conditional<ConstB, const reference, reference>::type  Reference;
            typedef typename ft::conditional<ConstB, const pointer, pointer>::type      Pointer;

			// -structors
			reverse_iterator			(typename Iter::value_type * ptr)					{ _it = Iter(ptr); }
			reverse_iterator			(const Iter & x)									{ _it = x; --_it; }
			reverse_iterator			(void)												{ _it = Iter(); }
			template <class U, bool B>
			reverse_iterator			(const reverse_iterator<U, B> & x)					{ _it = x.getIter(); }
			~reverse_iterator			(void)												{}
			template <class U, bool B>			friend class								reverse_iterator;

			// Assignment
			reverse_iterator &			operator=	(const reverse_iterator & x)			{ _it = x.getIter(); return (*this); }
			reverse_iterator &			operator+=	(int n)									{ _it -= n; return (*this); }
			reverse_iterator &			operator-=	(int n)									{ _it += n; return (*this); }
			// Comparison
			template <class U, bool B> bool		operator==	(const reverse_iterator<U, B> & x) const	{ return (_it == x.getIter()); }
			template <class U, bool B> bool		operator!=	(const reverse_iterator<U, B> & x) const	{ return (_it != x.getIter()); }
			template <class U, bool B> bool		operator<	(const reverse_iterator<U, B> & x) const	{ return (_it > x.getIter()); }
			template <class U, bool B> bool		operator>	(const reverse_iterator<U, B> & x) const	{ return (_it < x.getIter()); }
			template <class U, bool B> bool		operator<=	(const reverse_iterator<U, B> & x) const	{ return (_it >= x.getIter()); }
			template <class U, bool B> bool		operator>=	(const reverse_iterator<U, B> & x) const	{ return (_it <= x.getIter()); }
			// -crementation
			reverse_iterator &			operator++	(void)									{ --_it; return (*this); }
			reverse_iterator &			operator--	(void)									{ ++_it; return (*this); }
			reverse_iterator			operator++	(int)									{ reverse_iterator<Iter, ConstB> x(*this); --_it; return (x); }
			reverse_iterator			operator--	(int)									{ reverse_iterator<Iter, ConstB> x(*this); ++_it; return (x); }
			// Operation
			reverse_iterator			operator+	(int n) const							{ return (_it - n + 1); }
			reverse_iterator			operator-	(int n) const							{ return (_it + n + 1); }
			std::ptrdiff_t				operator-	(const reverse_iterator & x) const		{ return (x.getIter() - _it); }
			// Dereference
			const reference	operator[]	(size_t n) const									{ return (*(_it - n)); }
			reference		operator[]	(size_t n) 											{ return (*(_it - n)); }
			reference operator*   (void) const 												{ iterator_type tmp = _it; return (*tmp); }
			// reference		operator*	(void) 		 										{ iterator_type tmp = _it; return (*tmp); }
			pointer	operator->	(void) const												{ return (&operator*()); }
			// pointer			operator->	(void) 												{ return (&operator*()); }
			// reference		operator*	(void)  											{ Iter tmp = _it; return (*tmp); }
			// pointer			operator->	(void) 												{ return (&operator*()); }
			// Member functions
			iterator_type				base		(void)									{ return (++Iter(_it)); }
			iterator_type				getIter		(void) const							{ return (_it); }
			// Non-member functions
			friend reverse_iterator		operator+	(int n, const reverse_iterator & x)		{ return (x.getIter() - n + 1); }

		private:
			iterator_type		_it;
	};

	// class reverse_iterator {
	// 	public:
	// 		typedef Iter																iterator_type;
	// 		typedef typename ft::iterator_traits<Iter>::value_type						value_type;
	// 		typedef typename ft::iterator_traits<Iter>::reference       				reference;
	// 		typedef typename ft::iterator_traits<Iter>::pointer                 		pointer;
	// 		typedef typename ft::iterator_traits<Iter>::difference_type         		difference_type;
	// 		typedef typename ft::iterator_traits<Iter>::iterator_category				iterator_category;
	// 		typedef typename ft::conditional<ConstB, const reference, reference>::type  Reference;
    //         typedef typename ft::conditional<ConstB, const pointer, pointer>::type      Pointer;

	// 		// -structors
	// 		reverse_iterator			(typename Iter::value_type * ptr)					{ _it = Iter(ptr); }
	// 		reverse_iterator			(const Iter & x)									{ _it = x; --_it; }
	// 		reverse_iterator			(void)												{ _it = Iter(); }
	// 		template <class U, bool B>
	// 		reverse_iterator			(const reverse_iterator<U, B> & x)					{ _it = x.getIter(); }
	// 		~reverse_iterator			(void)												{}
	// 		template <class U, bool B>			friend class								reverse_iterator;

	// 		// Assignment
	// 		reverse_iterator &			operator=	(const reverse_iterator & x)			{ _it = x.getIter(); return (*this); }
	// 		reverse_iterator &			operator+=	(int n)									{ _it -= n; return (*this); }
	// 		reverse_iterator &			operator-=	(int n)									{ _it += n; return (*this); }
	// 		// Comparison
	// 		template <class U, bool B> bool		operator==	(const reverse_iterator<U, B> & x) const	{ return (_it == x.getIter()); }
	// 		template <class U, bool B> bool		operator!=	(const reverse_iterator<U, B> & x) const	{ return (_it != x.getIter()); }
	// 		template <class U, bool B> bool		operator<	(const reverse_iterator<U, B> & x) const	{ return (_it > x.getIter()); }
	// 		template <class U, bool B> bool		operator>	(const reverse_iterator<U, B> & x) const	{ return (_it < x.getIter()); }
	// 		template <class U, bool B> bool		operator<=	(const reverse_iterator<U, B> & x) const	{ return (_it >= x.getIter()); }
	// 		template <class U, bool B> bool		operator>=	(const reverse_iterator<U, B> & x) const	{ return (_it <= x.getIter()); }
	// 		// -crementation
	// 		reverse_iterator &			operator++	(void)									{ --_it; return (*this); }
	// 		reverse_iterator &			operator--	(void)									{ ++_it; return (*this); }
	// 		reverse_iterator			operator++	(int)									{ reverse_iterator<Iter, ConstB> x(*this); --_it; return (x); }
	// 		reverse_iterator			operator--	(int)									{ reverse_iterator<Iter, ConstB> x(*this); ++_it; return (x); }
	// 		// Operation
	// 		reverse_iterator			operator+	(int n) const							{ return (_it - n + 1); }
	// 		reverse_iterator			operator-	(int n) const							{ return (_it + n + 1); }
	// 		std::ptrdiff_t				operator-	(const reverse_iterator & x) const		{ return (x.getIter() - _it); }
	// 		// Dereference
	// 		const reference	operator[]	(size_t n) const									{ return (*(_it - n)); }
	// 		reference		operator[]	(size_t n) 											{ return (*(_it - n)); }
	// 		reference operator*   (void) const 												{ iterator_type tmp = _it; return (*tmp); }
	// 		// reference		operator*	(void) 		 										{ iterator_type tmp = _it; return (*tmp); }
	// 		pointer	operator->	(void) const												{ return (&operator*()); }
	// 		// pointer			operator->	(void) 												{ return (&operator*()); }
	// 		// reference		operator*	(void)  											{ Iter tmp = _it; return (*tmp); }
	// 		// pointer			operator->	(void) 												{ return (&operator*()); }
	// 		// Member functions
	// 		iterator_type				base		(void)									{ return (++Iter(_it)); }
	// 		iterator_type				getIter		(void) const							{ return (_it); }
	// 		// Non-member functions
	// 		friend reverse_iterator		operator+	(int n, const reverse_iterator & x)		{ return (x.getIter() - n + 1); }

	// 	private:
	// 		iterator_type		_it;
	// };
}

#endif