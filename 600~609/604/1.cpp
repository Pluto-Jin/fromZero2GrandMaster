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
		vi ar(n); for (auto &i:ar) cin>>i;
		int g,s,b,ok=1; g=s=b=0;
		for (int i=0;i<n;i++) if (ar[i]==ar[0]) g++; else break;
		s=b=g+1;
		if (g+s+b>n/2) ok=0;
		int cnt=0;
		for (int i=g+s;ok and i<n;i++) if (ar[i]==ar[g+s-1]) cnt++; else break;
		s+=cnt;
		if (g+s+b>n/2) ok=0;
		cnt=0;
		for (int i=g+s+b;ok and i<n;i++) if (ar[i]==ar[g+s+b-1] or i+1<=n/2 and ar[i]!=ar[n/2]) cnt++; else break;
		b+=cnt;
		if (g+s+b>n/2) ok=0;
		if (!ok) g=s=b=0;
		cout<<g<<' '<<s<<' '<<b<<endl;
	}
}

