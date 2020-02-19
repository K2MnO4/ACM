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
const int num=205;
const long long INF=0x3f3f3f3f;
const long long mod=1e9+7;
int m,n,t,r2,c2;
int vis[num][num];
char maze[num][num];
int minStep=INF;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int x,int y,int k,int step)
{
	if(x==r2&&y==c2)
	{
		minStep=min(step,minStep);
		return;
	}
	if(x<1||x>m||y<1||y>n)//可行性剪枝 
		return;
	for(int i=0;i<4;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(maze[xx][yy]=='#'&&k&&!vis[xx][yy])
		{
			vis[xx][yy]=1;
			dfs(xx,yy,k-1,step+1);
			vis[xx][yy]=0;//回溯 
		}
		else if(maze[xx][yy]!='#'&&!vis[xx][yy])
		{
			vis[xx][yy]=1;
			dfs(xx,yy,k,step+1);
			vis[xx][yy]=0;//回溯 
		}
		//vis[xx][yy]=0;错误回溯 
	}
	//vis[x][y]=0;正确回溯. 
}

int main()
{
	int r1,c1;
	scanf("%d%d%d",&m,&n,&t);
	getchar();
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%c",&maze[i][j]);
			if(maze[i][j]=='@')
			{
				r1=i;
				c1=j;
			}
			if(maze[i][j]=='+')
			{
				r2=i;
				c2=j;
			}
		}
		getchar();
	}
	memset(vis,0,sizeof(vis));
	dfs(r1,c1,t,0);//位置坐标,查克拉数量,步数.
	if(minStep<INF)
		printf("%d",minStep);
	else
		printf("-1");
	return 0;
} 
