#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

// Usando o typedef do seu arquivo GrafoListaPeso.cpp
typedef std::vector<std::vector<std::pair<int, double>>> LP;

// Estrutura para representar uma aresta, necessária para o algoritmo de Kruskal
struct Aresta {
    int origem, destino;
    double peso;
};

// Estrutura auxiliar para Disjoint Set Union (DSU) ou Union-Find
struct DisjointSet {
    int *pai;

    // Construtor
    DisjointSet(int n) {
        pai = new int[n];
        for (int i = 0; i < n; i++) {
            pai[i] = i; // Cada vértice é seu próprio pai inicialmente
        }
    }

    // Encontra o representante do conjunto de 'i' (com compressão de caminho)
    int encontrar(int i) {
        if (pai[i] == i) {
            return i;
        }
        return pai[i] = encontrar(pai[i]);
    }

    // Une os conjuntos de 'x' e 'y'
    void unir(int x, int y) {
        int raiz_x = encontrar(x);
        int raiz_y = encontrar(y);
        if (raiz_x != raiz_y) {
            pai[raiz_x] = raiz_y;
        }
    }

    // Destrutor para liberar a memória
    ~DisjointSet() {
        delete[] pai;
    }
};

// Função para comparar duas arestas pelo peso. Usada para ordenação.
bool compararArestas(const Aresta& a, const Aresta& b) {
    return a.peso < b.peso;
}

// Implementação do Algoritmo de Kruskal
void kruskalAGM(int V, std::vector<Aresta>& arestas) {
    std::cout << "\n--- Executando Algoritmo de Kruskal ---\n";
    std::vector<Aresta> resultado;
    double custo_total = 0.0;

    // 1. Ordena todas as arestas em ordem crescente de peso.
    std::sort(arestas.begin(), arestas.end(), compararArestas);

    // Cria os subconjuntos para a estrutura Union-Find.
    DisjointSet ds(V);

    // 2. Itera sobre as arestas ordenadas.
    for (const auto& aresta : arestas) {
        int u = aresta.origem;
        int v = aresta.destino;

        int set_u = ds.encontrar(u);
        int set_v = ds.encontrar(v);

        // 3. Verifica se a aresta forma um ciclo.
        if (set_u != set_v) {
            resultado.push_back(aresta);
            custo_total += aresta.peso;
            ds.unir(u, v);
        }
    }

    // Imprime o resultado
    std::cout << "Arestas da Arvore Geradora Minima (AGM):" << std::endl;
    for (const auto& aresta : resultado) {
        std::cout << aresta.origem << " -- " << aresta.destino << "  (Peso: " << aresta.peso << ")" << std::endl;
    }
    std::cout << "Custo total da AGM: " << std::fixed << std::setprecision(2) << custo_total << std::endl;
}

// Função de leitura do arquivo GrafoListaPeso.cpp
void leituraGrafo(LP &G, int m) {
    int a, b;
    double c;
    while (m--) {
        std::cin >> a >> b >> c;
        G[a].push_back(std::make_pair(b, c));
        G[b].push_back(std::make_pair(a, c));
    }
}

// Função de escrita do arquivo GrafoListaPeso.cpp - COM CORREÇÃO
void escritaGrafo(LP &G) {
    int n = G.size();
    std::cout << "Lista de Adjacencia do Grafo Lido:" << std::endl;
    for (int u = 0; u < n; u++) {
        std::cout << u << ": ";
        // Alterado para ser compatível com C++11/14
        for (const auto& par : G[u]) {
            int v = par.first;
            double peso = par.second;
            std::cout << "[-> " << v << ", w: " << peso << "] ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    LP Grafo;
    Grafo.assign(n, std::vector<std::pair<int, double>>());
    leituraGrafo(Grafo, m);
    escritaGrafo(Grafo);
    
    std::cout << "\nTotal Vertices: " << n << std::endl;
    std::cout << "Total Arestas: " << m << std::endl;

    std::vector<Aresta> todasArestas;
    for (int u = 0; u < n; u++) {
        // Alterado para ser compatível com C++11/14
        for (const auto& par : Grafo[u]) {
            int v = par.first;
            double peso = par.second;
            if (u < v) {
                todasArestas.push_back({u, v, peso});
            }
        }
    }

    kruskalAGM(n, todasArestas);

    return 0;
}