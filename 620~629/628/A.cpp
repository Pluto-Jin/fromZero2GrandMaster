#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
//#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int x; cin>>x;
		if (x%2==0) cout<<x/2<<' '<<x/2<<endl;
		else {
			x--;
			int a=1;
			while (x%2) {
				a*=2;
				x/=2;
			}
			cout<<a<<' '<<x/a<<endl;
		}	
	}
}

