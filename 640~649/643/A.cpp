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
		ll a,k; cin>>a>>k;
		while (--k) {
			ll tmp=a;
			int ma=-1,mi=10;
			while (tmp) {
				int x=tmp%10;
				ma=max(ma,x);
				mi=min(mi,x);
				tmp/=10;
			}
			a+=ma*mi;
			if (!mi) break;
		}
		cout<<a<<endl;
	}
}

