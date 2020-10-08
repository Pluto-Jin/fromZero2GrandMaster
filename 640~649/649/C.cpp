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
	vi ar(n+1),que,ans;
	for (int i=1;i<=n;i++) {
		cin>>ar[i];
		if (ar[i]>ar[i-1]+1) for (int j=ar[i-1]+1;j<ar[i];j++) que.pb(j);
	}
	int cur=0,p=0,ok=1;
	for (int i=1;i<=n;i++) {
		if (ar[i]==ar[i-1]+1) ans.pb(ar[i-1]);
		else if (cur==ar[i]) ans.pb((p<que.size()?que[p++]:1e6));
		else {
			ans.pb(cur);
			if (p<que.size() and que[p]==cur) p++;
			if (p<que.size() and que[p]<ar[i]) {ok=0;break;}
		}
		cur=ar[i];
	}
	for (auto i:ans) cout<<i<<' '; cout<<endl;
}

