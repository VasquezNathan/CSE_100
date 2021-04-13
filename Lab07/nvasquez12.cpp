#include <iostream>
#include <climits>
int main(int arc, char **argv) {
    int n;
    std::cin >> n;

    //user input size of rod and subsequent price table
    int *p;
    p = new int[n+1];
    //price of no rod should be 0
    p[0] = 0;
    for(int i = 1; i <= n; i++) {
        std::cin >> p[i];
    }

    // declare maximum revinue (r) and breakdown (s) arrays
    int *r;
    int *s;
    int q;
    r = new int[n+1];
    s = new int[n+1];
    s[0] = 0; // rod of zero inches should have revenue and breakdown of 0
    r[0] = 0;
    for(int i = 1; i <= n; i++) {
        q = INT_MIN;
        for(int j = 1; j <= i; j++) {
            if (q < (p[j] + r[i-j])) {
                q = p[j] + r[i-j];
                s[i] = j;
            }
        }
        r[i] = q;
    }

    // use for peaking inside of the breakdown (s) array
    // for(int i = 0; i <= n ; i++) {
    //     std::cout << s[i] << std::endl;
    // }

    std::cout << r[n] << std::endl;
    while (n > 0) {
        std::cout << s[n] << " ";
        n = n - s[n];
    }
    std::cout << -1 << std::endl;

    delete [] p;
    delete [] r;
    delete [] s;
    return 0;
}
// from example given in instructions: 7 1 5 8 9 10 17 17
// should return values 18, 1, 6