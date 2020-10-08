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

const int N=2e5+1;
ll n,x,d[N*2],hug[N*2],sumd[N*2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>x;
	for (int i=1;i<=n;i++) {
		ll tmp; cin>>tmp;
		d[i]=d[i+n]=tmp;
		hug[i]=hug[i+n]=(1ll+tmp)*tmp/2;
	}
	for (int i=1;i<=2*n;i++) hug[i]+=hug[i-1],sumd[i]=sumd[i-1]+1ll*d[i];
	ll ans=0;
	for (int i=n+1;i<=2*n;i++) {
		int lo=i-n,hi=i;
		while (lo<hi-1) {
			int mid=(hi-lo)/2+lo;
			if (x>sumd[i]-sumd[mid]) hi=mid;
			else lo=mid;	
		}
		ll tmp=x-(sumd[i]-sumd[hi]);
		ans=max(ans,(d[hi]+d[hi]-tmp+1)*tmp/2+hug[i]-hug[hi]);
	}
	cout<<ans<<endl;
}

