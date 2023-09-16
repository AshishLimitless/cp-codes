#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")  

#include <bits/stdc++.h>
using namespace std;  

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long
#define pb push_back
#define F first
#define S second
#define I insert
#define ull unsigned long long
typedef long double lld;
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define mem(x,v) memset(x,v,sizeof(x))
#define inp(v,n) loo(i,n){cin>>v[i];}


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";cerr<<"\n";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";cerr<<"\n";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";cerr<<"\n";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";cerr<<"\n";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {cerr<<"{"<<i.F<<" "<<i.S<<"} ";} cerr << "]";cerr<<"\n";}


#define vll vector<ll>
#define vdd vector<double>
#define vss vector<string>
#define vpl vector<pair<ll,ll>>
#define vcl vector<char>
#define vvl vector<vector<ll>>
#define vvc vector<vector<char>>
#define ppi pair<ll,ll>
#define maxe(v) *max_element((v).begin(),(v).end());
#define mine(v) *min_element((v).begin(),(v).end());
#define loo(i,n) for(long long i=0;i<n;i++)  
#define sor(v) sort(v.begin(),v.end());
#define pyes cout<<"YES"<<endl;
#define pno cout<<"NO"<<endl;
#define ayes cout<<"Yes"<<endl;
#define ano cout<<"No"<<endl;
#define mll map<ll,ll>
#define mcl map<char,ll>
#define mod 1000000007
#define ft front()
#define bk back()
#define pf push_front
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define lb lower_bound
#define ub upper_bound
#define each(a,x) for(auto a:x)  
#define nl cout<<"\n";
#define pri(xx) cout<<xx<<endl;
#define sll set<ll>
#define sch set<char>
#define rt return
#define pq priority_queue
#define pql priority_queue<ll>
#define INF 1e9
#define manh(a,b,c,d) abs(a-c)+abs(b-d)
#define euc(a,b,c,d) sqrt((a-c)*(a-c)+(b-d)*(b-d))
#define foo(i,a,b) for(ll i=a;i<b;i++)
#define pril(i,a,b,v) foo(i,a,b){cout<<v[i]<<" ";}
#define pqc priority_queue<char>
#define to_upper(s)  transform(s.begin(), s.end(), s.begin(), ::toupper);
#define lowercase(s)  transform(s.begin(), s.end(), s.begin(), ::tolower);



/*  //SNIPPET LIST 
  // 1)segtree  
   -(used to build a segment tree and to solve range based queries and point update)
   2)freqidblocks
   -(in a vector we can find number of increasing and decreasing subsegment)
   3)UNIV -(gives unique vector no duplicates)
   4)levaltraversalTree
   5)bpow
   6)sttoi
   7)commonsubstring2chr
   8)factorstore-(stores all the factors of a num)
   9)issubstring
   10)perfectSqorNot
   11)seivestore
   12)precompfac -(factorial)
   13)range overlap 
   14)countfreqcontinuos  -(ex--> v=(1,1,1,2) return vpl={{1,3},{2,1}})
   15)getMaxContifreq -(same as above but gives maximum of all same number)
   16)DSU*snipp ------->(Contains all functions of dsu like unite, find par) (***imp***)
   (ex---> v=(1,1,2,1,1,1) return freq freq[1]=3 & freq[2]=1 and all other 0)
   */



// JAI SRI KRISHNA!! JAI SRI KRISHNA!! //

vector<pair<ll,ll>>seg;
void build(ll ind,ll low,ll high,vll &v){
  seg.resize(4*v.size()+1);
  if(low==high){
    seg[ind]={v[low],1};
    rt;
  }
  ll mid=(low+high)/2;
  build(2*ind+1,low,mid,v);
  build(2*ind+2,mid+1,high,v);
  if(seg[2*ind+1].F<seg[2* ind+2].F){
    seg[ind].F=seg[2*ind+1].F;
    seg[ind].S=seg[2*ind+1].S;
  }
  else if(seg[2*ind+1].F>seg[2* ind+2].F){
    seg[ind].F=seg[2*ind+2].F;
    seg[ind].S=seg[2*ind+2].S;
  }
  else{
    seg[ind].F=seg[2*ind+1].F;
    seg[ind].S=seg[2*ind+1].S+seg[2*ind+2].S;
  }
}
void Pupdate(ll ind,ll low,ll high,ll x,ll val,vll &v){
  if(low==high){
    seg[ind].F=val;
    v[x]=val;
    return;
  }
  ll mid=(low+high)/2;
  if(x<=mid) Pupdate(2*ind+1,low,mid,x,val,v);
  else Pupdate(2*ind+2,mid+1,high,x,val,v);
  if(seg[2*ind+1].F<seg[2* ind+2].F){
    seg[ind].F=seg[2*ind+1].F;
    seg[ind].S=seg[2*ind+1].S;
  }
  else if(seg[2*ind+1].F>seg[2* ind+2].F){
    seg[ind].F=seg[2*ind+2].F;
    seg[ind].S=seg[2*ind+2].S;
  }
  else{
    seg[ind].F=seg[2*ind+1].F;
    seg[ind].S=seg[2*ind+1].S+seg[2*ind+2].S;
  }

}
pair<ll,ll> query(ll ind,ll low,ll high,ll l,ll r,vll &v){
  if(r<low || l>high) return {mod,mod};
  if(l<=low && high<=r ){
    debug(seg[ind])
    return seg[ind];
  }
  ll mid=(low+high)/2;
  pair<ll,ll> left=query(2*ind+1,low,mid,l,r,v);
  pair<ll,ll> right=query(2*ind+2,mid+1,high,l,r,v);
  if(left.F<right.F){
    return left;
  }
  else return right;

}

void madara(){
  ll n;
  cin>>n;
  vll v(n);
  inp(v,n)
  build(0,0,n-1,v);
  debug(seg)
  ll q;
  cin>>q;
  loo(i,q){
    ll t;
    cin>>t;
    if(t==1){
      ll l,r;
      cin>>l>>r;
      l--;
      r--;
      pair<ll,ll> ans=query(0,0,n-1,l,r,v);
      cout<<ans.F<<" "<<ans.S<<endl;
    }
    else{
      ll x,val;
      cin>>x>>val;
      x--;
      Pupdate(0,0,n-1,x,val,v);
    }
  }

  
  

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  freopen("Error.txt", "w", stderr);
#endif 
  ll ashish;
  cin>>ashish;
  while(ashish--){
      madara();
  }
  return 0;

}











