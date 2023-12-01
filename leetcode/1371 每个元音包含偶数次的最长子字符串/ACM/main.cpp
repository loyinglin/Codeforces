//
//  main.cpp
//  ACM
//
//  Created by loyinglin on 16/9/4.
//  Copyright © 2016年 loyinglin. All rights reserved.
/************************** 题解 **********************
 [题目链接](https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)
 **题目大意：**
 给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。


 示例 1：

 输入：s = "eleetminicoworoep"
 输出：13
 解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。
 示例 2：

 输入：s = "leetcodeisgreat"
 输出：5
 解释：最长子字符串是 "leetc" ，其中包含 2 个 e 。
 示例 3：

 输入：s = "bcbcbc"
 输出：6
 解释：这个示例中，字符串 "bcbcbc" 本身就是最长的，因为所有的元音 a，e，i，o，u 都出现了 0 次。
  

 提示：

 1 <= s.length <= 5 x 10^5
 s 只包含小写英文字母。



 **题目解析：**

 从简单的开始思考，假如要求只有一个字母a出现偶数次；
 那么如果数组中字母a出现偶数次，则直接满足；如果a出现奇数次，那么去掉最左边的a及左边的部分，或者去掉最右边a及右边的部分；（复杂度O(N) )
 由此我们知道，肯定是去掉最初出现的字母a，或者最后出现的字母a。
 
 现在要求变成字母a、o出现偶数次，能否延续上面的思路：去掉最左边或者最右边的某一些部分，使得剩下部分满足要求？
 理论上是可行的，左边去掉部分，可能是奇数或者偶数个a，有可能是奇数或者偶数个o，右边同理；剩下的部分要求a和o都是偶数。
 
 对于左边来说，去掉的部分有4种可能：偶数a偶数o，偶数a奇数o，奇数a偶数o，奇数a奇数o；
 为了方便描述我们用0表示偶数，1表示奇数，那么上面的状态可以表示为00、01、10、11，刚好可以用数字0、1、2、3来表示这4个状态。
 假如原始字符串，最开始的状态是state；最终剩下的字符串，状态应该是00，假如左边去掉字符串的状态是leftState，右边去掉字符串的状态是rightState，那么就有 leftState ^ rightState ^ state = 0；（这里采用异或操作符，可以用实际操作例子感受下）
 
 当字母扩展为a、e、i、o、u之后，同样可以用上面的方式。
 
 

 ```
 
 ```
 
 **思考：**
 
 
 
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
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1


struct Node {
    int first, second;
    Node(){}
    Node(int f, int s) {
        first = f;
        second = s;
    }
    bool operator < (const Node tmp) const {
        if (first != tmp.first) {
            return first > tmp.first;
        }
        else {
            return second > tmp.second;
        }
    }
};


typedef long long lld;
const int N = 50000;
class Solution {
public:
    int findTheLongestSubstring(string s) {
        char aoe[] = "aeiou";
        int state = 0;
        int left[33] = {0}, right[33] = {0};
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            int k = -1;
            for (int j = 0; j < 5; ++j) {
                if (aoe[j] == c) {
                    k = j;
                    break;
                }
            }
            if (k >= 0) {
                state = state ^ (1 << k);
                if (state && !left[state]) {
                    left[state] = i + 1;
//                    cout << "left " << state << " " << i + 1 << endl;
                }
            }
        }
        
        state = 0;
        right[state] = s.length();
        for (int i = s.length() - 1; i >= 0; --i) {
            char c = s[i];
            int k = -1;
            for (int j = 0; j < 5; ++j) {
                if (aoe[j] == c) {
                    k = j;
                    break;
                }
            }
            if (k >= 0) {
                state = state ^ (1 << k);
                if (state && !right[state]) {
                    right[state] = i;
//                    cout << "right " << state << " " << i + 1 << endl;
                }
            }
        }
//        cout << "state " << state << endl;
        
        int ans = 0;
        for (int j = 0; j < 32; ++j) {
            int leftState = j;
            int rightState = j ^ state;
//            cout << leftState << " " << rightState << " " << s.length() - (s.length() - right[rightState]) - left[leftState] << endl;
            ans = max(ans, right[rightState] - left[leftState]);
        }
        
        return ans;
    }
}leetcode;


int main(int argc, const char * argv[]) {
//    string str = "___aeiou_aeiou_uoiea";
    string str = "bcbcbca";
    
    while (true) {
        cin >> str;
        cout << leetcode.findTheLongestSubstring(str) << endl;
    }
    cout << leetcode.findTheLongestSubstring(str) << endl;
    
    
    return 0;
}
