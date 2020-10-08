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

ll solve(int n,int ed) {
	if (n<=ed) return n;
	n-=ed;
	ll res=n%9;
	for (int i=0;i<n/9;i++) res=res*10+9;
	return res*10+ed;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,k; cin>>n>>k;
		if (n<(1+k)*k/2) cout<<-1<<endl;
		else if (!k) cout<<solve(n,9)<<endl;
	    else {
			ll mi=2e18;
			int tmp=n-(1+k)*k/2;
			if (tmp%(k+1)==0) mi=solve(tmp/(k+1),9-k);
			for (int i=1;i<=k;i++) {
				tmp=n-(19-i)*i/2-(2+k-i)*(1+k-i)/2;
				if (tmp<0) continue;
				if (tmp%(k+1)==0) {
					if (solve(tmp/(k+1),8)<=1e17) 
						mi=min(mi,10*solve(tmp/(k+1),8)+10-i);
				}
			}
			cout<<(mi==2e18?-1:mi)<<endl;
		}	
	}
}

