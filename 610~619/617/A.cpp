#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector<int> ar;
		ar.resize(n);
		int odd=0,even=0;
		while (n--) {
			int tmp;
			cin>>tmp;
			if (tmp%2) odd++;
			else even++;
		}
		if (odd%2) cout<<"YES"<<endl;
		else if (!odd or even==0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}

