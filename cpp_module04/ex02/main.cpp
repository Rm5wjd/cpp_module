#include "Cat.hpp"
#include "Dog.hpp"

void f()
{
	system("leaks a.out");
}

int main()
{
	atexit(f);
	AAnimal *a = new Cat();
	// AAAnimal *b = new AAAnimal();

	a->makeSound();
	// ...

	delete a;
	std::cout << "\n\n\n-------------------------------new test------------------------------------------\n\n\n" << std::endl;
	AAnimal* aniArr[10];
	for (int i = 0; i < 10; i++) {
		if (i < 5)
			aniArr[i] = new Dog();
		else
			aniArr[i] = new Cat();
	}

	for (int i = 0; i < 10; i++) {
		aniArr[i]->makeSound();
	}

	for (int i = 0; i < 10; i++) {
		delete aniArr[i];
	}
	return 0;
}