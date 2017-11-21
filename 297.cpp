#include <iostream>
#include <cstring>
using namespace std;

struct node
{
    node()
    {
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
    }
    ~node()
    {
        for (int i = 0; i < 4; ++i)
            delete c[i];
    }
    bool b[4];
    node* c[4];
};

void make_tree(node** r, string& s, int& i)
{    
    if (!*r)
        *r = new node;

    for (int k = 0; k < 4 && i < s.size(); ++k)
    {
        switch (s[i++])
        {
        case 'p': make_tree(&(*r)->c[k], s, i); break;
        case 'f': (*r)->b[k] = 1; break;
        }
    }
}

int get_pixels(node* r, int x)
{
    int sum = 0;
    for (int k = 0; k < 4; ++k)
    {
        if (r->b[k])
            sum += x;
        else if (r->c[k])
            sum += get_pixels(r->c[k], x / 4);
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int i = 0;
        node* r = nullptr;
        make_tree(&r, a, i);
        i = 0;
        make_tree(&r, b, i);
        cout << "There are " << get_pixels(r, 1024) << " black pixels.\n";
        delete r;
    }
}
