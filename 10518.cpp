#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;

int mod;
int add(int a, int b) { return (a += b) < mod? a : a - mod; }
int sub(int a, int b) { return (a -= b) >=  0? a : a + mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int pwr(int a, int p) {
    if (p == 0) return 1;
    if (p & 1) return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}
int inv(int a) { return pwr(a, mod - 2); }


struct Matrix
{
    vvi A;
    int dim;
    Matrix() {}
    Matrix(int n) : dim(n) { A.assign(n, vi(n));}
    vi &operator [](int n){ return A[n];}
};

Matrix operator *(Matrix A, Matrix B)
{
    int n = A.dim;
    Matrix C(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
    
    return C;
}

Matrix operator ^(Matrix A, ll k)
{
    int n = A.dim;
    
    Matrix R(n);
    for (int i = 0; i < n; ++i)
        R[i][i] = 1;

    while (k > 0)
    {
        if (k % 2)
            R = R * A;

        A = A * A;
        k /= 2;
    }

    return R;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    int t = 1;
    while (cin >> n >> mod, n || mod)
    {
        Matrix m(3);
        m[0] = {0, 1, 0};
        m[1] = {1, 1, 1};
        m[2] = {0, 0, 1};
        m = m ^ n;
        cout << "Case " << t++ << ": " << n << ' ' << mod << ' ';
        cout << (m[0][0] + m[0][1] + m[0][2]) % mod << '\n';
    }
}
