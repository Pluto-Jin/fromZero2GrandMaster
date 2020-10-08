#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		string s;
		cin>>s;
		vector<string> ar;
		ar.push_back("");
		string ma=s;
		int ans=1;
		for (int i=1;i<=n;i++) {
			string tmp="";
			tmp+=s.substr(i-1,n-i+1);
			if (i>1) {
				string ttmp=s.substr(0,i-1);
				if ((n-i+1)%2==0) tmp+=ttmp;
				else {reverse(ttmp.begin(),ttmp.end());tmp+=ttmp;}
			}
			if (tmp<ma) {ma=tmp;ans=i;}
		}
		cout<<ma<<endl<<ans<<endl;
	}
}
