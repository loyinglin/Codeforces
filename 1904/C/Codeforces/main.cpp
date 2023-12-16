//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](https://codeforces.com/contest/1904/problem/C)
 **题目大意：**
 有n个整数的数组a，现在可以进行下面的操作：
 选择数组中任意两个元素，将两个元素差值的绝对值，插入到数组中的最后面；
 
 现在可以进行上面的操作k次，要求让数组中的最小值在操作之后，尽可能的小；
  
 
 **输入：**
 第一行，整数𝑡 表示t个样例 𝑡 (1≤𝑡≤1000)
 每个样例2行
 第1行整数𝑛 and 𝑘 (2≤𝑛≤2⋅1e3 , 1≤𝑘≤1e9 )
 第2行n个整数 𝑎1,𝑎2,…,𝑎𝑛   (1≤𝑎𝑖≤1e18)
   
 **输出：**
 每个样例一行，输出操作后的最小值。
 
 
 **Examples**
 **input**
 4
 5 2
 3 9 7 15 1
 4 3
 7 4 15 12
 6 2
 42 47 50 54 62 79
 2 1
 500000000000000000 1000000000000000000



 **output**
 1
 0
 3
 500000000000000000


 **题目解析：**
 数组a都是大于1的值，那么最终的结果必然是大于等于0；
 当n=2的时候，如果a1=a2，那么结果就是0；
 如果a1!=a2，那么|a1-a2|必然会产生一个新的数字，以[4, 2]为例：
 4 2
 4 2 2
 4 2 2 0
 
 但是，当a1和a2差距较大时，我们有：
 10 2
 10 2 8
 10 2 8 2
 10 2 8 2 0
 
 也就是当操作次数没有限制时，我们必然能够产生0，比如说：
 c=b-a；
 d=b-c=(b-(b-a))=a;
 这样数组[a, b, c, d]，只需要选择a-d=a-a=0；
 只要k>=3，必然可以得到0。
 
 当k==1时，直接枚举两两想减的情况，得到结果；
 当k==2时，我们枚举数组两两想减，得到新的数字，假设是数组b；
 这样我们就有[a1, a2, a3... an] 和 [b1, b2, b3...bn]两个数组；
 这样只需要再枚举数组a和数组b相减，得到数组c；
 最小值就是数组a、b、c中的最小值。
 
 这样的复杂度，首先是数组b的生成，O(N^2)，最多会生成1e6个数字；
 最后再枚举生成c的时候，复杂度就达到了O(N^3），最终复杂度超标。
 
 
 重新审视问题分析过程，当k==1时，其实不需要所有数字两两相减，举一个例子：
 当数组为[9,7,5,1]，当枚举9与其他数字的差值时，只需要考虑[9,7]的情况，也就是整个数组其实只需要考虑3个情况[9, 7] 、[7,5]、[5,1]；
 这里的前提，是数组是有序的。可以对数组进行排序，复杂度是O(NlogN），接下来枚举复杂度就是O(N）；
 但是，当k==2时，是否可以继续只考虑相邻数字呢？
 是不可以的，因为相邻数字想减，生成的只是当前最小，不意味着再一次操作的更小，比如说[9,7,5,4]，第一次无法生成9-5=4，那么第二次操作就无法归零。
 所以首次操作，需要生成N^2个数字的数字b；
 在第二次操作的时候，我们会从数组a选择1个数字，再从数组b选择1个数字，此时可以参考k=1的时候的做法，将数组b排序，对于每个数字a[i]，我们只需要考虑数组b中离a[i]数字最接近的数字。
 此时可以用二分法，在数组b中寻找。但是我们有更简单的做法：
 将数组a和数组b一起排序，然后对于a[i]，我们就往左右遍历，这样就能更方便去找到数字。
 
 
 
 
 
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
    static const int N = 4010100;
    lld a[N];
    pair<lld, lld> b[N];
    
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int n, k;
            cin >> n >> k;
            
            for (int i = 0; i < n; ++i) cin >> a[i];
            sort(a, a + n);
            
            if (k >= 3) {
                cout << 0 << endl;
            }
            else if (k == 2) {
                int cnt = 0;
                for (int i = 0; i < n; ++i) {
                    b[cnt].first = a[i];
                    b[cnt].second = 0;
                    cnt++;
                }
                
                for (int i = 0; i < n; ++i) {
                    for (int j = i + 1; j < n; ++j) {
                        b[cnt].first = abs(a[i] - a[j]);
                        b[cnt].second = 1;
                        ++cnt;
                    }
                }
                
                sort(b, b + cnt);
                
                lld ans = a[0];
                for (int i = 0; i < cnt; ++i) {
                    ans = min(ans, b[i].first);
                    if (b[i].second == 0) { // 数组a来匹配最近的一个数字
                        int x = i, y = i;
                        while (x > 0) {
                            --x;
                            if (b[x].second == 1) break;
                        }
                        
                        while (y < cnt - 1) {
                            ++y;
                            if (b[y].second == 1) break;
                        }
                        if (x != i) {
                            ans = min(ans, abs(b[i].first - b[x].first));
                        }
                        if (y != i) {
                            ans = min(ans, abs(b[i].first - b[y].first));
                        }
                    }
                }
                
                cout << ans << endl;
            }
            else if (k == 1) {
                lld ans = a[0];
                for (int i = 1; i < n; ++i) ans = min(ans, min(a[i], a[i] - a[i - 1]));
                cout << ans << endl;
            }
        }
    }
}
ac;
 
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ac.solve();
    
    return 0;
}
 
