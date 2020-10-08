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

	int t; cin>>t;
	while (t--) {
		int n,k; cin>>n>>k;
		int vis[101]={0},cnt=0;
		for (int i=0;i<n;i++) {
			int tmp; cin>>tmp;
			if (!vis[tmp]) cnt++;
			vis[tmp]=1;
		}
		if (cnt>k) cout<<-1<<endl;
		else {
			cout<<n*k<<endl;
			for (int i=0;i<n;i++) {
				for (int j=1;j<=n;j++) if (vis[j]) cout<<j<<' ';
				for (int j=0;j<k-cnt;j++) cout<<1<<' ';
			} 
			cout<<endl;
		}
	}
}

