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
		int ok=0,cnt=0;
		if (n==2) ok=1;
		else {
			while (n%2==0) n/=2,cnt++;
			if (n==1) ok=0;
			else if (cnt!=1) ok=1;
			else for (int i=3;i<=sqrt(n);i+=2) if (n%i==0) {ok=1;break;} 	
		}
		cout<<(ok?"Ashishgup":"FastestFinger")<<endl;
	}
}

