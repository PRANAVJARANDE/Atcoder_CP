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
#define MOD (int)(998244353)
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


//{cnt,sum}

pair<ll,ll> helper(ll in,ll k,ll lim,vector<vector<pair<ll,ll>>>&dp)
{
    if(k<0)return {0,0};
    if(in>=lim)
    {
        if(k==0)return {1,0};
        return {0,0};
    }
    if(dp[in][k].first!=-1)return dp[in][k];

    auto op1=helper(in+1,k-1,lim,dp);
    auto op2=helper(in+1,k,lim,dp);
    ll res=((op1.first%MOD)*(mod_pow(2,in,MOD)%MOD))%MOD;
    res=((res%MOD) + (op1.second%MOD))%MOD;
    res=((res%MOD) + (op2.second%MOD))%MOD;
    return dp[in][k]={((op1.first%MOD) + (op2.first%MOD))%MOD,res};
}

ll cntbits(ll n)
{
    ll ans=0;
    while(n)
    {
        if(n%2)ans++;
        n/=2;
    }
    return ans;
}



void solve()
{
    ll n,k;cin>>n>>k;
    ll tot=cntbits(n);
    ll ans=0;
    if(tot==k)ans+=n;

    ll pr=0,in=0,rs=n;
    while(n)
    {
        if(n%2)
        {
            pr++;
            rs-=(1ll<<in);
            ll diff=k-(tot-pr);
            vector<vector<pair<ll,ll>>>dp(61,vector<pair<ll,ll>>(61,{-1,-1}));
            auto res=helper(0,diff,in,dp);
            ans=((ans%MOD)+ ((rs%MOD) * (res.first%MOD))%MOD + (res.second%MOD))%MOD;
            // cout<<in<<" "<<rs<<" "<<diff<<endl;
            // cout<<res.first<<" "<<res.second<<endl;
            // cout<<ans<<endl;
        }
        in++;
        n/=2;
    }
    cout<<ans<<endl;







    // auto ans=helper(0,2,4,dp);
    // cout<<ans.first<<" "<<ans.second<<endl;

    // ll temp=n;
    // ll ans=0;
    // ll in=0;
    
    // while(temp)
    // {
    //     ll rem=temp%2;
    //     if(rem==1)
    //     {
    //         ans=((ans%MOD)+(helper(0,k,in+1,dp)%MOD))%MOD;
    //     }   
    //     in++;
    //     temp/=2;
    // }
    // cout<<ans<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int t;cin >> t;
    while (t--) 
    {
        solve();
    }
    return 0;
}
