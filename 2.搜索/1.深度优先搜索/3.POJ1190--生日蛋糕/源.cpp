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
const int num=25;
const long long INF=0x3f3f3f3f;
const long long mod=1e9+7;
int Area=0,minArea=INF,N,M;
int minA[num],minV[num];

int maxVfun(int m,int h,int r)
{
	int maxV=0;
	for(int i=0;i<m;i++)
		maxV+=(r-i)*(r-i)*(h-i);
	return maxV;
}

void dfs(int v,int m,int h,int r)//用m层去凑体积v，最底层高度不超过h，半径不超过r的蛋糕 
{
	if(m==0)
	{
		if(v)
			return;
		else
		{
			minArea=min(minArea,Area);
			return;
		}
	}
	if(v<=0)//可行性剪枝1 
		return;
	if(minV[m]>v)//可行性剪枝2：搭建过程中发现还没搭的那些层的体积，一定会超过还缺少的体积，则停止搭建 
		return;
	if(h<m||r<m)//可行性剪枝3：搭建过程中预见到再往上搭，高度已经无法安排，或者半径 已经无法安排，则停止搭建 
		return;//最大高度h<m，往上搭到顶层最大高度为负数（半径同理） 
	if(maxVfun(m,h,r)<v)//可行性剪枝4：搭建过程中发现还没搭的那些层的体积，最大也到不了还缺少的体积，则停止搭建 
		return;
	if(minA[m]+Area>=minArea)//最优性剪枝：搭建过程发现当前最小的表面积已超过之前搭建完成的最小表面积，则停止搭建 
		return; 
	for(int rr=r;rr>=m;rr--)
	{
		if(m==M)//判断是否为最底下的那层蛋糕 
			Area=rr*rr;
		for(int hh=h;hh>=m;hh--)
		{
			Area+=2*rr*hh;
			dfs(v-rr*rr*hh,m-1,hh-1,rr-1);
			Area-=2*rr*hh;//复原 
		}
	}
}

int main()
{
	int maxH,maxR;
	scanf("%d%d",&N,&M);
	minA[0]=0;minV[0]=0;
	for(int i=1;i<=M;i++)//minA未包含所有蛋糕的底面积(并不影响结果) 
	{
		minA[i]=minA[i-1]+2*i*i;//至第x层最小总表面积
		minV[i]=minV[i-1]+i*i*i;//至第x层最小总体积 
	}
	if(minV[M]>N)
		printf("0");
	else
	{
		maxH=(N-minV[M-1])/(M*M)+1;//最大高度 
		maxR=sqrt((N-minV[M-1])/M)+1;//最大半径
		//+1为了有小数取整，并不影响结果(反正暴力搜索). 
		dfs(N,M,maxH,maxR);
		printf("%d",minArea);		 
	}
	return 0;
}
