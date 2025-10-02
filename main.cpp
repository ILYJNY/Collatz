#include <any>
#include <iostream>
#include <string>
#include "cmath"
#include "vector"
#include "ctime"
#include "fstream"

using namespace std;
//
// struct judgetf {
//     unsigned long long x;
//     unsigned long long y;
// };
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
std::vector<unsigned long long> CRS(unsigned long long n) {//CRS = Complete Residue System
    std::vector<unsigned long long> v;
    for (unsigned long long i = 0; i < n; i++) {
        cout << i;
        v.push_back(i);
    }
    return v;
}
struct modifier {
    unsigned long long r;
    unsigned long long N;
};

void onedimvector(std::vector<auto> v) {
    cout << endl << "[";
    for (unsigned long long i = 0; i < v.size(); i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << "]" << std::endl;
}
//
// bool tf(judgetf B) {00000000000000000000000000000000000000000000000000
//
// }
modifier moderation(unsigned long long R,unsigned long long n) {
    return {R%n,n};
}
unsigned long long collatz(unsigned long long n) {
    if (n % 2 == 1) return 3 * n + 1;
    else return n / 2;
}
unsigned long long expended_collatz(unsigned long long n) {
    if (n%2 == 1) return (3 * n + 1)/2;
    else return n/2;
}
int main() {
    clock_t start, end;
    start = clock();
    unsigned long long n;
    std::cin >> n;
    // while (n != 1) {
    //     std::cout << n << std::endl;
    //     n = collatz(n);
    // }
    // std::cout << 1 << std::endl;

    for (unsigned long long i = 1; i <= n; i++) {
        vector<unsigned long long> lists;
        unsigned long long k = i;
        bool breaking = true;
        while (breaking) {


            for (unsigned long long j : lists) {
                if (j == moderation(k,n).r) {

                    breaking = false;// 루프 종료
                    cout << i << j << breaking << endl;
                }
            }
            onedimvector(lists);
            cout << k  << "," << moderation(k,n).r << endl;
            lists.push_back(moderation(k,n).r);
            k = collatz(k);
        }
        cout << i << "============================" << endl;

    }


    end = clock();
    long double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time : " << time_spent << "s" << endl;
    return 0;
}