#include "Collection.h"
#include <fstream>
#include <array>
#include <string>
#include <ostream>
#include <vector>
using namespace std;

//default constructor
Collection::Collection(){
    capacity_ = 8;
    array_ = new double[capacity_];
    size_ = 0;
}
//constructor with parameters
Collection::Collection(int size){
    capacity_ = size;
    array_ = new double[capacity_];
    size_ = 0;

}
//return size
int Collection::getSize() const{
   return size_;
}
//return capacity
int Collection::getCapacity() const{
   return capacity_;
}
//return index at ndx
double Collection::get(int ndx) const{
   if(ndx >= size_ || ndx < 0){
       throw out_of_range("Out of range");
   }
   return array_[ndx];
}
//get value at front of array
double Collection::getFront() const{
   if(size_ == 0){
       throw out_of_range("Out of range");
   }
   return array_[0];
}
//get value at end of array
double Collection::getEnd() const{
   if(size_ == 0){
       throw out_of_range("Out of range");
   }
   return array_[size_ - 1];
}
//find needle at i
int Collection::find(double needle) const{
    for(int i = 0; i < size_; i++){
        if(array_[i] == needle){
            return i;
        }
    }
   return -1;
}
//adds double to end of array, if array is full, create new array (resize method)
void Collection::add(double item){
    if(size_ == capacity_){
        resize();
    }
    array_[size_] = item;
    size_++;
}
//removes first value of array, moves everything over
void Collection::removeFront(){
    if(size_ != 0){
        for(int i = 0; i < size_-1; i++){
            array_[i] = array_[i+1];
        }
        size_--;
    }

}
//removes last value of array
void Collection::removeEnd(){
    if(size_ != 0){
        size_--;
    }
}
//removed specified value from the array
void Collection::remove(double item){
    int temp = find(item);
    if(temp < 0){
        return;
    }
    size_--;
    for(int i = temp; i < size_; i++){
        array_[i] = array_[i+1];
    }
}
//allows class to be accessed like an array
double& Collection::operator[](int ndx){
   //TODO:remove tmp and return a refernce
   //to the actual value in the collection
//   double* tmp = new double(-1.0);
//   return *tmp
    if(ndx >= size_ || ndx < 0){
        throw out_of_range("Out of range");
    }
    return array_[ndx];
}
//removes specified value from array
Collection& Collection::operator-(int count){
    for(int i = 0; i < count; i++){
        removeEnd();
    }
   return *this;
}
//adds specified number to end of array
Collection& Collection::operator+(double item){
    add(item);
   return *this;
}
//adds all of elements from other collection
Collection& Collection::operator+(const Collection& other){
    for(int i = 0; i < other.size_; i++){
        this->add(other.array_[i]);
    }
   return *this;
}
//adds double to end of array
Collection& Collection::operator<<(double item){
    this->add(item);
   return *this;
}
//outputs values in array
std::ostream& operator<<(std::ostream& out, const Collection& other){
    for(int i = 0; i < other.size_; i++){
        out << other.array_[i] << " ";
    }
    out << endl;
   return out;
}
//overloaded assignment operator
Collection& Collection::operator=(const Collection &other) {
    size_ = 0;
    capacity_ = other.capacity_;
    delete[] this->array_;
    this->array_ = new double[capacity_];
    for(int i = 0; i < other.size_; i++){
        this->add(other.array_[i]);
    }
    return *this;
}
//deep copy
Collection::Collection(const Collection &other) {
    capacity_ = other.capacity_;
    array_ = new double(capacity_);
    size_ = 0;
    for(int i = 0; i < other.size_; i++){
        add(other.get(i));
    }
}
//destructor
Collection::~Collection() {
    delete[] this->array_;
}

//if array is full, create new array 2x large, copy
void Collection::resize() {
    double *temp = new double[capacity_ * 2];
    for(int i = 0; i < size_; i++){
        temp[i] = array_[i];
    }
    capacity_ = capacity_ * 2;
    delete[] array_;
    array_ = temp;
}