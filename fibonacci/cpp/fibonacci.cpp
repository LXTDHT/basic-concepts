#include <iostream>

const int N = 10; // Set the number of iterations here.

int main(int argc, char* argv[]) {
    int f[N]; f[0] = 0; f[1] = 1; f[2] = 1;

    for (auto i = 3; i < N; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }

    for (auto i = 0; i < N; ++i) {
        std::cout << f[i] << std::endl;
    }
}