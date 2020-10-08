#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int d,m; cin>>d>>m;
		ll ans=1;
		for (int i=0;;i++) {
			ll cur=min((1ll<<i+1)-1,1ll*d)-(1ll<<i)+2;
			ans*=cur%m;
			ans%=m;
			if ((1ll<<i+1)>d) break;
		}
		cout<<(ans+m-1)%m<<endl;
	}
}

