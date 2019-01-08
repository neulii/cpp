#include <iostream>
#include <vector>

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
	
	
	Rectangle *rr = new Rectangle(10, 10);


	DrawingObject *r = new DrawingObject(10, 2);

	

	std::vector<ViewAble *> objects;

	objects.push_back(r);
	objects.push_back(rr);


	for (int i = 0; i < objects.size(); i++) {

		objects.at(i)->showObjectToConsole();

	}


	
	


	system("PAUSE");
	return 0;
}