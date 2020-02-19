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
const int maxm=1e6+7;
const long long INF=0x3f3f3f3f;
const long long mod=1e9+7;
int vis[maxm],n,k,step=0;
queue<int>q;

void bfs()
{
	q.push(n);
	while(q.size())
	{
		int x=q.front();
		q.pop();//队列首个元素出列 
		if(x==k)
			break;
		int temp=x-1;
		if(temp>=0&&vis[temp]==-1)//判断是否越界与走过该点. 
		{
			vis[temp]=vis[x]+1;//标记已经走过该点，顺便记录步数. 
			q.push(temp);//将新元素压进队列. 
		}
		temp=x+1;
		if(temp<=maxn&&vis[temp]==-1)
		{
			vis[temp]=vis[x]+1;
			q.push(temp);
		}
		temp=x*2;
		if(temp<=maxn&&vis[temp]==-1)
		{
			vis[temp]=vis[x]+1;
			q.push(temp);
		}
		
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	memset(vis,-1,sizeof(vis));//将未走过的坐标标记为0.
	vis[n]=0;//已经走过起始位置. 
	bfs();
	printf("%d",vis[k]); 	
} 
