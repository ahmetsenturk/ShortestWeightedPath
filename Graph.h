//
// Created by Ahmet Şentürk on 2.12.2018.
//

#ifndef PROJECT4_GRAPH_H
#define PROJECT4_GRAPH_H

#include <list>
#include <queue>
#include <cstdlib>
#include "WeightedEdge.h"
#include "SpanVertex.h"
using namespace std;

struct compareEdges{
    bool operator()(const WeightedEdge e1, const WeightedEdge e2){
        return e1.weight > e2.weight;
    }
};
class Graph {
    int N;
    int M;
public:
    int maxLadder;
    int targetX;
    int targetY;
    int totVisited;
    int** vertices;
    bool** boolDfs;
    bool** boolSpan;
    list<SpanVertex>* adjSpan;
    priority_queue<WeightedEdge, vector<WeightedEdge>, compareEdges> priorityEdges;
    Graph(int N, int M);
    void createSpanningTree();
    void dfs(int x, int y, int maxLad);
    void addEdges(int x, int y);
    void clear();
};


#endif //PROJECT4_GRAPH_H
