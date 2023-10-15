#include<iostream>
using namespace std;
// so in case of hybrid inheritance we use combination of different type of inheritance and create a new inheritance this is called hybrid inheritance
class Vehicle {
	private :
		int maxSpeed;

	protected :
		int numTyres;

	public :
		string color;

	
		Vehicle() {
		cout << "Vehicle's default constructor " << endl;
	}

	void print() {
		cout << "Vehicle" << endl;
	}


	Vehicle(int z) {
	cout << "Vehicle's Parametrized constructor " << z << endl; 
		maxSpeed = z;
	}

	~Vehicle() {
		cout << "Vehicle's Destructor " << endl;
	}

};
//created a class truck that is inherited from the class vehicle 
class Truck : virtual public Vehicle {                  // parent class is vehicle
	public :

		Truck() : Vehicle(4) {
			cout << "Truck's constructor " << endl;
		}
};
class Car : virtual public Vehicle{                     // parent class is Vehicle    
                                                                        // to avoid twice inheritation  of same member function via different derived classes whose parent classes has that  we use the keyword "virtual"
	public :                                                        // by this we can say that we will not copy the dual members functions inside class that is derived from this class..
		int numGears;
		Car() : Vehicle(3) {                                                     
			cout << "Car's default constructor " << endl;
		}
		/*
		Car(int x, int y) : Vehicle(x) {
			cout << "Car's constructor " << endl;
			numGears = y;
		}*/
		~Car() {                                            
			cout << "Car's Destructor " << endl;
		}
		void print() {
			cout << "NumTyres : " << numTyres << endl;
			cout << "Color : " << color << endl;
			cout << "Num gears : " << numGears << endl;
			//		cout << "Max Speed : " << maxSpeed << endl;
		}
};
class Bus : public Car, public Truck {                              // First car class constructor will be called and secondly Truck class constructor will be called..
	public :
		Bus() : Vehicle(5)  {                                                   
			cout << "Bus's constructor " << endl;
		}
		
		void print() {
			cout << "BUs" << endl;
		}
};
//so we can see that when we created an object the constructor of class bus  value is intialised this proves that the vlaue constructor is being called by the bus class 
//since we have used the virtual keyword that is why 
int main(){
    Bus b;                  
    b.print();

}

// so now we will see if the default constructor is not available / or we needd to call the paremeterised constructor then how we will call 

// So basically what is a Virtual Class ???
/*Answer is -> In C++, a virtual base class is a class that is used as a base class for other derived classes, and is designed to be shared among those derived classes.
The use of a virtual base class allows multiple paths in a class hierarchy to access a single instance of a base class, preventing the creation of multiple copies of that base class.
When a class is derived from a virtual base class, the virtual base class is not copied into the derived class, but rather shared among all the classes that derive from it.
This means that when a virtual base class is included in a hierarchy of derived classes, it is constructed only once, and any changes made to it are visible to all the classes that derive from it.
The syntax for declaring a virtual base class is to add the keyword "virtual" before the base class name in the derived class declaration.*/
