namespace nCr {
  ll factorial[N], invFactorial[N];
  ll ncr(ll n, ll r){
    return (( (factorial[n] * invFactorial[r]) % MOD) * invFactorial[n - r]) % MOD;
  }
  void init(){
    invFactorial[1] = 1;
    for(int i = 2;i < N;i++)invFactorial[i] = MOD - (MOD / i) * invFactorial[MOD % i] % MOD;
    factorial[0] = factorial[1] = invFactorial[0] = 1;
    for(int i = 2; i < N; i++){
      factorial[i] = (factorial[i - 1] * i) % MOD;
      invFactorial[i] = (invFactorial[i - 1] * invFactorial[i]) % MOD;
    }
  }
}