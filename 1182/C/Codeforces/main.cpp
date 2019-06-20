//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1182/problem/C)
 **题目大意：**
 一段悦耳的歌词有两行，每行有两个单词，并且要求：
 1、第一行的第一个单词中元音数量，和第二行第一个单词相同；
 2、第一行的第二个单词中元音数量，和第二行第二个单词相同；
 3、第一行的第二个单词中的最后一个元音，和第二行第二个单词相同。
 
 给出n个单词，问最多能拼出多少段悦耳的歌词，每个单词只能用一次。
 
 
 输入：
 第一行n，表示n个单词；（n<=10^5）
 接下来n行，每行包括一个单词。
 所有单词的字符总数不会超过10^6。
 
 输出：
 第一行数字m，表示m段歌词。
 接下来是m段歌词，每段两行。
 
 
 
 **Examples**
 **input**
 14
 wow
 this
 is
 the
 first
 mcdics
 codeforces
 round
 hooray
 i
 am
 proud
 about
 that
 **output**
 3
 about proud
 hooray round
 wow first
 this is
 i that
 mcdics am
 
 
 **题目解析：**
 先去除无关因素的影响，把每个单词的元音提取出来，分类成：
 1、单词中元音的长度，分别是len=1、2、3.。。
 2、相同长度的元音，分别有a/e/i/o/u 五种结尾的类型。
 
 我们用vec[i][j]表示长度为i，结尾是第j个元音的字符串集合。

 再来看看题目的要求，拼出最多的歌词，并且每个单词只能用一次。
 而歌词的要求，可以表述为：
 1、从相同长度字符串中，取出结尾相同的两个单词，作为第1、2行的第二个单词；
 2、从相同长度字符串中，取出长度相同的两个单词，作为第1、2行的第一个单词；

 从这里，我们可以得到一个贪心的策略：
 a.先两个两个的取出所有长度相同并且元音结尾相同的单词，得到x组，这是可能的最大歌词数量；
 b.从剩下的所有单词中，两两取出所有长度相同的单词，得到y组，ans=min(x, y)组；
 如果x>y，那么剩下(x-y)组单词还可以两两组成歌词，此时还有ans+=(x-y)/2；
 **思考🤔：**
 当x>y时，能否取出x组中3个单词，取出1个步骤b剩下的单词，进行配对呢？
 答案是可以，但是没有必要。因为步骤b只会剩下0个或者1个某个长度的单词。
 
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

vector<string> str[1000001][5];
vector<string> len[1000001];
vector<string> bestStr;
vector<string> ans;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    char vowels[] = "aeiou";
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int x = 0, y = 0;
        for (int j = 0; j < s.length(); ++j) {
            for (int k = 0; k < 5; ++k) {
                if (s[j] == vowels[k]) {
                    ++x;
                    y = k;
                }
            }
        }
        if (x) {
            str[x][y].push_back(s);
            maxLen = max(maxLen, x);
        }
    }
    
    for (int i = 1; i <= maxLen; ++i) {
        for (int j = 0; j < 5; ++j) {
            while (str[i][j].size() > 1) {
                string s = str[i][j].back();
                str[i][j].pop_back();
                bestStr.push_back(s);
                
                s = str[i][j].back();
                str[i][j].pop_back();
                bestStr.push_back(s);
            }
            if (str[i][j].size()) {
                len[i].push_back(str[i][j].back());
            }
        }
    }
    
    for (int i = 1; i <= maxLen; ++i) {
        while (len[i].size() > 1) {
            if (bestStr.size()) {
                ans.push_back(len[i].back());
                ans.push_back(bestStr.back());
                bestStr.pop_back();
                len[i].pop_back();
                
                ans.push_back(len[i].back());
                ans.push_back(bestStr.back());
                bestStr.pop_back();
                len[i].pop_back();
            }
            else {
                break;
            }
        }
    }
    
    while (bestStr.size() >= 4) {
        string a = bestStr.back();
        bestStr.pop_back();
        string b = bestStr.back();
        bestStr.pop_back();
        string c = bestStr.back();
        bestStr.pop_back();
        string d = bestStr.back();
        bestStr.pop_back();
        ans.push_back(a);
        ans.push_back(c);
        ans.push_back(b);
        ans.push_back(d);
    }
    
    cout << ans.size() / 4 << endl;
    while (ans.size()) {
        string a = ans.back();
        ans.pop_back();
        string b = ans.back();
        ans.pop_back();
        cout << b << " " << a << endl;
    }

    return 0;
}
