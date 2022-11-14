#include "../includes/vector.hpp"

//****** CONSTRUCTORS / DESTRUCTOR / OPERATOR= ******

explicit vector::vector(const allocator_type& alloc = allocator_type()){

} 
explicit vector::vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){

} 
template <class InputIterator> vector::vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){

}
vector::vector(const vector& x){

} 
vector::~vector< T , Alloc >( void ){

}
vector& vector::operator=(const vector& x){

}

//****** ITERATORS ******

iterator vector::begin(){

}
const_iterator vector::begin() const{

}
iterator vector::end(){

}
const_iterator vector::end() const{

}
reverse_iteraor vector::rbegin(){

}
const_reverse_iterator vector::rbegin() const{

}
reverse_iteraor vector::rend(){

}
const_reverse_iterator vector::rend() const{

}
const_iterator vector::cbegin() const noexcept{

}
const_iterator vector::cend() const noexcept{

}
const_reverse_iterator vector::crbegin() const noexcept{

}
const_reverse_iterator vector::crend() const noexcept{

}

//****** CAPACITY *****
size_type vector::size() const{
    return (_size);
}
size_type vector::max_size() const{
    
}
void vector::resize (size_type n, value_type val = value_type()){

}
size_type vector::capacity() const{
    return (_capacity);
}
bool vector::empty() const{
    if (_size == 0)
        return (true);
    return (false);
}
void vector::reserve (size_type n){

}
void vector::shrink_to_fit(){

}

//*****ELEMENT ACCESS*****
reference vector::operator[] (size_type n){

}
const_reference vector::operator[] (size_type n) const{

}
reference vector::at (size_type n){

}
const_reference vector::at (size_type n) const{

}
reference vector::front(){

}
const_reference vector::front() const{

}
reference vector::back(){

}
const_reference vector::back() const{

}
value_type* vector::data() noexcept{

}
const value_type* vector::data() const noexcept{

}

//*****MODIFIERS*****
template <class InputIterator>  void vector::assign (InputIterator first, InputIterator last){

}
void vector::assign (size_type n, const value_type& val){

}
void vector::push_back (const value_type& val){

}
void vector::pop_back(){

}
iterator vector::insert (iterator position, const value_type& val){

} //single element
void vector::insert (iterator position, size_type n, const value_type& val){

} //fill
template <class InputIterator> void vector::insert (iterator position, InputIterator first, InputIterator last){

} // range
iterator vector::erase (iterator position){

}
iterator vector::erase (iterator first, iterator last){

}
void vector::swap (vector& x){

}
void vector::clear(){

}
template <class... Args>iterator vector::emplace (const_iterator position, Args&&... args){

}
template <class... Args>  void vector::emplace_back (Args&&... args){

}

//*****Allocator*****
allocator_type get_allocator() const{

}