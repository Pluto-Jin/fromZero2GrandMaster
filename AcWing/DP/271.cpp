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

int n,a[5];
ll dp[31][16][11][8][7];

ll solve(int a,int b,int c,int d,int e) {
	if (a<b or b<c or c<d or d<e or e<0) return 0;
	if (dp[a][b][c][d][e]) return dp[a][b][c][d][e];
	return dp[a][b][c][d][e]=solve(a-1,b,c,d,e)+solve(a,b-1,c,d,e)+solve(a,b,c-1,d,e)+solve(a,b,c,d-1,e)+solve(a,b,c,d,e-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	while (1) {
		cin>>n; if (!n) break;
		for (int i=0;i<n;i++) cin>>a[i];
		for (int i=n;i<5;i++) a[i]=0;
		memset(dp,0,sizeof(dp));
		dp[1][0][0][0][0]=1;
		cout<<solve(a[0],a[1],a[2],a[3],a[4])<<endl;
	}
}
