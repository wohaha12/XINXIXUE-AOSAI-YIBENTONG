#include <iostream>
using namespace std;

const int N = 1e2 + 10;
int cards[N];

int main(){
    int n; cin >> n;
    int sum = 0;
    for(int i = 0;i < n;i++){
        cin >> cards[i];
        sum += cards[i];
    }
    int avg = sum / n;
    int moves = 0;
    // 贪心策略：从左向右遍历
    // 我们只需要遍历到倒数第二堆 (n-1)，因为前 n-1 堆处理好了，最后一堆自然就平衡了
    for (int i = 0; i < n - 1; ++i) {
        // 如果当前堆已经是平均值，不需要操作
        if (cards[i] == avg) {
            continue;
        }
        // 核心逻辑：
        // 当前堆与平均值的差额（正数代表多了，负数代表少了）
        // 我们不关心具体移动几张，只要有移动，步数就+1
        // 将这个差额“转移”给下一堆
        int diff = cards[i] - avg;
        
        cards[i+1] += diff; // 下一堆承接了上一堆的盈亏
        moves++;            // 发生了一次移动操作
    }
    // for(int i = 0;i < n - 1;i++){
    //     if(cards[i] != avg){
    //         cards[i + 1] += cards[i] - avg;
    //         moves++;
    //     }
    // }
    cout << moves << endl;
    return 0;
}
