/*You are given a number str(in string format) in hexadecimal. A new number can be made from the number str by selecting any subsequence of it (in HexaDecimal) and rearranging it.
You have tell the number of distinct numbers that can be made from number n.

Your Task:
You don't need to read or print anyhthing. Your task is to complete the function countOfDistinctNo() which takes str in string format as input and returns the total possible combination modulo 109+7.
*/


const int N = 5e4 + 50;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 61LL;
 
long long arr[N];
string str, ss;
map <char, int> f;
long long fact[N], ifact[N], inv[N];
long long cnt[N];
class Solution {
public:
void pre() {
    fact[1] =fact[0] = ifact[0] = ifact[1] = inv[0] = inv[1] =1;
    for (int i = 1; i < N; ++i) fact[i] = (fact[i - 1] * i) % mod;
    for (int i = 2; i < N; ++i) inv[i] = (((-(mod/ i) * inv[mod % i]) % mod) + mod) % mod;
    for (int i = 2; i < N; ++i) ifact[i] = (ifact[i - 1] * inv[i]) % mod;
    for (int i = 2; i < N; ++i) {
        if ((fact[i] * ifact[i] % mod) != 1) assert(0);
    }
}
long long C(long long n, long long k) {
    return 0;
}
long long mult = 1, ddiv = 1;
int countOfDistinctNo(string str){
	f.clear();
	memset(arr, 0, sizeof(arr));
	memset(inv, 0, sizeof(arr));
	memset(ifact, 0, sizeof(arr));
	memset(inv, 0, sizeof(arr));
	memset(cnt, 0, sizeof(cnt));
  pre();
  //cout << fact[16] << endl;
  cnt[0] = 1;
  for (int i = 0; i < str.size(); ++i) {
    f[str[i]]++;
  }
  int ct = 0;
  for (map <char, int> :: iterator ii = f.begin(); ii != f.end(); ++ii) {
      if (ii -> first != '0') ct++;
      else continue;
      for (int i = 2000; i >= 0; --i) {
          for (int j = 1; j <= ii -> second; ++j) {
              cnt[i + j] += (cnt[i] * ifact[j]) % mod;
              cnt[i + j] %= mod;
          }
      }
  }
  long long sol = 0;
  for (int i = 1; i <= 2000; ++i) {
     // if (i < 10) cout << cnt[i] << endl;
      for (int j = 0; j <= f['0']; ++j) {
         sol += (((((cnt[i] * fact[i + j - 1]) % mod) * (1LL * i)) % mod) * ifact[j]) % mod;
        sol %= mod;
      }
      //cout << sol << endl;
  }
  if (f['0']) sol++;
  sol %= mod;
  return (int)sol;
}
};
