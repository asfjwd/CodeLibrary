// Pragmas
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3,unroll-loops") 
#pragma GCC target("avx,avx2,fma")

// Custom Priority Queue
std::priority_queue< int, std::vector<int>, std::greater<int> > Q; // increasing

//gp hash table https://codeforces.com/blog/entry/60737
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<key, int, chash> table;

//bitset
BS._Find_first()
BS._Find_next(x) //first set bit after xth bit if exists, returns x otherwise

