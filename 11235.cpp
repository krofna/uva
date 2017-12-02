#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class segtree
{
    int* A;
    vi st;
    int n;
public:
    segtree(int* A, int n) : A(A), n(n)
    {
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j)
    {
        return rmq(1, 0, n - 1, i, j);
    }

private:
    int left(int p)
    {
        return p << 1;
    }

    int right(int p)
    {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R)
    {
        if (L == R)
            st[p] = L;
        else
        {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j)
    {
        if (i > R || j < L) return -1;
        if (L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return (A[p1] >= A[p2]) ? p1 : p2;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int n, q, A[100000], k, a, b;
    while (cin >> n, n)
    {
        cin >> q >> k;
        A[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            int pk = k;
            cin >> k;
            A[i] = (k == pk ? A[i - 1] + 1 : 1);
        }
        segtree seg(A, n);
        for (int i = 0; i < q; ++i)
        {
            cin >> a >> b; a--; b--;
            int f = seg.rmq(a, b);
            int mi = min(f - a + 1, A[f]);
            if (f != b)
                mi = max(mi, A[seg.rmq(f + 1, b)]);
            cout << mi << '\n';
        }
    }
}
