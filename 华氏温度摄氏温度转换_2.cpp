#include <iostream>
int main()
{
	//华氏温度==摄氏温度*9.0/5.0 + 32
	const unsigned short Constant = 32;
	const double Rate = 9.0/5.0; 
	double input ,output;
	char type_in,type_out;
	std::cout<<"请输入要转换的温度格式 XX.X F或者XX.X C"<<"\n";
	std::cin>>input>>type_in;
	std::cin.ignore(100,'\n');
	
	switch(type_in)
	{
		case 'F':
		case 'f':
			std::cout<<(input-32)/Rate<<" "<<"C";
			break;
		case 'C':
		case 'c':
			std::cout<<input*Rate+32<<" "<<"F";
			break;
		default:
			std::cout<<"您的输入有误导致程序爆炸坏掉啦";
			break;
		
	}
	
}
