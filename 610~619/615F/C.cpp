#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector<int> ans;
		for (int i=2;n and i<=sqrt(n) and ans.size()<2;i++) {
			if (n%i) ;
			else {
				n/=i;
				ans.push_back(i);
			}
		}
		if (ans.size()<2 or n<2 or n==ans[0] or n==ans[1]) cout<<"NO"<<endl;
		else cout<<"YES"<<endl<<ans[0]<<" "<<ans[1]<<" "<<n<<endl;
	}
}
