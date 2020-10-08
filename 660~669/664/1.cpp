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
		int a,b,c,d; cin>>a>>b>>c>>d;
		int cnt=a%2+b%2+c%2;
		if (!a or !b or !c) {
			if (!cnt or cnt==1 and d%2==0) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		} else {
			if (!cnt or cnt==3 or cnt==1 and d%2==0 or cnt==2 and d%2) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}

