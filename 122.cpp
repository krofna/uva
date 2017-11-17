#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;

struct node
{
    node() : k(-1), l(nullptr), r(nullptr) { }
    ~node()
    {
        delete l;
        delete r;
    }
    int k;
    node* l;
    node* r;
};

bool good;

void add(node** r, int k, string& ds, size_t it)
{
    if (!*r)
        *r = new node;

    if (it == ds.size())
    {
        if ((*r)->k != -1) good = false;
        (*r)->k = k;
    }
    else if (ds[it] == 'R')
        add(&(*r)->r, k, ds, it + 1);
    else
        add(&(*r)->l, k, ds, it + 1);
}

vi bfs(node* r)
{
    queue<node*> Q;
    Q.push(r);
    vi k;
    while (!Q.empty())
    {
        r = Q.front(); Q.pop();
        k.push_back(r->k);
        if (r->l) Q.push(r->l);
        if (r->r) Q.push(r->r);
    }
    return k;
}

int main()
{
    string s;
    while (cin >> s)
    {
        node* root = nullptr;
        good = true;
        while (s != "()")
        {
            string ks, ds;
            int i = 1;
            while (s[i] != ',') ks += s[i++];
            while (s[i] != ')') ds += s[i++];
            add(&root, stoi(ks), ds, 1);
            cin >> s;
        }
        vi k;
        if (good)
        {
            k = bfs(root);
            for (int l : k)
                if (l == -1)
                    good = false;
        }
        
        if (good)
        {
            for (int i = 0; i < k.size(); ++i)
            {
                cout << k[i];
                if (i != k.size() - 1) cout << ' ';
            }
        }
        else
            cout << "not complete";
        cout << '\n';
        delete root;
    }
}
