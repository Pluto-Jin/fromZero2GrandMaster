#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		string s;
		cin>>s;
		int cnt=0;
		int ans=0,flag=0;
		for (auto i:s) {
			if (i=='1') {
				if (flag) ans+=cnt;
				flag=1;
				cnt=0;
			}
			else {
				cnt++;
			}
		}
		cout<<ans<<endl;
	}
}
