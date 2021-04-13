#include <iostream>
#include <climits>
void matrix_chain_order(int* p, int** s, int** m, int n);
void print_optimal_output(int** s, int i, int j);
int main(int argc, char** argv) {
    int n;
    int* p;
    int** m;
    int** s;
    std::cin >> n;
    p = new int[n+1];
    m = new int*[n];
    for(int i = 0; i < n; i++) {
        m[i] = new int[n];
    }
    s = new int*[n];
    for(int i = 0; i < n; i++) {
        s[i] = new int[n];
    }
    for (int i = 0; i <= n; i++) {
        std::cin >> p[i];
    }
    matrix_chain_order(p, s, m, n);
//  used for viewing the tables:
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n; j++) {
//            std::cout << s[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std:: endl;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            std::cout << m[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
    std::cout << m[0][n-1] << std::endl;
    print_optimal_output(s, 0, n-1);
    std::cout << std::endl;
    
    delete[] p;
    for(int i = 0; i < n; i++)
        delete[] m[i];
    delete[] m;
    for (int i = 0; i < n-1; i++)
        delete[] s[i];
    delete[] s;
    return 0;
}

void matrix_chain_order(int* p, int**s, int**m, int n) {
    int j;
    int q;
    for (int i = 0; i < n; i++) {
        m[i][i] = 0;
    }
    for(int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i-1][j-1] = INT_MAX;
            for(int k = i; k <= j-1; k++) {
                q = m[i-1][k-1] + m[k][j-1] + (p[i-1] * p[k] * p[j]);
                if(q < m[i-1][j-1]){
                    m[i-1][j-1] = q;
                    s[i-1][j-1] = k;
                }
            }
        }
    }
}
void print_optimal_output(int** s, int i, int j) {
    if (i >= j)
        std::cout << "A" << i;
    else {
        std::cout << "(";        print_optimal_output(s, i, s[i][j]-1);
        print_optimal_output(s, s[i][j], j);
        std::cout << ")";
    }
}

//  example from book
//  6
//  30 35 15 5 10 20 25
//  0   4   3
//  0   2   1
//  ((a1(
//  0   1
