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
const int num=6;
const long long INF=0x3f3f3f3f;
const long long mod=1e9+7;
int maze[num][num],vis[num][num];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct node
{
	int x,y;//坐标 
	int up;//上一点 
}q[num*num],now;

bool cp(int xx,int yy)
{
	if(xx<0||xx>4||yy<0||yy>4)
		return false;
	else
		return true;
}

void printf(int head)
{
	while(q[head].up!=-1)
	{
		printf(q[head].up);
		printf("(%d, %d)\n",q[head].x,q[head].y);
		return;
	}
	printf("(0, 0)\n");
}

void bfs(int x,int y)
{
	int head=0,tail=1;
	q[0].x=0;
	q[0].y=0;
	q[0].up=-1;
	while(head<tail)//判断队列头指针和尾指针是否重合 
	{
		if(q[head].x==4&&q[head].y==4)
		{
			printf(head);
			return;
		}
		for(int k=0;k<4;k++)
		{
			now.x=q[head].x+dir[k][0];
			now.y=q[head].y+dir[k][1];
			now.up=head;
			if(cp(now.x,now.y)&&!vis[now.x][now.y]&&!maze[now.x][now.y])
			{
				vis[now.x][now.y]=1;//标记已经走过
				q[tail++]=now;//入列 
			}
		}
		head++;	
	}
}


int main()
{
	for(int i=0;i<=4;i++)
		for(int j=0;j<=4;j++)
			scanf("%d",&maze[i][j]);
	memset(vis,0,sizeof(vis));
	vis[0][0]=1;
	bfs(0,0);
	return 0;
}
