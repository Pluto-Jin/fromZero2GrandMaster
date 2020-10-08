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

	int n; cin>>n;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) if (i%2) cout<<0<<' ';
			else cout<<(1ll<<(i+j))<<' ';
		cout<<endl;
	}
	cout<<flush;
	int q; cin>>q;
	while (q--) {
		ll s; cin>>s;
		bitset<50> bit(s);
		int x=1,y=1,cnt=1;
		cout<<x<<' '<<y<<endl;
		for (int i=1;cnt<2*n-1 and i<50;cnt++,i++) {
			if (x==n or bit[i]==bit[i-1]) cout<<x<<' '<<++y<<endl;
			else cout<<++x<<' '<<y<<endl;
		}
		cout<<flush;
	}
}

