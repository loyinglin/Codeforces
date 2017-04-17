//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright © 2016年 loyinglin. All rights reserved.

/************************** 题解 **********************
 题目链接：http://codeforces.com/contest/752/problem/D
 题目大意：
 k个字符串，长度均为n；
 每个字符串有一个权值a[i]；
 现在可以从k个字符串中，选择若干个字符串拼成一个新的回文串str，要求每个字符串只能用一次，并且不能改变原有字符串的字符序列；
 str的权值为所有拼成的串的权值和，求str的最大权值。
 （注意，空串也是回文串，所有str的最大权值不小于0）
 
 1 ≤ k, n ≤ 100 000; n·k  ≤ 100 000
 - 10 000 ≤ a[i] ≤ 10 000
 
 Examples
 input
 7 3
 abb 2
 aaa -3
 bba -1
 zyz -4
 abb 5
 aaa 7
 xyx 4
 output
 12
 input
 3 1
 a 1
 a 2
 a 3
 output
 6
 input
 2 5
 abcde 10000
 abcde 10000
 output
 0
 
 
 题目解析：
 每个字符串分两种，第一种是自身为回文，第二种是自身不为回文。
 自身为回文有两种选择，放在中心点和不放在中心点。
 我们同样把每个值分成桶，相同的key放到同一个桶，把桶按照字符串是否为回文分成两类。
 先看，非回文系列。用贪心的思想，知道，只要自己和对应revs的字符串权值之和大于0即可添加
 再看，回文系列。需要两个一组添加，直到不足两个或者其中一个小于0
 这里有个trick  因为这个位置还可以放在中间，所以贪心应该是两个都大于零才放进去  -3和5这种  即使大于零 也不要
 每个桶尽可能使用  同时声明一个使用中间位置的收益
 最后在统计完所有桶收益后 取一个声明的最大值。
 
 
 
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

struct Node {
    string str;
    int value;
    
    bool operator<(const Node &tmp) const
    {
        return value > tmp.value;
    };
    Node(string first, int second):str(first), value(second){};
    Node(){};
}node[N];
map<string, int> strHash;
int keys = 0;
vector<vector<Node> > bucket(N);

bool cmp(vector<Node> &x, vector<Node> &y) {
    return false;
}

bool isPalindrome(string str) {
    bool ret = true;
    int l = 0, r = (int)str.size() - 1;
    while (l < r) {
        if (str[l] != str[r]) {
            ret = false;
            break;
        }
        else {
            ++l;
            --r;
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int k, n;
    cin >> k >> n;
    string s;
    while (k--) {
        Node p;
        cin >> p.str >> p.value;
        if (strHash.find(p.str) == strHash.end()) {
            strHash[p.str] = keys++;
        }
        bucket[strHash[p.str]].push_back(p);
    }
    for (int i = 0; i < keys; ++i) {
        sort(bucket[i].begin(), bucket[i].end());
//        cout << bucket[i][0].str;
//        for (int j = 0; j < bucket[i].size(); ++j) {
//            cout << " " << bucket[i][j].value;
//        }
//        cout<< endl;
    }
    int ans = 0, addition = 0;
    for (int i = 0; i < keys; ++i) {
        if (isPalindrome(bucket[i][0].str)) { // is palindrome
            int x = 0;
            while (x + 1 < bucket[i].size()) {
                if (bucket[i][x + 1].value >= 0) { // meaning both >= 0
                    ans += bucket[i][x].value + bucket[i][x + 1].value;
                }
                else {
                    if (bucket[i][x].value + bucket[i][x+1].value > 0) {
                        ans += bucket[i][x].value + bucket[i][x+1].value;
                        addition = max(addition, -bucket[i][x + 1].value); // additional profit
                    }
                    else {
                        addition =  max(addition, bucket[i][x].value);
                    }
                    
                    break;
                }
                x += 2;
            }
            if (x + 1 == bucket[i].size()) { // left only one
                addition =  max(addition, bucket[i][x].value);
            }
        }
        else { // not palindrome
            string paliStr = bucket[i][0].str;
            reverse(paliStr.begin(), paliStr.end());
            if (strHash.find(paliStr) != strHash.end()) {
                int src = i, dest = strHash[paliStr];
                int x = 0, y = 0;
                while (x < bucket[src].size() && y < bucket[dest].size()) {
                    if (bucket[src][x].value + bucket[dest][y].value <= 0) {
                        break;
                    }
                    else {
                        ans += bucket[src][x].value + bucket[dest][y].value;
                    }
                    ++x, ++y;
                }
                strHash.erase(bucket[src][0].str); // avoid duplicate when search another palindrome
            }

        }
    }
    ans += addition;
    cout << ans << endl;
//    sort(bucket.begin(), bucket.begin() + keys, cmp);
//    cout << bucket[0][0].str << endl;
    
    return 0;
}
