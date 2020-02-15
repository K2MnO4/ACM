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
const int num=100;
const long long INF=0x3f3f3f3f;
const long long mod=1e9+7;
int a[num][num];
int flag;

bool check(int pos,int x)
{
	for(int i=0;i<9;i++)//�����ͬ��һ�����Ƿ�����ͬ������.
	{
		int j=pos/9;
		if(a[j][i]==x)
			return false;
	} 
	for(int i=0;i<9;i++)//�����ͬ��һ�����Ƿ�����ͬ������.
	{
		int j=pos%9;
		if(a[i][j]==x)
			return false;
	}
	int xx=pos/9/3*3;//ÿ��С�ľŹ�������ϽǺ�����. 
	int yy=pos%9/3*3;//ÿ��С�ľŹ�������Ͻ�������. 
	for(int i=xx;i<xx+3;i++)//����ÿһ��С�ľŹ����Ƿ�����ͬ������. 
		for(int j=yy;j<yy+3;j++)
		{
			if(a[i][j]==x)
				return false;
		} 
	return true;
}

void dfs(int pos)
{
	if(pos>=81)//�ж��Ƿ��Ѿ���������.
	{
		flag=1;
		return;
	} 
	int x=pos/9,y=pos%9;
	if(a[x][y]!=0)//�ж��Ƿ����������� 
		dfs(pos+1);
	else
	{
		for(int i=1;i<=9;i++)
		{
			if(check(pos,i))
			{
				a[x][y]=i;
				dfs(pos+1); 
				if(flag)
					return;
				else
					a[x][y]=0;//��������ֲ����ʾͽ���ȡ��. 
			}
		}
	} 
}

int main()
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			scanf("%d",&a[i][j]);
	dfs(0);
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			printf("%d%c",a[i][j],j==8?'\n':' ');
	return 0;
}
