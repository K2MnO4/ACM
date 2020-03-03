#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 7;
const int maxm = 2e5 + 7;
const int num = 205;
const long long INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
int dp[num][num];
int n,m,q;

void floyd()
{
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]); //k:��ת�� 
			}
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = INF;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		dp[x][y] = min(dp[x][y],z); //�������ر�,ȡ��Ȩ��̵ķ������� 
	}
	floyd();
	
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(dp[x][y] < INF/2) //��a,b����ͨ,�����ڸ���Ȩ������dp[a][b]<INF,����������<INF/2 
			printf("%d\n",dp[x][y]);
		else
			printf("impossible\n");
	} 
	return 0;
}
