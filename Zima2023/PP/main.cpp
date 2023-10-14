/*
Program do generowania haseł.
Rozwijany na każdych kolejnych zajęciach.
Kompilowanie i uruchomienie: clang++ -std=c++20 main.cpp && ./a.out
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){

  vector<string> options = {"Podaj, które znaki chcesz w haśle",
                            "1. Małe litery [a-z]",
                            "2. Duże litery [A-Z]",
                            "3. Liczby [0-9]",
                            "4. Znaki specjalne[&*][{}]",
			    "0. Koniec"};
			    
  unsigned short int choice = 100;
  
  while(choice){
    for (auto &output : options){
        cout<<output<<endl;
      }
      
    cin>>choice;
    cout<<"Wybrano opcje: "<<choice<<"\n\n";
      
  }

			                      
}
