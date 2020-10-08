#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		ll n,k; cin>>n>>k;
		vi ar(n);
		int mi=1e9,ma=-1e9;
		for (auto &i:ar) {
			cin>>i;
			mi=min(i,mi);
			ma=max(i,ma);
		}
		if (k%2) for (auto &i:ar) i=ma-i;
		else for (auto &i:ar) i=i-mi;
		for (auto i:ar) cout<<i<<' ';
		cout<<endl;
	}
}

