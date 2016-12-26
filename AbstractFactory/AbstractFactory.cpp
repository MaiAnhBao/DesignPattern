/*
 * AbstractFactory.cpp
 *
 *  Created on: 22 déc. 2016
 *      Author: hnnguyen
 */

#include <iostream>

class HelloWorld {
public:
	virtual void sayGreeting() = 0;
	virtual ~HelloWorld() = default;
};

class HelloWorldEnglish: public HelloWorld {
public:
	void sayGreeting() {
		std::cout << "Hello World\n";
	}
};

class HelloWorldFrench: public HelloWorld {
public:
	void sayGreeting() {
		std::cout << "Bonjour tout le monde\n";
	}
};

class HelloWorldSpanish: public HelloWorld {
public:
	void sayGreeting() {
		std::cout << "Hola el mundo\n";
	}
};

class Factory {
public:
	virtual HelloWorld *createGreetingSentence() = 0;
	virtual ~Factory() = default;
};

class HelloWorldEnglishFactory: public Factory {
public:
	HelloWorld *createGreetingSentence() {
		return new HelloWorldEnglish;
	}
};

class HelloWorldFrenchFactory: public Factory {
public:
	HelloWorld *createGreetingSentence() {
		return new HelloWorldFrench;
	}
};

class HelloWorldSpanishFactory: public Factory {
public:
	HelloWorld *createGreetingSentence() {
		return new HelloWorldSpanish;
	}
};

class Printing {
private:
	Factory *factory;
public:
	Printing(Factory *f) {
		factory = f;
	}

	void sayGreeting() {
		HelloWorld * helloWorld = factory->createGreetingSentence();
		helloWorld->sayGreeting();
	}


};

int main(int argc, char **argv) {
	Factory *factory;
#ifdef ES
	factory = new HelloWorldSpanishFactory;
#elif FR
	factory = new HelloWorldFrenchFactory;
#else
	factory = new HelloWorldEnglishFactory;
#endif
	Printing *p = new Printing(factory);
	p->sayGreeting();
	return 0;
}
