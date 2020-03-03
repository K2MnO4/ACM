#include<bits/stdc++.h>
using namespace std;
queue<string>q;
int n,m,t;
string name;
int judge(int x)
{
	while(x)
	{
		if(x%10==7)
			return 1;
		else
			x/=10;
	}
}

int main()
{
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>name;
		q.push(name);
	}
	for(int i=1;i<m;i++)
	{
		q.push(q.front());
		q.pop();
	}
	while(q.size()>1)
	{
		if(judge(t)||t%7==0)
			q.pop();
		else
		{
			q.push(q.front());
			q.pop();
		}
		t++;
	}
	cout<<q.front()<<endl;
	return 0;
}
