#include <iostream>
#include <limits>
using namespace std;

int n;

struct node
{
    ~node()
    {
        delete r;
        delete l;
    }
    int k;
    node* l;
    node* r;
};

int parse_int(const string& t, size_t& in)
{
    string i;
    while (t[in] != '(')
        i += t[in++];
    return stoi(i);
}

node* parse_tree(const string& t, size_t& in)
{
    if (t[++in] == ')')
        return nullptr;
    
    node* n = new node;
    n->k = parse_int(t, in);
    n->l = parse_tree(t, in); ++in;
    n->r = parse_tree(t, in); ++in;
    return n;
}

bool dfs(node* r, int k)
{
    if (!r->l && !r->r) return k + r->k == n;
    if (r->l && dfs(r->l, k + r->k)) return true;
    if (r->r && dfs(r->r, k + r->k)) return true;
    return false;
}

int main()
{
    while (cin >> n)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '(');
        string t = "(";
        int o = 1;
        do
        {
            char c = cin.get();
            if (c != ' ' && c != '\n') t += c;
            if (c == '(') ++o;
            if (c == ')') --o;
        } while (o);
        size_t in = 0;
        node* r = parse_tree(t, in);
        cout << (r && dfs(r, 0) ? "yes" : "no") << '\n';
        delete r;
    }
}
