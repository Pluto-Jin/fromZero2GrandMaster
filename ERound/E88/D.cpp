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
	int ma=0,cur,ans=0;
	for (auto &i:ar) cin>>i,ma=max(ma,i);
	if (!ma) cout<<0<<endl;
	else {
		for (int j=ma;j>=1;j--) {
			cur=ma=0;
			for (int i=0;i<n;i++) {
				int tmp=ar[i]>j?-1e9:ar[i];
				cur=max(tmp,cur+tmp);
				ma=max(ma,cur);
			}
			ans=max(ans,ma-j);
		}
		cout<<ans<<endl;
	}
}

