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

	int T; cin>>T;
	while (T--) {
		int h,c,t; cin>>h>>c>>t;
		double ave=1.0*(h+c)/2;
		if (t==h) cout<<1<<endl;
		else if (t<=ave) cout<<2<<endl;
		else {
			double tmp=(h-ave)/(t-ave);
			int a=floor(tmp),b=ceil(tmp);
			if (a==b and a%2==0) a=max(1,a-1),b=max(3,b+1);
			else if (a!=b) {
				if (b%2) a=max(1,a-1);
				else b=max(3,b+1);
			}
			double ea=abs((ave*(a-1)+h)/a-t),eb=abs((ave*(b-1)+h)/b-t);
			if (a==2) ea=ave;
			if (ea<=eb) cout<<a<<endl;
			else cout<<b<<endl;
		}	

	}
}

