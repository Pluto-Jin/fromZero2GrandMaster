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
		int a=6,b=10,c=14,d=15,tmp=n-a-b-c;
		if (n>30) {
			cout<<"YES"<<endl;	
			if (tmp==a or tmp==b or tmp==c) c=d; 
			cout<<a<<' '<<b<<' '<<c<<' '<<n-a-b-c<<endl;
		}
		else cout<<"NO"<<endl;
	}
}

