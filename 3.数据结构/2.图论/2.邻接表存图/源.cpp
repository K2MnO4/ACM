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
const int num = 5005;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
vector<int> map[num]; 
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
			map[u].push_back(v);
		}
		scanf("%d",&q);
		for(int i = 1; i <= q; i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			int flag = 0;
			for(int j = 0;j < map[a].size(); j++)
			{
				if(map[a][j] == b)
				{
					flag=1;
					break;
				}
			}
			if(flag)
				printf("Yes\n");
			else
				printf("No\n");
		}
		for(int i =0; i < n; i++)
			map[i].clear();
	}
	return 0;
}
