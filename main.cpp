//
// Created by Ahmet Şentürk on 2.12.2018.
//
#include <iostream>
#include <queue>
#include <sstream>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <iterator>
#include "Graph.h"
#include "WeightedEdge.h"
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
    int count = 0;
    for (int i=0; i<N; i++) {
        getline(infile, line);
        vector<string> numbers;
        split1(line, numbers);
        for (int j=0; j<M; j++) {
            g.vertices[count] = stoi(numbers[j]);
            count++;
        }
    }
    ios_base::sync_with_stdio(false);
    ofstream outputFile;
    outputFile.open (argv[2]);
    g.createSpanningTree();

    vector<string> input2;
    getline(infile, line);
    split1(line, input2);
    int K = stoi(input2[0]);

    for(int i=0; i<K; i++){
        string line;
        getline(infile, line);
        vector<string> cords;
        split1(line, cords);
        g.targetV = (stoi(cords[2])-1)*M + stoi(cords[3]) - 1;
        g.sourceV = (stoi(cords[0])-1)*M + stoi(cords[1]) - 1;
        g.bonusFind();
        outputFile<<g.maxLadder<<endl;
        g.maxLadder = 0;
    }
    return 0;
}
