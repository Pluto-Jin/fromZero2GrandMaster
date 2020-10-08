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

	int a,b,c,d; cin>>a>>b>>c>>d;
	ll ans=0;
	for (int i=a;i<=b;i++) {
		int bg=max(b,c-i+1),mid=(d-i+1);
		if (mid<=c) {
			if (mid>b) ans+=1ll*(i+bg-c+d-c+1)*(d+2-i-bg)/2+1ll*(c-mid)*(d-c+1);
			else ans+=1ll*(c-b+1)*(d-c+1);
		}
		else ans+=1ll*(i+bg-c+i)*(c-bg+1)/2;
	}
	cout<<ans<<endl;
}

