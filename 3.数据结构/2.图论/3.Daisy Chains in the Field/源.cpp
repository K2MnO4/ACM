#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 7;
const int maxm = 2e5 + 7;
const int num = 255;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
vector<int> map[num]; 
int a[num],vis[num];
int n,m;
void dfs(int x)
{
	vis[x]=1;
	for(int i = 0; i < map[x].size(); i++)
	{
		if(map[x][i] == x || vis[map[x][i]])
			continue;		
		dfs(map[x][i]);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	memset(map,0,sizeof(map));
	memset(vis,0,sizeof(vis));
	for(int i = 1; i <= m; i++)
	{
		int c1,c2;
		scanf("%d%d",&c1,&c2);
		map[c1].push_back(c2);
		map[c2].push_back(c1);
	}
	dfs(1);
	int j = 0;
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i])
			a[++j] = i;
	}
	sort(a+1,a+j+1);
	if(j)
	{
		for(int i = 1; i <= j; i++)
			printf("%d\n",a[i]);
	}
	else
		printf("0");
	return 0;
}
