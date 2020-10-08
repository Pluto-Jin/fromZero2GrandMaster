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

const int N=5e5+2;
int ans[N],lfac[N];
bool vis[N];
vi pr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=2;i<=n;i++) {
		if (!vis[i]) {
			pr.pb(i);
			lfac[i]=i;
			for (int j=2*i;j<=n;j+=i) {
				vis[j]=true; 
				if (!lfac[j]) lfac[j]=i;
			}
		}
	}
	for (int i=2;i<=pr.size()+1;i++) ans[i]=1;
	for (int res=2,cur=pr.size()+2;;res++) {
		for (auto i:pr) {
			if (i>lfac[res] or i*res>n) break;
			ans[cur++]=res;
		}
		if (cur>n) break;
	}
	for (int i=2;i<=n;i++) cout<<ans[i]<<' ';
	cout<<endl;
}

