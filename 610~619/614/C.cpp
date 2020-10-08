#include "bits/stdc++.h"
using namespace std;

int n,q,x,y;
int i,tmp;
set<float> blk;

int main()
{
	cin>>n>>q;
	vector<int> grid[2];
	grid[0].resize(n);
	grid[1].resize(n);
	vector<int> ans;
	ans.resize(q);
	for (i=0;i<q;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		tmp=(x+1)%2;
		if (not grid[x][y])
		{
			grid[x][y]=1;
			if (grid[tmp][y])
				blk.insert(y);
			if (y-1>=0 and grid[tmp][y-1])
				blk.insert(y-0.5);
			if (y+1<n and grid[tmp][y+1])
				blk.insert(y+0.5);
		}
		else
		{
			grid[x][y]=0;
			blk.erase(y);
			if (not (y-1>=0 and grid[x][y-1] and grid[tmp][y]))
				blk.erase(y-0.5);
			if (not (y+1<n and grid[x][y+1] and grid[tmp][y]))
				blk.erase(y+0.5);
		}
		ans[i]=blk.empty();
	}
	for (i=0;i<q;i++)
		if (ans[i])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
}
