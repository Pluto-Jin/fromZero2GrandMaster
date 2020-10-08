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

	int n,k,c1=0,c2=0; cin>>n>>k;
	vi ar,br,cr;
	for (int i=0;i<n;i++) {
		int t,x,y; cin>>t>>x>>y;
		if (x and y) cr.pb(t),c1++,c2++;
		else if (x) ar.pb(t),c1++;
		else if (y) br.pb(t),c2++;
	}
	if (c1<k or c2<k) cout<<-1<<endl;
	else {
		sort(ar.begin(),ar.end());
		sort(br.begin(),br.end());
		sort(cr.begin(),cr.end());
		int a=0,b=0,c=0,ans=0;
		while (k) {
			if (a>=ar.size() or b>=br.size()) {
				while (k) ans+=cr[c++],k--;
			} else if (c>=cr.size()) {
				while (k) ans+=ar[a++]+br[b++],k--;
			} else {
				if (ar[a]+br[b]<=cr[c]) ans+=ar[a++]+br[b++];
				else ans+=cr[c++];
				k--;
			}
		}
		cout<<ans<<endl;
	}
}

