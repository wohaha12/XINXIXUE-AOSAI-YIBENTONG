#include <iostream>
#include <iomanip> // 用于设置输出精度

using namespace std;
int main() {
    // 阴影三角形面积150，底15，计算高
    double height = 150 * 2.0 / 15; // 高 = 20
    // 梯形上底15，下底25，计算面积
    double area = (15 + 25) * height / 2.0;
    // 输出保留两位小数
    cout << fixed << setprecision(2) << area << endl;
    return 0;
}
