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
#define clr(ds) memset(ds, 0, sizeof(ds))
#define sort(ds) sort(all(ds))
#define reverse(ds) reverse(all(ds))
#define tsum(ds) (accumulate(all(ds), 0ll))
#define ctx(ds, x) (count(all(ds), (x)))
#define sz(ds) ((ll)(ds).size())
#define minv(ds) (*min_element(all(ds)))
#define maxv(ds) (*max_element(all(ds)))
#define minIdx(ds) (min_element(all(ds)) - (ds).begin())
#define maxIdx(ds) (max_element(all(ds)) - (ds).begin())
#define bs(ds, x) (binary_search(all(ds), x))
#define lob(ds, x) (lower_bound(all(ds), (x)) - (ds).begin())
#define upb(ds, x) (upper_bound(all(ds), (x)) - (ds).begin())
#define ceil(num, div) ((num % div != 0) ? ((num / div) + 1) : (num / div))
const ll INF = 4e18;                    
const ld EPS = 1e-9;                    
const ld PI = 3.1415926535897932384626; 
ll min(ll a,ll b) { if (a<b) return a; return b; }
ll max(ll a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll mod_pow(ll a,ll b, ll m) {ll res=1;while(b>0){if(b&1){res=(res*a)%m;}a=(a*a)%m;b=b>>1;}return res;}
ll mod_neg(ll a,ll b){ll ans=((a%b)+b)%b;return ans;}
ll modinv(ll b, ll m){return mod_pow(b,m-2,m);}
string to_upper(string a){ for(int i=0;i<(int)a.size();++i)if(a[i]>='a' && a[i]<='z')a[i]-='a'-'A';return a;}
string to_lower(string a){ for(int i=0;i<(int)a.size();++i)if(a[i]>='A' && a[i]<='Z')a[i]+='a'-'A';return a;}

// Trie ------------------------------------------------------------------------------------------------------
class Trie{
public:
    class node
    {
        public:
        bool endd;
        node* next[26];
        node()
        {
            endd=0;
            for(ll i=0;i<26;i++)
            {
                next[i]=NULL;
            }
        }
    };
    node* trie;
    Trie()
    {
        trie=new node();
    }

    void insertt(string s)
    {
        ll i=0;
        node* temp=trie;
        while(i<s.size())
        {
            if(temp->next[s[i]-'a']==NULL)temp->next[s[i]-'a']=new node();
            temp=temp->next[s[i]-'a'];
            i++;
        }
        temp->endd=1;
    }

    bool searchh(string s)
    {
        ll i=0;
        node* temp=trie;
        while(i<s.size() && temp!=NULL)
        {
            temp=temp->next[s[i]-'a'];
            i++;
        }
        return temp != NULL && temp->endd;
    }

};

// DSU -----------------------------------------------------------------------------------------------

class dsu
{
public:
    vll parent;
    vll sz;
    int k;

    dsu(int n)
    {
        k=n;
        parent=vll(n,0);
        sz=vll(n,1);
        for(int i=0;i<k;i++)parent[i]=i;
    }

    int find_set(int x)
    {
        if(x==parent[x])return x;
        return parent[x]=find_set(parent[x]);
    }

    void union_set(int a,int b)
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b)return;
        if(sz[a]>sz[b])
        {
            parent[b]=a;
            sz[a]=sz[a]+sz[b];
        }
        else
        {
            parent[a]=b;
            sz[b]=sz[b]+sz[a];
        }
    }
};

// Sieve ----------------------------------------------------------------------------------------

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

// Segment Tree ----------------------------------------------------------------------------------------

void build(int node,int i,int j,vector<ll>&a,vector<ll>&tree)
{
    if(i==j)
    {
        tree[node]=a[i];
        return;
    }
    ll mid=(i+j)/2;
    build(2*node+2,mid+1,j,a,tree);
    build(2*node+1,i,mid,a,tree);
    tree[node]=max(tree[2*node+2],tree[2*node+1]);
}

ll query(int node,int i,int j,vector<ll>&tree,int l,int r)
{
    if(i>r || j<l)return INT_MIN;
    if(l<=i && j<=r)return tree[node];
    ll mid=(i+j)/2;
    return max(query(2*node+1,i,mid,tree,l,r),query(2*node+2,mid+1,j,tree,l,r));
}

void update(int node,int i,int j,vector<ll>&a,vector<ll>&tree,int in,ll val)
{
    if(i==j)
    {
        a[i]=val;
        tree[node]=val;
        return;
    }

    ll mid=(i+j)/2;
    if(in<=mid)update(2*node+1,i,mid,a,tree,in,val);
    else update(2*node+2,mid+1,j,a,tree,in,val);
    tree[node]=max(tree[2*node+1],tree[2*node+2]);
}

// Binary Lifiting ---------------------------------------------------------------------------------------
void binary_lifting(ll in,ll par,ll l,vll&depth,vvl&dp,vvl&adj)
{
    depth[in]=l;
    dp[in][0]=par;
    for(int i=1;i<21;i++)if(dp[in][i-1]!=-1)dp[in][i]=dp[dp[in][i-1]][i-1];
    for(auto x:adj[in])if(x!=par)binary_lifting(x,in,l+1,depth,dp,adj);
}

ll lca(ll a,ll b,vll&depth,vvl&dp)
{
    if(depth[a]>depth[b])swap(a,b);
    ll diff=depth[b]-depth[a];
    for(int i=20;i>=0;i--)if(diff & (1<<i))b=dp[b][i];
    if(a==b)return a;
    for(int i=20;i>=0;i--){
        if(dp[a][i]!=dp[b][i]){
            a=dp[a][i];
            b=dp[b][i];
        }
    }
    return dp[a][0];
}

//Interactive problem ------------------------------------------------------------------------------------

ll ask(int i,int j)
{
    cout<<"? "<<i<<" "<<j<<endl;
    cout.flush();
    ll res;cin>>res;
    return res;
}

//------------------------------------------------------------------------------------------------

void solve()
{
    ll a,b,c,d;cin>>a>>b>>c>>d;
    if(c>=a)
    {
        if(d>=b)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
}


// Main  -----------------------------------------------------------------------------------------

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
