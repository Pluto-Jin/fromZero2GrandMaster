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

bitset<7> s0(0b1110111),s1(0b0010010),s2(0b1011101),s3(0b1011011),s4(0b0111010),s5(0b1101011),s6(0b1101111),s7(0b1010010),s8(0b1111111),s9(0b1111011);
bitset<7> seg[10]={s0,s1,s2,s3,s4,s5,s6,s7,s8,s9};
string dp[2][2001];
vector<string> ar;
int n,k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>k;
	ar.resize(n);
	for (int i=0;i<n;i++) {
		string tmp; cin>>tmp;
		ar[n-i-1]=tmp;
	}
	for (int t=0;t<n;t++) {
		string tmp=ar[t];
		bitset<7> s(tmp);
		for (int i=9;i>=0;i--) {
			if ((s|seg[i])!=seg[i]) continue;
			int stk=(s^seg[i]).count();
			if (t==0 and stk<=k and dp[0][stk].size()==0) dp[0][stk]+=char('0'+i);
			else {
				for (int j=k;j>=stk;j--)
					if (dp[!(t%2)][j-stk].size()==t and dp[t%2][j].size()<t+1)
						dp[t%2][j]=char('0'+i)+dp[!(t%2)][j-stk];
			}
		}
	}
	cout<<(dp[(n-1)%2][k].size()==n?dp[(n-1)%2][k]:"-1")<<endl;

}


