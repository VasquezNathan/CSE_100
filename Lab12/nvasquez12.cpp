#include <iostream>
#include <list>
#include <climits>

struct Vertex {
    int value;
    int weight;
};
void BellmanFord(std::list<Vertex> *graph, int size);
int main(int argc, char** argv) {
    int num_of_verticies;
    int num_of_edges;
    int weight;
    int source;
    int destination;
    std::list<Vertex> *graph;

    std::cin >> num_of_verticies >> num_of_edges;
    graph = new std::list<Vertex>[num_of_verticies];

    struct Vertex vertex;
    for (int i = 0; i < num_of_edges; i++) {
        std::cin >> source >> destination >> weight;
        vertex = {destination, weight};
        graph[source].push_back(vertex);
    }

    BellmanFord(graph, num_of_verticies);

    delete [] graph;
    return 0;
}

void BellmanFord(std::list<Vertex> *graph, int size) {
    int distances[size];
    for (int i = 1; i < size; i++)
        distances[i] = INT_MAX;
    distances[0] = 0;

    for (int i = 0; i < size; i++) {
        for (std::list<Vertex>::iterator it = graph[i].begin(); it != graph[i].end(); ++it) {
            if (distances[i] != INT_MAX && (distances[i] + (*it).weight) < distances[(*it).value])
                distances[(*it).value] = distances[i] + (*it).weight;
        }
    }
    for (int i = 0; i < size; i++) {
        for (std::list<Vertex>::iterator it = graph[i].begin(); it != graph[i].end(); ++it) {
            if (distances[i] != INT_MAX && (distances[i] + (*it).weight) < distances[(*it).value]){
                std::cout << "FALSE";
                return;
            }
        }
    }
    
    std::cout << "TRUE" << std::endl;
    for (int i = 0; i < size; i++) {
        if (distances[i] != INT_MAX)
            std::cout << distances[i] << std::endl;
        else
            std::cout << "INFINITY";
    }

}



/*
input from example
6 10
0 1 6
1 2 5
1 3 -4
1 4 8
2 1 -2
3 0 2
3 2 7
3 4 9
4 0 7
5 2 5

6 11
0 1 6
1 2 5
1 3 -4
1 4 8
2 1 -2
3 0 2
3 2 7
3 4 9
3 5 -14
4 0 7
5 2 5

*/