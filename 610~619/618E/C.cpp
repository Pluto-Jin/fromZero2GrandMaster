#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> a;
	vector<string> ar;
	a.resize(n);
	ar.resize(n);
	for (int i=0;i<n;i++) {
		int tmp;
		cin>>tmp;
		a[i]=tmp;
		ar[i]=bitset<32>(tmp).to_string();
	}
	int pos=0;
	for (int i=0;i<32;i++)
	{
		int cnt=0;
		int tmp=0;
		for (int j=0;j<n;j++)
		{
			if (ar[j][i]=='1') {
				cnt++;
				tmp=j;
			}
			if (cnt==2) break;
		}
		if (cnt==1) {
			pos=tmp;
			break;
		}
	}
	cout<<a[pos]<<" ";
	for (int i=1;i<n;i++) {
		if (i==pos) cout<<a[0]<<" ";
		else cout<<a[i]<<" ";
	}
	cout<<endl;
}
