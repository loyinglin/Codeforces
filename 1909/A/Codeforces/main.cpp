//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1909/problem/A)
 **题目大意：**
 在二维坐标系上，小明站在原点（0，0），每次可以往上下左右四个方向分别位移1个单位；
 现在有n个点，小明需要去遍历；
 但是4个方向对应的按钮，小明最多只能按3个，如果4个方向的按钮全部按过，则直接失败。
 问小明是否能够顺利完成。
  
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤10000)
 每个样例第一行，整数 𝑛 (1≤𝑛≤100)
 接下来n行整数，每行2个整数表示目标点 𝑥𝑖 , 𝑦𝑖 (−100≤𝑥𝑖,𝑦𝑖≤100 )
 
  
 **输出：**
 每个样例一行，如果可以成功则输出YES，如果失败则输出NO；
 
 **Examples**
 **input**
 6
 3
 1 -1
 0 0
 1 -1
 4
 -3 -2
 -3 -1
 -3 0
 -3 1
 4
 1 1
 -1 -1
 1 -1
 -1 1
 6
 -4 14
 -9 -13
 -14 5
 14 15
 -8 -4
 19 9
 6
 82 64
 39 91
 3 46
 87 83
 74 21
 7 25
 1
 100 -100

 **output**
 YES
 YES
 NO
 NO
 YES
 YES




 **题目解析：**
 假设只能向上、向右走，那么小明可以访问到第一象限上面的点，但是可以遍历到所有点吗？
 假设第一象限上，有四个点组成一个正方形，小明必然会有对角线的点无法访问。
 
 同理，小明站在原点上，将n个点分配到四个象限。
 当存在对角象限同时存在点时，必然无解。比如说（1，1）和（-1，-1），须要用到4个方向。
 但是这个象限处理方式，在遇到0时，比较难以处理。
 
 重新思考题目，其实4个方向，就是分别对应x坐标的正负，y坐标的正负。
 那么假设所有的点，对应到x坐标，如果没有小于零，那么对应按钮↓可以不用。
 
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
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            int a[2] = {0}, b[2] = {0};
            while (n--) {
                int x, y;
                cin >> x >> y;
                if (x != 0) a[x > 0 ? 0:1] = 1;
                if (y != 0) b[y > 0 ? 0:1] = 1;
            }
            if (a[0] + a[1] + b[0] + b[1] < 4) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
