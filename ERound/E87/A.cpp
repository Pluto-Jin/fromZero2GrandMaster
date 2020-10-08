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
		ll a,b,c,d; cin>>a>>b>>c>>d;
		if (b>=a) cout<<b<<endl;
		else {
			a-=b;
			if (d>=c) cout<<-1<<endl;
			else cout<<(a/(c-d)+(a%(c-d)!=0))*c+b<<endl;
		}
	}
}


