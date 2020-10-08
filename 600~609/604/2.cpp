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

	int a,b,c,d; cin>>a>>b>>c>>d;
	if (!a and !b) {
		if (abs(c-d)>1) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			if (d-c==1) cout<<3<<' ';
			for (int i=0;i<min(c,d);i++) cout<<2<<' '<<3<<' ';
			if (c-d==1) cout<<2<<' ';
			cout<<endl;
		}
	} else if (!c and !d) {
		if (abs(a-b)>1) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			if (b-a==1) cout<<1<<' ';
			for (int i=0;i<min(a,b);i++) cout<<0<<' '<<1<<' ';
			if (a-b==1) cout<<0<<' '; 
			cout<<endl;
		}

	} else {
		int x01=a,x23=d,x21=min(b-a,c-d),x1=b-x01-x21,x2=c-x23-x21;
		if (x21<0 or x1>1 or x2>1) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			if (x1) cout<<1<<' ';
			for (int i=0;i<x01;i++) cout<<"0 1 ";
			for (int i=0;i<x21;i++) cout<<"2 1 ";
			for (int i=0;i<x23;i++) cout<<"2 3 ";
			if (x2) cout<<2<<' ';
			cout<<endl;
		}
	}
}

