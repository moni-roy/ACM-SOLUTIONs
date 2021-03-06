/// using topological sort
/// like bfs.....
#include <bits/stdc++.h>
#define mx 101

using namespace std;

int m,n,ok[mx];

vector<int> tpsort(int mt[][mx])
{
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(ok[i]==0)
		{
			q.push(i);
		}
	}
	vector<int>lst;
	while(!q.empty())
	{
		int p=q.front();q.pop();
		lst.push_back(p);
		for(int i=1;i<=n;i++)
		{
			if(mt[p][i]==1)
			{
				ok[i]--;
				if(ok[i]==0) q.push(i);
			}
		}
	}
	return lst;
}
int main()
{
	int edge[mx][mx];
	while(cin>>n>>m)
	{
		if(m==0&&n==0) break;
		///for(int i=0;i<=mx;i++)
		///{
		///	for(int j=0;j<=mx;j++)
		///	{
		///		edge[i][j]=0;
		///		ok[i]=0;
		///	}
		///}
		memset(ok,0,sizeof ok);
		memset(edge,0,sizeof edge);
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			edge[x][y]=1;
			ok[y]++;
		}
		vector<int> ls=tpsort(edge);
		int ln=ls.size();
		for(int i=0;i<ln;i++)
		{
			if(i!=0) cout<<' ';
			cout<<ls[i];
		}
		cout<<endl;
	}
	return 0;
}