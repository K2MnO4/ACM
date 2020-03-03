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
	while(q.size()>1)//只需要队列剩一人 
	{
		for(int i=1;i<=m-1;i++)
		{
			int sign=q.front();//标记队列小朋友 
			q.pop();//让队列小朋友出列 
			q.push(sign);//让刚刚出列的小朋友入列(到队尾) 
		}
		q.pop();//让第m个小朋友出列(不再入列) 
	}
	printf("%d",q.front());
	return 0;
}
//约瑟夫环问题 
