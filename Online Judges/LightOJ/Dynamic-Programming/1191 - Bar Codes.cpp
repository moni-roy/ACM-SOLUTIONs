//1191 - Bar Codes
#include <bits/stdc++.h>

using namespace std;

typedef long long          	ll;
typedef long long unsigned  llu;
typedef double             	dl;
typedef pair<int,int>      	pii;
typedef pair<ll,ll>     	pll;
typedef vector<int>        	vi;
typedef vector<ll>        	vl;
typedef map<int,int> 		mii;
typedef map<ll,ll>         	mll;
typedef map<string,int>    	msi;
typedef map<char,int>      	mci;
typedef pair<int ,pii>      piii;
typedef vector<pii>         vpii;
typedef vector<piii>        vpiii;

#define pi                  acos(-1.0)
#define S                   second
#define F                   first
#define pb                  push_back
#define MP                  make_pair
#define mem(a,b)            memset(a,b,sizeof a)
#define all(v)              v.begin(),v.end()
#define vsort(v)            sort(v.begin(),v.end())
#define IO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define gcd(a,b)            __gcd(a,b)

#define I(a)                scanf("%d",&a)
#define I2(a,b)             scanf("%d%d",&a,&b)
#define L(a)                scanf("%lld",&a)
#define L2(a,b)             scanf("%lld%lld",&a,&b)
#define D(a)                scanf("%lf",&a)

#define SP                  cout<<" ";
#define PI(a)               printf("%d",a)
#define PL(a)               printf("%lld",a)
#define PD(a)               printf("%lf",a)
#define CHK                 cout<<"MK"<<endl

template <class T> inline T BMOD(T p,T e,T m){T ret=1;while(e){if(e&1) ret=(ret*p)%m;p=(p*p)%m;e>>=1;}return (T)ret;}
template <class T> inline T MODINV(T a,T m){return BMOD(a,m-2,m);}
template <class T> inline T isPrime(T a){for(T i=2;i<=sqrt(double(a));i++){if(a%i==0){return 0;}}return 1;}
template <class T> inline T lcm(T a, T b){return (a/gcd(a,b))*b;}
template <class T> inline T power(T a, T b){return (b==0)?1:a*power(a,b-1);}
template <class T> inline string toStr(T t) { stringstream ss; ss<<t; return ss.str();}
template <class T> inline long long toLong(T t) {stringstream ss;ss<<t;long long ret;ss>>ret;return ret;}
template <class T> inline int toInt(T t) {stringstream ss;ss<<t;int ret;ss>>ret;return ret;}

//~ cout << fixed << setprecision(20) << Ans << endl;
//~ priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra
/*                 _                      */
/*____________|\/||_||\||_________________*/

string buffer;
int INT(){
	getline(cin,buffer);
	return toInt(buffer);
}
int LONG(){
	getline(cin,buffer);
	return toLong(buffer);
}

#define MX 11
#define MD 1e9+7
const int SIZE = 15;
ll sv[51][51][51],n,m;
ll go(int p,int k,int r){
	if(p==0){
		if(k==0) return 1;
		return 0;
	}
	if(k<0) return 0;
	ll &ret = sv[p][k][r];
	if(ret!=-1) return ret;
	ret = 0;
	for(int i=1;i<=r;i++){
		if(p-i>=0) ret += go(p-i,k-1,r);
	}
	return ret;
}
void fun(){
	for(int i=0;i<51;i++){
		sv[0][0][i]=1;
		sv[1][1][i]=1;
	}
	for(int k=1;k<51;k++){
		for(int i =2;i<51;i++){
			for(int j=1;j<=i;j++){
				for(int a =1;a<=min(k,i);a++){
					sv[i][j][k]+= sv[i-a][j-1][k];
				}
			}
		}
	}
}
int main()
{
	//~ IO;
	//~ freopen("/home/krishna/PRG/practice/input.in","r",stdin);
	int ts,cs=0;
	ll k;
	I(ts);
	//~ mem(sv,-1);
	fun();
	while(ts--){
		L2(n,k);L(m);
		
		ll Ans = sv[n][k][m];
		printf("Case %d: %lld\n",++cs,Ans);
	}
	return 0;
}
