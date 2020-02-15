#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+7;
const int maxm=2e5+7;
const int num=110;
const long long INF=0x3f3f3f3f;
const long long mod=1e9+7;
int minL[num][maxn];//minL[i][j]:总到城市i,总路费为j的最优路径长度.
int vis[num];
int totalLen=0,totalCost=0;//总路程和总花销. 
int minLen=INF; //最短的距离. 
int K,N,R;
struct road
{ 
	int d;//终点 
	int l;//距离
	int t;//花销  
}r;
vector< vector<road> >G(num);//G[s][i]表示有路连接到s的城市 

void dfs(int s)//表示从s向N继续走. 
{
	if(s==N)
	{
		minLen=min(totalLen,minLen);
		return;
	}
	for(int i=0;i<G[s].size();i++)//邻接表
	{
		int d=G[s][i].d;//表示s相邻的城市d，也就是s能通向d.
		if(!vis[d])//判断是否走过该城市.
		{
			int cost=totalCost+G[s][i].t;//假如要走向城市d的花销+之前的总花销.
			if(cost>K)//判断花销是否已经超过他的花费能力. 
				continue; 
			if(totalLen+G[s][i].l>=minLen)//判断走到城市d之后路程是否已经超过之前到达终点的最短路程.
				continue;//最优性剪枝(1)
			if(totalLen+G[s][i].l>=minL[d][cost])//判断再次走到城市d,此时的花费与上次一致，但路程是否超过上次路程 
				continue;//最优性剪枝(2)
			//假如都不符合以上条件
			totalCost=cost;
			totalLen+=G[s][i].l;
			minL[d][cost]=totalLen;
			vis[d]=1;
			dfs(d);
			//此题寻找最佳方案，走过的路不一定最佳，所以进行复位.
			vis[d]=0;
			 totalCost-=G[s][i].t;
			 totalLen-=G[s][i].l;
		} 
	} 
}

int main()
{
	memset(vis,0,sizeof(vis));
	vis[1]=1;//已经在城市1. 
	cin>>K>>N>>R;
	for(int i=0;i<R;i++)
	{
		int s;
		cin>> s >> r.d >> r.l >>r.t;
		if(s!=r.d)//判断起点与终点是否相同
			G[s].push_back(r);//插入数据 
	}
	for(int i=0;i<num;i++)
		for(int j=0;j<maxn;j++)
			minL[i][j]=INF;
	dfs(1);
	if(minLen<INF)
		cout<<minLen<<endl;
	else
		cout<<"-1"<<endl; 
	return 0;
} 

