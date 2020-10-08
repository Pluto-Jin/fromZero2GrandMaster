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

int npr[1001];
vi pr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	for (int i=2;i<1000;i++) {
		if (!npr[i]) {
			pr.pb(i);
			for (int j=2*i;j<=1000;j+=i) npr[j]=1;
		}
	}
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vi ar(n),ans(n),vis(n,0);
		int cnt=1;
		for (auto &i:ar) cin>>i;
		for (auto p:pr) {
			if (p*p>1000) break;
			int ok=0;
			for (int i=0;i<n;i++) {
				if (vis[i]) continue;
				if (ar[i]%p==0) {
					ans[i]=cnt;
					vis[i]=1;
					ok=1;
				}
			}
			if (ok) cnt++;
		}
		cout<<cnt-1<<endl;
		for (auto i:ans) cout<<i<<' ';
		cout<<endl;

	}
}

