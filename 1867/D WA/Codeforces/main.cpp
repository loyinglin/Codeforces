//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1867/problem/C)
 **题目大意：**
 

 **输入：**
 第一行，整数𝑡 表示t次游戏 (1≤𝑡≤100000)
 每个样例有多行：
 第一行整数𝑛(1≤𝑛≤1e5)
 第二行整数数组s (0≤𝑠1<𝑠2<…<𝑠𝑛≤1e9)
 接下来有多行，每行一个整数y：
 如果y>=0，表示Bob从数组中移除该数字；
 y=-1，表示该次游戏结束；
 
 **输出：**
 每个样例若干行，每行一个整数x，表示要添加的整数；
 
 **Examples**
 **input**
 6
 5 3
 2 3 5 3 4
 4 2
 2 4 3 1
 1 1
 1
 3 1
 1 2 3
 5 3
 5 4 3 2 1
 6 1
 1 2 3 1 5 6

 **output**
 YES
 NO
 YES
 YES
 NO
 NO

 样例解释：
 样例一的整个操作过程 𝑙 = [1,2,3] . Now 𝑎 = [2,3,1,0,0] .
 𝑙 = [3,5,4] . Now 𝑎 = [2,3,5,3,4] = 𝑏 .
 
 



 **题目解析：**
 
 
 
 思考：
 如果去掉k的限制，变成k可以任意选择呢？
 此时可以从节点开始遍历，直到遇到访问过的节点，那么这个遍历可以分为A->B->C->...->B，A为起点，B 为重复点，C为经过的节点；
 （可以想象，一直访问下一个，总是能遇到一个访问节点）
 其实B->C->B，可以构成一个循环；
 A->B->C也可以生成，A=B,B=C，C=A最后重复的C=A，也会被B->C->B覆盖；
 所以理论上去掉k，所有数据有借。
 
 
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
    static const int N = 101010;
    int a[N];
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, k;
            cin >> n >> k;
            for (int i = 0; i < n; ++i) cin >> a[i + 1];
            map<int ,int> vis;
            int ok = 1;
            
            if (k == 1) {
                for (int i = 1; i <= n; ++i) ok = ok && (i == a[i]);
            }
            if (k == 2) {
                for (int i = 1; i <= n; ++i) ok = ok && (i != a[i]);
            }
            else {
                for (int i = 1; i <= n && ok; ++i) {
                    if (vis.find(i) != vis.end()) continue;;
                    int tmp = k, cur = i;
                    map<int, int> vec;
                    //                cout << i << " start ";
                    while (tmp--) {
                        if (vec.find(cur) != vec.end()) {
                            ok = 0;
                            break;
                        }
                        //                    cout << cur << " ";
                        vec[cur] = 1;
                        vis[cur] = 1;
                        cur = a[cur];
                    }
                    //                cout << endl;
                }
            }
            cout << (ok ? "YES" : "NO") << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 


/*
 33
 8 4
 3 1 5 7 6 2 8 3
 
 */
