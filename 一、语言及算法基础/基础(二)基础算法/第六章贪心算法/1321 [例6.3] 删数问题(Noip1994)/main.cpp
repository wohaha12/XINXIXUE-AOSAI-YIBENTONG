#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. 优化 I/O 效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    int s;

    // 2. 读取输入
    // n 是高精度数，必须用字符串读入
    if (!(cin >> n >> s)) return 0;

    // 3. 核心贪心逻辑：执行 s 次删除操作
    for (int k = 0; k < s; ++k) {
        int len = n.length();
        int i = 0;
        
        // 寻找第一个“递减区间”的起点
        // 即找到第一个满足 n[i] > n[i+1] 的位置
        // 这样删掉 n[i] 后，更小的 n[i+1] 会补位上来，使高位变小
        while (i < len - 1 && n[i] <= n[i+1]) {
            i++;
        }
        
        // 删除找到的这个字符
        // 如果循环正常结束没找到递减点（即数字是升序的，如 12345），
        // 那么 i 会停在 len-1，正好删除最后一个数字
        n.erase(i, 1);
    }

    // 4. 处理前导零
    // 例如结果是 "0013"，需要变成 "13"
    // 注意：如果结果就是 "0"，不能把这个唯一的 0 删掉
    while (n.length() > 1 && n[0] == '0') {
        n.erase(0, 1);
    }

    // 5. 输出结果
    cout << n << endl;

    return 0;
}
