#include<bits/stdc++.h>
#include<iostream>
#include<bitset>
#include<vector>
#include<map>
#include<string>
#include<cmath>
#include<algorithm>
#include<climits>
#define ll long long int
#define lld long long double
#define pb push_back
#define ff first
#define ss second
#define dbl double
#define vd vector<dbl>
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vll>
#define vvi vector<vi>
#define pll pair<ll,ll>
#define pi pair<int,int>
#define vpi vector<pi>
#define vpll vector<pll>
#define forn(n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
class DisjointSet {public: 	vector<ll> rank, parent, size; 	DisjointSet(ll n) {		rank.resize(n + 1, 0);		parent.resize(n + 1);		size.resize(n + 1, 1);		for(ll i = 1; i <= n; i++) parent[i] = i;	} 	void unionByRank(ll x, ll y) { 		ll par_x = findPar(x);		ll par_y = findPar(y); 		if(par_x == par_y) return; 		if(rank[par_x] < rank[par_y]) {			parent[par_x] = par_y;		} else if(rank[par_y] < rank[par_x]) {			parent[par_y] = par_x;		} else {			parent[par_x] = par_y;			rank[par_y]++;		}	} 	void unionBySize(ll x, ll y) { 		ll par_x = findPar(x);		ll par_y = findPar(y); 		if(par_x == par_y) return; 		if(size[par_x] < size[par_y]) {			parent[par_x] = par_y;			size[par_y] += size[par_x];		} else {			parent[par_y] = par_x;			size[par_x] += size[par_y];		}	} 	ll findPar(ll x) { 		if(parent[x] == x) return x; 		return parent[x] = findPar(parent[x]); 	} }; 
struct Node {     Node* links[26];     bool flag = false;     bool containsKey(char ch) {        return links[ch - 'a'] != NULL;    }     void put(char ch, Node* node) {        links[ch - 'a'] = node;    }     Node* get(char ch) {        return links[ch - 'a'];    }     void setEnd() {        flag = true;    }     bool isEnd() {        return flag;    }}; 
class Trie {private:    Node* root; public:     Trie() {        root = new Node();    }     void insert(string word) {        Node* node = root;        for (int i = 0; i < word.length(); i++) {            if (!node->containsKey(word[i])) {                 node->put(word[i], new Node());            }             node = node->get(word[i]);        }         node->setEnd();    }    bool search(string word) {        Node* node = root;        for (int i = 0; i < word.length(); i++) {            if (!node->containsKey(word[i])) {                 return false;            }             node = node->get(word[i]);        }         return node->isEnd();    }     bool startsWith(string prefix) {        Node* node = root;        for (int i = 0; i < prefix.length(); i++) {            if (!node->containsKey(prefix[i])) {                 return false;            }             node = node->get(prefix[i]);        }         return true;    }};  
class SGTree{public:     vector<int> seg;    SGTree(int n){        seg.resize(4*n+1);    }    void build(int ind,int low,int high,int arr[]){        if(low == high){            seg[ind]=arr[low];            return;        }        int mid = (low+high)/2;        build(2*ind+1,low,mid,arr);        build(2*ind+2,mid+1,high,arr);        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);    }    int query(int ind,int low,int high,int l,int r){         if(r<low || high<l)return INT_MAX;         if(low>=l && r>=high)return seg[ind];               int mid = (low+high)>>1;        int left = query(2*ind+1,low,mid,l,r);        int right = query(2*ind+2,mid+1,high,l,r);        return min(left,right);    }    void update(int ind,int low,int high,int i,int val){        if(low == high){            seg[ind]=val;            return;        }        int mid=(low+high)/2;        if(i<=mid)update(2*ind+1,low,mid,i,val);        else update(2*ind+2,mid+1,high,i,val);        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);    }};
vll read(ll n) { vll v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }
vll prime(int n) { vll f; while (n % 2 == 0) f.pb(2), n /= 2; for (int i = 3; i * i <= n; i += 2) while (n % i == 0) f.pb(i), n /= i; if (n > 2) f.pb(n); return f; }
ll fact(int n) {const int MOD = 1e9 + 7;long long result = 1;for (int i = 1; i <= n; i++) {result = (result * i) % MOD;  }return result;}
ll MOD = 1e9+7;
ll nCr(ll n, ll r) {
    if (r > n) return 0; if (r == 0 || r == n) return 1;  return fact(n) / (fact(r) * fact(n - r));}
ll mod_exp(ll x, ll n){ll res = 1ll;while (n > 0){if (n % 2ll)res = (res * x) % MOD;x = (x * x) % MOD;n /= 2ll;}return res;}
     
void solve(){
    
}



int main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
