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
		int n,k; cin>>n>>k;
		vi ar(n),peak;
		for (auto &i:ar) cin>>i;
		int p1=0,p2=0,ans1=0,ans2=0;
		for (int i=1;i<n-1;i++) {
			if (ar[i]>ar[i-1] and ar[i]>ar[i+1]) peak.pb(i);
		}
		while (1) {
			while (p2<peak.size() and peak[p2]-peak[p1]+3<=k) {
				if (p2-p1+1>ans1) ans1=p2-p1+1,ans2=peak[p2]+1;
				p2++;
			}
			if (p2==peak.size()) break;
			while (peak[p2]-peak[p1]+3>k) p1++;
		}
		cout<<ans1+1<<' '<<max(1,ans2-k+2)<<endl;

	}
}

