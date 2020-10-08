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
		vi ar(n);
		for (auto &i:ar) cin>>i;
		int p=0,i=0,ok=1,q=n;
		while (i<n) {
			if (ar[i]!=q) {
				p=ar[i];
				while (i+1<n and ar[i+1]-ar[i]==1) i++;
				if (ar[i]!=q) {ok=0;break;}
				i++;
				q=p-1;
			}
			else {
				while (i+1<n and ar[i]-ar[i+1]==1) i++;
				q=ar[i]-1;
				i++;
			}
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
}

