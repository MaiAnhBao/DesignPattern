/*
 * ChainResponsibility.cpp
 *
 *  Created on: 26 déc. 2016
 *      Author: hnnguyen
 */


#include <iostream>

class HelloWorldBase {
	HelloWorldBase* next;
public:
	HelloWorldBase() {
		next = 0;
	}

	virtual ~HelloWorldBase() = default;

	void setNext(HelloWorldBase* n) {
		next = n;
	}

	void add(HelloWorldBase* n) {
		if (next)
			next->add(n);
		else
			next = n;
	}
	virtual void handle(int i) {
		next->handle(i);
	}
};

class HelloWorldEnglish: public HelloWorldBase {
public:
	void handle(int i) {
		if (i % 3 == 0) {
			std::cout << "HelloWorld English " << i << std::endl;
			HelloWorldBase::handle(i);
		} else {
			std::cout << "Hello World\n";
		}
	}
};

class HelloWorldFrench: public HelloWorldBase {
public:
	void handle(int i) {
		if (i % 3 == 1) {
			std::cout << "HelloWorld French " << i << std::endl;
			HelloWorldBase::handle(i);
		} else {
			std::cout << "Bonjour tout le monde\n";
		}
	}
};

class HelloWorldSpanish: public HelloWorldBase {
public:
	void handle(int i) {
		if (i % 3 == 2) {
			std::cout << "HelloWorld Spanish " << i << std::endl;
			HelloWorldBase::handle(i);
		} else {
			std::cout << "Hola el mundo\n";
		}
	}
};

int main(int argc, char **argv) {
	HelloWorldEnglish root;
	HelloWorldFrench two;
	HelloWorldSpanish thr;
	root.add(&two);
	root.add(&thr);
	thr.setNext(&root);
	for (int i = 0; i < 10; ++i) {
		root.handle(i);
		std::cout << std::endl;
	}
	return 0;
}
