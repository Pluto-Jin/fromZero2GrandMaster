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

const int MOD=1e9+7;
ll fpow(ll a, ll b) {
	ll res=1;
	while (b) {
		if (b%2) res*=a,res%=MOD;
		b/=2;
		a*=a,a%=MOD;
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	ll tmp=1;
	for (int i=1;i<=n;i++) tmp=tmp*i%MOD;
	cout<<(MOD+tmp-fpow(2,n-1))%MOD<<endl;
}

