#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void f() {
	system("leaks Polymorphism");
}

int main()
{
	atexit(f);
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	// ...
	std::cout << "\n----------------------------------------------------\n" << std::endl;

	const WrongAnimal* w_Meta = new WrongAnimal();
	const WrongAnimal* w_Cat = new WrongCat();
	std::cout << w_Cat->getType() << " " << std::endl;
	std::cout << w_Meta->getType() << " " << std::endl;
	w_Cat->makeSound();
	w_Meta->makeSound();
	delete w_Meta;
	delete w_Cat;

	return 0;
}