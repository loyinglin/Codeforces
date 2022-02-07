//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1335/problem/C)
 **题目大意：**
 有n个整数a[i]，现在需要从中选择两组数字，要求：
 1、两组数字的数量一样，每个整数只能划分到一个组内；
 2、第一组的数字各不相同，第二组的数字完全相同；
 现在希望两组数字尽可能的多，问最多一组能有几个整数。
 
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤10000)
 接下来每个样例两行，第一行整数𝑛 (1≤𝑛≤2⋅1e5)
 第二行n个整数 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑛),
 
 **输出：**
 每个样例一行，整数x，表示一组最多能够有x个整数。
 
 **Examples**
 input
 4
 7
 4 2 4 1 4 3 4
 5
 2 1 5 4 3
 1
 1
 4
 1 1 1 3
 ⁣output
 ⁣3
 ⁣1
 ⁣0
 ⁣2
 
 
 **题目解析：**
 假如没有要求2，那么直接平分，x最大值就是n/2；
 单独考虑不同数字的情况，直接算出数组中有k个不同的整数q，再算出数组中最多重复的整数w;
 大多数情况下，min(q, w)就是答案了。
 但是存在q和w会公用一个整数，比如说1.2.3,3,3这种情况，或者1.2.3.4.5.2.2情况。
 
 当w<=q-1的时候，重复的数字比较少，所以答案就是w；
 如果w>q-1的时候，重复的数字比较多，那么优先把重复的数字分配到第一组，答案就是min(w-1,q)；

 
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
const int N = 200010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int a[N];
map<int, int> hmap;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        hmap.clear();
        int maxCount = 0;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            ++hmap[k];
            maxCount = max(maxCount, hmap[k]);
        }
        
        if (hmap.size() <= maxCount - 1) {
            cout << hmap.size() << endl;
        }
        else {
            cout << min((int)hmap.size() - 1, maxCount) << endl;
        }
    }   
    
    return 0;
}
