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

const int N=2e5+2;
int ar[N],clr[N];
bool vis[N];

int solve(int start) 
{
	vi tmp;
	int p=start;
	while (ar[p]!=start) tmp.pb(p),vis[p]=true,p=ar[p];
	tmp.pb(p);
	vis[p]=true;
	int n=tmp.size();
	if (n==1) return 1;
	for (int i=1;i<n;i++) {
		if (n%i) continue;
		for (int j=0;j<i;j++) {
			int ok=1;
			for (int p=j;p<n;p+=i) 
				if (clr[tmp[p]]!=clr[tmp[j]]) {ok=0; break;}
			if (ok) return i;
		}
	}
	return n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		fill(vis,vis+N,0);
		int n; cin>>n;
		for (int i=1;i<=n;i++) cin>>ar[i];
		for (int i=1;i<=n;i++) cin>>clr[i];
		int ans=1e9;
		for (int i=1;i<=n;i++) {
			if (vis[i]) continue;
			ans=min(ans,solve(i));
			if (ans==1) break;
		}
		cout<<ans<<endl;
	}

}

