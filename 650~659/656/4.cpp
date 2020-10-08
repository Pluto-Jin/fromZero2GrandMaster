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

const int N=131073;
int n,cnt[26][N];
string s;

int solve(int x,int p1) {
	int p2=n/(1<<x)+p1,len=p2-p1,ed=p2+len-1; 
	if (!len) return s[p1-1]-'a'!=x-1;
	return min(solve(x+1,p1)+len-cnt[x-1][ed]+cnt[x-1][p2-1],solve(x+1,p2)+len-cnt[x-1][p2-1]+cnt[x-1][p1-1]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>s;
		for(int i=1;i<=n;i++) {
			for (int j=0;j<26;j++) cnt[j][i]=cnt[j][i-1];
			cnt[s[i-1]-'a'][i]++;
		}
		cout<<solve(1,1)<<endl;
		for (int i=1;i<=n;i++) for (int j=0;j<26;j++) cnt[j][i]=0;
	}
}

