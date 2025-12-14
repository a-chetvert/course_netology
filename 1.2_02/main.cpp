/**
 * @brief ���� � ����� �����
 * @note  Please, reopen with Encoding Cyrilic(Windows-1251)
 */
#include <Windows.h>
#include <iostream>

using namespace std;

int main() {
  string word;

  SetConsoleCP(1251);         // ��������� ������� �������� win-cp 1251 � ����� �����
  SetConsoleOutputCP(1251);   // ��������� ������� �������� win-cp 1251 � �����
                              // ������ char string[20];
  cout << "������� �����:" << endl;  // ����� ������

  cin >> word;  // ������ ������, ��������� ���������
  cout << "�� �����:\n" << word << endl;  // ����� ������

  return 0;
}
