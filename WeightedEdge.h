//
// Created by Ahmet Şentürk on 12.12.2018.
//

#ifndef PROJECT4_WEIGHTEDEDGE_H
#define PROJECT4_WEIGHTEDEDGE_H


class WeightedEdge {
public:
    int x1;
    int y1;
    int x2;
    int y2;
    int weight;
    WeightedEdge(int x1, int y1, int x2, int y2, int weight){
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->weight = weight;
    }
};


#endif //PROJECT4_WEIGHTEDEDGE_H
