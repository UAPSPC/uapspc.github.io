// C++ Solution to Is it Even?
// See Python 3 solution for explaination.

#include <iostream>
#include <algorithm>

int n, k, e, x;

int main() {

    std::cin >> n >> k;

    for (int i = 0; i < n; i++) {
        std::cin >> x;
        while (x % 2 == 0) x /= 2, e++;
    }

    std::cout << (e >= k) << "\n";

    return 0;
}
