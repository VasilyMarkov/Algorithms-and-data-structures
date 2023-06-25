#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include<bits/stdc++.h>
class Graph {

    // No. of vertices
    int _vertices;

    // Pointer to an array containing adjacency lists
    std::vector<std::list<int> > adj;

public:
    // Constructor
    Graph(int V);

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // Prints BFS traversal from a given source s
    void BFS(int s);

    void DFS(int s);
};

inline Graph::Graph(int V)
{
    _vertices = V;
    adj.resize(_vertices);
}

inline void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

inline void Graph::BFS(int s)
{
    std::vector<bool> visited;
    visited.resize(_vertices, false);

    std::list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty()) {
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();

        for (auto adjacent : adj[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

inline void Graph::DFS(int s)
{
    std::vector<bool> visited;
    visited.resize(_vertices, false);
    std::stack<int> stack;
    stack.push(s);
    while(!stack.empty()) {
        s = stack.top();
        stack.pop();
        if(!visited[s]) {
            for(auto i : adj[s]) {
                stack.push(i);
            }
            visited[s] = true;
        }
    }
}
using iPair= std::pair<int, int>;
class WeightedGraph {
    int _v;
    std::list<iPair>* adj;
    const int INF = 0x3f3f3f3f;
public:
    WeightedGraph(int v): _v(v) {
        adj = new std::list<iPair>[_v];
    }

    void addEdge(int u, int v, int w ) {
        adj[u].push_back(std::make_pair(v, w));
        adj[v].push_back(std::make_pair(u, w));
    }
    void primMST() {
        std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> pq;
        int src = 0;
        std::vector<int> key(_v, INF);
        std::vector<int> parent(_v, -1);
        std::vector<bool> inMST(_v, false);
        pq.push(std::make_pair(0, src));
        key[src] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            if(inMST[u] == true){
                continue;
            }
            inMST[u] = true;
            std::list<iPair>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = (*i).first;
                int weight = (*i).second;
                if (inMST[v] == false && key[v] > weight)
                {
                    key[v] = weight;
                    pq.push(std::make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }
        for (int i = 1; i < _v; ++i)
            printf("%d - %d\n", parent[i], i);
    }
};

#endif // GRAPH_H
