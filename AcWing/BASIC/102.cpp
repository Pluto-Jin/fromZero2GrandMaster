#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
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

const int N=1e5+1;
double ar[N],pre[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,f; cin>>n>>f;
	for (int i=1;i<=n;i++) cin>>ar[i];
	double lo=1.0,hi=2001.0;
	while (hi-lo>1e-5) {
		double mid=(lo+hi)/2,mi=0;
		int ok=0;
		for (int i=1;i<=n;i++) pre[i]=ar[i]-mid+pre[i-1];
		for (int i=f;!ok and i<=n;i++) {
			mi=min(mi,pre[i-f]);
			if (pre[i]-mi>=0) ok=1;
		}
		if (ok) lo=mid; else hi=mid;
	}
	cout<<(int)(1000*hi)<<endl;
	return 0;
}
