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
	map<int,int> cnt;
	for (int x,i=0;i<n;i++) cin>>x,cnt[x]++;
	vvi ar(n+1);
	int ma=0;
	for (auto [x,y]:cnt) ar[y].pb(x),ma=max(ma,y);

	int r,c,tot=0,cur=0;
	for (int i=max((int)sqrt(n),ma);i>=1;i--) {
		if (1ll*i*i<=n) {
			int j=n;
			while (j%i) j--;
			if (j>tot) tot=j,r=i,c=j/i;
		}
		n-=ar[i].size()+cur;
		cur+=ar[i].size();
	}
	for (int i=r+1;i<=ma;i++) for (auto j:ar[i]) ar[r].pb(j);
	vvi ans(r,vi(c));
	int cr=0,cc=0,bg=0;
	for (int k=r;k>=1;k--) for (auto t:ar[k]) {
		for (int j=0;j<k;j++) {
			ans[cr++][cc++]=t;
			if (cr==r) cr=0,cc=++bg;
			if (cc==c) cc=0;
			if (bg==c) goto gg;
		}	
	}
	gg:cout<<tot<<endl<<r<<' '<<c<<endl;
	for (auto i:ans) {
		for (auto j:i) cout<<j<<' ';
		cout<<endl;
	}
}

