#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct arr
{
    string name;
    int base, size, dim, lo[10], hi[10];
};

int main()
{
    int n, r;
    cin >> n >> r;
    map<string, arr> A;
    for (int i = 0; i < n; ++i)
    {
        arr a;
        cin >> a.name >> a.base >> a.size >> a.dim;
        for (int j = 0; j < a.dim; ++j)
            cin >> a.lo[j] >> a.hi[j];
        A[a.name] = a;
    }
    for (int i = 0; i < r; ++i)
    {
        string name;
        cin >> name;
        cout << name << "[";
        arr& a = A[name];
        vector<int> D(a.dim);
        for (int j = 0; j < a.dim; ++j)
        {
            if (j != 0) cout << ", ";
            cin >> D[j];
            cout << D[j];
        }
        vector<int> C(a.dim, a.size);
        for (int i = a.dim - 2; i >= 0; --i)
            C[i] = C[i + 1] * (a.hi[i + 1] - a.lo[i + 1] + 1);
        int addr = a.base;
        for (int i = 0; i < a.dim; ++i)
            addr -= C[i] * a.lo[i];
        for (int i = 0; i < a.dim; ++i)
            addr += C[i] * D[i];
        cout << "] = " << addr << '\n';
    }
}
