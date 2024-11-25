#include <iostream>
using namespace std;

void welcome(int& choice, int& input);
void printCalc(int& choice, int& input);

int main() {
    int choice;
    int input;

    welcome(choice, input);

    if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        cout << "Blad: Wybrano zly system liczbowy. \n" << endl;
        main();
    }

    cout << endl;

    printCalc(choice, input);

    system("pause");
    return 0;
}

void printCalc(int& choice, int& input) {
    cout << "###################################### \n"
        << "\n    Dziesietne: "
        << "10" << "\n"
        << "\n    Dwojkowe: "
        << "2" << "\n"
        << "\n    Osemkowy: "
        << "8" << "\n"
        << "\n    Szestnastkowy: "
        << "16" << "\n"
        << "\n    Czy jest palindromem: "
        << "bool"
        << "\n"
        << "\n###################################### \n";
    system("pause");
    main();
}

void welcome(int& choice, int& input) {
    cout << "###################################### \n"
        << "Wybierz system liczbowy do zamiany: \n"
        << "    1 -> Dziesietny\n"
        << "    2 -> Dwojkowy\n"
        << "    3 -> Osemkowy\n"
        << "    4 -> Szesnastkowy\n"
        << "Twoj wybor: ";
    cin >> choice;

    cout << "Podaj liczbe: ";
    cin >> input;
    cout << "###################################### \n" << endl;
}