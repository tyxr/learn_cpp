#include <iostream>

int main()
{
      char answer;

      std::cout << "���Ը�ʽ������Ӳ����?[Y/N]";
      std::cin >> answer;
      std::cout << "\n";

      switch( answer )
      {
      case 'Y':
      case 'y':
            std::cout << "ѡ�����" << "\n";
            break;

      case 'N':
      case 'n':
            std::cout << "����ѡ������ȷ��, Ӳ�̲�������ʽ��!" << "\n";
            break;

      default:
            std::cout << "������[Y/N]�ش����⡣" << "\n";
            break;
      }

      std::cout << "�����������������!" << "\n";
      std::cin.get();
      std::cin.ignore(100, '\n');

      return 0;
}
