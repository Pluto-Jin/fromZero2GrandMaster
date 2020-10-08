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
	vi fib(2,1);
	for (int i=2;;i++) if (fib[i-2]+fib[i-1]>1e9) break; else fib.pb(fib[i-2]+fib[i-1]);
	while (t--) {
		int a,b,n; cin>>a>>b>>n;
		if (a<b) swap(a,b);
		if (a>n) cout<<0<<endl;
		else for (int i=1;;i++) if (1ll*a*fib[i]+1ll*b*fib[i-1]>n) {cout<<i<<endl;break;} 
	}
	 
}

