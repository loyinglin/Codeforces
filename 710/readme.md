###前言
有朋友推荐一个新的算法练习网站[leetcode](https://leetcode.com/)，说北美的公司招人都是400题起步，国内公司招聘也经常用到，上海的尤其多。  
很有意思，可以花点时间做做leetcode，看看题目质量。
这次更新的仍然是CodeForces的[Contest710](http://codeforces.com/contest/710)。

###正文
####A
[题目链接](http://codeforces.com/contest/710/problem/A)  
**题目大意**  
一个8*8的棋盘，输入一个点表示国际象棋中的king的位置，求king能行动的格子数量；
![](http://upload-images.jianshu.io/upload_images/1049769-b17138b553ec9121.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
 输入两个字符，表示列和行。 列是'a'到'h'，行是1到8。

>###Example
####input
e4
####output
8


**题目解析**
 题目较简单，看如何实现比较方便。  
 列-'a'得到索引x；  
 行-'1'得到索引y；  
 特判当king在边界的时候和同时在两个边界的时候。  

####B
[题目链接](http://codeforces.com/contest/710/problem/B)  
**题目大意**  
输入n个x轴上的点，输出和n个点距离最近的点，如果有多个点，输出最左边的那个点。
 n (1 ≤ n ≤ 3 * 1e5)
 x[i] ( - 1e9 ≤ x[i] ≤ 1e9)
 
 >###Example
####input
 4
 1 2 3 4
####output
 2
 
 
** 题目解析**
 对点排序，易知最后的点在最中间。
 
 对于在[A, B]中的点x，易知x到A和B的距离是固定；  
 那么对于[A, B, C]的最优解，必然是在B；  
 同上，在[A,B,C,D]中，点x到A和D的距离是固定的，同时与x到[B, C]的最优解的重叠。  
 类推，得到答案就是排序完最中间靠左边的点。  



####C
[题目链接](http://codeforces.com/contest/710/problem/C)  
**题目大意**  
输入一个**奇数**n，输出一个n\*n的矩阵，矩阵内数字从1到n\*n。  
 矩阵的要求是行、列、对角线的和都是奇数。  
  n (1 ≤ n ≤ 49)  
 
>###Examples
####input
 1
####output
 1
####input
 3
####output
 2 1 4
 3 5 7
 6 9 8
 
 
 
 **题目解析**
 我们把1到n\*n的数字抽象成0，1.（根据奇偶性）
 我们来看 n=3的时候  
 010  
 111  
 010  
 
 问题是当n=5的时候，如何构造？  
 已知，n=3的矩阵，那么只要保证n=3外面的矩阵行列和都是偶数就行。  
 1 010 1  
 
 0 010 0  
 1 111 1  
 0 010 0  
 
 1 010 1  
 
 那么题目可以变成这样一圈圈的去构造；  
 并且为了方便，从中心开始构造最为简单。  

 
###E
[题目链接](http://codeforces.com/contest/710/problem/E)  
**题目大意**  
构造n个'a'字符，x为insert/delete 'a'一次的代价，y为复制粘贴一次的代价。  
 n, x and y (1 ≤ n ≤ 107, 1 ≤ x, y ≤ 109).  
 
> ###Examples
#### input
 8 1 1
#### output
 4
#### input
 8 1 10
#### output
 8

 
 **题目解析：**
 动态规划。  
 dp[i] 表示构造i个字符的最优解。  
 对应三种可能，三个状态转移。  
 dp[i] = min(dp[i], dp[i + 1] + x);     删除  
 dp[i + 1] = min(dp[i + 1], dp[i] + x); 增加  
 dp[i \* 2] = min(dp[i \* 2], dp[i] + y); 双倍  
 
 1 2 4 8 16 13 26 52 删除3次，double 6次  
 1 2 4 6 12 13 25 52 增加3次，double 6次  


####F
[题目链接](http://codeforces.com/contest/710/problem/F)  
**题目大意**  
m个操作。  
 操作1，把一个字符串s放入集合D，每次插入不同；  
 操作2，把一个字符串s从集合D删除，保证有值；  
 操作3，询问一个字符串x在集合中子串的数量。  
  m (1 ≤ m ≤ 3·1e5)
 
>###Examples
####input
 5
 1 abc
 3 abcabc
 2 abc
 1 aba
 3 abababc
####output
 2
 2
 
 题目解析：  
 题目有一个很重要的性质：每次插入不同。  
 于是可以插入建一个自动机，删除建一个自动机，相减即可。  
  
 
 查找函数再引入一个dp值，如果访问一次，就记录当前值。这样每个点就只访问一次  
 build函数，dp值=-1 比较关键  
 这里的字典树要引入一个flag来标志是否真的有孩子。（build之后，及时字典树没有孩子，ch指针也会指向fail指针）死循环了几次  
 插入和更新，在引入一个flag，有更新之后再重新build  
 
 
 如果题目数据更强：（队友提供的神优化）  
 再引入logN的优化，建logN个自动机，分别存放1、2、4、8等个自动机。  
 
 ###总结
A、B是简单题，C是构（脑）造（洞）题，E是动态规划，F是AC自动机。
新年快乐~