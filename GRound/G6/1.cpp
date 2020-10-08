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
		int ok0=0,ok2=0,ok3=0;
		for (auto i:s) {
			int tmp=i-'0';
			if (!tmp) ok0=1;
			if (tmp%2==0) ok2++;
			ok3+=tmp;
		}
		cout<<(ok0 and ok2>1 and ok3%3==0?"red":"cyan")<<endl;
	}
}

