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
		int n,m; cin>>n>>m;
		set<ll> ar;
		for (int i=0;i<n;i++) {
			string s; cin>>s;
			ar.insert(stoll(s,nullptr,2));
		}
		ll lo=0,hi=1ll<<m;
		while (lo<hi-1) {
			ll mid=lo+(hi-lo)/2,cnt=mid;
			for (auto i:ar) {
				if (i<mid) cnt--;
			}
			if (cnt>((1ll<<m)-n-1)/2) hi=mid;
			else lo=mid;
		}
		while (ar.count(lo)) lo--;
		bitset<64> ans(lo);
		cout<<ans.to_string().substr(64-m)<<endl;
	}
}


