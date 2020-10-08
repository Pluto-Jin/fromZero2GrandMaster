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
	int ma=0,cnt[20]={0};
	for (int i=0;i<n;i++) {
		int x,cur=0; cin>>x;
		for (int i=19;i>=0;i--) {
			if (!(x&(1<<i))) continue;
			if (!cur) cur=i;
			cnt[i]++;
		} 	
		ma=max(cur,ma);
	} 
	ll ans=0;
	for (int i=0;i<n;i++) {
		ll cur=0;
		for (int i=19;i>=0;i--) if (cnt[i]) cur|=(1<<i),cnt[i]--;
		if (!cur) break;
		ans+=cur*cur;
	}
	cout<<ans<<endl;
}

