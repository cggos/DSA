#include "alg/algorithm.h"

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// int的字长
int world_length() {
  int i;
  unsigned int v = ~0;
  for (i = 1; (v = v >> 1) > 0; ++i)
    ;
  return i;
}

// 2015北航,七题
void test7() {
  char s[100], *p = s, max;
  while (scanf("%c", p++) != EOF)
    ;
  max = *s;
  p = s;
  while (*p++ != '\0') {
    if (*p > max) max = *p;
  }
  printf("%d", max);
}

void test_abc() {
  double dval = 3.0;
  const int &ival = dval;

  std::cout << std::endl;
}

/**
 * @brief
 * @note 机器数 为 补码
 * @ref https://blog.csdn.net/zl10086111/article/details/80907428
 */
void test_complementary_code() {
  const int N_INT = sizeof(int);
  const int N_CHR = sizeof(char);
  const int N_POINTER = sizeof(void *);

  std::cout << "type size (byte): "
            << "char " << N_CHR << ", int " << N_INT << ", pointer " << N_POINTER << std::endl;

  int a = 500;
  char c = *(char *)&a;
  std::bitset<N_INT * 8> ba(a);
  std::bitset<N_CHR * 8> bc(c);
  std::cout << a << ", " << ba << "\n" << int(c) << ", " << bc << std::endl;

  int e = -9;
  std::bitset<N_CHR * 8> be(e);  // 1000 1001 [原码] -- 1111 0110 [反码] -- 1111 0111 [补码]
  std::cout << be << std::endl;  // out: 1111 0111

  int d = -0x00000080;
  d = d >> 1;
  std::bitset<32> bd(d);
  std::cout << bd << std::endl;

  std::cout << std::endl;
}

void test_arr_pointer() {
  int arr[6] = {0, 1, 2, 3, 4, 5};
  int *ptr = (int *)(&arr + 1);
  std::cout << *(ptr - 1) << ", " << (arr + 1)[2] << std::endl;  // 5, 3

  std::cout << std::endl;
}

void test_map() {
  map<int, string> mapStudent;
  mapStudent.insert(pair<int, string>(1, "student_one"));
  mapStudent.insert(pair<int, string>(2, "student_two"));
  mapStudent.insert(pair<int, string>(3, "student_three"));

  map<int, string>::reverse_iterator iter;
  for (iter = mapStudent.rbegin(); iter != mapStudent.rend(); iter++)
    cout << iter->first << "  " << iter->second << endl;

  std::cout << std::endl;
}

void test_lambda_exp() {
  std::vector<int> vi(5, 0);
  std::for_each(vi.begin(), vi.end(), [](int &v) { return v = 1; });
  for (auto v : vi) std::cout << v << std::endl;

  std::cout << std::endl;
}

void test_precision() {
  float f = std::sqrt(9.0f) - 3.0f;
  std::cout << std::fixed << std::setprecision(20) << f << std::endl;

  std::cout << std::endl;
}

int main() {
  test_abc();
  test_complementary_code();
  test_arr_pointer();
  test_map();
  test_lambda_exp();
  test_precision();
  return 0;
}