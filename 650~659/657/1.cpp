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
	string x="abacaba";
	while (t--) {
		int n; cin>>n;
		string s; cin>>s;
		vi ar(n);
		int a=0,b=0;
		for (int i=0;i<=n-7;i++) {
			int ok=1,cnt=0;
			for (int j=0;j<7;j++) {
				if (s[i+j]=='?') cnt++;
				if (s[i+j]!='?' and s[i+j]!=x[j]) ok=0;
			}
			if (!cnt and ok) a++,ar[i]=2;
			else if (ok) {
				if (i+10<n and s.substr(i+7,4)=="caba") ar[i]=0;
				else if (i+12<n and s.substr(i+7,6)=="bacaba") ar[i]=0;
				else if (i-4>=0 and s.substr(i-4,4)=="abac") ar[i]=0;
				else if (i-6>=0 and s.substr(i-6,6)=="abacab") ar[i]=0;
				else b++,ar[i]=1;
			}	
		}
		if (a>1 or !a and !b) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			if (a==1) for (int i=0;i<n;i++) cout<<(s[i]=='?'?'z':s[i]);
			else {
				int ok=1;
				for (int i=0;i<n;i++) {
					if (ok and ar[i]==1) cout<<x,i+=6,ok=0;
					else cout<<(s[i]=='?'?'z':s[i]);
				}
			}
			cout<<endl;
		}
	}
}

