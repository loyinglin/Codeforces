#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1024;

int n, t;
bool a[MAX_N][MAX_N];
int inT1[MAX_N];
int b[MAX_N];
int t1[MAX_N];
int t2[MAX_N];
int len1;
int len2;

int GetPos(int *seq, int len, int num)
{
    int pos = -1;
    for(int i = 0; i < len; ++i)
    {
        if(a[num][seq[i]] == 1)
            pos = i;
        else if(pos >= 0)
            return -2;
    }
    return pos;
}

bool Insert(int *seq, int &len, int num)
{
    int pos = GetPos(seq, len, num);
    if(pos == -2)
        return false;
    else if(pos == -1)
        seq[len++] = num;
    else
    {
        for(int i = len; i > pos; --i)
        {
            seq[i] = seq[i-1];
        }
        seq[pos] = num;
        len++;
    }
    
    return true;
}

int BinSearch(int arr[], int len, int num)
{
    int start = 0;
    int end = len - 1;
    while(start <= end)
    {
        int mid = start + end >> 1;
        if(arr[mid] <= num)
            start = mid + 1;
        else if(arr[mid] > num)
            end = mid - 1;
    }
    return start;
}

int GetCount()
{
    int sb = 0;
    for(int i = 0; i < len2; ++i)
    {
        int pos = GetPos(t1, len1, t2[i]);
        if(pos == -2)
            continue;
        if(pos == -1)
            b[sb++] = len1;
        else
        {
            int idx = BinSearch(b, sb, pos);
            b[idx] = pos;
            if(idx >= sb)
                sb++;
        }
    }
    return sb;
}

int main()
{
    while(scanf("%d %d", &n, &t) == 2)
    {
        if(n == 0 || t == 0)
            break;
        
        //int ttt[5] = {3, 3, 3, 3, 3};
        //for(int i = 0; i < 7; ++i)
        //{
        //	printf("%d\n", BinSearch(ttt, 5, i));
        //}
        len1 = 0;
        len2 = 0;
        memset(inT1, 0, sizeof(inT1));
        
        char str[2111];
        getchar();
        for(int i = 1; i <= n; ++i)
        {
            gets(str);
            for(int j = 1; j <= n; ++j)
            {
                char ch = str[j * 2 - 2];
                a[i][j] = ch - '0';
            }
        }
        
        bool ret = true;
        for(int i = 0; i < t; ++i)
        {
            int num;
            scanf("%d", &num);
            inT1[num] = 1;
        }
        
        for(int i = 1; i <= n; ++i)
        {
            if(inT1[i] == 0)
            {
                ret &= Insert(t2, len2, i);
            }
            else
            {
                ret &= Insert(t1, len1, i);
            }
            if(!ret) break;
        }
        
        if(ret)
        {
            int count = GetCount();
            printf("YES %d\n", count);
        }
        else
        {
            printf("NO \n");
        }
    }
    return 0;
}
