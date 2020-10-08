#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	ll u,v; cin>>u>>v;
	if (!u and !v)	{
		cout<<0<<endl;
		return 0;
	}
	if (u==v) {
		cout<<1<<endl<<u<<endl;
		return 0;
	}
	if (u>v or (v-u)%2) {
		cout<<-1<<endl;
		return 0;
	}
	ll tmp=(v-u)/2;
	if (tmp&u) cout<<3<<endl<<u<<' '<<tmp<<' '<<tmp<<endl;
	else cout<<2<<endl<<tmp<<' '<<(tmp^u)<<' '<<endl;


}

