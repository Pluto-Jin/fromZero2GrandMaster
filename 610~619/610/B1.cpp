#include "bits/stdc++.h"
using namespace std;

int t,n,p,k;
vector<int> ar;

int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n>>p>>k;
		ar.clear();
		ar.resize(n);
		for (auto &i:ar) cin>>i;

		sort(ar.begin(),ar.end());
		int odd=0,even=-1;
		int sodd=0,seven=0;
		for (int i=0;i<n;i++)
		{
			if (i%2)
			{
				sodd+=ar[i];
				if (sodd<=p) odd+=2;	
			}	
			else
			{
				seven+=ar[i];
				if (seven<=p) even+=2;
				else if (sodd>p) break;
			}
		}
		cout<<max(odd,even)<<endl;

	}
}
