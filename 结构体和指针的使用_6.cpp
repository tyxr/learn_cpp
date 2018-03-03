#include <iostream>
#include <fstream>
#include <windows.h>         // 为了使用Sleep()函数

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
		std::cout << "请选择需要进行的操作: \n";
		std::cout << "1. 打印数据到屏幕\n";
		std::cout << "2. 录入数据\n";
		std::cout << "3. 退出程序\n";
		std::cin >> i;

		switch( i )
		{
			case 1:
				if( ReadFishC() )
					std::cout << "成功读取文件^_^\n\n";
				else
					std::cout << "读取文件失败T_T\n\n";
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
		std::cout << "\n正在输出记录数据...... ";
		/*for( int i=0; i <= 100; i++ )      // 打印百分比
		{
			std::cout.width(3);
			std::cout << i << "%";
			Sleep(1);
			std::cout << "\b\b\b\b";
		}
		std::cout << "\n\n";*/


		std::cout << " 姓名 " << "  身份证  " << " 性别 " << "\n\n";

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
		std::cout << "请输入账号: ";
		std::cin >> OilData.name;
		std::cout << "请输入身份证：";
		std::cin >> OilData.uid;
		std::cout << "请输入性别：";
		std::cin >> OilData.sex;

		std::cout << "录入成功, 请问需要保存吗？（Y/N）";
		std::cin >> Save;
		if( 'Y' == Save )
		{
			pOilData = &OilData;
			if( WriteFishC( pOilData ) )
				std::cout << "成功写入文件^_^\n";
			else
				std::cout << "写入文件失败T_T\n";
		}
		else
		{
			return;
		}

		std::cout << "/n请问需要再次录入吗？（Y/N）";
		std::cin >> goon;
	}
}

bool WriteFishC( FishOil *pOilData )
{
	std::ofstream fileOutput("struct.txt", std::ios::app);
		// std::ios::app用来说明在老数据追加新数据
	if( fileOutput.is_open() )
	{
		fileOutput << pOilData->name << " ";
		fileOutput << pOilData->uid << " ";
		fileOutput << (*pOilData).sex << "\n";//指针表示法 

		fileOutput.close();
		std::cout << "数据成功保存到struct.txt\n\n";
	}
	else
		std::cout << "保存失败T_T\n";
}
