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
		vi ar(n),br(n);
		for (auto &i:ar) cin>>i;
		for (auto &i:br) cin>>i;
		sort(ar.begin(),ar.end());
		sort(br.begin(),br.end());
		reverse(br.begin(),br.end());
		int ans=0;
		for (int i=0;i<k;i++) ans+=max(ar[i],br[i]);
		for (int i=k;i<n;i++) ans+=ar[i];
		cout<<ans<<endl;
	}
}

