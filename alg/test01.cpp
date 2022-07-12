#include <bitset>
#include <iostream>

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
  int a = -0x00000080;
  a = a >> 1;
  std::bitset<32> bs(a);
  std::cout << bs << std::endl;

  {
    Base aa;
    Derived bb;
    bb.print();
    std::cout << sizeof(aa) << ", " << sizeof(bb) << std::endl;
  }

  double dval = 3.0;
  const int &ival = dval;

  int a_n = 500;
  char *a_c = (char *)&a_n;
  std::cout << int(*a_c) << std::endl;

  std::cout << sizeof(char *) << std::endl;
  std::cout << sizeof(int) << std::endl;

  int arr[6] = {0, 1, 2, 3, 4, 5};
  int *ptr = (int *)(&arr + 1);
  std::cout << *(ptr - 1) << ", " << (arr + 1)[2] << std::endl;  // 5, 3

  return 0;
}
