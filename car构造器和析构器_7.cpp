#include <iostream>
#include <windows.h>

#define FULL_GAS 85

class Car
{
public:	
	std::string  color;
	std::string  engine;
	unsigned int  gas_tank;
	unsigned int  wheel;
	
	Car(void);
	void setColor(std::string col);	
	void setEngine(std::string eng);
	void setWheel(unsigned int whe);
	void fillTank(int  liter); 
	int running(void);
	void warning(void); 
}; 

Car::Car(void)
{
	color = "While";
	engine = "V8";
	wheel = 4;
	gas_tank = FULL_GAS;
}

void Car::setColor(std::string col)
{
	color = col;
}

void Car::setEngine(std::string eng)
{
	engine = eng;	
}

void Car::setWheel(unsigned int whe)
{
	wheel = whe;
}

void Car::fillTank(int  liter)
{
	gas_tank += liter;
}

int Car::running(void)
{
	char i;
	
	std::cout << "��������120��ʱ����ǰ�ƶ�������Խ���Ǹ�ɽԽ���Ǻӡ�����\n";
	gas_tank--;
	std::cout << "��ǰ��ʣ " << 100*gas_tank/FULL_GAS << "%" << "����!\n";	
	 
	if( gas_tank < 10 )
	{
		std::cout << "�����Ƿ���Ҫ����������ʻ?(Y/N)\n";
		std::cin >> i;
		if( 'Y' == i || 'y' == i )
		{
			fillTank(FULL_GAS);
		}
		
		if( 0 == gas_tank )
		{
			std::cout << "��ê�С�����������";
			return 1;
		} 
	}
		
	return 0;	
}

void Car::warning(void) 
{
	std::cout << "WARNING!!" << "��ʣ " << 100*gas_tank/FULL_GAS << "%" << "����!";	
}
 
int main()
{
	Car mycar;

	while( !mycar.running() )
	{
		;	
	}
	
	return 0;
}
