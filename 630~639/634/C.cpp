#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vi cnt(n+1);
		int cntd=0,ma=0;
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			if (!cnt[x]) cntd++;
			cnt[x]++;
			ma=max(ma,cnt[x]);
		}
		if (ma>cntd) cout<<cntd<<endl;
		else cout<<min(cntd-1,ma)<<endl;
	}
}

