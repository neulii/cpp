#include <iostream>
#include <vector>

int pong_main();

class ViewAble {
public:
	virtual void showObjectToConsole() = 0;

};

class DrawingObject: public ViewAble {
protected:
	int x;
	int y;

public:
	DrawingObject(int x, int y) {
		this->x = x;
		this->y = y;
	}

	virtual void showObjectToConsole() {
		std::cout << "first class with viewable interface" << std::endl;

	}
	int getX() {
		std::cout << "drawing object" << std::endl;
		return x;
	}

	int getY() {
		return y;
	}

	void showAll() {
		std::cout << "zeige alles";
	}
};


class Rectangle :public DrawingObject, public ViewAble {
private:
	std::string name;

public: 
	Rectangle(int x, int y) :DrawingObject(x, y) {}
	Rectangle() :DrawingObject(0, 0) {}

	virtual void showObjectToConsole() {
		std::cout << "this is my interface: virtual function" << std::endl;

	}

	int getX(){
		std::cout << "rectangle" << std::endl;
		return x;
	}
	void showAll() {
		DrawingObject::showAll();
		std::cout << "und nun der rest";
	}
};



int main() {
	
	pong_main();



	
	return 0;
}