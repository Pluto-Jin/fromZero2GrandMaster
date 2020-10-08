#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se first
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector<int> ar;
		ar.resize(n);
		for (auto &i:ar) cin>>i;
		sort(ar.begin(),ar.end());
		reverse(ar.begin(),ar.end());
		for (auto i:ar) cout<<i<<' ';
		cout<<endl;
	}
}
