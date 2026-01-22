#include <iostream>
using namespace std;
int main() {
    char ch;
    cin >> ch;
    // 第1行：1个字符，前面2个空格（总宽度5，1+4空格，居中）
    cout << "  " << ch << endl;
    // 第2行：3个字符，前面1个空格（总宽度5，3+2空格，居中）
    cout << " " << ch << ch << ch << endl;
    // 第3行：5个字符，前面0个空格（总宽度5，5+0空格，居中）
    cout << ch << ch << ch << ch << ch << endl;
    return 0;
}