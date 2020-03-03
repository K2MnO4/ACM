#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 7;
const int maxm = 2e5 + 7;
const int num = 16;
const long long INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
LL a[num][num],ans = 0,sum = 0,hh[num],ll[num],sum1,sum2;
int n,m,k;
struct node
{
    LL s,e; // s:第s行/列总和, e:第e行/列. 
}h[num],l[num];

bool cmp(node a,node b)
{
    return a.s > b.s;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1; i <= n; i++)
    {   
        for(int j = 1; j <= m; j++)
        {
            scanf("%lld",&a[i][j]);
            sum += a[i][j];
            h[i].s += a[i][j];
            hh[i] += a[i][j];
            h[i].e = i;
            l[j].s += a[i][j];
            ll[j] += a[i][j];
            l[j].e = j;
        }
    }
    if(k >= n || k >= m) //k=n∣∣k=m将所有行或所有列全部选择是最优策略
    {
        printf("%lld",sum);
        return 0;
    }
    for(int t = 1; t <= k; t++) //行列之中选最大 
    {
        sort(h+1,h+n+1,cmp);
        sort(l+1,l+m+1,cmp);
        if(h[1].s >= l[1].s)
        {
            ans += h[1].s;
            for(int y = 1; y <= m; y++)
            {
                l[y].s -= a[h[1].e][l[y].e];
                a[h[1].e][l[y].e] = 0;
                /*错误写法 
                    l[y].s -= a[h[1].e][y];
                    a[h[1].e][y] = 0;
                */ 
            }
            h[1].s = 0;
        }
        else
        {
            ans += l[1].s;
            for(int x = 1; x <= n; x++)
            {
                h[x].s -= a[h[x].e][l[1].e];
                a[h[x].e][l[1].e] = 0;
                /*错误写法 
                    h[x].s -= a[x][l[1].e];
                    a[x][l[1].e] = 0;
                */
            }
            l[1].s = 0;
        }
    }
    
    for(int i = 1; i <= k; i++) //单独只选行
    {
        sort(hh+1,hh+n+1);
        sum1 += hh[n];
        hh[n] = 0;
    } 
    ans = max(ans,sum1);
    
    for(int i = 1; i <= k; i++) //单独只选列 
    {
        sort(ll+1,ll+m+1);
        sum2 += ll[n];
        ll[m] = 0;
    } 
    ans = max(ans,sum2);
    printf("%lld",ans);
    return 0;
}


/*
3 3 2
101 1 102
1 202 1
100 8 100

414

3 4 2
6 6 3 4
2 5 6 7
1 10 3 4

39

3 3 2
5 20 10
10 20 20
5 10 10

90
 
3 3 2
5 10 5
20 20 10
10 20 10

90

*/
