#include <iostream>
#include <list>
#include <iterator>



int main(int argc, char ** argv) {

    int m = 0;
    char operation;
    std::cin >> m;

    std::list<std::list<int>> table;
    std::list<int>::iterator it_table;
    std::list<std::list<int>>::iterator it_chain;

    table.resize(m);

    int test;
    std::cin.get(operation);
   // std:: cin >> test;
    

    std::cout << operation << " " <<  std::endl;




    return 0;
}