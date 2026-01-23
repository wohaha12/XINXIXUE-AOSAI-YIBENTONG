#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Person {
    long long time; // 接水时间
    int id;         // 原编号
};

int main() {
    int n;
    cin >> n;

    vector<Person> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].time;
        a[i].id = i + 1;  // 编号从 1 开始
    }

    // 1. 按接水时间排序
    sort(a.begin(), a.end(), [](const Person &x, const Person &y) {
        return x.time < y.time;
    });

    // 2. 输出排队顺序（原编号）
    for (int i = 0; i < n; i++) {
        cout << a[i].id;
        if (i != n - 1) cout << " "; // 注意最后一个数字后面不加空格
    }
    cout << endl;

    // 3. 计算总等待时间
    long long totalWait = 0; // 所有人的等待时间之和
    long long sum = 0; // 当前已接水总时间（前面的累计）
    for (int i = 0; i < n; i++) {
        totalWait += sum; // 当前人要等待前面的累计时间
        sum += a[i].time; // 加上当前人的接水时间
    }

    // 4. 计算并输出平均等待时间
    double avg = (double)totalWait / n;
    printf("%.2f\n", avg);

    return 0;
}




#include<iostream>
#include<algorithm>
using namespace std;

struct Person
{
    long long time; // 接水时间
    int id;         // 原编号
}per[1010];
int everyone_wait[1010]; // 每个人的等待时间
int main(){
    int n; cin >> n;
    int total_wait = 0; // 所有人的等待时间之和
    for(int i=1;i<=n;i++){
        cin >> per[i].time;
        per[i].id = i;
    }
    sort(per + 1,per+n+1,[](const Person &a,const Person &b){
        return a.time < b.time;
    });
    
    for(int i=1;i<=n;i++){
        total_wait += per[i].time * (n - i);
        cout << per[i].id;
        if(i != n) cout << " ";
    }

    // cout << per[1].id << " ";

    // for(int i=2;i<=n;i++){
    //     everyone_wait[i] += everyone_wait[i-1] + per[i-1].time;
    //     total_wait += everyone_wait[i]; 
    //     cout << per[i].id;
    //     if(i != n) cout << " ";
    // }

    printf("\n%.2f\n",1.0 * total_wait/n);
    return 0;
}




#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int,int>> people(n);
    for(int i=0;i<n;i++){
        cin >> people[i].first;
        people[i].second = i+1;
    }

    sort(people.begin(), people.end());

    long long sum = 0;         // 当前已接水总时间（前面的累计）
    long long total_wait = 0;  // 所有人的等待时间之和
    for(int i = 0;i < n;i++){
        total_wait += sum;      // 当前人要等待前面的累计时间
        sum += people[i].first; // 加上当前人的接水时间
        cout << people[i].second;
        if(i != n - 1) cout << " ";
    }
    cout << endl;
    double avg = (double)total_wait / n;
    cout << fixed << setprecision(2) << avg << endl;
    return 0;
}