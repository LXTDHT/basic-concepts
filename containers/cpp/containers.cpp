#include <stdio.h>
#include <iostream>

void cArray() {
    printf("* C array\n");

    // The length of a C array is fixed at initialization.
    int a[]{}, b[0];
    int c[]{ 2, 4, 6, 8 };
    int d[4]{ 2, 4, 6, 8 }; // full initialization
    
    int numbers[4];
    printf("\t> unpopulated:");
    for (auto i = 0; i < sizeof(numbers) / sizeof(numbers[0]); ++i) {
        printf("\t%d", numbers[i]);
        numbers[i] = (i + 1) * 2; // manually populating
    }

    printf("\n");
}

#include <array>
using namespace std;

// C++ array (sequential)
void cppArray() {
    cout << "* C++ array\n";

    // The length of a C++ array is fixed at initialization.
    array<int, 0> a, b{};
    array<int, 4> c{ 2, 4, 6, 8 }; // full initialization
    if (a.empty()) cout << "\tarray<int, 0> a;\t\tempty\n";
    else cout << "\tarray<int, 0> a;\t\tNOT empty\n";
    if (b.empty()) cout << "\tarray<int, 0> b{};\t\tempty\n";
    else cout << "\tarray<int, 0> b{};\t\tNOT empty\n";
    if (c.empty()) cout << "\tarray<int, 4> c{ 2, 4, 6, 8 };\tempty\n";
    else cout << "\tarray<int, 4> c{ 2, 4, 6, 8 };\tNOT empty\n";

    array<int, 4> numbers;
    if (numbers.empty()) cout << "\tarray<int, 4> numbers;\t\tempty\n";
    else cout << "\tarray<int, 4> numbers;\t\tNOT empty\n";
    cout << "\t> 'numbers':\t";
    for (auto i = 0; i < numbers.size(); ++i) {
        cout << "\t" << numbers[i];
        // Values can be assigned to a C++ array using the member function 'at'.
        numbers.at(i) = c[i];
    }
    cout << "\n\t> populated:\t";
    for (auto& n : numbers) { // Using the reference operator '&' allows value assignment.
        cout << "\t" << n;
        n *= n; // changing the values
    }
    cout << "\n\t> modified:\t";
    for (auto i = begin(numbers); i != end(numbers); ++i) {
        cout << "\t" << *i;
        *i = *i / 2; // changing the values
    }
    cout << "\n\t> halved & reversed:";
    for (auto i = numbers.end() - 1; i != numbers.begin() - 1; --i) {
        cout << "\t" << *i;
    }

    cout << "\n\t> front: " << numbers.front();
    cout << "\n\t> back: " << numbers.back();

    numbers.front() = 6; numbers.back() = 7;
    cout << "\n\tfront & back hard-coded to 6 & 7";
    cout << "\n\t> front: " << numbers.front();
    cout << "\n\t> back: " << numbers.back();

    numbers.swap(c);
    cout << "\n\t> 'numbers' swapped with 'c':";
    for (const auto n : numbers) {
        cout << "\t" << n;
    }

    numbers.fill(67);
    cout << "\n\t> 'numbers' filled with 67:";
    for (const auto n : numbers) { cout << "\t" << n; }

    cout << endl;
}

// C++ vector (sequential)
void cppVector() {
    cout << "* C++ vector\n";

    vector<int> a; // same as: vector<int> a{};
    if (a.empty()) cout << "\tvector<int> a;\t\tempty\n";
    else cout << "\tvector<int> a;\t\tNOT empty\n";
    
    // not safe for memory management
    vector<int> b[]{}; // b->size() == 0
    if (b->empty()) cout << "\tvector<int> b[]{};\tempty\n";
    else cout << "\tvector<int> b[]{};\tNOT empty\n";

    vector<int> c[0], d[0]{}, e = {}, f[] = {}, g[0] = {}, h = { 2, 4, 6, 8 };
    if (c->empty()) cout << "\tvector<int> c[0];\tempty\n";
    else cout << "\tvector<int> c[0];\tNOT empty\n";
    if (d->empty()) cout << "\tvector<int> d[0]{};\tempty\n";
    else cout << "\tvector<int> d[0]{};\tNOT empty\n";
    if (e.empty()) cout << "\tvector<int> e = {};\tempty\n";
    else cout << "\tvector<int> e = {};\tNOT empty\n";
    if (f->empty()) cout << "\tvector<int> f[] = {};\tempty\n";
    else cout << "\tvector<int> f[] = {};\tNOT empty\n";
    if (g->empty()) cout << "\tvector<int> g[0] = {};\tempty\n";
    else cout << "\tvector<int> g[0] = {};\tNOT empty\n";

    vector<int> numbers[4];
    if (numbers->empty()) cout << "\tvector<int> numbers[4];\tempty\n";
    else cout << "\tvector<int> numbers[4];\tNOT empty\n";

    cout << "\t> 'numbers':\t";
    for (auto i = 0; i < (*numbers).size(); ++i) {
        cout << "\t" << numbers->at(i);
    }
    *numbers = h;
    cout << "\n\t> populated:\t";
    for (auto& n : *numbers) { // Using the reference operator '&' allows value assignment.
        cout << "\t" << n;
        n *= n; // changing the values
    }
}

int main() {
    // cArray(); printf("\n");
    // cppArray(); printf("\n");
    cppVector();
}