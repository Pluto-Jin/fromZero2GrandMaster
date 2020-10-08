#include "bits/stdc++.h"
using namespace std;

const int INF=2e9;

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		string s,t;
		cin>>s;
		cin>>t;
		vector<array<int,26>> ar;
		ar.resize(s.size()+1);
		for (auto &i:ar[s.size()]) i=INF;

		for (int i=s.size()-1;i>=0;i--) {
			for (int j=0;j<26;j++) ar[i][j]=ar[i+1][j];
			ar[i][s[i]-'a']=i;
		}
		int cnt=0,tmp=0;
		for (int i=0;i<t.size();i++) {
			if (ar[0][t[i]-'a']==INF) {
				cnt=INF;
				break;
			}
			if (!tmp) cnt++;
			tmp=ar[tmp][t[i]-'a']+1;
			if (tmp==s.size()) tmp=0;
			if (tmp>=INF) {
				tmp=ar[0][t[i]-'a']+1;
				cnt++;
			}	
		}
		if (cnt==INF) cout<<-1<<endl;
		else cout<<cnt<<endl;
	}
}
