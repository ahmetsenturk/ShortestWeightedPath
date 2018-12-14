//
// Created by Ahmet Şentürk on 2.12.2018.
//

#ifndef PROJECT4_GRAPH_H
#define PROJECT4_GRAPH_H

#include <list>
#include <queue>
#include <cstdlib>
#include "WeightedEdge.h"
using namespace std;

struct compareEdges{
    bool operator()(const WeightedEdge e1, const WeightedEdge e2){
        return e1.weight > e2.weight;
    }
};

class Graph {
    int N;
    int M;
    int V;
public:
    int maxLadder;
    int targetV;
    int sourceV;
    int sourceLevel;
    int targetLevel;
    int* vertices;
    int* level;
    bool* boolSpan;
    int* parents;
    priority_queue<WeightedEdge, vector<WeightedEdge>, compareEdges> priorityEdges;
    Graph(int N, int M);
    void createSpanningTree();
    void bonusFind();
    void addEdges(int v);
};


#endif //PROJECT4_GRAPH_H
