#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+7;
const int maxm=2e5+7;
const long long mod=1e9+7;
const long long INF=0x3f3f3f3f;
int dp[maxn][2],max_h;
struct time
{
    int x1;
    int x2;
    int h;
}a[maxn];
 
bool cmp(time b,time c)
{
    return b.h<c.h;
}
 
void leftTime(int i)
{
    int k=i-1;
    while(k>0&&a[i].h-a[k].h<=max_h)
    {
        if(a[i].x1>=a[k].x1&&a[i].x1<=a[k].x2)
        {
            dp[i][0]=a[i].h-a[k].h+min(dp[k][0]+a[i].x1-a[k].x1,dp[k][1]+a[k].x2-a[i].x1);
            return;
        }
        else
            k--;
    }
    if(a[i].h-a[k].h>max_h)
        dp[i][0]=INF;
    else
        dp[i][0]=a[i].h-a[k].h;
}
 
void rightTime(int i)
{
    int k=i-1;
    while(k>0&&a[i].h-a[k].h<=max_h)
    {
        if(a[i].x2<=a[k].x2&&a[i].x2>=a[k].x1)
        {
            dp[i][1]=a[i].h-a[k].h+min(dp[k][0]+a[i].x2-a[k].x1,dp[k][1]+a[k].x2-a[i].x2);
            return;
        }
        else
            k--;
    }
    if(a[i].h-a[k].h>max_h)
        dp[i][1]=INF;
    else
        dp[i][1]=a[i].h-a[k].h;
}
 
int main()
{
    int t,n,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&x,&y,&max_h);
        a[n+1].x1=x;
        a[n+1].x2=x;
        a[n+1].h=y;
        a[0].x1=-maxm;
        a[0].x2=maxm;
        a[0].h=0;
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&a[i].x1,&a[i].x2,&a[i].h);
        sort(a,a+n+2,cmp);
        for(int i=1;i<=n+1;i++)
        {
            leftTime(i);
            rightTime(i);
        }
        printf("%d\n",min(dp[n+1][0],dp[n+1][1]));
         
    }
    return 0;
}
