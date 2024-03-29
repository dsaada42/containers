/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:24:46 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/06 14:24:47 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include <vector>
# include "vector.hpp"

namespace ft {
 
    template < class T, class Container = ft::vector<T> >
    class stack{
        public:
            typedef T                   value_type;
            typedef Container           container_type;
            typedef std::size_t         size_type;
            typedef T&                  reference;
            typedef const T&            const_reference;

        public:
            container_type _ctnr;

        public:
            //***** MEMBER FUNCTIONS *****
            explicit stack (const container_type& ctnr = container_type()){
                _ctnr = ctnr;    
            }
            bool empty() const{
                return (_ctnr.empty());
            }
            size_type size() const{
                return (_ctnr.size());
            }
            value_type& top(){ 
                return (_ctnr.back());
            }
            const value_type& top() const{
                return (_ctnr.back());
            }
            void push (const value_type& val){
                _ctnr.push_back(val);
            }
            void pop(){
                _ctnr.pop_back();
            }
    };

    //***** NON-MEMBER FUNCTION OVERLOADS *****
    //___Relational operators___
    template <class T, class Container>  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._ctnr == rhs._ctnr);
    }	
    template <class T, class Container>  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._ctnr != rhs._ctnr);
    }
    template <class T, class Container>  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._ctnr < rhs._ctnr);
    }
    template <class T, class Container>  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._ctnr <= rhs._ctnr);
    }
    template <class T, class Container>  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._ctnr > rhs._ctnr);
    }
    template <class T, class Container>  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
        return (lhs._ctnr >= rhs._ctnr);
    }

}

#endif