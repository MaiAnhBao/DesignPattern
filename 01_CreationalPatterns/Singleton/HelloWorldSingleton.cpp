/*
 * HelloWorldSingleton.cpp
 *
 *  Created on: 21 déc. 2016
 *      Author: hnnguyen
 */

#include <iostream>

class HelloWorld {
private:
	std::string mGreetingSentence;
	static HelloWorld *mInstance;
	HelloWorld(std::string strGreetingSentence = "") {
		mGreetingSentence = strGreetingSentence;
	}

public:
	static HelloWorld *getInstance() {
		if (!mInstance) {
			mInstance = new HelloWorld;
		}
		return mInstance;
	}

	void setGreetingSentence(std::string str) {
		mGreetingSentence = str;
	}

	void sayHelloWorld() {
		std::cout << mGreetingSentence;
	}
};


HelloWorld *HelloWorld::mInstance = 0;

int main(int argc, char **argv) {
	HelloWorld::getInstance()->setGreetingSentence("Hello World\n");
	HelloWorld::getInstance()->sayHelloWorld();
	HelloWorld::getInstance()->setGreetingSentence("Bonjour Tout le monde\n");
	HelloWorld::getInstance()->sayHelloWorld();
	HelloWorld::getInstance()->setGreetingSentence("Hola el mundo\n");
	HelloWorld::getInstance()->sayHelloWorld();
	return 0;
}
