#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		vector<int> ar;
		ar.resize(n);
		for (auto &i:ar) cin>>i;

		int sum=0,res=0;

		for (auto i:ar) {
			if (i==0) {
				sum+=1;
				res+=1;
			}
			else sum+=i;
		}
		if (sum==0) res+=1;
		cout<<res<<endl;
	}
}
