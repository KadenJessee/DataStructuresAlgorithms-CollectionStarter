#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>

class Collection {
protected:
    double *array_;
    int size_; //this is the size
    int capacity_;
public:
  Collection();
  Collection(int size);
  virtual int getSize() const;
  virtual int getCapacity() const;
  virtual void add(double item);
  virtual double get(int ndx) const;
  virtual int find(double needle) const;
  virtual double getFront() const;
  virtual double getEnd() const;
  virtual void removeFront();
  virtual void removeEnd();
  virtual void remove(double item);
  virtual double& operator[](int ndx);

  virtual Collection& operator-(int count);
  virtual Collection& operator+(double item);
  virtual Collection& operator+(const Collection& other);
  //deep copy constructor
  Collection(const Collection& other);
  virtual Collection& operator<<(double item);
  friend std::ostream& operator<<(std::ostream& out, const Collection& other);
  Collection& operator = (const Collection & other);
  void resize();
  ~Collection();
};
#endif
