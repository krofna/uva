#include <iostream>
using namespace std;

int A[10000], n = 0, i = 0;

struct node
{
    node(int k, node* p = nullptr) : k(k), p(p), r(nullptr), l(nullptr) { }
    ~node()
    {
        delete r;
        delete l;
    }
    int k;
    node* p;
    node* r;
    node* l;
};

void rec(node* r, int up = 1e6)
{
    while (i < n)
    {
        if (A[i] > r->k)
        {
            if (A[i] > up) return;
            rec(r->r = new node(A[i++], r), up);
        }
        else
            rec(r->l = new node(A[i++], r), r->k);
    }
}

void post(node* r)
{
    if (r->l) post(r->l);
    if (r->r) post(r->r);
    cout << r->k << '\n';
}

int main()
{
    while (cin >> A[n]) n++;
    node* r = new node(A[i++]);
    rec(r);
    post(r);
    delete r;
}
