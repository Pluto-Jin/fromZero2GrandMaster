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
		vector<bool> vis(n+1);
		int last=0;
		for (int i=1;i<=n;i++) {
			int k,ok=0; cin>>k;
			for (int j=0;j<k;j++) {
				int x; cin>>x;
				if (!ok and !vis[x]) {
					ok=1;
					vis[x]=true;
				}
			}
			if (!ok) last=i;
		}
		if (!last) cout<<"OPTIMAL"<<endl;
		else {
			cout<<"IMPROVE"<<endl;
			for (int i=1;i<=n;i++) {
				if (!vis[i]) {cout<<last<<' '<<i<<endl;break;}
			}
		}
	}
}

