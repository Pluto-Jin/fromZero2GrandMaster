#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int tmp;
	if (n%2) tmp=n/2*(n/2-1)+n/2;
	else tmp=n/2*(n/2-1);
	if (m>tmp) {cout<<-1<<endl;return 0;}
	if (m==tmp) {for (int i=1;i<=n;i++) cout<<i<<" ";cout<<endl; return 0;}

	vector<int> ans;
	ans.resize(n);
	int p;
	for (int i=0;i<n;i++)
	{
		int tmp=(i)/2;
		if (m>tmp) {m-=tmp;ans[i]=i+1;}
		else {
			ans[i]=i+1+2*(tmp-m);
			p=i;
			break;
		}
	}
	for (int i=p+1;i<n;i++) ans[i]=ans[i-1]+50000;
	for (auto i:ans) cout<<i<<" ";
	cout<<endl;
}
