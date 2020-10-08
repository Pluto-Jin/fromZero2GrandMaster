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
		int ok=1;
		vi ar(n);
		for (int i=0;i<n;i++) {
			cin>>ar[i];
			if (i and ar[i]<ar[i-1]) ok=0;
		}
		int a=0,b=0;
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			if (x) b=1;
			else a=1;	
		}
		if (a and b or ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

