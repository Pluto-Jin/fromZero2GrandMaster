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
		ll n,l,r; cin>>n>>l>>r;
		if (l==n*(n-1)+1) {
			cout<<1<<' '<<endl;
			continue;
		}
		ll tmp=n-1,sum=0;
		while (l>sum+2*tmp) sum+=2*tmp,tmp--;
		for (ll i=l;i<=r;i++) {
			if (i==n*(n-1)+1) {
				cout<<1<<' ';
				break;
			}
			if (i>sum+2*tmp) sum+=2*tmp,tmp--;
			ll j=i-sum;
			cout<<(j%2?n-tmp:j/2+n-tmp)<<' ';
		}
		cout<<endl;
	}
}

