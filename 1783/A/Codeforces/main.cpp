//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1783/problem/A)
 **题目大意：**
 有n个整数的数组，如果数组存在某个元素，等于该元素前面所有数字的和，则称这个元素为ugly；
 比如说数组 [6,3,9,6]，元素 9 = 6 + 3，则元素9是ugly的；
 现在可以任意调换数组中元素的位置，但是不能删除或者增加元素，问是否能够让数组没有ugly的元素。
  **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤2000)
 每个样例2行，第一行整数𝑛 (2≤𝑛≤50）
 第二行n个整数 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎1≤𝑎2≤⋯≤𝑎𝑛≤100)
 
  
 **输出：**
 每个样例一行，如果无解输出NO，如果有解则输出YES，接下来一行输出调整顺序后的整数数组；
  
 
 **Examples**
 **input**
 4
 4
 3 3 6 6
 2
 10 10
 5
 1 2 3 4 5
 3
 1 4 4

 **output**
 YES
 3 6 3 6
 NO
 YES
 2 4 1 5 3
 YES
 1 4 4

 
 **题目解析：**
 ugly的要求是前面元素的和，那么前面的元素如果比当前元素大，必然前面元素和会更大；
 将整数数组按照从大到小排队，由于整数元素都有>=1，那么从第3个元素开始，必然不会出现ugly元素；
 假如a1=a2，那么将最小的元素插入到a2中。（如果数组中所有元素相同，则无解）
 
 
 ************************* 题解 ***********************/
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
 
typedef long long lld;
 
class Solution {
    static const int N = 201010;
    int a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) cin >> a[i];
            sort(a, a + n, greater<int>());
            if (a[0] == a[n - 1]) cout << "NO" << endl;
            else {
                cout << "YES" << endl;
                int tmp = a[1];
                a[1] = a[n - 1];
                a[n - 1] = tmp;
                for (int i = 0; i < n; ++i) cout << a[i] << " ";
                cout << endl;
            }
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
