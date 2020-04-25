//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1277/problem/C)
 **题目大意：**
 
 
 输入：
 
 输出：

 
 input
 
 output
 
 
 **题目解析：**
 对于某个字符结尾，可能有normal、o、on、t、tw这几种情况，分别表示为状态0、1、2、3、4；
 那么dp[i][j]表示，第i个字符，以状态j结尾时，需要去掉的最少字符数量；
 
 对于第i个字符，都可以有dp[i][j] = dp[i-1][j] + 1;
 同时，根据字符内容，有特定的转移方案：
 a[i]='o', dp[i-1][1] = dp[i-1][0]；

 
 
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
const int N = 201000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

string a;
int dp[N][5];
pair<int, int> last[N][5];

void compare(int i, int j, int x, int y) {
    if (dp[i][j] > dp[x][y]) {
        dp[i][j] = dp[x][y];
        last[i][j] = make_pair(x, y);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin >> t;
    while (t--) {
        cin >> a;
        int n = (int)a.length();
        
        for (int j = 0; j < 5; ++j) {
            dp[0][j] = n;
            last[0][j] = make_pair(0, 0);
        }
        if (a[0] == 'o') {
            dp[0][1] = 0;
        }
        else if (a[0] == 't') {
            dp[0][3] = 0;
        }
        else {
            dp[0][0] = 0;
        }
        
        for (int i = 1; i < n; ++i) {
            // 不取a[i]
           for (int j = 0; j < 5; ++j) {
               dp[i][j] = dp[i - 1][j] + 1;
               last[i][j] = make_pair(i - 1, j);
            }
            
            // 取a[i]， normal、o、on、t、tw这几种情况，分别表示为状态0、1、2、3、4；
            if (a[i] == 'o') {
                compare(i, 1, i-1, 0);
                compare(i, 1, i-1, 1);
                compare(i, 1, i-1, 2);
                compare(i, 1, i-1, 3);
            }
            else if (a[i] == 'n') {
                compare(i, 2, i - 1, 1);
                
                compare(i, 0, i-1, 0);
                compare(i, 0, i-1, 2);
                compare(i, 0, i-1, 3);
                compare(i, 0, i-1, 4);
            }
            else if (a[i] == 't') {
                compare(i, 3, i-1, 0);
                compare(i, 3, i-1, 1);
                compare(i, 3, i-1, 2);
                compare(i, 3, i-1, 3);
                compare(i, 3, i-1, 4);
            }
            else if (a[i] == 'w') {
                compare(i, 4, i-1, 3);
                
                compare(i, 0, i-1, 0);
                compare(i, 0, i-1, 1);
                compare(i, 0, i-1, 2);
                compare(i, 0, i-1, 4);
            }
            else if (a[i] == 'e') {
                compare(i, 0, i-1, 0);
                compare(i, 0, i-1, 1);
                compare(i, 0, i-1, 3);
                compare(i, 0, i-1, 4);
            }
            else {
                compare(i, 0, i-1, 0);
                compare(i, 0, i-1, 1);
                compare(i, 0, i-1, 2);
                compare(i, 0, i-1, 3);
                compare(i, 0, i-1, 4);
            }
        }
        long index = min_element(dp[n - 1], dp[n - 1] + 5) - dp[n - 1];
        
        cout << dp[n-1][index] << endl;
        
        long x = n - 1, y = index;
        while (x != 0 || y != 0) {
            pair<int, int> fp = last[x][y];
            if (dp[fp.first][fp.second] < dp[x][y]) {
                printf("%d ", x + 1);
            }
            x = fp.first, y = fp.second;
        }
        puts("");
    }
           
    
    return 0;
}


/**
 4
 onetwone
 testme
 oneoneone
 twotwo
 
 twoone
 
 

 int main(int argc, const char * argv[]) {
     // insert code here...
     int t;
     cin >> t;
     while (t--) {
         cin >> a;
         int n = (int)a.length();
         
         for (int j = 0; j < 5; ++j) {
             dp[0][j] = n;
         }
         if (a[0] == 'o') {
             dp[0][1] = 0;
         }
         else if (a[0] == 't') {
             dp[0][3] = 0;
         }
         else {
             dp[0][0] = 0;
         }
         
         for (int i = 1; i < n; ++i) {
             // 不取a[i]
            for (int j = 0; j < 5; ++j) {
                dp[i][j] = dp[i - 1][j] + 1;
             }
             
             // 取a[i]， normal、o、on、t、tw这几种情况，分别表示为状态0、1、2、3、4；
             if (a[i] == 'o') {
                 dp[i][1] = min(dp[i][1], *min_element(dp[i-1], dp[i-1] + 4));
             }
             else if (a[i] == 'n') {
                 dp[i][2] = min(dp[i][2], dp[i - 1][1]);
                 vector<int> tmp = {dp[i-1][0], dp[i-1][2], dp[i-1][3], dp[i-1][4]};
                 sort(tmp.begin(), tmp.end());
                 dp[i][0] = min(dp[i][0], tmp.front());
             }
             else if (a[i] == 't') {
                 dp[i][3] = min(dp[i][3], *min_element(dp[i-1], dp[i-1] + 5));
             }
             else if (a[i] == 'w') {
                 dp[i][4] = min(dp[i][4], dp[i - 1][3]);
                 vector<int> tmp = {dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][4]};
                 sort(tmp.begin(), tmp.end());
                 dp[i][0] = min(dp[i][0], tmp.front());
             }
             else if (a[i] == 'e') {
                 vector<int> tmp = {dp[i-1][0], dp[i-1][1], dp[i-1][3], dp[i-1][4]};
                 sort(tmp.begin(), tmp.end());
                 dp[i][0] = min(dp[i][0], tmp.front());
             }
             else {
                 dp[i][0] = min(dp[i][0], *min_element(dp[i-1], dp[i-1] + 5));
             }
         }
         int ans = *min_element(dp[n - 1], dp[n - 1] + 5);
         
         cout << ans << endl;
         
 //        for (int i = n - 1; i >= 0; --i) {
 //            int val_min = *min_element(dp[i], dp[i] + 5);
 //            if (val_min == ans) {
 //                continue;
 //            }
 //            else {
 //                --ans;
 //                printf("%d ", i + 2);
 //            }
 //        }
 //        puts("");
     }
            
     
     return 0;
 }     
 */
