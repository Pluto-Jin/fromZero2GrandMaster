#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0;
	for (int c='z';c>'a';c--) {
		int tmp=0;
		for (int i=0;i<n;i++) if (s[i]!=0) {tmp=i;break;}
		for (int i=tmp;i<n;i++) {
			if (s[i]=='0') continue;
			if (s[i]!=c) tmp=i;
			else if (s[tmp]==c-1) {s[i]='0';ans++;}
			else tmp=i;
		}
		tmp=n-1;
		for (int i=n-1;i>=0;i--) if (s[i]!='0') {tmp=i;break;}
		for (int i=tmp;i>=0;i--) {
			if (s[i]=='0') continue;
			if (s[i]!=c) tmp=i;
			else if (s[tmp]==c-1) {s[i]='0';ans++;}
			else tmp=i;
		}
	}
	cout<<ans<<endl;
}
