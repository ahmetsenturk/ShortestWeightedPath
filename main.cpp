//
// Created by Ahmet Şentürk on 2.12.2018.
//
#include <iostream>
#include <queue>
#include <sstream>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include "Graph.h"
#include "Vertex.h"
using namespace std;

template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);

    if (argc != 3) {
        cout << "Run the code with the following command: ./project4 [input_file] [output_file]" << endl;
        return 1;
    }

    ifstream infile(argv[1]);
    string line;
    vector<string> input;

    getline(infile, line);
    split1(line, input);
    int N = stoi(input[0]);
    int M = stoi(input[1]);
    Graph g(N, M);
    for (int i=0; i<N; i++) {
        getline(infile, line);
        vector<string> numbers;
        split1(line, numbers);
        for (int j=0; j<M; j++) {
            g.vertices[i][j] = stoi(numbers[j]);
            if(j-1>=0){
                g.allEdges.push(make_pair(make_pair(make_pair(i,j), make_pair(i,j-1)),
                                       abs(g.vertices[i][j] - g.vertices[i][j-1])));
            }
            if(i-1>=0){
                g.allEdges.push(make_pair(make_pair(make_pair(i,j), make_pair(i-1,j)),
                                       abs(g.vertices[i][j] - g.vertices[i-1][j])));
            }
        }
    }

    g.createSpanningTree();
    return 0;
}
