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
		int cnt[1001]={0};
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			cnt[x]=1;
		}
		int ans=0;
		for (int i=0;i<m;i++) {
			int x; cin>>x;
			if (cnt[x]) ans=x;
		}
		if (!ans) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl<<1<<' '<<ans<<endl;
		}
	}
}

