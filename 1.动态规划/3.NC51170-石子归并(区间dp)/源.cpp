#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+7;
const int maxm=2e5+7;
const long long INF=0x3f3f3f3f;
const long long mod=1e9+7;
int n;
int sum[maxn],dp[350][350],a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int l=1;l<=n;l++)//ö�����䳤��
	{
		for(int i=1;i+l<=n;i++)//ö����������
		{
			int j=i+l;//�������ͳ��ȵó��յ�
			dp[i][j]=INF;
			for(int k=i;k<j;k++)//ö�ٷָ��
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);//״̬ת�Ʒ���
		}
	}
	printf("%d",dp[1][n]); 
	return 0;
} 
