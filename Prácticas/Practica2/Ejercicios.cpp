#include <iostream>
#include <cstdlib>
using namespace std;

class Ejercicio1{
private:

public:
	static void A(){
		int a = 5, *p;

		a = *p * a;

		if(a == *p)
			cout << "Es igual" << endl;
		else
			cout << "NO es igual" << endl;
	}

	static void B(){
		int a = 5, *p;

		*p = *p * a;

		if(a == *p)
			cout << "Es igual" << endl;
		else
			cout << "NO es igual" << endl;
	}

	static void C(){
		int a = 5, *p = &a;

		*p = *p * a;

		if(a == *p)
			cout << "Es igual" << endl;
		else
			cout << "NO es igual" << endl;
	}

	static void D(){
		int a = 5, *p = &a, **p2 = &p;

		**p2 = *p + (**p2 / a);
		*p = a + 1;
		a = **p2 / 2;

		cout << "El valor de a es: " << a << endl;
	}
};

int main(){
	//Ejercicio1::A();
	//Ejercicio1::B();
	//Ejercicio1::C();
	//Ejercicio1::D();

	system ("pause");
}