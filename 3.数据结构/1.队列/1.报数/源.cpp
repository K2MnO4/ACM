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
const long long INF=0x3f3f3f3f;
const long long mod=1e9+7;
int n,m;
queue<int>q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		q.push(i);
	while(q.size()>1)//ֻ��Ҫ����ʣһ�� 
	{
		for(int i=1;i<=m-1;i++)
		{
			int sign=q.front();//��Ƕ���С���� 
			q.pop();//�ö���С���ѳ��� 
			q.push(sign);//�øոճ��е�С��������(����β) 
		}
		q.pop();//�õ�m��С���ѳ���(��������) 
	}
	printf("%d",q.front());
	return 0;
}
//Լɪ������ 
