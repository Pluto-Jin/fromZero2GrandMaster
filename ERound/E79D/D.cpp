#include "bits/stdc++.h"
using namespace std;

const int mod=998244353;
int gf[1123456];

int main()
{
	int n;
	cin>>n;
	vector<int> k;
	vector<set<int>> st;
	k.resize(n);
	st.resize(n);
	for (int i=0;i<n;i++) {
		cin>>k[i];
		for (int j=0;j<k[i];j++) {
			int tmp;
			cin>>tmp;
			st[i].insert(tmp);
		}
	}


}

