#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    map<int, string> mapStudent;

    mapStudent.insert(pair<int, string>(1, "student_one"));

    mapStudent.insert(pair<int, string>(2, "student_two"));

    mapStudent.insert(pair<int, string>(3, "student_three"));

    map<int, string>::reverse_iterator iter;

    for (iter = mapStudent.rbegin(); iter != mapStudent.rend(); iter++)
        cout << iter->first << "  " << iter->second << endl;

    std::vector<int> vi(5, 0);
    std::for_each(vi.begin(), vi.end(), [](int &v) { return v = 1; });
    for (auto v : vi) std::cout << v << std::endl;

    float f = std::sqrt(9.0f) - 3.0f;
    std::cout << std::fixed << std::setprecision(20) << f << std::endl;
}