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
		char tmp=s[0];
		int ok=1;
		for (int i=1;i<s.size();i++) if (s[i]!=tmp) {ok=0;break;}
		if (ok) cout<<s<<endl;
		else {
			cout<<s[0];
			for (int i=1;i<s.size();i++) {
				if (s[i]==s[i-1]) cout<<char('1'+'0'-s[i]);
				cout<<s[i];
			}
			cout<<endl;
		}
	}
}

