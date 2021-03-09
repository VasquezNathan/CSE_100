#include <iostream>
#include <list>
#include <iterator>

void insert(std::list<int> *table, int key, int m);
void Delete(std::list<int> *table, int key, int m);
void search(std::list<int> *table, int key, int m);
void output(std::list<int> *table, int key, int m);
int hash(int key, int m);

int main(int argc, char ** argv) {

    int m;
    char operation;
    int key;
    std::list<int> *table;
    std::cin >> m;

    table = new std::list<int>[m];
    std::list<int>::iterator it_chain;
    
    for(;;) {
        std::cin >> operation;

        if (operation == 'e') {
            delete [] table;
            return 0;
        }
        std:: cin >> key;
        if (operation == 'i')
            insert(table, key, m);
        else if(operation == 'd')
            Delete(table, key, m);
        else if(operation == 's')
            search(table, key, m);
        else if(operation == 'o')
            output(table, key, m);
    }
        delete [] table;
        return 0;
}

void output(std::list<int> *table, int key, int m) {
    for(int i = 0; i < m; i++) {
        for(std::list<int>::iterator it = table[i].begin(); it != table[i].end(); ++it) {
            std::cout << i << ":" << *it << "->";
        }
        std::cout << ";\n";
    }
}

void insert(std::list<int> *table, int key, int m) {
    table[hash(key, m)].push_back(key);
}

void search(std::list<int> *table, int key, int m) {
    int i = 0;
    for(std::list<int>::iterator it = table[hash(key,m)].begin(); it != table[hash(key,m)].end(); ++it) {
        if(*it == key) {
            std::cout << key << "FOUND_AT" << hash(key,m) << "," << i << ";\n"; 
            return;
        }
        i++;
    }
    std::cout << key << "NOT_FOUND;\n";
}

void Delete(std::list<int> *table, int key, int m) {
    int x = table[hash(key,m)].size();
    table[hash(key,m)].remove(key);
    if(table[hash(key,m)].size() != x)
        std::cout << key << "DELETED;\n";
    else
        std::cout << key << "DELETE_FAILED;\n";
}

int hash(int key, int m) {
    return key % m;
}