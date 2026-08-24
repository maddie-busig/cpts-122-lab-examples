#include <iostream>

class Animal {
public:
	/*virtual void speak() {
		std::cout << "Animal speak" << std::endl;
	}*/

	void speak() {
		std::cout << "Animal speak" << std::endl;
	}
};

class Dog : public Animal {
public:
	/*void speak() override {
		std::cout << "BARK!!!" << std::endl;
	}*/

	void speak() {
		std::cout << "BARK!!!" << std::endl;
	}
};

class Cat : public Animal {
public:
	/*void speak() override {
		std::cout << "Meow. -m-" << std::endl;
	}*/

	void speak() {
		std::cout << "Meow. -m-" << std::endl;
	}
};

int main() {

	std::cout << "Cat and dog directly:" << std::endl;
	Dog* dog = new Dog;
	dog->speak();

	Cat* cat = new Cat;
	cat->speak();

	Animal* dog_as_pani = dog;
	Animal* cat_as_pani = cat;

	std::cout << "Cat and dog w/ downcast:" << std::endl;

	dog_as_pani->speak();
	cat_as_pani->speak();

	std::cout << "Dog as animal (no ptr):" << std::endl;

	Animal dog_as_ani = *dog;

	dog_as_ani.speak();

	std::cout << "Animal as dog (static): " << std::endl;

	Animal* animal = new Animal;
	Dog* animal_as_dog = (Dog*)animal;

	animal_as_dog->speak();

	std::cout << "Animal as dog (dynamic): " << std::endl;

	/*Dog* animal_as_ddog = dynamic_cast<Dog*>(animal);

	animal_as_ddog->speak();*/

	return 0;
}

