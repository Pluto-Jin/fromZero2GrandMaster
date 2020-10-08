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
		int n; cin>>n;
		int ok=1,x1=0,y1=0;
		for (int i=0;i<n;i++) {
			int x,y; cin>>x>>y;
			if (x<x1 or y<y1 or x-x1<y-y1) ok=0;
			x1=x,y1=y;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
}

