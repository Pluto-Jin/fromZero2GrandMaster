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
		int n,x; cin>>n>>x;
		vi ar(n);
		for (auto &i:ar) cin>>i;
		sort(ar.begin(),ar.end());
		int p=ar.size()-1;
		ll sum=0;
		if (ar[p]<x) cout<<0<<endl;
		else if (ar[0]>=x) cout<<n<<endl;
		else {
			while (p>=0 and 1ll*x*(ar.size()-p)<=sum+ar[p]) sum+=ar[p--]; 
			cout<<ar.size()-p-1<<endl;
		}
	}
}

