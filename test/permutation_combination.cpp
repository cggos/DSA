#include <stdio.h>

/**
 * @brief 使用递归函数计算一个给定的数的阶乘
 * 
 * @param i 
 * @return double 
 */
double factorial(unsigned int i) {
    if (i <= 1) {
        return 1;
    }
    return i * factorial(i - 1);
}

/**
 * @brief 斐波那契数列：当n>1时，第n个元素的值等于第n-1个元素和n-2个元素的和
 * 
 * @param n 
 * @return int 
 */
int fibonaci(int i) {
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;
    return fibonaci(i - 1) + fibonaci(i - 2);
}

/**
 * @brief n块饼，每天吃1~3块，吃完为止，问一共有多少种不同的吃法
 *        eg: 10 --> 274
 * @param n 
 * @return int 
 */
int f1(int n) {
    if (n <= 0)  // n == 0 时，返回1；小于0，返回0
        return n == 0;
    return f1(n - 1) + f1(n - 2) + f1(n - 3);
}

/**
 * @brief n块饼干分t天吃完，每天吃1块或2块，问有多少种不同的吃法
 *        eg: (10, 7) --> 35
 * @param n 
 * @param t 
 * @return int 
 */
int f2(int n, int t) {
    if (n > 2 * t || n < t)
        return 0;
    else if (t == 1)
        return 1;
    else
        return f2(n - 1, t - 1) + f2(n - 2, t - 1);
}

int main() {
    printf("%d\n", f1(10));
    printf("%d\n", f2(10, 7));
}