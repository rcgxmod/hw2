#include <iostream>
#include <stack>
using namespace std;
 int Ack( int m,  int n) {
    stack<pair<int, int>> stk;
    stk.push(make_pair(m, n));
    //使用stack來模擬遞迴過程
    while (!stk.empty()) {
        pair< int,  int> p = stk.top();
        stk.pop();

        m = p.first;
        n = p.second;

        if (m == 0) {
            n = n + 1;
        }
        else if (n == 0) {
            stk.push(make_pair(m - 1, 1));
            continue;
        }
        //當 m>0 and n>0時
        else {
            stk.push(make_pair(m - 1, 0)); // 
            stk.push(make_pair(m, n - 1)); // 
            continue;
        }
        //如果堆疊不為空，則更新頂端的n值為計算結果
        if (!stk.empty()) {
            stk.top().second = n; //
        }
    }

    return n;
}

int main() {
     int m, n;
    cout << "輸入 m,n: ";
    cin >> m >> n;
    //計算並輸出非遞迴版本的Ack函數結果
    cout << "Ack(" << m << ", " << n << ") = " << Ack(m, n) << endl;
    return 0;
}
