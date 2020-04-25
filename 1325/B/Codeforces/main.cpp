//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1325/problem/B)
 **题目大意：**
 给出n个整数的数组，现在将数组复制，放在数组末尾，重复n次；
 求新的数组中，最长严格递增子序列的长度是多少？
  
 **输入：**
 第一行整数t，表示样例个数；  (1≤𝑡≤100)
 接下来t个样例，每个样例2行；
 第一行，整数𝑛 (1≤𝑛≤10^5)
 第二行，n个整数  𝑎1, 𝑎2, …, 𝑎𝑛 (1≤𝑎𝑖≤10^9)
 
 **输出：**
 每个样例一行，表示最长递增子序列的长度；
 
 **Examples**
 input
 2
 3
 3 2 1
 6
 3 1 4 1 5 9
 output
 3
 5
 样例解释，3,2,1重复3次，得到[3,2,1,3,2,1,3,2,1] 最长递增子序列是[1,2,3]，长度是3；
 
 **题目解析：**
 如果n个数字不相同，重复n次之后，必然可以选出n个数字，最长递增子序列的长度是n；（因为重复n次，每次选1个数字就好）
 如果n个数字中存在相同，则相同的数字只能取一个；
 所以答案就是数组中，数字不同的个数。
 
 
 **思考🤔：**
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

bool cmp(int a, int b) {
    return a > b;
}

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int ans = 0;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            if (!mp[k]) {
                mp[k] = 1;
                ++ans;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
