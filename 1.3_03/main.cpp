/**
 * @brief Задание 3*. Гороскоп.
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.3/03
 * @warning Please, reopen with Cyrilic(Windows1251)
 */
#include <iostream>

#define NUM_ZODIAC 3
#define VSCODE 
#ifdef VSCODE
  #include <Windows.h>
  #include <locale.h>
#endif

using namespace std;

int main() {

#ifdef VSCODE
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
#endif    

  char sex {0};
  int age {0};
  string zodiac;
  string zodiacWater[NUM_ZODIAC]={"рак", "скорпион","рыбы"};
  string zodiacEarth[NUM_ZODIAC]={"телец", "дева","козерог"};
  
  cout << "Введите пол: ";
  cin >> sex;

  cout << "Введите знак зодиака: ";
  cin >> zodiac;

  cout << "Введите возраст: ";
  cin >> age;

  cout << "Ваше предсказание:" << endl;

  switch (sex)
  {
  case 'м':
    if((age < 40) && (zodiac == zodiacWater[0] || zodiac == zodiacWater[1] || zodiac == zodiacWater[2])){
      cout << "Сегодня очень плодотворный день. Можно добиться того, что прежде казалось почти невозможным.\n";
    }
    else 
      cout << "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)";
    break;
  
  case 'ж':
    if((age >= 15)&&(age <= 30) && (zodiac == zodiacEarth[0] || zodiac == zodiacEarth[1] || zodiac == zodiacEarth[2])){
      cout << "Сегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок.";
      cout << "\nБудет не только весело, но и интересно: найдётся дело, которое увлечёт всех.";
    }
    else 
      cout << "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)";
    break;

  default:
    cout << "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)";
    break;
  }
  
  return EXIT_SUCCESS;
}
