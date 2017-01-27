//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright © 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：
 题目大意：
 
 
 
 题目解析：
 
 
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
const int N = 1001000, M = 3010100, inf = 0x7fffffff;

char str[N * 2];
int Right[5];

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    while (scanf("%s", str + 1) != EOF) {
        int n = strlen(str + 1);
        int ans = 0;
        memset(Right, 0, sizeof(Right));
        for (int i = 1; i < n * 2; ++i) {
            int id;
            if (i <= n) {
                id = str[i] - 'A';
            }
            else {
                id = str[i - n] - 'A';
            }
            if (id < 5) { //在钻石列表里
                Right[id] = i;
                
                bool ok = 1;
                for (int i = 0; i < 5; ++i) {
                    if (Right[i] == 0) {
                        ok = 0;
                    }
                }
                if (ok) {
                    int t = i;
                    ans = max(ans, n - (t - *min_element(Right, Right + 5) + 1));
                }
            }
        }
        cout << ans << endl;
        
    }
    
    
    
    return 0;
}
