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

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;
typedef std::vector<std::vector<int>> vvi;

using namespace std;

template<class T,class T2>
inline bool chkmax(T &x,const T2 &y){return x<y?(x=y,1):0;}
template<class T,class T2>
inline bool chkmin(T &x,const T2 &y){return x>y?(x=y,1):0;}

const int MOD=1e9;
ll dp[301][301];
bool vis[301][301];
string s;

ll solve(int i,int j) {
	if (vis[i][j]) return dp[i][j]; vis[i][j]=1;
	if (s[i]!=s[j] or (j-i)%2) return dp[i][j]=0;
	if (j==i) return dp[i][j]=1;
	ll res=0;
	for (int k=i+2;k<=j;k+=2) if (s[k]==s[i]) {
		res+=solve(i+1,k-1)*solve(k,j)%MOD;
		res%=MOD;	
	}
	return dp[i][j]=res;	
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>s;
	cout<<solve(0,(int)s.size()-1)<<endl;
	
	return 0;
}
