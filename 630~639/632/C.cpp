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
	vi ar(n);
	for (auto &i:ar) cin>>i;
	vector<ll> sum(n);
	sum[0]=ar[0];
	map<ll,int> dict;
	ll ans=0;
	for (int ma=-1,i=0;i<n;i++) {
		if (i) sum[i]=sum[i-1]+ar[i];
		if (dict.count(sum[i])) ma=max(dict[sum[i]]+1,ma);
		if (!sum[i]) ma=max(ma,0); 
		ans+=i-ma;
		dict[sum[i]]=i;
	}
	cout<<ans<<endl;
}

