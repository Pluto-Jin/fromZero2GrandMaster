#include "bits/stdc++.h"
using namespace std;

int main()
{
	string s;
	cin>>s;
	vector<int> ans;
	int res=0;
	int p1=0,p2=s.size()-1;
	while (p1<p2) {
		while (s[p1]==')') p1++;
		while (s[p2]=='(') p2--;
		if (p1>=p2) break;
		ans.push_back(p1+1);
		ans.push_back(p2+1);
		p1++;
		p2--;
	}
	if (ans.empty()) cout<<0<<endl;
	else {
		sort(ans.begin(),ans.end());
		cout<<1<<endl;
		cout<<ans.size()<<endl;
		for (auto i:ans) cout<<i<<" ";
		cout<<endl;
	}
}
