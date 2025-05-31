#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<pair<int,double>>> LP;
void leituraGrafo(LP &, int);
void escritaGrafo(LP &);
int main()
{
    int n, m;
    cin >> n >> m;
    LP Grafo;
    Grafo.assign(n, vector<pair<int, double>>());
    leituraGrafo(Grafo, m);
    escritaGrafo(Grafo);
    cout << "Total Vértices: " << n << endl;
    cout << "Total Arestas: " << m << endl;
    return 0;
}

void leituraGrafo(LP &G, int m)
{
    int a, b;
    double c;
    while (m--)
    {
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
        //G[b].push_back(make_pair(a, c));
    }
}

void escritaGrafo(LP &G)
{
    int n = G.size();
    cout << "Lista de Adjacência:" << endl;
    for (int u = 0; u < n; u++)
    {
        cout << u << ": ";
        for (auto v : G[u])
        {
            cout << "[(" << u << "," << v.first << ") w: " << v.second << "] ";
        }
        cout << endl;
    }
}
