#include <iostream>
#include <iomanip> // 用于格式化输出
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    // 设置每个整数占8个字符宽度，右对齐输出
    cout << setw(8) << right << a << " " 
         << setw(8) << right << b << " " 
         << setw(8) << right << c << endl;
    return 0;
}
