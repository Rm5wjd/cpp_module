#include "Cat.hpp"
#include "Dog.hpp"

void f()
{
	system("leaks brain");
}

int main()
{
	atexit(f);
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Cat c1;
	Cat c2 = c1;
	Cat c3;
	c3 = c1;

	delete j;//should not create a leak
	delete i;

	// ...
	std::cout << "\n\n\n-------------------------------new test------------------------------------------\n\n\n" << std::endl;
	Animal* aniArr[10];
	for (int i = 0; i < 10; i++) {
		if (i < 5)
			aniArr[i] = new Dog();
		else
			aniArr[i] = new Cat();
	}

	for (int i = 0; i < 10; i++) {
		delete aniArr[i];
	}

	return 0;
}