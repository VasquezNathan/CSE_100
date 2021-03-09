#include <iostream>
#include <list>
#include <iterator>

void insert(std::list<int> *table, int key, int m);
void Delete(std::list<int> *table, int key, int m);
void search(std::list<int> *table, int key, int m);
void output(std::list<int> *table, int m);
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
        if (operation == 'i') {
            std:: cin >> key;
            insert(table, key, m);
        }
            
        else if(operation == 'd') {
            std:: cin >> key;
            Delete(table, key, m);
        }
            
        else if(operation == 's') {
            std:: cin >> key;
            search(table, key, m);
        }
        else if(operation == 'o')
            output(table, m);
    }
        delete [] table;
        return 0;
}

void output(std::list<int> *table, int m) {
    for(int i = 0; i < m; i++) {
        std::cout << i << ":";
        for(std::list<int>::iterator it = table[i].begin(); it != table[i].end(); ++it) {
            std::cout << *it << "->";
        }
        std::cout << ";\n";
    }
}

void insert(std::list<int> *table, int key, int m) {
    table[hash(key, m)].push_front(key);
}

void search(std::list<int> *table, int key, int m) {
    int i = 0;
    for(std::list<int>::iterator it = table[hash(key,m)].begin(); it != table[hash(key,m)].end(); ++it) {
        if(*it == key) {
            std::cout << key << ":FOUND_AT" << hash(key,m) << "," << i << ";\n";
            return;
        }
        i++;
    }
    std::cout << key << ":NOT_FOUND;\n";
}

void Delete(std::list<int> *table, int key, int m) {
    for(std::list<int>::iterator it = table[hash(key,m)].begin(); it != table[hash(key,m)].end(); ++it) {
        if(*it == key) {
            table[hash(key,m)].erase(it);
            std::cout << key << ":DELETED;\n";
            return;
        }
    }
    std::cout << key << ":DELETE_FAILED;\n";
}

int hash(int key, int m) {
    return key % m;
}
