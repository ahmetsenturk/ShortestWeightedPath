//
// Created by Ahmet Şentürk on 6.12.2018.
//

#ifndef PROJECT4_VERTEX_H
#define PROJECT4_VERTEX_H


//#include <limits.h>
#include <list>
using namespace std;

class Vertex {
public:
    bool inSpan;
    bool* neighbors;//0 indicates right,1 for down, 2 for left and 3 for up
    Vertex();
};


#endif //PROJECT4_VERTEX_H
