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
#include<ctime>
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

const int N=3e5+5;
int a[N],dp[N];
stack<int> si,sd;
vi edge[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		while (si.size() and a[si.top()]>a[i]) si.pop(); 
		if (si.size()) edge[si.top()].pb(i);
		si.push(i);
		while (sd.size() and a[sd.top()]<a[i]) sd.pop();
		if (sd.size()) edge[sd.top()].pb(i);
		sd.push(i);
	}
	while (si.size()) si.pop();
	while (sd.size()) sd.pop();
	for (int i=n;i;i--) {
		while (si.size() and a[si.top()]>a[i]) si.pop(); 
		if (si.size()) edge[i].pb(si.top());
		si.push(i);
		while (sd.size() and a[sd.top()]<a[i]) sd.pop();
		if (sd.size()) edge[i].pb(sd.top());
		sd.push(i);
	}

	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	for (int i=1;i<=n;i++) for (auto to:edge[i]) dp[to]=min(dp[to],dp[i]+1);
	cout<<dp[n]<<endl;
}
