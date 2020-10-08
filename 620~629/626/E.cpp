#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se first
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;

const int N=500001;
ll l[N],r[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;
	while (t--) {
		int n,m;
		cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>r[i];
		for (int i=0;i<m;i++) {
			int x,y;
			cin>>x>>y;
			l[x]+=r[y];
		}
		ll ans=__gcd(l[1],l[2]);
		for (int i=3;i<=n;i++) {
			ans=__gcd(ans,l[3]);
		}
		cout<<ans<<endl;
	}
}
