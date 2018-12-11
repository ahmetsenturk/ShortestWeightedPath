//
// Created by Ahmet Şentürk on 6.12.2018.
//

#include "Vertex.h"

Vertex::Vertex() {
    inSpan = false;
    neighbors = new bool[4];
    for(int i=0; i<4; i++){
        neighbors[i] = false;
    }
}


