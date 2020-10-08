#include "bits/stdc++.h"
using namespace std;

int t;
long long a,b;
int tmp,cnt;
vector<long long> ans;

int main()
{
	cin>>t;
	while (t--)
	{
		cin>>a>>b;
		tmp=1,cnt=0;
		while (b)
		{
			cnt++;
			if (tmp)
				tmp=b%10==9;
			b/=10;
		}
		ans.push_back(a*(cnt-1+tmp));
	}
	for (auto i:ans)
		cout<<i<<endl;
}
