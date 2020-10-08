#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	vector<int> ar;
	ar.resize(n);

	string tmp="1";
	string ss="";
	ss+=s[0];
	ar[0]=1;
	for (int i=1;s[i];i++) {
		int j=tmp.size()-1;
		if (s[i]>=ss[j]) {ar[i]=1;tmp+="1";ss+=s[i];continue;}
		ss+=s[i];
		tmp+="0";
		while (j>=0 and s[i]<ss[j]) {
			if (tmp[j]=='0') {cout<<"NO"<<endl;return 0;}
			ss[j+1]=ss[j];
			tmp[j+1]=tmp[j];
			j--;
		}
		ss[j+1]=s[i];
		tmp[j+1]='0';
	}

	cout<<"YES"<<endl;
	for (auto i:ar) cout<<i;
	cout<<endl;
}

