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
    V = N*M;
    totVisited = 0;
    maxLadder = 0;
    vertices = new int[N*M];
    level = new int[N*M];
    boolSpan = new bool[N*M];
    parents = new int[N*M];
    for (int i=0; i<N*M; i++) {
        boolSpan[i] = false;
    }
}

void Graph::createSpanningTree() {
    addEdges(0);
    parents[0] = -1;
    level[0] = 0;
    while(totVisited!=N*M){
        WeightedEdge currentEdge = priorityEdges.top();
        if(!(boolSpan[currentEdge.v1] && boolSpan[currentEdge.v2])) {
            level[currentEdge.v2] = level[currentEdge.v1] + 1;
            boolSpan[currentEdge.v1] = true;
            boolSpan[currentEdge.v2] = true;
            parents[currentEdge.v2] = currentEdge.v1;
            priorityEdges.pop();
            addEdges(currentEdge.v2);
        }else{
            priorityEdges.pop();
        }
    }
}

void Graph::addEdges(int v) {
    totVisited++;
    if(v+M<V && !boolSpan[v+M]) {
        priorityEdges.push(WeightedEdge(v, v+M , abs(vertices[v] - vertices[v+M])));
    }
    if(v-M>=0 && !boolSpan[v-M]) {
        priorityEdges.push(WeightedEdge(v, v-M, abs(vertices[v] - vertices[v-M])));
    }
    if(v%M!=0 && !boolSpan[v-1]) {
        priorityEdges.push(WeightedEdge(v, v-1, abs(vertices[v] - vertices[v-1])));
    }
    if((v+1)%M!=0 && !boolSpan[v+1]) {
        priorityEdges.push(WeightedEdge(v, v+1, abs(vertices[v] - vertices[v+1])));
    }
}

void Graph::bonusFind() {
    targetLevel = level[targetV];
    sourceLevel = level[sourceV];
    while(sourceLevel > targetLevel){
        maxLadder = max(maxLadder, abs(vertices[sourceV]- vertices[parents[sourceV]]));
        sourceV = parents[sourceV];
        sourceLevel--;
    }
    while(targetLevel > sourceLevel){
        maxLadder = max(maxLadder, abs(vertices[targetV] - vertices[parents[targetV]]));
        targetV = parents[targetV];
        targetLevel--;
    }
    while(sourceV != targetV){
        maxLadder = max(maxLadder, abs(vertices[sourceV]- vertices[parents[sourceV]]));
        sourceV = parents[sourceV];
        sourceLevel--;
        maxLadder = max(maxLadder, abs(vertices[sourceV]- vertices[parents[sourceV]]));
        targetV = parents[targetV];
        targetLevel--;
    }
}
