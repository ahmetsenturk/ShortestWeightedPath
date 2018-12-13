//
// Created by Ahmet Şentürk on 2.12.2018.
//

#include "Graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

Graph::Graph(int N, int M) {
    this->N = N;
    this->M = M;
    totVisited = 0;
    maxLadder = 0;
    adjSpan = new list<SpanVertex>[N*M];
    vertices = new int*[N];
    boolDfs = new bool*[N];
    boolSpan = new bool*[N];
    for(int i = 0; i < N; ++i) {
        vertices[i] = new int[M];
        boolDfs[i] = new bool[M];
        boolSpan[i] = new bool[M];
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            boolDfs[i][j] = false;
            boolSpan[i][j] = false;
        }
    }
}

void Graph::createSpanningTree() {
    addEdges(0, 0);
    while(totVisited!=N*M){
        WeightedEdge currentEdge = priorityEdges.top();
        if(!(boolSpan[currentEdge.x1][currentEdge.y1] && boolSpan[currentEdge.x2][currentEdge.y2])) {
            boolSpan[currentEdge.x1][currentEdge.y1] = true;
            boolSpan[currentEdge.x2][currentEdge.y2] = true;
            adjSpan[currentEdge.x1 * M + currentEdge.y1].push_back(SpanVertex(currentEdge.x2, currentEdge.y2));
            adjSpan[currentEdge.x2 * M + currentEdge.y2].push_back(SpanVertex(currentEdge.x1, currentEdge.y1));
            priorityEdges.pop();
            addEdges(currentEdge.x2, currentEdge.y2);
        }else{
            priorityEdges.pop();
        }
    }
}

void Graph::addEdges(int x, int y) {
    totVisited++;
    if(y+1<M && !boolSpan[x][y+1]) {
        priorityEdges.push(WeightedEdge(x, y, x, y + 1, abs(vertices[x][y] - vertices[x][y + 1])));
    }
    if(x+1<N && !boolSpan[x+1][y]) {
        priorityEdges.push(WeightedEdge(x, y, x + 1, y, abs(vertices[x][y] - vertices[x + 1][y])));
    }
    if(y-1>=0 && !boolSpan[x][y-1]) {
        priorityEdges.push(WeightedEdge(x, y, x, y - 1, abs(vertices[x][y] - vertices[x][y - 1])));
    }
    if(x-1>=0 && !boolSpan[x-1][y]) {
        priorityEdges.push(WeightedEdge(x, y, x - 1, y, abs(vertices[x][y] - vertices[x - 1][y])));
    }
}


void Graph::dfs(int x, int y, int maxLad) {
    if(x==targetX && y==targetY) {
        maxLadder = maxLad;
        return;
    }
    if(boolDfs[x][y])
        return;

    boolDfs[x][y] = true;
    list<SpanVertex>::iterator itr;
    for(itr = adjSpan[x*M + y].begin(); itr != adjSpan[x*M + y].end(); ++itr){
        dfs(itr->x, itr->y, max(maxLad, abs(vertices[x][y] - vertices[itr->x][itr->y])));
    }
}

void Graph::clear() {
    totVisited = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            boolDfs[i][j] = false;
        }
    }
}
