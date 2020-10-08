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

const int N=1e6+1;
vector<vector<bool>> ar,br;
int d[N][3],dp[N][2][2][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	int tmp=min(n,m);
	ar.resize(n);
	br.resize(m);
	for (int i=0;i<m;i++) br[i].resize(n);
	for (int i=0;i<n;i++) {
		ar[i].resize(m);
		string s; cin>>s;
		for (int j=0;j<m;j++) ar[i][j]=br[j][i]=s[j]=='1';	
	}
	if (n>m) swap(ar,br),swap(n,m);
	if (tmp==1) cout<<0<<endl;
	else if (tmp==2) {
		int cnt=ar[0][0]+ar[1][0];
		for (int k=0;k<3;k++) d[0][k]=abs(cnt-k);
		for (int cnt,i=1;i<m;i++) {
			cnt=ar[0][i]+ar[1][i];
			d[i][0]=cnt+d[i-1][1];
			d[i][1]=abs(cnt-1)+min(d[i-1][0],d[i-1][2]);
			d[i][2]=abs(cnt-2)+d[i-1][1];
		}		
		cout<<min(min(d[m-1][0],d[m-1][1]),d[m-1][2])<<endl;
	} else if (tmp==3) {
		int a=ar[0][0],b=ar[1][0],c=ar[2][0];
		dp[0][0][0][0]=a+b+c;
		dp[0][0][0][1]=a+b+1-c;
		dp[0][0][1][0]=a+1-b+c;
		dp[0][0][1][1]=a+2-b-c;
		dp[0][1][0][0]=1-a+b+c;
		dp[0][1][0][1]=2-a-c+b;
		dp[0][1][1][0]=2-a-b+c;
		dp[0][1][1][1]=3-a-b-c;
		for (int a,b,c,i=1;i<m;i++) {
			a=ar[0][i],b=ar[1][i],c=ar[2][i];
			dp[i][0][0][0]=a+b+c+min(dp[i-1][1][0][1],dp[i-1][0][1][0]);
			dp[i][0][0][1]=a+b+1-c+min(dp[i-1][1][0][0],dp[i-1][0][1][1]);
			dp[i][0][1][0]=a+1-b+c+min(dp[i-1][1][1][1],dp[i-1][0][0][0]);
			dp[i][0][1][1]=a+2-b-c+min(dp[i-1][1][1][0],dp[i-1][0][0][1]);
			dp[i][1][0][0]=1-a+b+c+min(dp[i-1][1][1][0],dp[i-1][0][0][1]);
			dp[i][1][0][1]=2-a-c+b+min(dp[i-1][1][1][1],dp[i-1][0][0][0]);
			dp[i][1][1][0]=2-a-b+c+min(dp[i-1][1][0][0],dp[i-1][0][1][1]);
			dp[i][1][1][1]=3-a-b-c+min(dp[i-1][1][0][1],dp[i-1][0][1][0]);
		}
		int ans=1e9;
		for (int i=0;i<2;i++) for (int j=0;j<2;j++) for (int k=0;k<2;k++) ans=min(ans,dp[m-1][i][j][k]);
		cout<<ans<<endl;

	} else cout<<-1<<endl;	
}

