//
// Created by Ahmet Şentürk on 2.12.2018.
//

#include "Graph.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

Graph::Graph(int N, int M) {
    this->N = N;
    this->M = M;
    totVisited = 0;
    maxLadder = 0;
    boolVertices = new Vertex*[N];
    for(int i = 0; i < N; ++i)
        boolVertices[i] = new Vertex[M];

    vertices = new int*[N];
    for(int i = 0; i < N; ++i)
        vertices[i] = new int[M];
}

void Graph::createSpanningTree() {
    priority_queue<weightedEdge, vector<weightedEdge>, compareEdges> priorityEdges;
    priorityEdges.push(allEdges.top());
    allEdges.pop();
    while(totVisited!=N*M){
        int x1 = priorityEdges.top().first.first.first;
        int y1 = priorityEdges.top().first.first.second;
        int x2 = priorityEdges.top().first.second.first;
        int y2 = priorityEdges.top().first.second.second;
        if(!boolVertices[x1][y1].inSpan && !boolVertices[x2][y2].inSpan){
            //add the edge to spanning tree and pop it from the priorityEdges
            if(x1-x2 == 0) {
                if (y1 > y2) {
                    boolVertices[x1][y1].neighbors[1] = true;
                    boolVertices[x2][y2].neighbors[3] = true;
                } else{
                    boolVertices[x1][y1].neighbors[3] = true;
                    boolVertices[x2][y2].neighbors[1] = true;
                }
            }else{
               if (x1 > x2){
                   boolVertices[x1][y1].neighbors[2] = true;
                   boolVertices[x2][y2].neighbors[0] = true;
               } else{
                   boolVertices[x1][y1].neighbors[0] = true;
                   boolVertices[x2][y2].neighbors[2] = true;
               }
            }
            totVisited+=2;
            priorityEdges.pop();
        }else{
            priorityEdges.pop();
        }
        priorityEdges.push(allEdges.top());
        allEdges.pop();
    }
}

void Graph::dfs(int x, int y) {
    if(x==targetX && y == targetY)
        return;
    if(boolVertices[x][y].neighbors[0]){
        if(abs(vertices[x][y]-vertices[x+1][y]) > maxLadder)
            maxLadder = abs(vertices[x][y]-vertices[x+1][y]);
        dfs(x + 1, y);
    }
    if(boolVertices[x][y].neighbors[1]) {
        if(abs(vertices[x][y]-vertices[x][y+1]) > maxLadder)
            maxLadder = abs(vertices[x][y]-vertices[x][y+1]);
        dfs(x, y + 1);
    }
    if(boolVertices[x][y].neighbors[2]) {
        if(abs(vertices[x][y]-vertices[x-1][y]) > maxLadder)
            maxLadder = abs(vertices[x][y]-vertices[x-1][y]);
        dfs(x - 1, y);
    }
    if(boolVertices[x][y].neighbors[3]) {
        if(abs(vertices[x][y]-vertices[x][y-1]) > maxLadder)
            maxLadder = abs(vertices[x][y]-vertices[x][y-1]);
        dfs(x, y - 1);
    }
}

void Graph::printResult() {

}