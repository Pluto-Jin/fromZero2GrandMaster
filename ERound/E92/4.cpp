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
		ll l1,r1,l2,r2; cin>>l1>>r1>>l2>>r2;
		if (l1>l2) swap(l1,l2),swap(r1,r2);
		ll l=min(l1,l2),r=max(r1,r2);
		ll ans=0;
		if (l2<=r1) {
			k-=(min(r1,r2)-l2)*n;
			if (k<=0) ans=0;
			else {
				int cnt=n,tmp=l2-l1+abs(r2-r1);
				while (k>=tmp and cnt) {
					k-=tmp,ans+=tmp;
					cnt--;
				}
				if (k and cnt) ans+=k;
				else ans+=k*2;
			}
		} else {
			if (k>=(r-l)*n) ans=(l2-r1+r-l)*n+(k-(r-l)*n)*2;
			else {
				ans=l2-r1;
				if (k<=r-l) ans+=k;
				else {
					int cnt=n-1;
					k-=r-l,ans+=r-l;
					while (k>=r-l and cnt) {
						k-=r-l,ans+=l2-r1+r-l;
						cnt--;
					}
					if (cnt and k>=l2-r1) ans+=l2-r1+k;
					else ans+=k*2;
				}
			}
		}
		cout<<ans<<endl;
	}
}

