#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> a;

int solve (vector<int> v, int bit)
{
	if (v.empty() or bit==0)
		return 0;
	vector<int> l,r;
	for (auto &i:v)
		if (i>>(bit-1)&1) r.push_back(i);
		else l.push_back(i);

	if (r.empty()) return solve(l,bit-1);
	if (l.empty()) return solve(r,bit-1);
	return (1<<bit-1)+min(solve(l,bit-1),solve(r,bit-1));
}

int main()
{
	cin>>n;
	a.resize(n);
	for (auto &i:a)
		cin>>i;
	cout<<solve(a,30)<<endl;
}
