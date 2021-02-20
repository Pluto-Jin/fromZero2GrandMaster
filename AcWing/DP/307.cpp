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

vi operator+(const vi &x,const vi &y) {
	vi c;
	for (int i=0;i<min(x.size(),y.size());i++) c.pb(x[i]+y[i]);
	if (x.size()<y.size()) for (int i=x.size();i<y.size();i++) c.pb(y[i]);
	else for (int i=y.size();i<x.size();i++) c.pb(x[i]);
	for (int i=0;i<(int)c.size()-1;i++) c[i+1]+=c[i]/10,c[i]%=10; 
	while (c.back()>9) c.pb(c.back()/10),c[(int)c.size()-2]%=10;
	return c;
} 

vi operator-(const vi &x, const vi &y) {
	vi c;
	for (int i=0;i<y.size();i++) c.pb(x[i]-y[i]);
	for (int i=y.size();i<x.size();i++) c.pb(x[i]);
	for (int i=0;i<(int)c.size()-1;i++) if (c[i]<0) c[i]+=10,c[i+1]--;
	return c;
}

vi operator*(const vi &x, const int &y) {
	vi c;
	for (int i=0;i<x.size();i++) c.pb(x[i]*y);
	for (int i=0;i<(int)c.size()-1;i++) c[i+1]+=c[i]/10,c[i]%=10;
	while (c.back()>9) c.pb(c.back()/10),c[(int)c.size()-2]%=10;
	return c;
}

vi operator/(const vi &x, const int &y) {
	vi c;
	for (int i=(int)x.size()-1,tmp=0;~i;i--) {
		tmp=x[i]+tmp*10;
		if (tmp>=y) c.pb(tmp/y),tmp%=y;
		else if (c.size()) c.pb(0);
	}
	reverse(c.begin(),c.end());
	return c;
}

vi operator*(const vi &x,const vi &y) {
	vi c((int)x.size()+(int)y.size()-1);
	for (int i=0;i<x.size();i++) for (int j=0;j<y.size();j++) c[i+j]+=x[i]*y[j];
	for (int i=0;i<(int)c.size()-1;i++) c[i+1]+=c[i]/10,c[i]%=10;
	while (c.back()>9) c.pb(c.back()/10),c[(int)c.size()-2]%=10;
	return c;
}

void print(vi &x) {
	while (x.size() and !x.back()) x.ppb();
	if (!x.size()) cout<<0<<endl;
	for (int i=(int)x.size()-1;~i;i--) cout<<x[i];
	cout<<endl;
}

vi power[1300],dp[51],comb[51][51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	for (int i=1;i<51;i++) {
		comb[i][0].pb(1);
		for (int j=1;j<=i;j++) {
			if (j+j>i) comb[i][j]=comb[i][i-j];
			else comb[i][j]=comb[i][j-1]*(i-j+1)/j;
		}
	}
	power[0].pb(1);
	for (int i=1;i<1300;i++) power[i]=power[i-1]*2;
	for (int i=1;i<51;i++) {
		dp[i]=power[i*(i-1)/2];
		for (int j=1;j<i;j++) dp[i]=dp[i]-comb[i-1][j-1]*dp[j]*power[(i-j)*(i-j-1)/2];
	}

	while (1) {
		int n; cin>>n;
		if (!n) break;
		print(dp[n]);
	}
	
	return 0;
}
