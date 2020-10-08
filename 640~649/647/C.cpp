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

const int N=65;
ll ar[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	ar[0]=1ll;
	for (int i=1;i<=65;i++) ar[i]=2*ar[i-1]+1;

	int t; cin>>t;
	while (t--) {
		int pos=0;
		ll ans=0,n; cin>>n;
		while (n) {
			if (n&1) ans+=ar[pos];
			n>>=1;
			pos++;	
		}
		cout<<ans<<endl;
	}
}

