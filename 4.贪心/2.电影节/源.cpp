#include<bits/stdc++.h>
using namespace std;
const int num=110;
int n;
struct movie
{
	int bg;
	int ed;
}t[num],temp;

bool cmp(movie a,movie b)
{
	return a.ed<b.ed;
}

int main()
{
	while(~scanf("%d",&n)&&n!=0)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d",&t[i].bg,&t[i].ed);
		sort(t+1,t+n+1,cmp);
		queue<struct movie>q;
		q.push(t[1]);
		int ans=1;
		for(int i=2;i<=n;i++)
		{
			temp=q.front();
			if(temp.ed<=t[i].bg)
			{
				ans++;
				q.push(t[i]);
				q.pop();
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
