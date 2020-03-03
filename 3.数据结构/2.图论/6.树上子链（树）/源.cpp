#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 7;
const int maxm = 2e5 + 7;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
LL n,a[maxn],u,v,dp[maxn],ans=-INF;
int vis[maxn];
vector<LL> G[maxn];

void dfs(LL x)
{
    vis[x] = 1; //标记该点已经走过
    LL tmp1 = a[x],tmp2 = a[x]; //tmp1为该节点最长链，tmp2为该节点次长链 
    for(int i = 0; i<G[x].size(); i++)
    {
         if(vis[G[x][i]]) //判断邻接点是否遍历过 
            continue;
         dfs(G[x][i]); //如果未遍历过就先进行遍历
         dp[x] = max(dp[x],dp[G[x][i]] + a[x]); //用dp来存当前该根节点最大权值
         if(dp[G[x][i]] + a[x] > tmp1) //判断是否新的子链大于最长子链 
         {
            tmp2 = tmp1; //将原来的最长子链变成第二长子链
            tmp1 = dp[G[x][i]] + a[x]; 
         } 
         else if(dp[G[x][i]] + a[x] > tmp2) //判断是否新的子链大于次长子链而不是最长子链
            tmp2 = dp[G[x][i]] + a[x]; //更新次长子链 
    } 
    dp[x] = tmp1; //仅有一一个子节点 
    ans = max(ans,tmp1 + tmp2 -a[x]);//最长子链 + 次长子链 - 当前节点权值 
}

int main()
{
    scanf("%lld",&n);
    for(int i = 1; i <= n; i++)
        scanf("%lld",&a[i]);
    for(int i = 1; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v); //用邻接表的方式存图 
        G[v].push_back(u);
    }
    memset(vis,0,sizeof(vis));
    dfs(1); //从第一个点开始遍历整个图 
    printf("%lld",ans);
    return 0;
}
