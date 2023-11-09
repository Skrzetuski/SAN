#include <random>
#include <thread>
#include <chrono>
#include <iostream>
#include "PasswordManager.hpp"

PasswordManager::PasswordManager(){};

int generate_number_in_range(int start, int end){
  default_random_engine engine(random_device{}());
  uniform_int_distribution<int> dist(start, end);
  return dist(engine);
}

void PasswordManager::run(){
    while(choice){
        system("clear");
        switch (managerState){
            case MAIN:
                execMain();
                break;
            case GENERATE:
                execGenerate();
                break;
            case HISTORY:
                execHistory();
                break;
        }
    }
}

void PasswordManager::execHistory(){
    printScreen(historyScreen);

    for (auto password : generatedPasswords){
      cout << password << endl;
    }
    cout << "Wciśnij dowolny klawisz by wrócić do menu: ";
    cin.get();
    cin.get();
    managerState = MAIN;
  }

void PasswordManager::execMain(){
    printScreen(mainScreen);
    cin >> choice;
    if (choice == 1){
      managerState = GENERATE;
    }
    else if (choice == 2){
      managerState = HISTORY;
    }
  }

void PasswordManager::execGenerate(){
    printScreen(generateScreen);
    cin >> choice;
    switch (choice){
    case 1 ... 4:
      passwordOptions.at(choice) = !passwordOptions.at(choice);
      break;
    case 5:
      cout << "Podaj długość hasła: ";
      cin >> lenght;
      cout << lenght << endl;
      cout << generate() << endl;
      cout << "Powrót do Menu za 5 sekundy" << endl;
      this_thread::sleep_for(chrono::seconds(5));
      passwordOptions = {{1, false}, {2, false}, {3, false}, {4, false}};
    case 6:
      managerState = MAIN;
      return;
    }

    cout << "Wybrano opcje: ";
    for (auto &[key, value] : passwordOptions){
      if (value == true){
        cout << key << " ";
      }
    }
  }

  void PasswordManager::printScreen(const vector<string> &screenScreen){
    for (auto &output : screenScreen){
      cout << output << endl;
    }
  }

  string PasswordManager::generate(){
    int number = generate_number_in_range(1337, 2137);
    string password = "";
    for (int i = 0; i < lenght;){
      if (passwordOptions[number % 4 + 1]){
        password += functionGenerateChar[number % 4]();
        i++;
      }
      number++;
    }
    generatedPasswords.insert(password);
    return password;
  }