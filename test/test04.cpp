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

/*
3. 说说下面代码的问题以及如何改正(已改)
*/

class Base {
 public:
  Base() {}
  Base(int size) { _p1 = new int[size]; }
  ~Base() { delete _p1; }

 public:
  int *_p1;
};

class Derive : public Base {
 public:
  Derive(int size) {
    _p2 = new int[size];
    if (_p1) *_p1 = 10;
  }
  ~Derive() { delete _p2; }

 private:
  int *_p2;
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

  Base *p = new Derive(10);
  delete p;

  return 0;
}
