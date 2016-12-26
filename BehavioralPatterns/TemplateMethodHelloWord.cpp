/*
 * TemplateMethodHelloWord.cpp
 *
 *  Created on: 22 déc. 2016
 *      Author: hnnguyen
 */

#include <iostream>

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

int main(int argc, char **argv) {
	HelloWorldBase *array[] = {
			new HelloWorldEnglish(),
			new HelloWorldFrench()};
	for (int i = 0; i < 2; ++i) {
		array[i]->execute();
		delete array[i];
	}

	return 0;
}
