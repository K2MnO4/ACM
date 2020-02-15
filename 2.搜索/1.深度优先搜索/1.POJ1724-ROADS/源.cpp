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
int minL[num][maxn];//minL[i][j]:�ܵ�����i,��·��Ϊj������·������.
int vis[num];
int totalLen=0,totalCost=0;//��·�̺��ܻ���. 
int minLen=INF; //��̵ľ���. 
int K,N,R;
struct road
{ 
	int d;//�յ� 
	int l;//����
	int t;//����  
}r;
vector< vector<road> >G(num);//G[s][i]��ʾ��·���ӵ�s�ĳ��� 

void dfs(int s)//��ʾ��s��N������. 
{
	if(s==N)
	{
		minLen=min(totalLen,minLen);
		return;
	}
	for(int i=0;i<G[s].size();i++)//�ڽӱ�
	{
		int d=G[s][i].d;//��ʾs���ڵĳ���d��Ҳ����s��ͨ��d.
		if(!vis[d])//�ж��Ƿ��߹��ó���.
		{
			int cost=totalCost+G[s][i].t;//����Ҫ�������d�Ļ���+֮ǰ���ܻ���.
			if(cost>K)//�жϻ����Ƿ��Ѿ��������Ļ�������. 
				continue; 
			if(totalLen+G[s][i].l>=minLen)//�ж��ߵ�����d֮��·���Ƿ��Ѿ�����֮ǰ�����յ�����·��.
				continue;//�����Լ�֦(1)
			if(totalLen+G[s][i].l>=minL[d][cost])//�ж��ٴ��ߵ�����d,��ʱ�Ļ������ϴ�һ�£���·���Ƿ񳬹��ϴ�·�� 
				continue;//�����Լ�֦(2)
			//���綼��������������
			totalCost=cost;
			totalLen+=G[s][i].l;
			minL[d][cost]=totalLen;
			vis[d]=1;
			dfs(d);
			//����Ѱ����ѷ������߹���·��һ����ѣ����Խ��и�λ.
			vis[d]=0;
			 totalCost-=G[s][i].t;
			 totalLen-=G[s][i].l;
		} 
	} 
}

int main()
{
	memset(vis,0,sizeof(vis));
	vis[1]=1;//�Ѿ��ڳ���1. 
	cin>>K>>N>>R;
	for(int i=0;i<R;i++)
	{
		int s;
		cin>> s >> r.d >> r.l >>r.t;
		if(s!=r.d)//�ж�������յ��Ƿ���ͬ
			G[s].push_back(r);//�������� 
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

