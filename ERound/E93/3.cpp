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
		string s; cin>>s;
		vi d(n+1),pre(n+1);
		for (int i=0;i<n;i++) pre[i+1]=pre[i]+s[i]-'0',d[i+1]=pre[i+1]-(i+1);

		map<int,int> dic;
		ll ans=0;
		for (int i=0;i<=n;i++) {
			ans+=dic[d[i]]++;
		}
		cout<<ans<<endl;
	}
}

