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
		vi ar(n);
		int ok=0,has=0;
		for (int i=0;i<n;i++) {
			cin>>ar[i];
			if (ar[i]==k) has=1;
			if (ar[i]>=k) {
				if (i>0 and ar[i-1]>=k) ok=1;
				if (i>1 and ar[i-2]>=k) ok=1;
			}
		}
		if (n==1) ok=has;
		cout<<((ok and has)?"yes":"no")<<endl;
	}
}

