#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define ff first
#define ss second
#define pb push_back
#define sz size()
#define mp make_pair
#ifndef ONLINE_JUDGE 
#include "/home/asif/Codes/Library/debug.h"
#endif
/*--------------------------------------------------------------------*/

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

const char START = '0'; // first letter in alphabet

struct Trie {
  
  static const int MAX = N * 32, ALPHA = 2, LEN = 32; // total characters, alphabet size
  int root, nodes, nxt[MAX][ALPHA], cnt[MAX];
  
  void init(){
    root = nodes = 1;
    memset(nxt, 0, sizeof nxt);
    memset(cnt, 0, sizeof cnt);
  }
  
  void insert(string str){
    int cur = root;
    for(auto c : str){
      if(!nxt[cur][c - START]) nxt[cur][c - START] = ++nodes;
      cur = nxt[cur][c - START];
      cnt[cur]++;
    }
  }

  void insert(int n){
    bitset<LEN> bits(n);
    insert(bits.to_string());
  }

  bool find(string str){
    int cur = root;
    for(auto c : str){
      if(!nxt[cur][c - START] or !cnt[nxt[cur][c - START]]) return false;
      cur = nxt[cur][c - START];
    }
    return true;
  }

  void erase(string str){ // may need to call find() before
    int cur = root;
    for(auto c : str) {
      cur = nxt[cur][c - START];
      cnt[cur]--;
    }
  }

  ll xorMin(string str){
    ll ret = 0LL; int cur = root;
    for(auto c : str){
      ret <<= 1LL;
      if(!nxt[cur][c - START] or !cnt[ nxt[cur][c - START] ]) {
        cur = nxt[cur][ (c - START) ^ 1]; ret++;
      }
      else cur = nxt[cur][c - START];
    }
    return ret;
  }

  ll xorMin(int n){
    bitset<LEN> bits(n);
    return xorMin(bits.to_string());
  }

  ll xorMax(string str){
    ll ret = 0LL; int cur = root;
    for(auto c : str){
      ret <<= 1LL; ret ^= 1LL;
      if(!nxt[cur][(c - START) ^ 1] or !cnt[ nxt[cur][(c - START) ^ 1] ]) {
        cur = nxt[cur][c - START]; ret ^= 1;
      }
      else cur = nxt[cur][(c - START) ^ 1];
    }
    return ret;
  }

  ll xorMax(int n){
    bitset<LEN> bits(n);
    return xorMax(bits.to_string());
  }
} T;

int main() {

  int t, n; cin >> t;
  while(t--){
    cin >> n; std::vector<int> v(n);
    T.init(); T.insert(0);
    ll ans = 0;
    for(int i = 0; i < n; i++){
      cin >> v[i];
      if(i) v[i] ^= v[i - 1];
      ans = max(ans, T.xorMax(v[i]));
      T.insert(v[i]);
    }
    cout << ans << endl;
  }

  return 0;
}