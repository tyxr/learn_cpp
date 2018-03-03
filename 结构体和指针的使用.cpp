#include <iostream>
#include <fstream>
#include <windows.h>         // Ϊ��ʹ��Sleep()����

struct FishOil
{
	std::string name;
	std::string uid;
	char sex;
};


bool ReadFishC();
void RecordFishC();
bool WriteFishC(FishOil *OilData);

int main()
{
	int i;


	while( 1 )
	{
		std::cout << "��ѡ����Ҫ���еĲ���: \n";
		std::cout << "1. ��ӡ���ݵ���Ļ\n";
		std::cout << "2. ¼������\n";
		std::cout << "3. �˳�����\n";
		std::cin >> i;

		switch( i )
		{
			case 1:
				if( ReadFishC() )
					std::cout << "�ɹ���ȡ�ļ�^_^\n\n";
				else
					std::cout << "��ȡ�ļ�ʧ��T_T\n\n";
				break;
			case 2:
				RecordFishC();
				break;
			case 3:
				return 0;
		}
	}



	return 0;

}

bool ReadFishC()
{
	std::string temp;
	std::ifstream fileInput("struct.txt");

	if( fileInput.is_open() )
	{
		std::cout << "\n���������¼����...... ";
		/*for( int i=0; i <= 100; i++ )      // ��ӡ�ٷֱ�
		{
			std::cout.width(3);
			std::cout << i << "%";
			Sleep(1);
			std::cout << "\b\b\b\b";
		}
		std::cout << "\n\n";*/


		std::cout << " ���� " << "  ���֤  " << " �Ա� " << "\n\n";

		while( std::getline( fileInput, temp ) )
		{
			std::cout << temp << "   ";
			std::cout << "\n";
		}
		std::cout << "\n\n";

		return true;
	}
	else
		return false;
}

void RecordFishC()
{
	char goon, Save;
	FishOil OilData;
	FishOil *pOilData;

	goon = 'Y';
	while( 'Y' == goon )
	{
		std::cout << "�������˺�: ";
		std::cin >> OilData.name;
		std::cout << "���������֤��";
		std::cin >> OilData.uid;
		std::cout << "�������Ա�";
		std::cin >> OilData.sex;

		std::cout << "¼��ɹ�, ������Ҫ�����𣿣�Y/N��";
		std::cin >> Save;
		if( 'Y' == Save )
		{
			pOilData = &OilData;
			if( WriteFishC( pOilData ) )
				std::cout << "�ɹ�д���ļ�^_^\n";
			else
				std::cout << "д���ļ�ʧ��T_T\n";
		}
		else
		{
			return;
		}

		std::cout << "/n������Ҫ�ٴ�¼���𣿣�Y/N��";
		std::cin >> goon;
	}
}

bool WriteFishC( FishOil *pOilData )
{
	std::ofstream fileOutput("struct.txt", std::ios::app);
		// std::ios::app����˵����������׷��������
	if( fileOutput.is_open() )
	{
		fileOutput << pOilData->name << " ";
		fileOutput << pOilData->uid << " ";
		fileOutput << (*pOilData).sex << "\n";//ָ���ʾ�� 

		fileOutput.close();
		std::cout << "���ݳɹ����浽struct.txt\n\n";
	}
	else
		std::cout << "����ʧ��T_T\n";
}
