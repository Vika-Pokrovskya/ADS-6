// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
  T* mass;
  int left, right, cast;

 public:
  TPQueue() : left(0), right(0), cast(0) { mass = new T[size]; }
  bool isEmpty() const { return 0 == cast; }
  bool isFull() const { return cast == size; }
  void push(const T& value) {
    if (isFull()) {
      throw std::string("fffull");
    } else {
      int assist = left;
      mass[left % size] = value;
      T t = mass[assist % size];
      while (mass[(assist - 1) % size].prior < mass[assist % size].prior &&
             right < assist) {
        t = mass[assist % size];
        mass[assist % size] = mass[(assist - 1) % size];
        mass[(assist - 1) % size] = t;
        assist--;
      }
      cast++;
      left++;
    }
  }
  const T& pop() {
    if (isEmpty()) {
      throw std::string("empty");
    } else {
      cast-=1;
      return mass[right++ % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
