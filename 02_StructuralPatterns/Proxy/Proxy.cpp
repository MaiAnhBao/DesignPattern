/*
 * Proxy.cpp
 *
 *  Created on: 26 déc. 2016
 *      Author: hnnguyen
 */
#include <iostream>

class HelloWorld {
public:
	virtual void sayGreeting() = 0;
	virtual ~HelloWorld() = default;
};

class HelloWorldReal: public HelloWorld {
	std::string str;
public:
	HelloWorldReal(std::string s) {
		str = s;
	}

	void sayGreeting() {
		std::cout << str << std::endl;
	}
};

class HelloWorldProxy: public HelloWorld {
	std::string str;
	HelloWorldReal* ptr;
public:
	HelloWorldProxy(std::string s) {
		if (s == "fr")
			ptr = new HelloWorldReal("Bonjour tout le monde");
		else
			ptr = new HelloWorldReal("Hello World");
	}

	~HelloWorldProxy() {
		delete ptr;
	}

	void sayGreeting() {
		ptr->sayGreeting();
	}
};

int main(int argc, char **argv) {
#ifdef FR
	HelloWorldProxy obj("fr");
#else
	HelloWorldProxy obj("en");
#endif
	obj.sayGreeting();
	return 0;
}
