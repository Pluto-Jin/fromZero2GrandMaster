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
		int n; cin>>n;
		vector<int> ar; ar.resize(n);
		int mi=1e9;
		for (auto &i:ar) {cin>>i;mi=min(mi,i);}
		int ok=1;
		for (auto &i:ar) {i-=mi;if (i%2) ok=0;}
		cout<<(ok?"YES":"NO")<<endl;
	}
}
