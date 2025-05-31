#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<double>> MP;
void leituraGrafo(MP &, int);
void escritaGrafo(MP &);
int main()
{
    int n, m;
    cin >> n >> m;
    MP Grafo;
    Grafo.assign(n, vector<double>(n, 0));
    leituraGrafo(Grafo, m);
    escritaGrafo(Grafo);
    cout << "Total Vértices: " << n << endl;
    cout << "Total Arestas: " << m << endl;
    return 0;
}
void leituraGrafo(MP &G, int m)
{
    int a, b;
    double c;
    while (m--)
    {
        cin >> a >> b >> c;
        G[a][b] = c;
        //G[b][a] = c;
    }
}

void escritaGrafo(MP &G)
{
    int n = G.size();
    cout << "Matriz de Adjacência:" << endl;
    cout << "   ";
    for (int u = 0; u < n; u++)
    {
        printf("%4d ",u);
    }
    cout << endl;
    for (int u = 0; u < n; u++)
    {
        cout << u << ": ";
        for (int v = 0; v < n; v++)
        {
            printf("%0.2lf ",G[u][v]);
        }
        cout << endl;
    }
}
