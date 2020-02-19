//解法一: 
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue> 
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+7;
const int maxm=2e5+7;
const int num=205;
const long long INF=0x3f3f3f3f;
const long long mod=1e9+7;
char maze[num][num];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int vis[num][num];
int m,n,t,st=0;
int r1,r2,c1,c2;
struct node
{
	int x,y;
	int up;
	int k;
	int step;
}q[num*num],now;

bool cp(int xx,int yy)
{
	if(xx<1||xx>m||yy<1||yy>n)
		return false;
	else
		return true;
}

int bfs()
{
	q[1].x=r1;
	q[1].y=c1;
	q[1].up=0;
	q[1].k=t;
	q[1].step=0;
	int head=1,tail=2;
	while(head<tail)
	{
		if(q[head].x==r2&&q[head].y==c2)
			return st=q[head].step;
		for(int i=0;i<4;i++)
		{
			now.x=q[head].x+dir[i][0];
			now.y=q[head].y+dir[i][1];
			now.up=head;
			if(cp(now.x,now.y)&&q[head].k&&maze[now.x][now.y]=='#'&&!vis[now.x][now.y])
			{
				vis[now.x][now.y]=1;
				now.step=q[head].step+1;
				now.k=q[head].k-1;
				q[tail++]=now;
			}
			else if(cp(now.x,now.y)&&maze[now.x][now.y]!='#'&&!vis[now.x][now.y])
			{
				vis[now.x][now.y]=1;
				now.step=q[head].step+1;
				now.k=q[head].k;
				q[tail++]=now;
			}
		}
		head++;
	}
	return 0;
}

int main()
{
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
	st=bfs();
	if(st)
		printf("%d",st);
	else
		printf("-1");
	return 0;
}

/*法二（主要想练练queue）：

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
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
int m,n,t,r1,c1,r2,c2,st=0;
int vis[num][num];
char maze[num][num];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct node
{
	int x,y;
	int k;
	int step;
}now;
queue<struct node>q;

bool cp(int xx,int yy)
{
	if(xx<1||xx>m||yy<1||yy>n)
		return false;
	else
		return true;
}

int bfs()
{
	node point;
	point.x=r1,point.y=c1;
	point.k=t,point.step=0;
	q.push(point);
	while(q.size())
	{
		node temp;//队列头部元素 
		temp=q.front();
		q.pop(); //删除队列首元素 
		if(temp.x==r2&&temp.y==c2)
			return st=temp.step;
		for(int i=0;i<4;i++)
		{
			now.x=temp.x+dir[i][0];//现在访问的元素 
			now.y=temp.y+dir[i][1];
			if(cp(now.x,now.y)&&!vis[now.x][now.y]&&temp.k&&maze[now.x][now.y]=='#')
			{
				vis[now.x][now.y]=1;
				now.step=temp.step+1;
				now.k=temp.k-1;
				q.push(now);//入列. 
			}
			else if(cp(now.x,now.y)&&!vis[now.x][now.y]&&maze[now.x][now.y]!='#')
			{
				vis[now.x][now.y]=1;
				now.step=temp.step+1;
				now.k=temp.k;
				q.push(now);//入列. 
			}
		}
		
	}
}

int main()
{
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
	bfs();
	if(st)
		printf("%d",st);
	else
		printf("-1"); 
	return 0;
} 
 
*/
