#include "bits/stdc++.h"
using namespace std;

int i,j,n,m,x;
int alpha=0,betaa;
int ansi,ansj;
vector<vector<int>> a;

int main()
{
	cin>>n>>m;
	int tmp=n;
	a.resize(n);
	while (tmp--)
	{
		a[n-tmp-1].resize(m);
		for (i=0;i<m;i++)
		{
			cin>>x;
			a[n-tmp-1][i]=x;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			betaa=numeric_limits<int>::max();
			for(x=0;x<m;x++)
			{
				tmp=(a[i][x]>a[j][x])?a[i][x]:a[j][x];
				betaa=(tmp<betaa)?tmp:betaa;
				if (betaa<=alpha)
					break;
			}
			if (betaa>alpha)
			{
				alpha=betaa;
				ansi=i+1;
				ansj=j+1;
			}
		}
	}
	cout<<ansi<<" "<<ansj<<endl;

	
}
