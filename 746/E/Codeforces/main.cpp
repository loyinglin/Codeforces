//
//  main.cpp
//  Codeforces
//
//  Created by loying on 16/7/27.
//  Copyright © 2016年 loying. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/746/problem/E
 题目大意：
 小明有n张卡片，每张卡片上有一个数字a[i];
 小红有m张卡片，卡片上的数字分别从1~m；
 现在小明可以和小红交换卡片，每次用他的一张卡片去交换小红的一张卡片；
 要求：小明所有奇数的卡片和偶数的卡片一样多，并且每一张的数字各不相同。
 n and m (2 ≤ n ≤ 2·1e5, 1 ≤ m ≤ 1e9)
  a1, a2, ..., an (1 ≤ ai ≤ 109)
 
 如果可以达到，先输出最小的交换次数；
 然后输出n个数字b[i], b[i]=a[i]表示这张卡片没变，b[i]!=a[i]，表示小明用第i张卡片去交换了小红的第b[i]张卡片；
 如果不能达到，输出-1；
 
 
 Examples
 input
 6 2
 5 6 7 9 4 5
 output
 1
 5 6 7 9 4 2
 input
 8 6
 7 7 7 7 8 8 8 8
 output
 6
 7 2 4 6 8 1 3 5
 input
 4 1
 4 2 1 10
 output
 -1
 
 
 题目解析：
 从结果来反推。
 假设小明最后能达成条件，那么需要n/2张奇数和偶数的卡片，即是需要各不相同的奇数和偶数各n/2;
 即是小明和小红的卡片去重后，奇数和偶数的数量都要大于等于n/2;
 
 容易知道，小明需要把去重时的卡片、大于n/2张的奇偶卡片去和小红交换；
 那么对于一张奇数卡片a[i]，假设当前奇数卡片剩下sum1张，如果还有多余的卡片a[i]或者sum1>n/2 || (sum1==n/2 && 剩余卡片>1)那么这张卡需要交换；
 当所有卡片处理完之后，判断奇数、偶数卡片是否等于n/2即可。
 
 思考🤔：
 代码比较长，所以在提交之后查看别人的解法。
 其实不需要去重之后，再来遍历卡片，判断是否应该交换；
 在一开始输入的时候，如果一个卡片是重复的（之前已经出现过），或者当前类型（奇偶数）剩余的卡片已经大于等于n/2，这张卡片就是多余的，可以加入交换queue里面；
 输入完成时，会有一个交换queue，这个queue就是需要交换的卡片；
 再按照奇偶数卡片的数量，去和小红交换，最后得到奇偶卡片的数量，再判断。 
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

int a[N];
map<int, int> hashMap;
vector<int> number;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m, sum1 = 0, sum2 = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (hashMap[a[i]]) {
            ++hashMap[a[i]];
        }
        else {
            if (a[i] % 2) {
                sum1++;
            }
            else {
                sum2++;
            }
            hashMap[a[i]] = 1;
            number.push_back(a[i]);
        }
    }
    int odd = 1, even = 2, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2) { // odd
            if (sum1 > n / 2 || (sum1 == n / 2 && hashMap[a[i]] > 1)) { // odd change even
                while (even <= m) {
                    if (hashMap.find(even) == hashMap.end()) {
                        break;
                    }
                    even += 2;
                }
                if (even <= m) {
                    --hashMap[a[i]];
                    if (hashMap[a[i]] == 0) {
                        --sum1;
                    }
                    hashMap[even] = 1;
                    ++sum2;
                    a[i] = even;
                    even += 2;
                    ++ans;
                    
                }
                else {
                    break;
                }
            }
            else {
                if (hashMap[a[i]] > 1) {
                    while (odd <= m) {
                        if (hashMap.find(odd) == hashMap.end()) {
                            break;
                        }
                        odd += 2;
                    }
                    if (odd <= m) {
                        --hashMap[a[i]];
                        hashMap[odd] = 1;
                        a[i] = odd;
                        odd += 2;
                        ++sum1;
                        ++ans;
                    }
                    else {
                        break;
                    }
                }
            }
        }
        else {
            if (sum2 > n / 2 || (sum2 == n / 2 && hashMap[a[i]] > 1)) {
                while (odd <= m) {
                    if (hashMap.find(odd) == hashMap.end()) {
                        break;
                    }
                    odd += 2;
                }
                if (odd <= m) {
                    --hashMap[a[i]];
                    if (hashMap[a[i]] == 0) {
                        --sum2;
                    }
                    hashMap[odd] = 1;
                    ++sum1;
                    a[i] = odd;
                    odd += 2;
                    ++ans;
                }
                else {
                    break;
                }
            }
            else {
                if (hashMap[a[i]] > 1) {
                    while (even <= m) {
                        if (hashMap.find(even) == hashMap.end()) {
                            break;
                        }
                        even += 2;
                    }
                    if (even <= m) {
                        --hashMap[a[i]];
                        hashMap[even] = 1;
                        a[i] = even;
                        even += 2;
                        ++sum2;
                        ++ans;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    if (sum2 == n / 2 && sum1 == n / 2) {
        cout << ans << endl;
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
    }
    else {
        cout << -1 << endl;
    }
    
    return 0;
}
