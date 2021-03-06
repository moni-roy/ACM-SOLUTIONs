#include <bits/stdc++.h>
using namespace std;

typedef long long          	ll;
typedef long long unsigned 	llu;
typedef double             	dl;
typedef pair<int,int>      	pii;
typedef pair<ll,ll>     	pll;
typedef vector<int>        	vi;
typedef map<int,int> 		mii;
typedef map<ll,ll>         	mll;
typedef map<string,int>    	msi;
typedef map<char,int>      	mci;

#define PI  		acos(-1.0)
#define S	    	second
#define F 	    	first
#define PB	    	push_back
#define MP	    	make_pair
#define zero(a) 	memset(a,0,sizeof a)
#define minus(a) 	memset(a,-1,sizeof a)
#define setinf(a) 	memset(a,126,sizeof a)
#define FR(i,x,y) 	for(int i=x;i<=y;i++)
#define FRV(i,x,y) 	for(int i=x;i>=y;i--)
#define all(v)		(v.begin(),v.end())
#define vsort(v)	sort(v.begin(),v.end())
#define nl  		puts("")
#define tcase(cs) 	printf("Case %d:",++cs)
#define endl		'\n'
#define I_O	    	ios_base::sync_with_stdio(0); cin.tie(0);

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}

int sv[10010][101];
int n,k,ts,as,a[10010];

int fun(int sm,int ps){
	sm=(sm%k+k)%k;
	if(ps>n-1){
		if(sm%k==0) return 1;
		return 0;
	}
	int &ret=sv[sm][ps];
	if(ret!=-1) return ret;
	int rt=0;
	rt=rt|fun(sm+a[ps],ps+1);
	rt=rt|fun(sm-a[ps],ps+1);
	return ret=rt;
}
int main()
{
	cin>>ts;
	while(ts--){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		minus(sv);
		as=fun(0,0);
		if(as==1) cout<<"Divisible"<<endl;
		else cout<<"Not divisible"<<endl;
	}
	return 0;
}
