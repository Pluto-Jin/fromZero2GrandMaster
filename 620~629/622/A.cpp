#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int a,b,c;
		cin>>a>>b>>c;
		int ans=0;
		if (a>0) {a--;ans++;}
		if (b>0) {b--;ans++;}
		if (c>0) {c--;ans++;}
		if (a>=2) {
			if (b>0) {a--;b--;ans++;}
			if (c>0) {a--;c--;ans++;}
			if (b>0 and c>0) {b--;c--;ans++;}
		}
		else if (b>=2) {
			if (a>0) {a--;b--;ans++;}
			if (c>0) {b--;c--;ans++;}
			if (a>0 and c>0) {a--;c--;ans++;}
		}
		else if (c>=2) {
			if (b>0) {c--;b--;ans++;}
			if (a>0) {a--;c--;ans++;}
			if (a>0 and b>0) {a--;b--;ans++;}
		}
		else 
		{
			if (a>0 and b>0) {a--;b--;ans++;}
			if (b>0 and c>0) {b--;c--;ans++;}
			if (a>0 and c>0) {a--;c--;ans++;}
		}
		if (a>0 and b>0 and c>0) {a--;b--;c--;ans++;}
		cout<<ans<<endl;


	}
}
