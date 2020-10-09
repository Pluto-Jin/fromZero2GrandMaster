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

string ar[5];
int dx[5]={1,-1,0,0,0},dy[5]={0,0,0,1,-1};
void turn(int r,int c) {
	for (int i=0,a,b;i<5;i++) {
		a=r+dx[i],b=c+dy[i];
		if (a>=0 and a<5 and b>=0 and b<5) ar[a][b]='1'+'0'-ar[a][b];
	}
}

int solve(int r,int cnt) {
	vi tmp;
	for (int i=0;i<5;i++) if (ar[r-1][i]=='0') tmp.pb(i);
	cnt+=tmp.size();
	if (cnt>6) return -1;
	for (auto i:tmp) turn(r,i);
	int res=cnt;
	if (r==4) {
		for (int i=0;i<5;i++) if (ar[r][i]=='0') res=-1;
	} else res=solve(r+1,cnt);
	for (auto i:tmp) turn(r,i);
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		for (auto &i:ar) cin>>i;
		int ans=10;
		for (int i=0;i<1<<5;i++) {
			vi tmp;
			for (int j=0;j<5;j++) if (i>>j&1) tmp.pb(j);
			for (auto i:tmp) turn(0,i);
			int cur=solve(1,tmp.size());
			if (cur!=-1) ans=min(ans,cur);
			for (auto i:tmp) turn(0,i);
		}
		cout<<(ans==10?-1:ans)<<endl;
	}
	return 0;
}
