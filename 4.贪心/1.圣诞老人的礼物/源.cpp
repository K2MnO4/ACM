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
const int num=110;
const double eps=1e-6;
const long long INF=0x3f3f3f3f;
const long long mod=1e9+7;
int n,w;
double totalValue=0;
struct gifts
{
	int v;//糖果价值
	int w;//糖果重量 
	double percent;//价值/重量 
}candy[num];

bool cmp(gifts a,gifts b)
{
	return a.percent>b.percent+eps;
}

int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&candy[i].v,&candy[i].w);
		candy[i].percent=1.0*candy[i].v/candy[i].w;
	}
	sort(candy+1,candy+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(w>=candy[i].w)
		{
			totalValue+=candy[i].v;
			w-=candy[i].w;
		}
		else
		{
			totalValue+=w*candy[i].percent;
			break;
		}
	}
	printf("%.1lf",totalValue);
	return 0;
}
