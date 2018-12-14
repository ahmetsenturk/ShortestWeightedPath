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
typedef pair<int, int> cords;

class Graph {
    int N;
    int M;
public:
    int maxLadder;
    int currentTargetX;
    int currentTargetY;
    int currentSourceX;
    int currentSourceY;
    int currentSourceLevel;
    int currentTargetLevel;
    int totVisited;
    int** vertices;
    int** level;
    bool** boolSpan;
    cords** parents;
    priority_queue<WeightedEdge, vector<WeightedEdge>, compareEdges> priorityEdges;
    priority_queue<int> ladders;
    Graph(int N, int M);
    void createSpanningTree();
    void bonusFind();
    void addEdges(int x, int y);
};


#endif //PROJECT4_GRAPH_H
