//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1182/problem/B)
 **题目大意：**
 h行w列的字符，由'*'和'.'两种符号组成。
 问字符中是否仅存在一个'+'号，加号的组成方式：
 1、中心点是一个'*'号；
 2、中心点的上下左右四个方向有一个或以上的连续'*'符号；
 
 并且，除了这个'+'号，其他左右的字符都是'.'。
 
 如果满足上面的条件，则输出"YES"，否则输出"NO"。
 
 
 
 输入：
 第一行是h, w;  (1≤ℎ, 𝑤≤500)
 接下来是h行字符，每行有w个。
 
 
 输出：
 满足上面的条件，则输出"YES"，否则输出"NO"。
 
 
 **Examples**
 **input**
 5 6
 ......
 ..*...
 .****.
 ..*...
 ..*...
 **output**
 YES
 **input**
 3 5
 ..*..
 ****.
 .*...
 **output**
 NO

 
 
 **题目解析：**
 
 先找到中心点，判断中心点是否为星号；
 然后从四个方向去遍历，每个方向至少有1个星号，得到每个方向的星号；
 总的星号是否等于图中的星号。
 
 **思考🤔：**
 另外一种简单的做法，以5个星号作为基础图案，遍历整个图找到一个最小的+号。
 然后延伸去看长度，最后看是否等于所有星号字符数量。
 
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

char str[N][N];
int sumX[N], sumY[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
   
    int totalCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            totalCount += str[i][j] == '*';
            
            sumX[i] += str[i][j] == '*';
            sumY[j] += str[i][j] == '*';
        }
    }
    
    int indexX = -1, indexY = -1;
    for (int i = 0; i < n; ++i) {
        if (sumX[i] > 1) {
            if (indexX == -1) {
                indexX = i;
            }
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    
    for (int j = 0; j < m; ++j) {
        if (sumY[j] > 1) {
            if (indexY == -1) {
                indexY = j;
            }
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    
    if (str[indexX][indexY] != '*') {
        cout << "NO" << endl;
        return 0;
    }
    
    int ans = 1;
    
    int dir[4][2] =
    {
        -1, 0,
        1, 0,
        0, -1,
        0, 1
    };
    
    for (int i = 0; i < 4; ++i) {
        int tmpX = indexX, tmpY = indexY, count = 0;
        do {
            tmpX += dir[i][0];
            tmpY += dir[i][1];
            if (tmpX < 0 || tmpX > n || tmpY < 0 || tmpY > m || str[tmpX][tmpY] != '*') {
                break;
            }
            ++count;
        } while (1);
        if (count <= 0) {
            cout << "NO" << endl;
            return 0;
        }
        else {
            ans += count;
        }
    }
    
    if (ans == totalCount) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
