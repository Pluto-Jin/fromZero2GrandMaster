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
		string s; cin>>s;
		int a=0,b=0;
		for (auto i:s) if (i=='0') a++; else break;
		reverse(s.begin(),s.end());
		for (auto i:s) if (i=='1') b++; else break;
		for (int i=0;i<a;i++) cout<<0;
		if (a+b<n) cout<<0;
		for (int i=0;i<b;i++) cout<<1;
		cout<<endl;
	}
}

