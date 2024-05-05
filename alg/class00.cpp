// Copyright 2024 Gavin Gao. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <iostream>
#include <utility>

/*
1. 实现三个类，基类：Class Animal，派生类：Class Cat, Class Dog，
   并实现方法Eat，要求Animal不能实例化，Cat/Dog有各自的Eat方法，
   并保证void Print(Animal* pAnimal)能调用到相应的方法。
*/

class Animal {
 public:
  virtual void Eat() = 0;
};

class Cat : public Animal {
 public:
  void Eat() { std::cout << "cat eat." << std::endl; }
};

class Dog : public Animal {
 public:
  void Eat() { std::cout << "dog eat." << std::endl; }
};

void Print(Animal *pAnimal) { pAnimal->Eat(); }

/*
2. 针对如下类，添加构造函数，拷贝构造函数以及移动构造函数
*/

class Vector {
 public:
  Vector(int sz, int vec[]) : _size(sz) {
    std::cout << "构造函数" << std::endl;
    _p = new int[sz];
    for (int i = 0; i < sz; i++) _p[i] = vec[i];
  }

  Vector(const Vector &rhs) {
    std::cout << "拷贝构造函数" << std::endl;
    if (rhs._p != NULL) {
      _size = rhs._size;
      _p = new int[rhs._size];
      for (int i = 0; i < rhs._size; i++) _p[i] = rhs._p[i];
    }
  }

  Vector(Vector &&rhs) {
    std::cout << "移动构造函数" << std::endl;
    if (rhs._p != NULL) {
      _p = rhs._p;
      _size = rhs._size;
      rhs._p = NULL;
      rhs._size = 0;
    }
  }

  ~Vector() {
    std::cout << "析构函数" << std::endl;
    if (_p != NULL) delete _p;
  }

 private:
  int _size;
  int *_p;
};

class Base {
 public:
  int a;
  Base() {
    a = 0;
    std::cout << "base constructor..." << std::endl;
  }
  void print() { std::cout << a << std::endl; }
  virtual void fun() {}
  ~Base() { std::cout << "base destructor..." << std::endl; }
};

class Derived : public Base {
 public:
  int a;
  Derived() {
    a = 1;
    std::cout << "derived constructor..." << std::endl;
  }
  virtual void fun() {}
  virtual void fun01() {}
  ~Derived() { std::cout << "derived destructor..." << std::endl; }
};

int main() {
  Animal *pAnimal;

  pAnimal = new Cat;
  Print(pAnimal);

  pAnimal = new Dog;
  Print(pAnimal);

  int arr[] = {1, 2, 3};
  Vector va(3, arr);
  Vector vb(va);
  Vector vc = std::move(va);

  Base aa;
  Derived bb;
  bb.print();
  std::cout << sizeof(aa) << ", " << sizeof(bb) << std::endl;

  return 0;
}
