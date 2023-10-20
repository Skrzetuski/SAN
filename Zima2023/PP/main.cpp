/*
Program do generowania haseł.
Rozwijany na każdych kolejnych zajęciach.
Kompilowanie i uruchomienie: clang++ -std=c++20 main.cpp && ./a.out
*/

#include <iostream>
#include <vector>
#include <random>

using namespace std;

// https://en.cppreference.com/w/cpp/numeric/random
int generate_number_in_range(int start, int end){

  default_random_engine engine(random_device{}());
  uniform_int_distribution<int> dist(start, end);
  return dist(engine);
}

char generate_special_char(){
  return generate_number_in_range(33, 47);
}

char generate_number(){
  return generate_number_in_range(48, 57);
}

char generate_letter(){
  return generate_number_in_range(97, 122);
}

int main(){

  vector<string> options = {"Podaj, które znaki chcesz w haśle",
                            "1. Małe litery [a-z]",
                            "2. Duże litery [A-Z]",
                            "3. Liczby [0-9]",
                            "4. Znaki specjalne[&*][{}]",
			    "0. Koniec"};
			    


  cout<<generate_special_char()<<endl;
  cout<<generate_number()<<endl;
  cout<<generate_letter()<<endl;
  cout<<char(toupper(generate_letter()))<<endl;

  // unsigned short int choice = 100;
  
  // while(choice){
  //   for (auto &output : options){
  //       cout<<output<<endl;
  //     }
      
  //   cin>>choice;
  //   cout<<"Wybrano opcje: "<<choice<<"\n\n";
      
  // }

			                      
}
