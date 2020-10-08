#include "bits/stdc++.h"
using namespace std;


int ar[26][26];
long long res[26][26];
int main()
{
	string s;
	cin>>s;
	int tmp[26]={0};
	for (auto i:s) tmp[i-'a']++;
	long long m=0;
	for (auto i:tmp) m=max(m,1ll*i);
	for (int i=1;s[i];i++) {
		for (int j=0;j<26;j++) {
			ar[s[i]-'a'][j]=ar[s[i-1]-'a'][j];
			res[s[i]-'a'][j]+=ar[s[i-1]-'a'][j];
		}
		ar[s[i]-'a'][s[i-1]-'a']++;
		res[s[i]-'a'][s[i-1]-'a']++;
	}
	for (int i=0;i<26;i++) 
		for (int j=0;j<26;j++) 
			if (res[i][j]>m) m=res[i][j];
	cout<<m<<endl;
}
