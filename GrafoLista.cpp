#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> Lista;
void leituraGrafo(Lista &, int);
void escritaGrafo(Lista &);
int main()
{
    int n, m;
    cin >> n >> m;
    Lista Grafo;
    Grafo.assign(n, vector<int>());
    leituraGrafo(Grafo, m);
    escritaGrafo(Grafo);
    cout << "Total Vértices: " << n << endl;
    cout << "Total Arestas: " << m << endl;
    return 0;
}

void leituraGrafo(Lista &G, int m)
{
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

void escritaGrafo(Lista &G)
{
    int n = G.size();
    cout << "Lista de Adjacência:" << endl;
    for (int u = 0; u < n; u++)
    {
        cout << u << ": ";
        for (auto v : G[u])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}
