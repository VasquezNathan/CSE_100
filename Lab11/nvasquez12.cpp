#include <iostream>
#include <list>
#include <climits>
struct Vertex{
    int value;
    int weight;
};


int extractMin(std::list<Vertex> *graph, int size, int *parents, bool *inSearch, bool *visited);
void printGraph(std::list<Vertex> *graph, int size); // prints graph with weights
void mstPrim(std::list<Vertex> *graph, int size);

int main(int argc, char** argv) {
    int num_of_verticies;
    int num_of_edges;
    int source;
    int destination;
    int weight;
    std::list<Vertex> *graph;
    
    std::cin >> num_of_verticies;
    std::cin >> num_of_edges;

    graph =  new std::list<Vertex>[num_of_verticies];
    struct Vertex vertex;
    // read input
    for(int i = 0; i < num_of_edges; i++) {
        std::cin >> source >> destination >> weight;
        vertex = {destination, weight};
        graph[source].push_back(vertex);
        // vertex = {source, weight, INT_MAX, -1}; // this and the following line for undirectioned.
        // graph[destination].push_back(vertex);
    }
    printGraph(graph, num_of_verticies);
    std::cout << std::endl;

    mstPrim(graph, num_of_verticies);

    delete [] graph;
    return 0;
}

int extractMin(std::list<Vertex> *graph, int size, int *parents, bool *inSearch, bool *visited) {
    int min = INT_MAX;
    int index = 0;
    int child = 0;
    for (int i = 0; i < size; i++) {
        if (inSearch[i]) {
            for(std::list<Vertex>::iterator it = graph[i].begin(); it != graph[i].end(); ++it) {
                if ((*it).weight < min && !(inSearch[(*it).value])) {
                    min = (*it).weight;
                    child = (*it).value;
                    index++;
                }
            }
        }
    }

    inSearch[child] = true;
    parents[child] = index;
    for (int i = 0; i < size - 1; i++) {
        std::cout << parents[i] << " ";
    }
    std::cout << std::endl;
    return index;
}

void mstPrim(std::list<Vertex> *graph, int size) {
    bool inSearch[size];
    bool visited[size];
    int parents[size-1];
    int u;
    for (int i = 0; i < size; i++) {
        inSearch[i] = false;
        visited[i] = false;
    }
    inSearch[0] = true;
    for (int i = 0; i < size; i++) {
        extractMin(graph, size, parents, inSearch, visited);
    }
   

}

void printGraph(std::list<Vertex> *graph, int size) {
    for(int i = 0; i < size; i++) {
        std::cout << i;
        for(std::list<Vertex>::iterator it = graph[i].begin(); it != graph[i].end(); ++it) {
            std::cout << " (" << (*it).weight << ")-> " << (*it).value;
        }
        std::cout << std::endl;
    }
}

/*
test case from instructions:

9
14
0 1 40
0 7 85
1 2 80
1 7 110
2 3 70
2 5 45
2 8 22
3 4 90
3 5 140
4 5 100
5 6 25
6 7 10
6 8 60
7 8 75
*/