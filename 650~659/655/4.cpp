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
	vi ar(n+1);
	vector<ll> pre0(n+1),pre1(n+1);
	for (int i=1;i<=n;i++) {
		cin>>ar[i];
		if (i%2==0) pre0[i]=ar[i]+pre0[i-2];
		else if (i==1) pre1[i]=ar[i];
		else pre1[i]=ar[i]+pre1[i-2];
	}
	ll ans=0;
	for (int i=1;i<=n;i++) {
		ll tmp=0;
		if (i%2) tmp=pre1[n]-pre1[i]+ar[i]+pre0[i-1];
		else tmp=pre0[n-1]-pre0[i-2]+pre1[i-1];
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
}

