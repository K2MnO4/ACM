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
const int maxm=3e5+7;
const long long INF=0x3f3f3f3f;
const long long mod=1e9+7;
int a[maxm],ans=0;
int n,t,k;
struct visitor
{
	int t;
	int city;
}temp,guest[maxm];

queue<struct visitor>vis;

int main()
{
	memset(a,0,sizeof(a));//��Ͱ��Ԫ�س�ʼ��Ϊ0. 
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&t,&k);
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&guest[i].city);
			guest[i].t=t;
			vis.push(guest[i]);//���ο���������.
			if(!a[guest[i].city])
				ans++;
			a[guest[i].city]++;
		}
		while(t-vis.front().t>=86400&&vis.size())//��ʼ�޳��������������ÿ�.
		{
			temp=vis.front();
			vis.pop();
			a[temp.city]--;
			if(!a[temp.city])
				ans--;
		} 
		printf("%d\n",ans);
	}
	
	return 0;
}
