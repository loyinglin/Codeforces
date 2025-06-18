//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/2111/problem/E)
更改字符串
给定一个仅由拉丁字母前三个字母（即每个字符只能是 a、b 或 c ）组成的字符串 s 。
同时给定 q 个需要对该字符串执行的操作。
在每个操作中，会提供两个来自拉丁字母前三个字母集合的字母 x 和 y ，并且对于每个操作，必须执行以下两个操作之一：
1、将字符串 s 中任意一个 x 字母的出现替换为 y 字母（前提是至少存在一个 x 字母的出现）；
2、不执行任何操作。
目标是按照给定的顺序执行所有操作，使得字符串 s 在字典序上最小。
回顾一下，字符串 a 在字典序上小于字符串 b ，当且仅当满足以下条件之一：
a 是 b 的前缀，但 a ≠ b ；
在 a 和 b 第一个不同的位置上，a 中的字母在字母表中的顺序比 b 中对应位置的字母更靠前。

输入
输入包含多个测试用例。第一行包含一个整数 t（1 ≤ t ≤ 10³ ）—— 测试用例的数量。接下来是测试用例的描述。
每个测试用例的第一行包含两个整数 n 和 q（1 ≤ n, q ≤ 2×10⁵ ）—— 字符串 s 的长度和操作的数量。
每个测试用例的第二行给出字符串 s —— 一个恰好有 n 个字符的字符串，每个字符是 a、b 或 c 。
每个测试用例接下来的 q 行描述操作。每行包含两个字符 x 和 y ，每个字符都是 a、b 或 c 。
输入的额外约束：
所有测试用例中 n 的总和不超过 2×10⁵ ；
所有测试用例中 q 的总和不超过 2×10⁵ 。
输出
对于每个测试用例，输出使用给定操作后能得到的字典序最小的字符串。

 
 **Examples**
 **input**
3
2 2
cb
c b
b a
10 10
bbbbbbbbbb
b a
b c
c b
b a
c a
b c
b c
b a
a b
c a
30 20
abcaababcbbcabcbbcabcbabbbbabc
b c
b c
c a
b c
b c
b a
b c
b c
b a
b a
b a
b a
c a
b c
c a
b c
c a
c a
b c
c b



**output**
ab
aaaaabbbbb
aaaaaaaaaaaaaaabbbabcbabbbbabc


 
**题目解析：**
题目只有a、b、c三个字符，并且由于目标是字典序最小，容易知道只有c->a，b->a，c->b，b->c这几种操作；
当我们从左到右遍历字符串，遇到某个非a字符串，并且此时有对应的ca和ba，必然是会直接执行c->a或者b->a操作；（此时字典序较少）
但是c->b的操作会更加复杂，因为还要考虑后续是否有对应的ba，如果有的话需要把对应的ba操作用来把当前位置变成a；（也就是c+cb+ba=a）
同理，当字符为b，且操作有b->c和c->a时，此时也会进行操作；
那么，自然那可以想到这样的一个简单做法：
从左到右遍历字符串，当遍历到第i个字符时：
如果是a，那么直接跳过；
如果是b，那么看是否有未使用的b->a操作，有则执行；如果没有，接着看是否有未使用的b->c操作并且后续有对应的c->a，有则执行；
如果是c，那么看是否有未使用的c->a操作，有则执行c->a；如果没有，接着看是否有未使用的c->b或者b->a操作，把字符串c变成相应的b或者a；

这样的复杂度是多少呢？
O(N * Q)，也就是N平方，在这里会超时。

针对上面的操作，我们发现可以把ba、ca操作单独拿出来，因为不影响其他操作；
重点在于cb、bc的操作，并且会有cb+ba、bc+ca先后时序的关系。
我们把ba、ca、cb、bc这四个操作的顺序单独用set管理起来。
通过贪心可以知道，每次需要操作的时候，我们都是从set里面的拿到最前面的操作；
在cb+ba这样的组合情况，同样是先拿cb出来，然后从cb的位置之后开始用二分方式在ba的set里面查找最近的位置；
bc+ca情况类似，但是有点差异：bc+ca必须同时满足，才会执行操作。
这样每个字符串的操作，我们都可以在O(logN)的时间复杂度内完成，整体复杂度就是O(NlogN)。

 
 
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
            int n, q;
            cin >> n >> q;
            string str;
            cin >> str;
            set<int> ba;
            set<int> bc;
            set<int> ca;
            set<int> cb;
            for (int i = 0; i < q; ++i) {
                char x, y;
                cin >> x >> y;
                if (x == 'b' && y == 'a') {
                    ba.insert(i);
                }
                else if (x == 'b' && y == 'c') {
                    bc.insert(i);
                }
                else if (x == 'c' && y == 'a') {
                    ca.insert(i);
                }
                else if (x == 'c' && y == 'b') {
                    cb.insert(i);
                }
            }
            for (int i = 0; i < n; ++i) {
                if (str[i] == 'a') {
                    continue;
                }
                else if (str[i] == 'b') {
                    if (ba.size()) {
                        str[i] = 'a';
                        ba.erase(ba.begin());
                    }
                    else if (bc.size() && ca.size()) {
                        int start = *bc.begin();
                        if (ca.lower_bound(start) != ca.end()) {
                            str[i] = 'a';
                            ca.erase(ca.lower_bound(start));
                            bc.erase(bc.begin());
                        }
                    }
                }
                else {
                    if (ca.size()) {
                        str[i] = 'a';
                        ca.erase(ca.begin());
                    }
                    else if (cb.size()) {
                        str[i] = 'b';
                        int start = *cb.begin();
                        cb.erase(cb.begin()); // cb一定会先操作，不管是否有ba
                        if (ba.lower_bound(start) != ba.end()) {
                            str[i] = 'a';
                            ba.erase(ba.lower_bound(start));
                        }
                    }
                }
            }
            cout << str << endl;
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here..
    ac.solve();
    return 0;
}
 
