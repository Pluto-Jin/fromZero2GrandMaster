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

	int n,d,m; cin>>n>>d>>m;
	vi ar,br;
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		if (x>m) br.pb(x);
		else ar.pb(x);
	}
	sort(ar.begin(),ar.end(),greater<int>());
	sort(br.begin(),br.end(),greater<int>());
	vector<ll> pre(ar.size()+1);
	for (int i=0;i<ar.size();i++) pre[i+1]=pre[i]+ar[i];
	ll ans=pre.back(),cur=0;
	for (int i=0;i<br.size();i++) {
		if (i+1+i*d>n) break;
		cur+=br[i];
		ans=max(ans,cur+pre[min((int)ar.size(),n-i*d-i-1)]);
	}
	cout<<ans<<endl;
}

