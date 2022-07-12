#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void test_abc() {
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
}

void test_bit() {
  int a = -0x00000080;
  a = a >> 1;
  std::bitset<32> bs(a);
  std::cout << bs << std::endl;
}

void test_map() {
  map<int, string> mapStudent;
  mapStudent.insert(pair<int, string>(1, "student_one"));
  mapStudent.insert(pair<int, string>(2, "student_two"));
  mapStudent.insert(pair<int, string>(3, "student_three"));

  map<int, string>::reverse_iterator iter;
  for (iter = mapStudent.rbegin(); iter != mapStudent.rend(); iter++)
    cout << iter->first << "  " << iter->second << endl;
}

void test_lambda_exp() {
  std::vector<int> vi(5, 0);
  std::for_each(vi.begin(), vi.end(), [](int &v) { return v = 1; });
  for (auto v : vi) std::cout << v << std::endl;
}

void test_precision() {
  float f = std::sqrt(9.0f) - 3.0f;
  std::cout << std::fixed << std::setprecision(20) << f << std::endl;
}

int main() {
  void test_abc();
  void test_bit();
  void test_map();
  void test_lambda_exp();
  void test_precision();
  return 0;
}
