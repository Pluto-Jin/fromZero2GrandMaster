#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se first
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	ll n; cin>>n;
	vector<ll> ar; ar.resize(n);
	vector<ll> br; br.resize(n);
	for (auto &i:ar) cin>>i;
	for (auto &i:br) cin>>i;
	for (int i=0;i<n;i++) ar[i]-=br[i];
	sort(ar.begin(),ar.end());
	ll p1=0,p2=n-1,ans=0;
	while (p1<p2) {
		while (p1<p2 and ar[p1]+ar[p2]>0) ans+=(p2--)-p1;
		p1++;
	}
	cout<<ans<<endl;
}
