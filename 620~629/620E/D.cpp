#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int n;
		string s;
		cin>>n>>s;

		vector<int> ar;
		vector<int> br;
		ar.resize(n);
		br.resize(n);

		int pos=n-1,cur=1;
		for (int i=comp.size()-1;i>=0;i--) {
			pos-=comp[i].first;
			int tmp=comp[i].second;
			if (tmp) {
				for (int j=pos;j<pos+comp[i].first+1;j++) {
					ar[j]=cur;
					cur++;
				}
			}
			else {
				if (i==comp.size()-1) ar[n-1]=cur++;
				for (int j=pos+comp[i].first-1;j>=pos+1 or j==0;j--) {
					ar[j]=cur;
					cur++;
				}
			}
		}

		int hi=n,lo=1;
		pos=0;
		for (int i=0;i<comp.size();i++) {
			int tmp=comp[i].second;
			if (tmp) {
				for (int j=pos;j<pos+comp[i].first or j==n-1;j++) {
					br[j]=lo;
					lo++;
				}
			}
			else {
				for (int j=pos;j<pos+comp[i].first or j==n-1;j++) {
					br[j]=hi;
					hi--;
				}
			}
			pos+=comp[i].first;
		}

		for (auto i:ar) cout<<i<<" ";
		cout<<endl;
		for (auto i:br) cout<<i<<" ";
		cout<<endl;
	}
}

