#include <iostream>
#include <string>

class Animal
{
public:
    std::string mouth;

    void eat();
    void sleep();
    void drool();
};

class Pig : public Animal
{
public:
    void climb();
};

class Turtle : public Animal
{
public:
    void swim();
};

void Animal::eat()
{
    std::cout << "I'm eatting!" << std::endl;
}

void Animal::sleep()
{
    std::cout << "I'm sleeping!Don't disturb me!" << std::endl;
}

void Animal::drool()
{
    std::cout << "���ǹ��ģ�����ĸ���һ�����ˮ������������ˮ������" << std::endl;
}

void Pig::climb()
{
    std::cout << "����һ��ֻƯ����Сĸ�����һ��������������������ꡣ����" << std::endl;
}

void Turtle::swim()
{
    std::cout << "����һֻС���㣬��ĸ����ץ�ҵ�ʱ���Ҿ��ε��������������" << std::endl;
}

int main()
{
    Pig pig;
    Turtle turtle;

    pig.eat();
    turtle.eat();
    pig.climb();
    turtle.swim();

    return 0;
}
