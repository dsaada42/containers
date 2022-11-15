#ifndef STACK_HPP
# define STACK_HPP

namespace ft {
 
    template < class T, class Container = deque<T> >
    class stack{
        private:
            typedef T                   value_type;
            typedef Container           container_type;
            typedef size_t              size_type;

        public:
            //***** MEMBER FUNCTIONS *****
            explicit stack (const container_type& ctnr = container_type());
            bool empty() const;
            size_type size() const;
            value_type& top();
            const value_type& top() const;
            void push (const value_type& val);
            template <class... Args> void emplace (Args&&... args);
            void pop();
            void swap (stack& x) noexcept;

    };

    //***** NON-MEMBER FUNCTION OVERLOADS *****
    //___Relational operators___
    template <class T, class Container>  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);	
    template <class T, class Container>  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    template <class T, class Container>  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    template <class T, class Container>  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    template <class T, class Container>  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    template <class T, class Container>  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    //___Swap(stack)___
    template <class T, class Container>  void swap (stack<T,Container>& x, stack<T,Container>& y) noexcept(noexcept(x.swap(y)));
   
    //***** NON-MEMBER CLASS SPECIALIZATION *****
    //___Use Allocator___
    template <class T, class Container, class Alloc>  struct uses_allocator<stack<T,Container>,Alloc>;

}

#endif