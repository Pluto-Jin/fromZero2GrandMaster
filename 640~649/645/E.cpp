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

	int n; cin>>n;
	vi ar(n);
	for (int i=0;i<(n+1)/2;i++) cin>>ar[i];
	int x; cin>>x;
	for (int i=(n+1)/2;i<n;i++) ar[i]=x;
	for (int i=1;i<n;i++) ar[i]+=ar[i-1];
}

