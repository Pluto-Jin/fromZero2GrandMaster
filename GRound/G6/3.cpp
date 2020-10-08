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

	int r,c; cin>>r>>c;
	if (r==1 and c==1) cout<<0<<endl;
	else if (c==1) for (int i=1;i<=r;i++) cout<<i+1<<endl;
	else {
		for (int i=1;i<=r;i++) {
			for (int j=r+1;j<=r+c;j++) cout<<i*j<<' ';
			cout<<endl;
		}
	}
}

