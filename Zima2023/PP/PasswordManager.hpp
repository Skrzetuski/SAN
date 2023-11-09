#include <vector>
#include <map>
#include <set>
#include <functional>
#include <string>

using namespace std;

// https://en.cppreference.com/w/cpp/numeric/random
int generate_number_in_range(int start, int end);

class PasswordManager {
public:
    PasswordManager();
    void run();

private:
    unsigned short int choice = 1;
    unsigned int lenght;
    enum STATE { MAIN, GENERATE, HISTORY};
    STATE managerState = MAIN;

    map<int, bool> passwordOptions = {{1, false}, {2, false}, {3, false}, {4, false}};
    set<string> generatedPasswords;

    vector<string> mainScreen = {"Wybierz element z menu",
                               "1. Generowanie hasła",
                               "2. Historia haseł",
                               "0. Koniec"};

    vector<string> generateScreen = {"\nPodaj, które znaki chcesz w haśle",
                                   "1. Małe litery [a-z]",
                                   "2. Duże litery [A-Z]",
                                   "3. Liczby [0-9]",
                                   "4. Znaki specjalne[&*][{}]",
                                   "5. Generuj",
                                   "6. Powrót",
                                   "0. Koniec"};

    vector<string> historyScreen = {"Historia wygenerowanych haseł"};

    vector<std::function<char(void)>> functionGenerateChar{
      [](){ return generate_number_in_range(97, 122); },
      [](){ return generate_number_in_range(65, 90); },
      [](){ return generate_number_in_range(33, 47); },
      [](){ return generate_number_in_range(48, 57); }};

    void execHistory();
    void execMain();
    void execGenerate();
    void printScreen(const vector<string> &screenScreen);
    string generate();
};