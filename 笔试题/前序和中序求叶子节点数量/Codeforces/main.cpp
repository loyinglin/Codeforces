//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接]
 **题目大意：**
 - 给定一颗二叉树，二叉树每个节点都有一个唯一的整数值代表节点，在遍历时，我们使用节点的整数值作为标记
 - 输入：二叉树的前序和中序 遍历结果，分别是第一行与第二行
 - 输出 ：二叉树叶子节点的个数
 - 输入格式
 - 二叉树 的前序和中序 遍历结果，以数组序列表示
 - 输出格式
 - 二叉树的节点数量
 - 输入样例
 3
 1 3 4
 3 1 4
 - 输出样例
 - 2
 - 数据范围
 
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
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

int a[N], b[N];


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int idx = 0, idy = 0, ans = 0;
    map<int, int> hMap;
    while (idy < n) {
        if (hMap[b[idy]]) { // 已经出现过，跳过
            ++idy;
        }
        else { // 找到一个最左边的节点
            while (idx < n) {
                hMap[a[idx]] = 1;
                if (a[idx] == b[idy]) {
                    break;
                }
                ++idx;
            }
            
        }
    }
    cout << ans << endl;
    
    return 0;
}


/**
 7
 1 2 4 6 7 3 5
 4 6 7 2 1 5 3
 
 */
