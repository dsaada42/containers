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
	// template <class Iter>
	// class reverse_iterator {
	// 	public:
	// 		typedef Iter																iterator_type;
	// 		typedef typename ft::iterator_traits<Iter>::value_type						value_type;
	// 		typedef typename ft::iterator_traits<Iter>::reference       				reference;
	// 		typedef typename ft::iterator_traits<Iter>::pointer                 		pointer;
	// 		typedef typename ft::iterator_traits<Iter>::difference_type         		difference_type;
	// 		typedef typename ft::iterator_traits<Iter>::iterator_category				iterator_category;

	// 		// -structors
	// 		reverse_iterator			(typename Iter::value_type * ptr)					{ _it = Iter(ptr); }
	// 		reverse_iterator			(const Iter & x)									{ _it = x; --_it; }
	// 		reverse_iterator			(void)												{ _it = Iter(); }
	// 		template <class U>
	// 		reverse_iterator			(const reverse_iterator<U> & x)					{ _it = x.getIter(); }
	// 		~reverse_iterator			(void)												{}
	// 		template <class U>			friend class								reverse_iterator;

	// 		// Assignment
	// 		reverse_iterator &			operator=	(const reverse_iterator & x)			{ _it = x.getIter(); return (*this); }
	// 		reverse_iterator &			operator+=	(int n)									{ _it -= n; return (*this); }
	// 		reverse_iterator &			operator-=	(int n)									{ _it += n; return (*this); }
	// 		// Comparison
	// 		template <class U> bool		operator==	(const reverse_iterator<U> & x) const	{ return (_it == x.getIter()); }
	// 		template <class U> bool		operator!=	(const reverse_iterator<U> & x) const	{ return (_it != x.getIter()); }
	// 		template <class U> bool		operator<	(const reverse_iterator<U> & x) const	{ return (_it > x.getIter()); }
	// 		template <class U> bool		operator>	(const reverse_iterator<U> & x) const	{ return (_it < x.getIter()); }
	// 		template <class U> bool		operator<=	(const reverse_iterator<U> & x) const	{ return (_it >= x.getIter()); }
	// 		template <class U> bool		operator>=	(const reverse_iterator<U> & x) const	{ return (_it <= x.getIter()); }
	// 		// -crementation
	// 		reverse_iterator &			operator++	(void)									{ --_it; return (*this); }
	// 		reverse_iterator &			operator--	(void)									{ ++_it; return (*this); }
	// 		reverse_iterator			operator++	(int)									{ reverse_iterator<Iter> x(*this); --_it; return (x); }
	// 		reverse_iterator			operator--	(int)									{ reverse_iterator<Iter> x(*this); ++_it; return (x); }
	// 		// Operation
	// 		reverse_iterator			operator+	(int n) const							{ return (_it - n + 1); }
	// 		reverse_iterator			operator-	(int n) const							{ return (_it + n + 1); }
	// 		std::ptrdiff_t				operator-	(const reverse_iterator & x) const		{ return (x.getIter() - _it); }
	// 		// Dereference
	// 		const reference	operator[]	(size_t n) const									{ return (*(_it - n)); }
	// 		reference		operator[]	(size_t n) 											{ return (*(_it - n)); }
	// 		reference operator*   (void) const 												{ iterator_type tmp = _it; return (*tmp); }
	// 		pointer	operator->	(void) const												{ return (&operator*()); }
	// 		// Member functions
	// 		iterator_type				base		(void)									{ return (++Iter(_it)); }
	// 		iterator_type				getIter		(void) const							{ return (_it); }
	// 		// Non-member functions
	// 		friend reverse_iterator		operator+	(int n, const reverse_iterator & x)		{ return (x.getIter() - n + 1); }

	// 	private:
	// 		iterator_type		_it;
	// };

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
	// template <class U>
	// bool operator==( const reverse_iterator<U>& x, const reverse_iterator<U>& y){ return (x.base() == y.base());}
	// template <class U>
	// bool operator<( const reverse_iterator<U>& x, const reverse_iterator<U>& y){ return (x.base() > y.base());}
	// template <class U>
	// bool operator!=( const reverse_iterator<U>& x, const reverse_iterator<U>& y){ return (x.base() != y.base());}
	// template <class U>
	// bool operator>( const reverse_iterator<U>& x, const reverse_iterator<U>& y){ return (x.base() < y.base());}
	// template <class U>
	// bool operator>=( const reverse_iterator<U>& x, const reverse_iterator<U>& y){ return (x.base() <= y.base());}
	// template <class U>
	// bool operator<=( const reverse_iterator<U>& x, const reverse_iterator<U>& y){ return (x.base() >= y.base());}
	// template <class U>
	// typename reverse_iterator<U>::difference_type operator-( const reverse_iterator<U>& x, const reverse_iterator<U>& y){ return (y.current - x.current);}
	// template <class U>
	// reverse_iterator<U> operator+( typename reverse_iterator<U>::difference_type n, const reverse_iterator<U>& x){ return (reverse_iterator<U>(x.current - n));}
}

#endif