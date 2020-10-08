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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,k,ar[300][300]={0}; cin>>n>>k;
		if (k) {
			int tmp=k/n,rem=k%n;
			for (int i=0;i<n;i++) {
				for (int j=i;j<i+tmp+(i<rem?1:0);j++) {
					ar[i][j%n]=1;
				}	
			}
			cout<<(rem?2:0)<<endl;
		} 
		else cout<<0<<endl;
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) cout<<ar[i][j];
			cout<<endl;
		}
	}
}

