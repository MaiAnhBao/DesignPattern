/*
 * State.cpp
 *
 *  Created on: 26 déc. 2016
 *      Author: hnnguyen
 */

#include <iostream>

class HelloWorldMachine {
	class State *current;
public:
	HelloWorldMachine();
	void setCurrentState(State *s) {
		current = s;
	}

	void eng();
	void fr();
};

class State {
public:
	virtual void eng(HelloWorldMachine *m) {
		std::cout << "Bonjour tout le monde\n";//"Hello World\n";
	}

	virtual void fr(HelloWorldMachine *m) {
		std::cout << "Hello World\n" ;//"Bonjour tout le monde\n";
	}

	virtual ~State() = default;
};

void HelloWorldMachine::eng() {
	current->eng(this);
}

void HelloWorldMachine::fr() {
	current->fr(this);
}


class HelloWorldEng: public State {
public:
	HelloWorldEng() {
		std::cout << "Constructor Hello World Eng\n";
	}

	~HelloWorldEng() {
		std::cout << "Destructor Hello World Eng\n";
	}

	void eng(HelloWorldMachine *m);
};

class HelloWorldFr: public State {
public:
	HelloWorldFr() {
		std::cout << "Constructor Hello World Fr\n";
	}

	~HelloWorldFr() {
		std::cout << "Destructor Hello World Fr\n";
	}

	void fr(HelloWorldMachine *m) {
		std::cout << "Change from FR to ENG\n";
		m->setCurrentState(new HelloWorldEng());
		delete this;
	}
};

void HelloWorldEng::eng(HelloWorldMachine *m) {
	std::cout << "Change from ENG to FR\n";
	m->setCurrentState(new HelloWorldFr());
	delete this;
}

HelloWorldMachine::HelloWorldMachine() {
	current = new HelloWorldEng();
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	void(HelloWorldMachine:: *ptrs[])() = {
		&HelloWorldMachine::eng, &HelloWorldMachine::fr
	};
	HelloWorldMachine fsm;
	int num;
	while (1) {
		std::cout << "Enter 0/1: ";
		std::cin >> num;
		(fsm.*ptrs[num])();
	}
	return 0;
}
