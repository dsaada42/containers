#include "../includes/map.hpp"

//***** MEMBER FUNCTIONS *****
//___Constructors___
explicit map::map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
    
}
template <class InputIterator>  map::map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
    
}    
map::map (const map& x){
    
}
//___Destructor___
map::~map( void ){
    
}
//___Operator= surcharge___
map& map::operator= (const map& x){
    
}

//***** ITERATORS *****
iterator map::begin(){
    
}
const_iterator map::begin() const{
    
}
iterator map::end(){
    
}
const_iterator map::end() const{
    
}
reverse_iterator map::rbegin(){
    
}
const_reverse_iterator map::rbegin() const{
    
}
reverse_iterator map::rend(){
    
}
const_reverse_iterator map::rend() const{
    
}
const_iterator map::cbegin() const noexcept{
    
}
const_iterator map::cend() const noexcept{
    
}
const_reverse_iterator map::crbegin() const noexcept{
    
}
const_reverse_iterator map::crend() const noexcept{
    
}

//***** CAPACITY *****
bool map::empty() const{
    
}
size_type map::size() const{
    
}
size_type map::max_size() const{
    
}

//***** ELEMENT ACCESS *****
mapped_type& map::operator[] (const key_type& k){
    
}
mapped_type& map::at (const key_type& k){
    
}
const mapped_type& map::at (const key_type& k) const{
    
}

//***** MODIFIERS *****
pair<iterator,bool> map::insert (const value_type& val){
    
}
iterator map::insert (iterator position, const value_type& val){
    
}
template <class InputIterator>  void map::insert (InputIterator first, InputIterator last){
    
}
void map::erase (iterator position){
    
}
size_type map::erase (const key_type& k){
    
}
void map::erase (iterator first, iterator last){
    
}
void map::swap (map& x){
    
}
void map::clear( void ){
    
}
template <class... Args>  pair<iterator,bool> map::emplace (Args&&... args){
    
}
template <class... Args>  iterator map::emplace_hint (const_iterator position, Args&&... args){
    
}

//***** OBSERVERS *****
key_compare map::key_comp() const{
    
}
value_compare map::value_comp() const{
    
}

//***** OPERATIONS *****
iterator map::find (const key_type& k){
    
}
const_iterator map::find (const key_type& k) const{
    
}
size_type map::count (const key_type& k) const{
    
}
iterator map::lower_bound (const key_type& k){
    
}
const_iterator map::lower_bound (const key_type& k) const{
    
}
iterator map::upper_bound (const key_type& k){
    
}
const_iterator map::upper_bound (const key_type& k) const{
    
}
pair<const_iterator,const_iterator> map::equal_range (const key_type& k) const{
    
}
pair<iterator,iterator> map::equal_range (const key_type& k){
    
}

//***** ALLOCATOR *****
allocator_type map::get_allocator() const{
    
}
