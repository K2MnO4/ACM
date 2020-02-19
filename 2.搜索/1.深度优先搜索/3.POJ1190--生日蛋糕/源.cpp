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

void dfs(int v,int m,int h,int r)//��m��ȥ�����v����ײ�߶Ȳ�����h���뾶������r�ĵ��� 
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
	if(v<=0)//�����Լ�֦1 
		return;
	if(minV[m]>v)//�����Լ�֦2��������з��ֻ�û�����Щ��������һ���ᳬ����ȱ�ٵ��������ֹͣ� 
		return;
	if(h<m||r<m)//�����Լ�֦3���������Ԥ���������ϴ�߶��Ѿ��޷����ţ����߰뾶 �Ѿ��޷����ţ���ֹͣ� 
		return;//���߶�h<m�����ϴ�������߶�Ϊ�������뾶ͬ�� 
	if(maxVfun(m,h,r)<v)//�����Լ�֦4��������з��ֻ�û�����Щ�����������Ҳ�����˻�ȱ�ٵ��������ֹͣ� 
		return;
	if(minA[m]+Area>=minArea)//�����Լ�֦������̷��ֵ�ǰ��С�ı�����ѳ���֮ǰ���ɵ���С���������ֹͣ� 
		return; 
	for(int rr=r;rr>=m;rr--)
	{
		if(m==M)//�ж��Ƿ�Ϊ����µ��ǲ㵰�� 
			Area=rr*rr;
		for(int hh=h;hh>=m;hh--)
		{
			Area+=2*rr*hh;
			dfs(v-rr*rr*hh,m-1,hh-1,rr-1);
			Area-=2*rr*hh;//��ԭ 
		}
	}
}

int main()
{
	int maxH,maxR;
	scanf("%d%d",&N,&M);
	minA[0]=0;minV[0]=0;
	for(int i=1;i<=M;i++)//minAδ�������е���ĵ����(����Ӱ����) 
	{
		minA[i]=minA[i-1]+2*i*i;//����x����С�ܱ����
		minV[i]=minV[i-1]+i*i*i;//����x����С����� 
	}
	if(minV[M]>N)
		printf("0");
	else
	{
		maxH=(N-minV[M-1])/(M*M)+1;//���߶� 
		maxR=sqrt((N-minV[M-1])/M)+1;//���뾶
		//+1Ϊ����С��ȡ��������Ӱ����(������������). 
		dfs(N,M,maxH,maxR);
		printf("%d",minArea);		 
	}
	return 0;
}
