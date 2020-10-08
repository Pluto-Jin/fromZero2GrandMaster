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
	vector<ll> ar(n);
	for (auto &i:ar) cin>>i;
	ll ans=0;
	for (int i=0;i<n;i++) 
		for (int j=i;j<n;j++) 
			for (int k=j;k<n;k++)
				ans=max(ans,ar[i]|ar[j]|ar[k]);
	cout<<ans<<endl;
}

