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
		ll a,b; cin>>a>>b;
		if (a>b) swap(a,b);
		int ok=1,cnt=0;
		while (b!=a) {
			if (b&1) {ok=0;break;}	
			b>>=1;
			cnt++;
		}
		if (!ok) cout<<-1<<endl;
		else cout<<cnt/3+!!(cnt%3)<<endl;
	}
}

