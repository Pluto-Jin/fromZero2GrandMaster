#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,a,b; cin>>n>>a>>b;
		string s="";
		for (int i=0;i<b;i++) s+='a'+i;
		for (int i=0;i<b-a;i++) s+='a';
		for (int p=0,i=0;i<n;i++) {
			cout<<s[p];
			p++;
			p%=b;
		}
		cout<<endl;
	}
}

