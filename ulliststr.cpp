#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  if (tail_!= nullptr){
    if (tail_->last < ARRSIZE){
      tail_->val[tail_->last] = val;
      tail_->last++;
    }
    else{
      Item* new_node = new Item();
      tail_->next = new_node;
      new_node->prev = tail_;
      tail_ = new_node;
      new_node->val[0] = val;
      new_node->last = 1;
    }
  }
  else{ // tail is empty, so list is empty
      Item* new_node = new Item();
      head_ = new_node;
      tail_ = new_node;
      new_node->val[0] = val;
      new_node->last = 1;

  }
  size_++;
}

 void ULListStr::pop_back()
 {
  if (empty())
  {
    return;
  }
  if (tail_->last - tail_->first >1){
    tail_->val[tail_->last - 1] = "";
    tail_->last--;
  }
  else{
    Item* temp = tail_;
    if (head_ == tail_){
      head_ = nullptr;
      tail_ = nullptr;
    }
    else{
      tail_->prev->next = nullptr;
      tail_ = tail_->prev;
    }
    delete temp;
  }  
  size_--;
 }
 

void ULListStr::push_front(const std::string& val)
{
  if (head_!= nullptr){
    if (head_->first > 0){
      head_->first--;
      head_->val[head_->first] = val;
    }
    else{
      Item* new_node = new Item();
      head_->prev = new_node;
      new_node->next = head_;
      head_ = new_node;
      new_node->first = ARRSIZE-1;
      new_node->last = ARRSIZE;
      new_node->val[ARRSIZE-1] = val;
      
    
    }
  }
  else{ // tail is empty, so list is empty
      Item* new_node = new Item();
      head_ = new_node;
      tail_ = new_node;
      new_node->val[0] = val;
      new_node->last = 1;

  }
  size_++;
}


void ULListStr::pop_front()
{
  if (empty())
  {
    return;
  }
  if (head_->last - head_->first >1){
    head_->val[head_->first] = "";
    head_->first++;
  }
  else{
    Item* temp = head_;
    if (head_ == tail_){
      head_ = nullptr;
      tail_ = nullptr;
    }
    else{
      head_->next->prev = nullptr;
      head_ = head_->next;
    }
    delete temp;
  }  
  size_--;
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc>=size_){
    return nullptr;
  }
  Item* curr = head_;
  while(curr != nullptr){
    size_t curr_node_size = curr->last - curr->first;
    if (loc < curr_node_size){
      return &curr->val[curr->first + loc];
    }
    loc -= curr_node_size;
    curr = curr->next;
  }
  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
