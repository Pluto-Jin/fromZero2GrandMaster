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
	vvi pos(n);
	for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) 
		if (ar[i]>ar[j]) pos[j].pb(i);	
	vii ans;
	for (int i=n-1;i>=0;i--) {
		sort(pos[i].begin(),pos[i].end(),[&](const int &a,const int &b){
				return (ar[a]==ar[b])?a<b:ar[a]<ar[b];});
		for (auto j:pos[i]) ans.pb(mp(j+1,i+1));
	}
	cout<<ans.size()<<endl;
	for (auto [i,j]:ans) cout<<i<<' '<<j<<endl;
}

