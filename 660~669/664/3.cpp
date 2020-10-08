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

	int n,m; cin>>n>>m;
	vi ar(n),br(m);
	for (auto &i:ar) cin>>i;
	for (auto &i:br) cin>>i;
	int ans=1e9;
	for (int cur=0;cur<512;cur++) {
		int okk=1;
		for (auto i:ar) {
			int ok=0;
			for (auto j:br) if ((i&j|cur)==cur) {ok=1;break;}
			if (!ok) {okk=0;break;} 
		}
		if (okk) {cout<<cur<<endl;break;}
	}
}

