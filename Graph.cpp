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
    vertices = new int*[N];
    level = new int*[N];
    boolSpan = new bool*[N];
    parents = new cords*[N];
    for(int i = 0; i < N; ++i) {
        vertices[i] = new int[M];
        level[i] = new int[M];
        boolSpan[i] = new bool[M];
        parents[i] = new cords[M];
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            boolSpan[i][j] = false;
        }
    }
}

void Graph::createSpanningTree() {
    addEdges(0, 0);
    parents[0][0] = make_pair(-1, -1);
    level[0][0] = 0;
    while(totVisited!=N*M){
        WeightedEdge currentEdge = priorityEdges.top();
        if(!(boolSpan[currentEdge.x1][currentEdge.y1] && boolSpan[currentEdge.x2][currentEdge.y2])) {
            level[currentEdge.x2][currentEdge.y2] = level[currentEdge.x1][currentEdge.y1] + 1;
            boolSpan[currentEdge.x1][currentEdge.y1] = true;
            boolSpan[currentEdge.x2][currentEdge.y2] = true;
            parents[currentEdge.x2][currentEdge.y2] = make_pair(currentEdge.x1, currentEdge.y1);
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

void Graph::bonusFind() {
    currentTargetLevel = level[currentTargetX][currentTargetY];
    currentSourceLevel = level[currentSourceX][currentSourceY];
    int temp = 0;
    while(currentSourceLevel > currentTargetLevel){
        ladders.push(abs(vertices[currentSourceX][currentSourceY]-
        vertices[parents[currentSourceX][currentSourceY].first][parents[currentSourceX][currentSourceY].second]));
        temp = currentSourceX;
        currentSourceX = parents[currentSourceX][currentSourceY].first;
        currentSourceY = parents[temp][currentSourceY].second;
        currentSourceLevel--;
    }
    while(currentTargetLevel > currentSourceLevel){
        ladders.push(abs(vertices[currentTargetX][currentTargetY]-
        vertices[parents[currentTargetX][currentTargetY].first][parents[currentTargetX][currentTargetY].second]));
        temp = currentTargetX;
        currentTargetX = parents[currentTargetX][currentTargetY].first;
        currentTargetY = parents[temp][currentTargetY].second;
        currentTargetLevel--;
    }
    int temp2 = 0;
    while(currentSourceX != currentTargetX || currentSourceY != currentTargetY){
        ladders.push(abs(vertices[currentSourceX][currentSourceY]-
                         vertices[parents[currentSourceX][currentSourceY].first][parents[currentSourceX][currentSourceY].second]));
        temp = currentSourceX;
        currentSourceX = parents[currentSourceX][currentSourceY].first;
        currentSourceY = parents[temp][currentSourceY].second;
        currentSourceLevel--;
        ladders.push(abs(vertices[currentTargetX][currentTargetY]-
                         vertices[parents[currentTargetX][currentTargetY].first][parents[currentTargetX][currentTargetY].second]));
        temp2 = currentTargetX;
        currentTargetX = parents[currentTargetX][currentTargetY].first;
        currentTargetY = parents[temp2][currentTargetY].second;
        currentTargetLevel--;
    }
    ladders.push(abs(vertices[currentSourceX][currentSourceY]-
                     vertices[parents[currentSourceX][currentSourceY].first][parents[currentSourceX][currentSourceY].second]));

    ladders.push(abs(vertices[currentTargetX][currentTargetY]-
                     vertices[parents[currentTargetX][currentTargetY].first][parents[currentTargetX][currentTargetY].second]));
    maxLadder = ladders.top();
    ladders = priority_queue <int>();
}
