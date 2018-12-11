//
// Created by Ahmet Şentürk on 2.12.2018.
//

#ifndef PROJECT4_GRAPH_H
#define PROJECT4_GRAPH_H

#include <list>
#include <queue>
#include "Vertex.h"
#include <cstdlib>

typedef pair<int, int> intPair;
typedef pair<intPair, intPair> edgePair;
typedef pair<edgePair, int> weightedEdge;

struct compareEdges{
    bool operator()(const weightedEdge e1, const weightedEdge e2){
        return e1.second > e2.second;
    }
};
class Graph {

public:
    int N;
    int M;
    int targetX;
    int targetY;
    int maxLadder;
    int totVisited;
    Vertex** boolVertices;
    int** vertices;
    priority_queue<weightedEdge, vector<weightedEdge>> allEdges;
    Graph(int N, int M);
    void createSpanningTree();
    void dfs(int x,int y);
    void printResult();
};


#endif //PROJECT4_GRAPH_H
