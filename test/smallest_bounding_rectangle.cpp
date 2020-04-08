/*====================================*\
|*          最小矩形面积覆盖          *|
|* 多边形A必须是凸包(默认：逆时针顺序)   *|
\*====================================*/
/*Author:Hacker_vision*/

// ref: https://blog.csdn.net/u012717411/article/details/47212213

#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;

const int _max = 1e3 + 10;
const double PI = acos(-1);
int n;

int sgn(double x) {  //三态函数
    if (fabs(x) < eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}

struct point {
    double x, y;
} p[_max], res[_max];

bool mult(point sp, point ep, point op) {
    return (sp.x - op.x) * (ep.y - op.y) >= (ep.x - op.x) * (sp.y - op.y);
}

bool operator<(const point &l, const point &r) {
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}

int graham(point pnt[], int n, point res[]) {  //构造凸包
    int i, len, k = 0, top = 1;
    sort(pnt, pnt + n);
    if (n == 0) return 0;
    res[0] = pnt[0];
    if (n == 1) return 1;
    res[1] = pnt[1];
    if (n == 2) return 2;
    res[2] = pnt[2];
    for (int i = 2; i < n; ++i) {
        while (top && mult(pnt[i], res[top], res[top - 1]))
            top--;
        res[++top] = pnt[i];
    }
    len = top;
    res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; --i) {
        while (top != len && mult(pnt[i], res[top], res[top - 1]))
            top--;
        res[++top] = pnt[i];
    }
    return top;  //返回凸包中点的个数
}

double len(point A, point B) {  //返回向量AB的模平方
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

double dot(point A, point B, point C) {  //点乘
    return (C.x - A.x) * (B.x - A.x) + (C.y - A.y) * (B.y - A.y);
}

double cross(point A, point B, point C) {  //叉乘
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

double minRetangleCover() {  //最小矩形面积覆盖(旋转卡壳)
    if (n < 3) return 0.0;
    res[n] = res[0];
    double ans = -1;
    int r = 1, p = 1, q;
    for (int i = 0; i < n; ++i) {
        //卡出离边 res[i]-res[i+1]最远的点
        while (sgn(cross(res[i], res[i + 1], res[r + 1]) - cross(res[i], res[i + 1], res[r])) >= 0)
            r = (r + 1) % n;
        //卡出res[i]-res[i+1]方向上正向n最远的点
        while (sgn(dot(res[i], res[i + 1], res[p + 1]) - dot(res[i], res[i + 1], res[p])) >= 0)
            p = (p + 1) % n;
        if (i == 0) q = p;
        //卡出res[i]-res[i+1]方向上负向最远的点
        while (sgn(dot(res[i], res[i + 1], res[q + 1]) - dot(res[i], res[i + 1], res[q])) <= 0)
            q = (q + 1) % n;
        double d = len(res[i], res[i + 1]);
        double temp = cross(res[i], res[i + 1], res[r]) * (dot(res[i], res[i + 1], res[p]) - dot(res[i], res[i + 1], res[q])) / d;
        if (ans < 0 || ans > temp) ans = temp;
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif  // ONLINE_JUDGE

    while (scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        n = graham(p, n, res);  //构造凸包
        printf("%.4f\n", minRetangleCover());
    }

    return 0;
}
