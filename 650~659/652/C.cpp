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
		vi ar(n),br(k);
		for (auto &i:ar) cin>>i;
		for (auto &i:br) cin>>i,i--;
		sort(ar.begin(),ar.end());
		sort(br.begin(),br.end());
		ll ans=0;
		for (int i=0,p1=0,p2=n-1;i<k;i++) {
			if (!br[i]) ans+=ar[p2--]*2;
			else {
				for (int j=k-1;j>=0 and br[j];j--) {
					ans+=ar[p1]+ar[p2--];
					p1+=br[j];
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
}

