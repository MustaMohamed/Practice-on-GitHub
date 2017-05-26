#include <bits/stdc++.h>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define all(x) x.begin(),x.end()
#define sorta(x) sort(all(x))
#define sortr(x) sort(x.rbegin(),x.rend())
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forn1(i,n) for (int i = 1; i <= int(n); i++)
#define dwn(i,n) for(int i=(n); --i>=0; )
#define fora(i,a,b) for (int i=a;i<b;i++)
#define forit(v, c) for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define min(a, b) (((a)<(b))?(a):(b))
#define max(a, b) (((a)>(b))?(a):(b))
#define remax(a,b) (a)=max((a),(b))
#define remin(a,b) (a)=min((a),(b))
#define digits(i) (int)((log(i)/log(10))+1)
#define powof2(n) (!(n & (n-1)))
#define setbit(n,x) (n |= (1<<x))
#define test int t;cin>>t;while(t--)
#define input(a,n) for(int i=0;i<n;i++)cin>>a[i];
//#define valid(i,j,n,m) (bool)valid(int i,int j,int n,int m){ return (i>=0&&i<n&&j>=0&&j<m);}
#define valid1(i,j,n,m) (bool)valid(int i,int j,int n,int m){return (i>0&&i<=n&&j>0&&j<=m);}

#define sf(n) scanf("%d",&n)
#define sf2(n,m) scanf("%d %d",&n,&m)
#define sf3(n,m,s) scanf("%d %d %d",&n,&m,&s)
#define sfch(n) scanf("%c",&n)
#define sfl(n) scanf("%I64d",&n)
#define sfl2(n,m) scanf("%I64d %I64d",&n,&m)
#define sff(n) scanf("%lf",&n)
#define sfs(n) scanf("%s",n)
#define line(n) getline(cin,n)

#define INF (int)1e9
#define bitcount __builtin_popcount
#define gcd __gcd
#define fll(a,v) memset(a, v, sizeof a)
#define sz(a) ((int)(a.size()))
#define checkbit(n,b) ( (n >> b) & 1)

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector< vector<int> > adjl;
struct edge {
    ll from,to,w;
    edge (int from,int to,ll w):from(from),to(to),w(w) {}
    bool operator < (const edge & e) const {
        return ((w > e.w));
    }
};
typedef vector<vector<edge> > adjlw;


void O_o()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
}

bool valid(ll i,ll j,ll n,ll m)
{ return (i>=0&&i<n&&j>=0&&j<m);}

bool vis[100500]={0};
vector<vpll> adj;

ll prim()
{
    ll cost=0;
    priority_queue<pll>pq;
    pq.push({-0,-1});
    while(!pq.empty())
    {
        int x=pq.top().s,c=pq.top().f;
        pq.pop();
        if(vis[-x]) continue;
        vis[-x]=1;
        cost+=-c;
        for(auto i: adj[-x])
            pq.push({-i.f,-i.s});
    }
    return cost;
}

int main()
{
	O_o();
  fll(vis,0);
  ll x,y;
  cin>>x>>y;
  adj.clear();
  adj.resize(x+5);
  //ll sum=0;
  while(y--)
  {
   	ll a,b,c;
   	cin>>a>>b>>c;
   	adj[a].pb({c,b});
   	adj[b].pb({c,a});
  }
  cout<<prim()<<endl;
	return 0;
}
