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
		int n,m,x,y; cin>>n>>m>>x>>y;
		y=min(y,2*x);
		int ans=0;
		for (int i=0;i<n;i++) {
			string s; cin>>s;
			for (int i=0;i<m;i++) {
				if (s[i]=='.') {
					if (i<m-1 and s[i+1]=='.') ans+=y,s[i+1]='*';
					else ans+=x;
				}
			}
		}
		cout<<ans<<endl;
	}
}

