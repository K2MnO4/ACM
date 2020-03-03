#include<bits/stdc++.h>
using namespace std;
queue<int>men;
queue<int>women;
int m,n,k;
int main()
{
	int m,n;
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=m;i++)
		men.push(i);
	for(int i=1;i<=n;i++)
		women.push(i);
	while(k--)
	{
		int man=men.front(),woman=women.front();
		men.pop();
		women.pop();
		men.push(man);
		women.push(woman);
		printf("%d %d\n",man,woman);
	}
	return 0;
}
