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
#include<numeric>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ppf pop_front
#define ppb pop_back
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	int a[101][2]={0};
	for (int len,i=0;i<2;i++) {
		len=i?m:n;
		if (len==1) a[1][i]=1;
		else if (len==2) a[1][i]=3,a[2][i]=4;
		else if (len==3) a[1][i]=1,a[2][i]=a[3][i]=2;
		else {
			for (int j=1;j<=len-1;j++) a[j][i]=1;
			if (len-1&1) a[len][i]=len-2>>1;
			else a[len-1][i]=2,a[len][i]=len+1>>1;
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) cout<<a[i][0]*a[j][1]<<' '; 
		cout<<endl;
	}
	
	return 0;
}
