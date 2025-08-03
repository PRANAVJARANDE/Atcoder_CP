#include <bits/stdc++.h>
using namespace std;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<ll, ll> pl; 
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long>> vllp;
typedef vector<pl> vpl;
typedef vector<vector<ll>> vvl;
#define MOD (int)(1e9 + 7)
#define endl "\n"
#define sqrt sqrtl
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define emb emplace_back 
#define mp make_pair
#define mll map<ll, ll>
#define sl set<ll>
#define sc set<char>


#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define ff first
#define ss second


#define all(ds) (ds).begin(), (ds).end()
// Clear Memory
#define clr(ds) memset(ds, 0, sizeof(ds))
// Ascending Vector
#define sort(ds) sort(all(ds))
// Descending Vector
#define rev(ds) reverse(all(ds))
// Total Sum
#define tsum(ds) (accumulate(all(ds), 0ll))
// Count frequency of x
#define ctx(ds, x) (count(all(ds), (x)))
// Size
#define sz(ds) ((ll)(ds).size())
// Min Value
#define minv(ds) (*min_element(all(ds)))
// Max Value
#define maxv(ds) (*max_element(all(ds)))
// Min Value Index
#define minIdx(ds) (min_element(all(ds)) - (ds).begin())
// Max Value Index
#define maxIdx(ds) (max_element(all(ds)) - (ds).begin())
// Binary Search
#define bs(ds, x) (binary_search(all(ds), x))
// Lower Bound Index
#define lob(ds, x) (lower_bound(all(ds), (x)) - (ds).begin())
// Upper Bound Index
#define upb(ds, x) (upper_bound(all(ds), (x)) - (ds).begin())
// Ceil Function
#define ceil(num, div) ((num % div != 0) ? ((num / div) + 1) : (num / div))

const ll INF = 0x3f3f3f3f;              //inf
const ll neg_INF = 0xcfcfcfcf;          //-inf
const ld EPS = 1e-9;                    //epsilon
const ld PI = 3.1415926535897932384626; //pi

ll min(ll a,ll b) { if (a<b) return a; return b; }
ll max(ll a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll mod_pow(ll a,ll b, ll m) { 
    ll res=1;
    while(b>0){
        if(b&1){
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return res;
}
ll mod_neg(ll a,ll b)
{
    ll ans=((a%b)+b)%b;
    return ans;
}
ll modinv(ll b, ll m){ return mod_pow(b,m-2,m); }
string to_upper(string a){ for(int i=0;i<(int)a.size();++i)if(a[i]>='a' && a[i]<='z')a[i]-='a'-'A';return a;}
string to_lower(string a){ for(int i=0;i<(int)a.size();++i)if(a[i]>='A' && a[i]<='Z')a[i]+='a'-'A';return a;}

//Interactive problem
ll ask(int i,int j)
{
    cout<<"? "<<i<<" "<<j<<endl;
    cout.flush();
    ll res;cin>>res;
    return res;
}

ll n;
ll helper(ll in,ll x,vvl&a,vvl&dp)
{
    if(in>=n)return x;
    if(dp[in][x]!=-1)return dp[in][x];
    ll p=a[in][0];
    ll inc=a[in][1];
    ll dec=a[in][2];
    if(p>=x)return dp[in][x]=helper(in+1,x+inc,a,dp);
    else return dp[in][x]=helper(in+1,max(0,x-dec),a,dp);
}

void solve()
{
    cin>>n;
    vvl a(n,vll(3,0));
    for(int i=0;i<n;i++)for(int j=0;j<3;j++)cin>>a[i][j];

    vll ps(n,0);
    for(int i=0;i<n;i++)
    {
        ps[i]=a[i][2];
        if(i-1>=0)ps[i]+=ps[i-1];
    }

    ll sz=1001;
    vvl dp(n+1,vll(sz,-1));

    
    ll q;cin>>q;
    while(q--)
    {
        ll x;cin>>x;
        ll diff=x-600;
        ll st=0;
        if(diff>0)
        {
            ll in=lob(ps,diff);
            if(in==n)
            {
                cout<<x-ps[n-1]<<endl;
                continue;
            }
            st=lob(ps,diff)+1;
            x-=ps[in];
            st=in+1;
        }   
        ll res=helper(st,x,a,dp);
        cout<<res<<endl;
    }    
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
