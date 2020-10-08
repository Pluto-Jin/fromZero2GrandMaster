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

const int N=5e5+1,M=1e7+1;
int ans[N][2],mip[M];
vi pr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	for (int i=2;i<=M;i++) {
		if (!mip[i]) pr.pb(i),mip[i]=i;
		for (auto j:pr) {
			if (1ll*i*j<M) mip[i*j]=j;
			else break;
			if (i%j==0) break;
		}
	}

	int n; cin>>n;
	for (int i=1;i<=n;i++) {
		int x; cin>>x;
		int tmp=x;
		while (tmp%mip[x]==0) tmp/=mip[x];
		if (tmp==1) ans[i][0]=ans[i][1]=-1;
		else ans[i][0]=mip[x],ans[i][1]=tmp;
	} 
	for (int i=1;i<=n;i++) cout<<ans[i][0]<<' '; cout<<endl;
	for (int i=1;i<=n;i++) cout<<ans[i][1]<<' '; cout<<endl;
}

