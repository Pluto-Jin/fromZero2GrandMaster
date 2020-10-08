#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	vector<int> ar;
	set<int> s;
	while (t--)
	{
		s.clear();
		ar.clear();	
		int n;
		int tmp;
		int ans=0;
		cin>>n;
		for (int i=0;i<n;i++)
		{
			cin>>tmp;
			if (tmp%2==0) 
			{
				if (s.count(tmp)) continue;
				s.insert(tmp);
				ar.push_back(tmp);
			}
		}
		sort(ar.begin(),ar.end());
		for (int i=ar.size()-1;i>=0;i--)
		{
			s.erase(ar[i]);
			while (!s.count(ar[i]) and !(ar[i]%2))
			{ 
				ar[i]/=2;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
