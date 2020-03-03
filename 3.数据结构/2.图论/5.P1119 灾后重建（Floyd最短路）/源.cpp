#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef long long LL;
const int num = 205;
const long long INF= 0x3f3f3f3f;
int t[num],dp[num][num],n,m,k = 0;
void floyd(int tt) //假如k每次都重新做中转点会TLE,假如新的访问点时间t根本就不大于t[k],可以不用跑floyd. 
{
	while(t[k] <= tt && k < n)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j =0; j < n; j++)
			{
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
		k++;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = INF;
		}
	}
	for(int i = 0; i < n; i++)
		scanf("%d",&t[i]);
	for(int i = 1; i <= m; i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		dp[x][y] = dp[y][x] = w;
	}
	int q;
	scanf("%d",&q);
	for(int i = 1; i <= q; i++)
	{
		int x,y,tt;
		scanf("%d%d%d",&x,&y,&tt);
		floyd(tt);
		if(t[x] > tt || t[y] > tt || dp[x][y] == INF)
			printf("-1\n");
		else
			printf("%d\n",dp[x][y]);
	}
	return 0;
}
