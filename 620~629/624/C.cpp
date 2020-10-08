#include "bits/stdc++.h"
using namespace std;

int p[212345];
int main()
{
	int t;
	cin>>t;
	while (t--) {
		int cnt[26]={0};
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		for (int i=0;i<m;i++) cin>>p[i];
		sort(p,p+m);
		p[m]=212345;
		int pos=0;
		int x=p[0];
		for (int i=0;i<n;i++) {
			int tmp=s[i]-'a';
			if (i>=x) {while (p[++pos]==p[pos-1]);x=p[pos];}
			cnt[tmp]+=m+1-pos;
		}
		for (auto i:cnt) cout<<i<<" ";
		cout<<endl;
	}
}
