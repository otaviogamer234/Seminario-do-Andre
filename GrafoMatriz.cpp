#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> Matriz;
void leituraGrafo(Matriz &, int);
void escritaGrafo(Matriz &);
int main()
{
    int n, m;
    cin >> n >> m;
    Matriz Grafo;
    Grafo.assign(n, vector<int>(n, 0));
    leituraGrafo(Grafo, m);
    escritaGrafo(Grafo);
    cout << "Total Vértices: " << n << endl;
    cout << "Total Arestas: " << m << endl;
    return 0;
}
void leituraGrafo(Matriz &G, int m)
{
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
}
void escritaGrafo(Matriz &G)
{
    int n = G.size();
    cout << "Matriz de Adjacência:" << endl;
    cout << "   ";
    for (int u = 0; u < n; u++)
    {
        cout << u << " ";
    }
    cout << endl;
    for (int u = 0; u < n; u++)
    {
        cout << u << ": ";
        for (int v = 0; v < n; v++)
        {
            cout << G[u][v] << " ";
        }
        cout << endl;
    }
}
