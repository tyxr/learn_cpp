#include <iostream>

int main()
{
	const unsigned short ITEM = 10;
	int num[ITEM];

	std::cout << "������" << ITEM << "����������!\n\n";

	for( int i=0; i < ITEM; i++ )
	{	
		std::cout << "�������" << i+1 << "������: ";

		while( !(std::cin >> num[i]) )
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "������һ���Ϸ���ֵ";
		}
	}

	int total = 0;
	
	for( int j=0; j < ITEM; j++ )
	{
		total += num[j];
	}

	std::cout << "�ܺ���: " << total << "\n";
	std::cout << "ƽ��ֵ��: " << (float)total / ITEM;
	std::cout << "\n";

	return 0;
}
