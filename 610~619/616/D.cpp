#include "bits/stdc++.h"
using namespace std;

const int N=2e5+5;
int ar[N][26];

int main()
{
	string s;
	cin>>s;
	int q;
	cin>>q;
	for (int i=1;s[i-1];i++) {
		ar[i][s[i-1]-'a']++;
		for (int j=0;j<26;j++) {
			ar[i][j]+=ar[i-1][j];
		}
	}
	while (q--) {
		int l,r;
		cin>>l>>r;
		if (l==r or s[l-1]!=s[r-1]) {
			cout<<"YES"<<endl;
			continue;
		}
		int cnt=0;
		for (int i=0;i<26;i++) if (ar[r][i]-ar[l-1][i]!=0) cnt++;
		if (cnt>2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}
}

