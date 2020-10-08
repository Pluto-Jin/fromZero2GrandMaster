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
		int n; cin>>n;
		set<int> s;
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			s.insert(x);
		}
		int ans,ok;
		for (ans=1;ans<1024;ans++) {
			ok=1;
			for (auto i:s) if (!s.count(i^ans)) {ok=0;break;}
			if (ok) break;
		}
		cout<<(ok?ans:-1)<<endl;
	}
}

