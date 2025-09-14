/*Given a sequence as follow:
1,1,7,19,73....
Find the Nth term of the given sequence.Your Task:
Your task is to complete the function NthTerm() which takes N as input paramater and returns Nth term of the given sequence modulo 109+7.*/

class Solution {
public:
using ll = long long int;
using matrix = vector<vector<ll>>;
ll MOD = 1e9 + 7;
// HINT: 5*a + 2*b
// HELP FOR SOLUTION TAKEN FROM ::  http://fusharblog.com/solving-linear-recurrence-for-programming-contest/
// computes A * B
matrix mul(matrix A, matrix B)
{
	int K = 2;
    matrix C(K+1, vector<ll>(K+1));
    for(int i = 1; i <= K; i++) 
    	for(int j = 1; j <= K; j++)
    		for(int k = 1; k <= K; k++)
        		C[i][j] = (C[i][j] + A[i][k]* B[k][j]) % MOD;
    return C;
}
// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}
// returns the N-th term
long long int NthTerm(long long int N)
{
	int K = 2;
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = 1;
    F1[2] = 1;
    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 5, T[2][2] = 2;
    // raise T to the (N-1)th power
    if (N == 1)
        return 1;
    T = pow(T, N-1);
    // the answer is the first row of T . F1
    ll res = 0;
    for(int i = 1; i <= K; i++)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}
};
