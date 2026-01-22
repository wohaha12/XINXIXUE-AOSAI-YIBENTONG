#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double x, a, y, b;
    cin >> x >> a >> y >> b;

    // 根据推导公式直接计算
    double z = (y * b - x * a) / (b - a);

    // 按要求保留两位小数
    cout << fixed << setprecision(2) << z << endl;

    return 0;
}