/*
使用方法:dfs+dp；记忆化搜索~
*/
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
const long long INF=0x3f3f3f3f;
const long long mod=1e9+7;
int path[105][105],dp[105][105];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,ans=0;

bool cp(int x,int y)
{
	if(x<1||x>n||y<1||y>m)//判断是否越界
		return false;
	else
		return true; 
}

int dfs(int i,int j)
{
	if(dp[i][j])//判断是否曾经进行记录 
		return dp[i][j];
	int ret=1;
	for(int k=0;k<=3;k++)//四个方向进行深搜 
	{
		int xx=dir[k][0]+i;
		int yy=dir[k][1]+j;
		if(cp(xx,yy)&&path[i][j]>path[xx][yy])
		{
			ret=max(dfs(xx,yy)+1,ret);//在之前最大的数和现在路径的数进行比较后取大的 
		}
	}
	dp[i][j]=ret;//将记录的数给予dp数组进行存放 
	return ret; 
}

int main()
{
	scanf("%d%d",&n,&m);//n:行数;m:列数. 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&path[i][j]);
		}
	}
	memset(dp,0,sizeof(dp));//将dp数组初始化为0. 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ans=max(ans,dfs(i,j));
		}
	}
	printf("%d",ans);
	return 0;
} 
