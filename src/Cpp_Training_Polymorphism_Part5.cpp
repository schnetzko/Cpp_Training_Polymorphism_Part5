//============================================================================
// Name        : Cpp_Training_Polymorphism_Part5.cpp
// Author      : Nico
// Version     :
// Copyright   : Your copyright notice
// Description : Testing Polymorphism in C++, Ansi-style
//============================================================================

// dynamic allocation and polymorphism
#include <iostream>
using namespace std;

// This is still an abstract base class, because it has at least one pure virtual function.
// But an abstract class is allowed to call its virtual members (see print_area()).
class Polygon {
	protected:
		int width, height;
	public:
		Polygon (int a, int b) : width (a), height(b) {}
		virtual int area() =0; // pure virtual function
		void print_area(){
			cout << this->area() << "\n";
		}
};

class Rectangle: public Polygon {
	public:
		Rectangle(int a, int b) : Polygon(a,b){}
		int area() {
			return width * height;
		}
};

class Triangle: public Polygon {
	public:
		Triangle(int a, int b) : Polygon(a,b){}
		int area() {
			return (width * height/2);
		}
};

int main() {
	Polygon* ppoly1 = new Rectangle(4,5);
	Polygon* ppoly2 = new Triangle(4,5);

	ppoly1->print_area();
	ppoly2->print_area();

	delete ppoly1;
	delete ppoly2;

	return 0;
}
