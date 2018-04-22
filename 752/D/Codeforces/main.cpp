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
 现在可以从k个字符串中，选择若干个字符串拼成一个新的回文串str，要求每个字符串只能用一次，并且不能改变原有字符串的字符排列顺序；
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
 
 
 题目解析：
 每个字符串分两种，第一种是自身为回文，第二种是自身不为回文。
 自身为回文串有两种选择，放在中心点（单独一个）和不放在中心点（两两配对分在左右）；
 自身不为回文串的字符串str，可以和str的reverse组合回文串；（比如abc和cba）
 我们把字符串相同的放到同一个桶，把桶按照字符串是否为回文分成两类。
 对于非回文串str，每次从str的桶里找一个最大的key值x，再从reverse(str)的桶里找一个最大的key值y，只要x+y>0，那么就组成一个匹配；
 对于回文串paliStr，每次从paliStr的桶里找key值最大的两个x和y，如果x+y>0，那么就组成一个匹配；
 这里有个trick：因为paliStr还可以单独放在中间，如果paliStr的两个权值是-3和5，那么选中-3其实是不划算的。
 但是如果只选择x>0&&y>0的话，假设有多个-3和5的组合，就会失去-3+5=2的额外收益。
 抉择是根源是在于paliStr可以选择放在中间！但是中间其实只能有一个字符串。
 于是可以采取额外补偿的方式，我们还是采用x+y>0的选择，但是保留一个addition的收益，类似-3和5的组合，addition的收益是3；
 同理，如果只剩下一个回文串，那么addition的收益是该回文串。
 最后计算所有的收益和+addition收益得到答案。
 
 
 更好理解addition的方式，是把组合看成单体的，比如说pair(-3, 5), pair(2, 3)；把剩下的单个，也视为单体；
 然后从所有的单体中选择一个，放入中间的收益。
 
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
