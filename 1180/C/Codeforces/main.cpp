//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1180/problem/C)
 **题目大意：**
 有一个数组a，长度为n；
 现在有一个操作，从数组最前面（a[0],a[1]）拿出两个数字假设是x，y；
 如果x<y，则把x放在数组的最后面，把y放在数组的最前面；
 如果x>=y,则把x放在数组的最前面，把y放在数组的最前面；
 
 问这个操作进行若干次之后，拿出来的数字x、y是什么；
 
 输入：
 第一行，两个整数𝑛 and 𝑞 (2≤𝑛≤10^5, 0≤𝑞≤3⋅10^5)，分别表示数组长度和询问次数；
 接下来有n个整数，𝑎1, 𝑎2, ..., 𝑎𝑛, where 𝑎𝑖 (0≤𝑎𝑖≤10^9)
 接下来有q行，每行一个整数𝑚𝑗,(1≤𝑚𝑗≤10^18)
 
 
 输出：
 对于q个询问，每个输出一行，一行有两个整数x、y；
 
 
 Examples
 input
 5 3
 1 2 3 4 5
 1
 2
 10
 output
 1 2
 2 3
 5 2

 >f样例解释：
 原始数组是[1,2,3,4,5]，在每次操作之前，数字的样子：
 [1,2,3,4,5]
 [2,3,4,5,1]
 [3,4,5,1,2]
 [4,5,1,2,3]
 [5,1,2,3,4]
 [5,2,3,4,1]
 [5,3,4,1,2]
 [5,4,1,2,3]
 [5,1,2,3,4]
 [5,2,3,4,1]
 
 每次操作都是拿出前两个。

 
 **题目解析：**
 题目的样例已经很明显阐述了一个规律： 若干次之后，数组中最大值会始终占据第一位。
 根据题目的其他描述，每次拿出来的A、B两个数字，在数组最大值放置在第一位之后，剩余的1~n-1的位置会不断轮换。
 
 为了实现简单，我们不去记录他最大值是什么。
 直接按照题目要求操作n次，记录其中每次操作的值；此时数组的最大值就会在最左边，接下来的操作会使得1~n-1数组开始循环。
 
 对于q次询问，每次先看询问值mj是否小于n， 是的话可以直接用原来存储的值；
 否则就直接取余，再从1~n-1找到下一个值。
 
 为了实现方便，这里n次的模拟可以使用双端队列deque来辅助实现。
 
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
const int N = 100010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

pair<int, int> ans[M];
int r[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    lld n, t;
    cin >> n >> t;
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        q.push_back(k);
    }
    
    for (int i = 1; i < n; ++i) {
        int a = q.front();
        q.pop_front();
        int b = q.front();
        q.pop_front();
        ans[i] = make_pair(a, b);
        if (a > b) {
            q.push_front(a);
            q.push_back(b);
        }
        else {
            q.push_front(b);
            q.push_back(a);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        r[i] = q.front();
        q.pop_front();
    }
    

    while (t--) {
        lld k;
        cin >> k;
        if (k < n) {
            cout << ans[k].first << " " << ans[k].second << endl;
        }
        else {
            --k;
            k = k % (n-1);
            cout << r[0] << " " << r[k + 1] << endl;
        }
    }
    
    return 0;
}
