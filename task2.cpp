#include <iostream>
#include <string>
#include <array>

using namespace std;

int main() {
    const int N = 8;
    array<string, N> words;

    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    size_t sum = 0;

    cout << "Елементи на парних місцях:\n";

    for (int i = 1; i < N; i += 2) {
        cout << i + 1
             << ". "
             << words[i]
             << " — довжина "
             << words[i].length()
             << '\n';

        sum += words[i].length();
    }

    cout << "\nСума довжин елементів на парних місцях: "
         << sum << '\n';

    return 0;
}
