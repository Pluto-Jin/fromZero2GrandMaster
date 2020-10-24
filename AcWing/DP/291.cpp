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
#include<iomanip>

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

ll dp[12][1<<11];
bool hao[1<<11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	while (1) {
		int n,m; cin>>n>>m;
		if (!n and !m) break;
		memset(dp,0,sizeof dp);
		memset(hao,1,sizeof hao);
		for (int i=0;i<1<<m;i++) {
			bitset<12> tmp(i);
			for (int j=0,cur=0;j<m;j++) {
				if (!tmp[j]) cur++;
				if (tmp[j] or j==m-1) {
					if (cur%2) hao[i]=0;
					cur=0;	
				}
			}
		}
		dp[0][0]=1;
		for (int i=1;i<=n;i++) {
			for (int j=0;j<1<<m;j++) if (dp[i-1][j]) {
				for (int k=0;k<1<<m;k++) 
					if ((k&j)==0 and hao[k|j]) dp[i][k]+=dp[i-1][j];
			}
		}
		cout<<dp[n][0]<<endl;
	}
	
	return 0;
}
