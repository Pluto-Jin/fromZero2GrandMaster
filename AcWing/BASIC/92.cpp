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

int n;

void dfs(int p=0,int cur=0) {
	if (p==n) {
		for (int i=0;i<n;i++) if (cur>>i&1) cout<<i+1<<' ';
		cout<<endl;
		return;
	}	
	dfs(p+1,cur);
	dfs(p+1,cur|1<<p);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin>>n;
	dfs();
}
