//
// Created by Ahmet Şentürk on 12.12.2018.
//

#ifndef PROJECT4_WEIGHTEDEDGE_H
#define PROJECT4_WEIGHTEDEDGE_H


class WeightedEdge {
public:
    int v1;
    int v2;
    int weight;
    WeightedEdge(int v1, int v2, int weight){
        this->v1 = v1;
        this->v2 = v2;
        this->weight = weight;
    }
};


#endif //PROJECT4_WEIGHTEDEDGE_H
