/*
 * HelloWorldFactory.cpp
 *
 *  Created on: 21 déc. 2016
 *      Author: hnnguyen
 */

#include <iostream>

class HelloWorldBase {
public:
	static HelloWorldBase* getInstance(std::string type);
	virtual void sayHelloWorld() = 0;
	virtual ~HelloWorldBase() = default;
};

class HelloWorldEnglish: public HelloWorldBase {
public:
	void sayHelloWorld() {
		std::cout << "Hello World\n";
	}
};

class HelloWorldFrench: public HelloWorldBase {
public:
	void sayHelloWorld() {
		std::cout << "Bonjour tout le monde\n";
	}
};

class HelloWorldSpanish: public HelloWorldBase {
public:
	void sayHelloWorld() {
		std::cout << "Hola el mundo\n";
	}
};

HelloWorldBase *HelloWorldBase::getInstance(std::string type) {
	if (type == "fr")
		return new HelloWorldFrench;
	else if (type == "es")
		return new HelloWorldSpanish;
	else
		return new HelloWorldEnglish;
}

int main(int argc, char **argv) {
	HelloWorldBase *helloWorldSpanish = HelloWorldBase::getInstance("es");// new HelloWorldDerivative;
	HelloWorldBase *helloWorldFrench  = HelloWorldBase::getInstance("fr"); //= new HelloWorldFrench;
	HelloWorldBase *helloWorldEnglish  = HelloWorldBase::getInstance("");
	helloWorldSpanish->sayHelloWorld();
	helloWorldFrench->sayHelloWorld();
	helloWorldEnglish->sayHelloWorld();
	return 0;
}
