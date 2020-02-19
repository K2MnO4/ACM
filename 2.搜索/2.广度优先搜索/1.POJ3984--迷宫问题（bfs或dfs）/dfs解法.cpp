#include<bits/stdc++.h>
using namespace std;
const long long INF=0x3f3f3f3f;
const int num=6;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int vis[num][num],maze[num][num];
int step,minStep=INF;
struct node
{
	int x,y;
};
node path[num*num];   //暂存路径的数组
node shortPath[num*num];

bool cp(int xx,int yy)
{
	if(xx<0||xx>4||yy<0||yy>4)
		return false;
	else
		return true;
}

void dfs(int x,int y,int step)
{
	if(x==4&&y==4)
	{
		if(minStep>step)
		{
			minStep=step;
			for(int i=0;i<minStep;i++)
				shortPath[i]=path[i];	
		}
		return;
	}
	if(step>minStep)
		return; //最优性剪枝 
	for(int k=0;k<4;k++)
	{
		int xx=x+dir[k][0];
		int yy=y+dir[k][1];
		if(cp(xx,yy)&&!maze[x][y]&&!vis[xx][yy])
		{
			path[step].x=xx;
			path[step].y=yy;
			vis[xx][yy]=1;
			dfs(xx,yy,step+1);
			vis[xx][yy]=0;//回溯 
		}
	} 
}

int main()
{
	for(int i=0;i<=4;i++)
		for(int j=0;j<=4;j++)
			scanf("%d",&maze[i][j]);
	memset(vis,0,sizeof(vis));
	vis[0][0]=1;
	dfs(0,0,0);
	printf("%d\n",minStep); 
	printf("(0, 0)\n"); 
	for(int i=0;i<minStep;i++)
		printf("(%d, %d)\n",shortPath[i].x,shortPath[i].y);
	return 0;
}
