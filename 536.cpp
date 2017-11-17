// todo: nevalja
#include <iostream>
using namespace std;

string pre, in;
int i, j;

struct node
{
    node(char c, node* p = nullptr) : c(c), p(p), r(nullptr), l(nullptr) { }
    ~node()
    {
        delete r;
        delete l;
    }
    char c;
    node* p;
    node* r;
    node* l;
};

void rec(node* r)
{
    if (i == pre.size())
        return;

    if (r->c != in[j])
        rec(r->l = new node(pre[i++], r)), ++j;

    if (i == pre.size())
        return;

    if (!r->p || (r->p->c != in[j + 1] && (!r->p->p || r->p->p->c != in[j + 1])))
        ++j, rec(r->r = new node(pre[i++], r));
}

string post(node* r)
{
    string s;
    if (r->l) s += post(r->l);
    if (r->r) s += post(r->r);
    s += r->c;
    return s;
}

int main()
{
    while (cin >> pre >> in)
    {
        i = 1;
        j = 0;
        node* r = new node(pre[0]);
        rec(r);
        cout << post(r) << '\n';
        delete r;
    }
}
