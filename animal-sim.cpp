// animal-sim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class animal {
public:
	virtual void fight() = 0;
	virtual void move() = 0;
	virtual void test() {
		cout << "test \n";
	}
};
class land : public animal {
public:
	virtual void move() {
		cout << "chose direct" << endl;
	}
	virtual void fight() {
		cout << "do nothing" << endl;
	}
	virtual void test() {
		cout << "test ";
	}
protected:
	int health;
};

class herbivore : public land {
	friend class carnivorous;
public:
	virtual void fight() {
		cout << "This animal can't fight" << endl;
	}
};
class carnivorous : public land {
	friend class herbivore;
protected:
	int attack;
	void eat(herbivore & food) {
		this->health += food.health;
	}
public:
	virtual void fight() {

	}
};
class nosacz_sundajski : public herbivore {
public:
	nosacz_sundajski() {
		this->health = 10;
	}

};
class bison :public herbivore {
public:
	bison() {
		this->health = 20;
	}
};
class honey_badger : public herbivore {
public:
	honey_badger() {
		this->health = 5;
	}
};
class elephant : public herbivore {
public:
	elephant() {
		this->health = 50;
	}
};
class wolf : public carnivorous {
public:
	wolf() {
		this->health = 20;
		this->attack = 10;
	}
	void test() {
		cout << "wilk";
	}
};
class dog : public carnivorous {
public:
	dog() {
		this->health = 10;
		this->attack = 5;
	}
};
class lion : public carnivorous {
public:
	lion() {
		this->health = 25;
		this->attack = 15;
	}
};
class sabertooth : public carnivorous {
public:
	sabertooth() {
		this->health = 10;
		this->attack = 10;
	}
};
class map {
protected:
	unsigned int size_n;
	unsigned int size_m;

public:
	map() {
		cout << "podaj szerokosc pola"<<endl;
		cin >> this->size_n;
		cout << "podaj wysokosc pola"<<endl;
		cin >> this->size_m;
		
	}
};
class world :public map {
private:
	unsigned int wolf_number, sabertooth_number, lion_number, dog_number, elephant_number, bison_number, nosacz_number, badger_number;
	unsigned int animals;
	animal ***position;
public:
	world(): map() {
		animals = 0;
		cout << "podaj ilosc wilkow. max" << size_n * size_m << endl;
		cin >> wolf_number;
		animals += wolf_number;
		cout << "podaj ilosc szablozebych. max" << size_n * size_m - animals << endl;
		cin >> sabertooth_number;
		animals += sabertooth_number;
		cout << "podaj ilosc lwow. max" << size_n * size_m - animals << endl;
		cin >> lion_number;
		animals += lion_number;
		cout << "podaj ilosc psow. max" << size_n * size_m - animals << endl;
		cin >> dog_number;
		animals += dog_number;
		cout << "podaj ilosc sloni. max" << size_n * size_m << endl;
		cin >> elephant_number;
		animals += elephant_number;
		cout << "podaj ilosc bizonow. max" << size_n * size_m - animals << endl;
		cin >> bison_number;
		animals += bison_number;
		cout << "podaj ilosc nosaczy. max" << size_n * size_m - animals << endl;
		cin >> nosacz_number;
		animals += nosacz_number;
		cout << "podaj ilosc miodozerow. max" << size_n * size_m - animals << endl;
		cin >> badger_number;
		animals += badger_number;
		create_map();
		create_animal();
		show();
	}
	void create_map() {
		position = new animal**[size_m];
		for (int i = 0; i < size_m; i++) {
			position[i] = new animal*[size_n];
		}
	}
	void create_animal() {
		for (int i = 0; i < size_m; i++) {
			for (int j = 0; j < size_m; j++) {
				position[i][j]=new wolf();
			}
		}
	}
	void show() {
		for (int i = 0; i < size_m; i++) {
			for (int j = 0; j < size_m; j++) {
				position[i][j]->test();
			}
			cout << endl;
		}
	}
	virtual ~world() {
		for (int i = 0; i < size_m; i++) {
			for (int j = 0; j < size_m; j++) {
				delete position[i][j];
			}
			delete[] position[i];
		}
		delete position;
	}
};

int main(){
	srand(time(NULL));
	{
		world swiat;
	}
	getchar();
	getchar();
	return 0;
}
