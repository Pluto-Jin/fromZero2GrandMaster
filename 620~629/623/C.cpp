#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector<int> br;
		vector<int> ar;
		br.resize(n);
		ar.resize(2*n);
		int tmp=0,ttmp=1;
		for (auto &i:br) {
			cin>>i;
			if (i>=2*n) tmp=1;
			if (i==1) ttmp=0;
		}
		if (tmp or ttmp) {cout<<-1<<endl;continue;}

		for (int i=1;i<=2*n;i++) {
			tmp=0;
			int fg=0;
			for (int j=0;j<n;j++) {
				if (br[j]==i) {
					ar[2*j]=i;
					fg=1;
					break;
				}
			}
			if (!fg) {
				for (int j=0;j<2*n;j+=2) {
					if (ar[j] and !ar[j+1]) {ar[j+1]=i;tmp=1;break;}
				}
				if (!tmp) break;
			}
		}
		if (!tmp) {cout<<-1<<endl;continue;}
		for (auto i:ar) cout<<i<<" ";
		cout<<endl;
	}
}
