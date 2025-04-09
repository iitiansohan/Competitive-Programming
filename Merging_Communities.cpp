#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;

class DSU
{
    vector<int> par, rank;

public:
    int get_rank(int a)
    {
        return rank[a];
    }
    
    void make_set(int n)
    {
        par.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            rank[i] = 1;
        }
    }
    
    int find_set(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find_set(par[x]); // Path compression
    }
    
    void union_set(int a, int b)
    {
        int p1 = find_set(a);
        int p2 = find_set(b);
        if (p1 == p2)
            return;
        if (rank[p1] > rank[p2])
        {
            par[p2] = p1;
            rank[p1] += rank[p2];
        }
        else
        {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    DSU d;
    int n, q;
    cin >> n >> q;
    d.make_set(n);
    
    char type;
    int i, j;
    
    for (int k = 0; k < q; k++)
    {
        cin >> type;
        if (type == 'M')
        {
            cin >> i >> j;
            d.union_set(i, j);
        }
        else
        {
            cin >> i;
            cout << d.get_rank(d.find_set(i)) << endl;
        }
    }
    
    return 0;
}
