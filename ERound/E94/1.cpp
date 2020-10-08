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
		string s; cin>>s;
		int x; cin>>x;
		string ans(s.size(),'1');
		for (int i=0;i<s.size();i++) if (s[i]=='0') {
			if (i-x>=0) ans[i-x]='0'; 
			if (i+x<s.size()) ans[i+x]='0';
		}
		int ok=1;
		for (int i=0;ok and i<s.size();i++) if (s[i]=='1') {
			int cnt=0;
			if (i-x>=0 and ans[i-x]=='1') cnt++; 
			if (i+x<s.size() and ans[i+x]=='1') cnt++;
			if (!cnt) ok=0;
		}
		cout<<(ok?ans:"-1")<<endl;
	}
}

