#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numeri = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::sort(numeri.begin(), numeri.end());

    for (const int& numero : numeri) {
        std::cout << numero << " ";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

bool confrontoPersonalizzato(int a, int b) {
    // Personalizza la logica di confronto
    return a > b;
}

int main() {
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};
    std::sort(numbers.begin(), numbers.end(), confrontoPersonalizzato);

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}



