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
const int num = 5005;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
int map[num][num];
int n,m,q;
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(map,0,sizeof(map));
		for(int i = 1; i <= m; i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			map[u][v] = 1;
		}
		scanf("%d",&q);
		for(int i = 1; i <= q; i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(map[a][b])
				printf("Yes\n");
			else
				printf("No\n");
		}
		
	}
	return 0;
}
