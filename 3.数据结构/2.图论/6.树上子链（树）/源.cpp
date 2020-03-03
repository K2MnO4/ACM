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
    vis[x] = 1; //��Ǹõ��Ѿ��߹�
    LL tmp1 = a[x],tmp2 = a[x]; //tmp1Ϊ�ýڵ������tmp2Ϊ�ýڵ�γ��� 
    for(int i = 0; i<G[x].size(); i++)
    {
         if(vis[G[x][i]]) //�ж��ڽӵ��Ƿ������ 
            continue;
         dfs(G[x][i]); //���δ���������Ƚ��б���
         dp[x] = max(dp[x],dp[G[x][i]] + a[x]); //��dp���浱ǰ�ø��ڵ����Ȩֵ
         if(dp[G[x][i]] + a[x] > tmp1) //�ж��Ƿ��µ�������������� 
         {
            tmp2 = tmp1; //��ԭ�����������ɵڶ�������
            tmp1 = dp[G[x][i]] + a[x]; 
         } 
         else if(dp[G[x][i]] + a[x] > tmp2) //�ж��Ƿ��µ��������ڴγ����������������
            tmp2 = dp[G[x][i]] + a[x]; //���´γ����� 
    } 
    dp[x] = tmp1; //����һһ���ӽڵ� 
    ans = max(ans,tmp1 + tmp2 -a[x]);//����� + �γ����� - ��ǰ�ڵ�Ȩֵ 
}

int main()
{
    scanf("%lld",&n);
    for(int i = 1; i <= n; i++)
        scanf("%lld",&a[i]);
    for(int i = 1; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        G[u].push_back(v); //���ڽӱ�ķ�ʽ��ͼ 
        G[v].push_back(u);
    }
    memset(vis,0,sizeof(vis));
    dfs(1); //�ӵ�һ���㿪ʼ��������ͼ 
    printf("%lld",ans);
    return 0;
}
