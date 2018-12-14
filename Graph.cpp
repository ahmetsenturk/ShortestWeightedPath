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
    maxLadder = 0;
    vertices = new int[N*M];
    level = new int[N*M];
    boolSpan = new bool[N*M];
    parents = new int[N*M];
    for (int i=0; i<N*M; i++) {
        boolSpan[i] = false;
    }
    for (int i=0; i<N*M; i++) {
        level[i] = 0;
    }
}

void Graph::createSpanningTree() {
    parents[0] = -1;
    level[0] = 0;
    boolSpan[0] = true;
    addEdges(0);
    int totVisited = 1;
    while(totVisited != V){
        WeightedEdge currentEdge = priorityEdges.top();
        priorityEdges.pop();
        if(!(boolSpan[currentEdge.v2])) {
            level[currentEdge.v2] = level[currentEdge.v1] + 1;
            boolSpan[currentEdge.v2] = true;
            parents[currentEdge.v2] = currentEdge.v1;
            addEdges(currentEdge.v2);
            totVisited++;
        }
    }
    cout << "Check"<<endl;
}

void Graph::addEdges(int v) {
    if((v + M) < V && !boolSpan[v + M]) {
        priorityEdges.push(WeightedEdge(v, v+M , abs(vertices[v] - vertices[v+M])));
    }
    if((v-M)>=0 && !boolSpan[v-M]) {
        priorityEdges.push(WeightedEdge(v, v-M, abs(vertices[v] - vertices[v-M])));
    }
    if((v - 1) % M != (M - 1) && v - 1 >= 0  && !boolSpan[v-1]) {
        priorityEdges.push(WeightedEdge(v, v-1, abs(vertices[v] - vertices[v-1])));
    }
    if(((v+1)%M)!=0 && !boolSpan[v+1]) {
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
        maxLadder = max(maxLadder, abs(vertices[targetV]- vertices[parents[targetV]]));
        targetV = parents[targetV];
        targetLevel--;
    }
    cout<<vertices[targetV]<<endl;
    cout<<vertices[sourceV];

}
