/*
 * TemplateMethodHelloWord.cpp
 *
 *  Created on: 22 déc. 2016
 *      Author: hnnguyen
 */

#include <iostream>
#include <vector>
#include <memory>

class HelloWorldBase {
protected:
	virtual void sayGreeting() = 0;

public:
	virtual ~HelloWorldBase() = default;
	void execute() {
		sayGreeting();
	}
};

class HelloWorldEnglish: public HelloWorldBase {
	void sayGreeting() {
		std::cout << "Hello World\n";
	}
};

class HelloWorldFrench: public HelloWorldBase {
	void sayGreeting() {
		std::cout << "Bonjour tout le monde\n";
	}
};

class HelloWorldSpanish: public HelloWorldBase {
	void sayGreeting() {
		std::cout << "Hola el mundo\n";
	}
};

int main(int argc, char **argv) {
	std::vector<std::unique_ptr<HelloWorldBase>> array;
	array.emplace_back(new HelloWorldEnglish);
	array.emplace_back(new HelloWorldFrench);
	array.emplace_back(new HelloWorldSpanish);
//	HelloWorldBase *array[] = {
//			new HelloWorldEnglish(),
//			new HelloWorldFrench()};
//	for (int i = 0; i < 2; ++i) {
//		array[i]->execute();
//		delete array[i];
//	}
	for (auto& x: array) {
		x->execute();
	}
	return 0;
}
