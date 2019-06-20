//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1181/problem/B)
 **题目大意：**
 有一个字符串str，表示一个数字（没有前导零)，现在需要把这个数字分成两个合法的数字，并且希望和尽可能的小。
 
 输入：
 第一行，数字n，表示字符串str的长度；(2≤n≤100000)
 第二行，字符串str，表示数字；
 
 输出：
 最小的和。
 
 **Examples**
 **input**
 7
 1234567
 **output**
 1801
 **input**
 3
 101
 **output**
 11
 
 **题目解析：**
 先不考虑复杂度，对于每个位置pos，只要str[pos]不是字符0，那么就可以切分成两个字符串[0, pos) 和 [pos, n)两部分。
 那么可以枚举每一个位置，计算一遍数字的和，最终得到一个最小的数字和。
 枚举复杂度是O(N)，分割数字和计算数字和是(N)，总的复杂度是O(N^2)；
 因为n最大可以为10w，那么这个复杂度是不可以接受的。
 
 容易知道，很多位置的分割，是不可能成为最小和的值。比如说字符串1234567，如果分割成12+34567或者1+234567是明显重复的计算。
 由贪心的思想可以知道，分割出来的字符串a、b的长度应该尽可能接近。
 对于长度为n字符串，分割成长度为n/2和n-n/2 ，或者(n+1)/2和n-(n+1)/2的组合是最好的。
 
 那么是否枚举这个情况即可？
 
 并不是！因为存在一个数字0的情况。比如说数字123000321，中间的位置都是0。
 综合上面的考虑，我们可以将n/2向左延伸，直到找到一个不为零的数字，作为分割点；
 同样的，将(n+1)/2向右延伸，知道找到一个不为零的数字，作为分割点。
 
 然后从上面的两个可能，选择一个最小的值。
 
 
 时间复杂度O(N)；
 
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


string getMinStr(string a, string b) {
    if (a.length() < b.length()) {
        return a;
    }
    else if (a.length() > b.length()) {
        return b;
    }
    else {
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] < b[i]) {
                return a;
            }
            else if (a[i] > b[i]) {
                return b;
            }
        }
        return b;
    }
}

string getSumStr(string a, string b) {
    string ret;
    int add = 0;
    int indexA = a.length() - 1, indexB = b.length() - 1;
    
    while (indexA >= 0 || indexB >= 0) {
        int tmp = add;
        if (indexA >= 0) {
            tmp += a[indexA] - '0';
            --indexA;
        }
        if (indexB >= 0) {
            tmp += b[indexB] - '0';
            --indexB;
        }
        if (tmp >= 10) {
            tmp -= 10;
            add = 1;
        }
        else {
            add = 0;
        }
        ret.push_back('0' + tmp);
    }
    if (add) {
        ret.push_back('1');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string getSplitSum(string str, int pos) {
    string a(str.begin(), str.begin() + pos), b(str.begin() + pos, str.begin() + str.length());
    return getSumStr(a, b);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    cin >> n;
    string str;
    cin >> str;
    
    /*
      所有的切分都是[0, t-1], [t, n)  不同的是t的位置不同
     要求，str[t]不能为字符0.
     
     t可以是n/2,n/2+1等
     */
    
    int x = (n + 1) / 2, y = n / 2;
    string ansX = str, ansY = str;
    
    while (x < str.length() && str[x] == '0') {
        ++x;
    }
    if (x < str.length()) {
        ansX = getSplitSum(str, x);
    }
    
    while (y >= 0 && str[y] == '0') {
        --y;
    }
    if (y >= 0) {
        ansY = getSplitSum(str, y);
    }
    
    cout << getMinStr(ansX, ansY) << endl;
    
    
    return 0;
}
