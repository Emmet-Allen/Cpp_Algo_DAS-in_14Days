#include <iostream>
#include <string>

using namespace std; //calling std so we dont have to keep calling it within our code


// Give a type T the expression sizeof(T) gives the size of that type
// i.e. int q = 5; sizeof(q);  will output the bit size of int, so 4

//Enumeration: User-defined type that can hold any of a set of discrete values

//Floating Point: A variable of type float holds a single-percision floating point number
// To force a literal to be a float add the suffix "f" or "F" as in 2.0f or 1.234e-3F. 

//Pointers: memory address located in the computers memory
// Pointer operator: *
// Given a type T, the type T* denotes a pointer to a variable of type T. 
//i.e. int* denotes a pointer to an interger

//Adress-of operator: returns the contents of a given address, denoted by "&"
// if "x" is an interger variable, &x is the address of "x" in memory

//Dereferencing: Accesing an objects value from its address
// if we declare q to be a pointer to an interger using * operator (int*)
// then we set q = &x
// we could access x's value with *q

//Useful to have a null pointer
// null pointer = pointer assigned the value 0, symbol NULL is equal to 0 in cpp
//Definition is activated when insterting "#include <cstdlib>"

//We can also declare pointers to type "void" (void*)
// Such a pointer can point to a variable of ANY type, use is STRONGLY DISCOURAGED

//Arrays: collection of elements of the same type
// Given any type T and a constant N a variable of type T[N] holds an array of N elements of type T
// Each element of the array is referenced by its index
// Index: a number from 0 to N - 1
// NOT POSSIBLE TO INCREASE NUMBERS OF ELEMENTS IN ARRAY!
// Vector type provides capabalities of complete array type and ability to dynamically change array's size

//A two-dimensional array is implemented as an "array of arrays." 
// i.e. int A[15][30]; declares A to be an array of 30 objects each of which is an array of 15 intergers
// the "array of arrays" is then indexed as int A[i][j] where "i" is in range of "0 - 14", while "j" is "0 - 29"

// We can also intialize values by enclosing elements in curly braces, we then don't need to specify size of array.

//Also possible to declare an array of pointers to intergers
// i.e. int* r[17] declares an array "r" that consist of 17 pointers to objects of type int
// once intalized we can dereference an element of this array using "*" 
// i.e. *r[16] is the value of the interger point to by the last element of this array


//string: An array of char's
// To use "#include <string>" 
// By definition strings are apart of STL and their full name is std::string
// By adding "using std::string" we can inform complier that we want to access definition directly


//Structure: Used to store aggregation of elements of different or same types
// Each 'structure' is reffered to by a given name
// Individual members of a struct are accessed using the "member selection operator" with form "struct_name.member"
// Structures of same type can be assigned to another

//C++ run-time system reserves a large block of memory called the "free store" aka "heap"
// The "new" operator dynamically allocates the correct amount of storage for an object of a given type from the heap

// i.e. Let p_pass be a pointer to a Passenger structure, this implies that *p_pass refers to the actual structure
// We can then have p_pass assigned to a new Passanger dynamically using "new"  
// from there we could access the members of Passanger (p_pass.mealPref = REGULAR;)
// To shorten the access member use "->" operator
// i.e. pointer_name->member == (*pointer_name).member

// Memory that is being used by the "new" operator exsist until it is EXPLICITLY deleted with "delete" operator
// "delete" operator destorys memory being used by a "new" object, C++ knows how much memory to dealloacte depending
// C++ Does not include "garbage collection", programmers responsibility of explicitly deleteing all dynamcially allocated objects

//Arrays can be allocated with "new", which dynamically returns a pointer to the first element of the array
// A dynamically allocated array with elements of type "T" would be declared being of type "*T"
//Arrays allocated in this way cannot be deallocated with "delete" operator
// Instead operator "delete[]" is used

// Failing to delete dynamically allocated objects cause "memory leaks" which takes up space for other objects that may need it

// References: provide another way to indirectly refer to an object
// i.e. Given a type T, the notation T& idicates a reference to an object of type T
// References MUST REFERE to an actual variable
// Any access to the reference is treated exactly as reference to the underlying object

// "const" decleration variables can not be changed or mutated within scope
// "typedef" decleration defines a new type name

//Namespace: a mechanism that allows a group of related names to be defined in one place
// Helps organize global objects into natural groups
// We can access an object x in namespace group using "group::x" which is called a "fully qualified name"

//Post increment: var++
//Pre increment: ++var

//Bitwise Operators: representation of numbers as binary bit strings which can be applied to "int" types
// the result is also a "int" type
//~exp: bitwise complement
// &, ^(exclusive-or), | , 
// exp1 << exp2: shift exp1 left by exp2 bits 
// exp1 >> exp2: shift exp1 right by exp2 bits

//"class_name::member" = class-scope resolution
//"namespace_name::member" = namespace resolution
// "bool_exp ? true_exp : false_exp" = conditional expression

// "stream >> var" = stream input
// "stream << var" = stream output

//Type casting: To cast the value of the expression to type T we can use notation "(T)exp" a "C-style cast"
// The more perffered method of casting is "functional-style cast" with notation "T(exp)"

//Static Casting: Used when a conversion is made between two related types
// syntax = "static_cast <desired_type> (expression) "
// commonly used for casting between numeric types
// Can cause problems because it can truncate values, UNSAFE, Older C++ compliers may have problems compiling

// Implicit Casting: Compiler automatically inserts a cast into the machine-generated code
// Play it safe: implicit casting requires complier's behavior towards the value, explicit cast removes this

//Array Arguments: A copy of array is not made in function arguement, it is instead converted to a pointer to its intial element
// type T[] is converted to type T*
// Arrays are also not passed by value

//Class Structure: "class" consist of "memebers"
//"members" that are variables or constants are "data members"(also called member variables) 
// "members" that are functions a re called "member functions (also called methods)
// "public" defines class's public interface, users of class are allowed to access
// "private" defines class's private interface, useres of class are NOT allowed to access

const int CAT = 1;
int dog = CAT;

namespace myglobals {
	int cat; 
	string mouse = "Squeak Squeak";
}

void expf(int value, int& ref) {
	value++; //no effect on the acutal argument
	ref++;	//modifies the actual "ref" argument
	cout << value << endl;	//outputs 2
	cout << ref << endl;	//outputs 6
}

class Counter {
public:
	Counter();		//intialization
	int getCount();	// get the current count "getter function, provides access to private memebers"
	void increaseBy(int x);	// add x to the count
private:
	int count;		//the counter's value
};

Counter::Counter() //constructor 
{ count = 0; }
int Counter::getCount() { return count;  } //get current count "getter function, provides access to private memebers"
void Counter::increaseBy(int x) { count += x; }	//add x to the count


int main() {
	int q = 5;
	cout << sizeof(q) << endl;

	enum Day{SUN, MON, TUE, WED, THU, FRI, SAT}; //SUN would have automatic value of "0" and would increase through array
	enum Mood{HAPPY = 3, SAD = 1, ANXIOUS = 4, SLEEPY = 2}; //We set values to within the array so when called they output that value 

	Day today = THU; 
	Mood myMood = SLEEPY; 

	cout << today << endl;
	cout << myMood << '\n' << endl; 
	
	char ch = 'q';
	char* pch = &ch; //*p holds address of ch 
	cout << *pch << endl; // outputs q
	ch = 'Z'; //ch now holds Z
	cout << *pch << endl;  //outputs Z
	*pch = 'X'; //ch now holds X
	cout << ch << '\n' << endl;  // outputs X

	int* x, y, z; //same as int* x, int y, int z; 

	double f[5]; //array double size 5
	int m[10]; // array int size 10
	f[4] = 2.5;
	m[2] = 4;
	cout << f[m[2]] << '\n' << endl ; //Outputs f[4] because m[2] = 4, which is 2.5

	char c[] = { 'b','a','d' };
	char* j = c; //j points to c array
	char* i = &c[0]; //i points to memory address of c[0]
	cout << c[2] << j[2] << i[2] << '\n' << endl; //will all out put 'd'
	//Overall better to use a "vector" type

	
	//enum type to handle meal preferences
	enum MealType {NO_PREF, REGULAR, LOW_FAT, VEGETARIAN};

	//struct for information about airline passangers
	struct Passanger {
		string name;		//passenger name
		MealType mealPref;	//meal preference
		bool isFreqFlyer;	//in the frequent flyer program? (T/F)
		string freqFlyerNo;  // the passengers freq flyer number
	};

	//Define a new type called Passenger with variable name "pass"
	Passanger pass{ "Jon", VEGETARIAN, true, "54431" };

	//Member Selection Operator Example
	pass.name = "Daryl"; //change name of pass
	pass.mealPref = LOW_FAT; //change meal preference of pass

	//Assigns pointer p_pass to Passanger struct
	Passanger* p_pass;
	// Dynamically create a new instance using the "new" operator
	p_pass = new Passanger; //p_pass points to the new Passanger
	p_pass->name = "Mike"; // "->" short way to access memebers (using pointers)
	p_pass->mealPref = REGULAR;
	p_pass->isFreqFlyer = false;
	p_pass->freqFlyerNo = "NONE";

	char* buffer = new char[500]; //allocate a char type pointer array named "buffer" to 500 chars
	buffer[3] = 'a';		     // buffer elements are still accessed using []
	delete[] buffer;			// deletes "buffer"

	string author = "Samuel";
	string& penName = author; //reference of penName is assigned value author
	penName = "Mark Twain";		//penName is assigned "Mark Twain"
	cout << author;

	const int CUT_OFF[]{ 90.80,70,60 };
	const int N_DAYS = 7; 

	typedef char* BufferPtr; //type BufferPtr is a pointer to char
	typedef double Coordinate; // type Corrdinate is a double 

	BufferPtr bp;
	Coordinate a, b; 

	const int CAT = 2;
	cout << "\n" << CAT << endl;

	int arr[] = { 0,20,31,52 };
	int ai = 2;			
	int aj = ai++;		//aj = 2 and now ai = 3;
	int ak = --ai;		//now ai = 2 and ak = 2
	cout <<  arr[ak++] <<'\n' << endl;

	//Type Casting
	int kitten = 14; 
	double puppy = (double)kitten;	// C-Style Casting 
	double piggy = double(kitten);	// Functional Casting

	//Function-Type Casting
	int i1 = 18;
	int i2 = 16;
	double dv1 = i1 / i2;
	double dv2 = double(i1) / double(i2);
	double dv3 = double(i1 / i2);

	cout << dv1 << endl;
	cout << dv2 << endl;
	cout << dv3 << endl; 

	//Static Casting
	double d1 = 3.2;
	double d2 = 3.9999999;
	int ai2 = static_cast<int>(d1);
	int ai3 = static_cast<int>(d2);

	cout << ai2 << " " << ai3 << endl; 

	//Implicit Casting
	int g = 3;
	double h = 4.5;
	double d3 = g / h; //d3 = 0.625 = double(g)/d
	int g2 = d3;	   //g2 = 0 = int(d3) WARNNING: ASSIGNMENT MAY LOSE INFORMATION	

	cout << '\n';

	//Reference in Argument
	int pie = 1;
	int muffin = 5;
	expf(pie, muffin); // pass pie by value, and muffin by reference
	cout << '\n';
	cout << pie << endl;	//outputs 1
	cout << muffin << endl; //outputs 6
	cout << '\n';


	Counter ctr; //an instance of  Counter
	cout << ctr.getCount() << endl; //Prints inital value 0
	ctr.increaseBy(3);				//increase by 3
	cout << ctr.getCount() << endl;	//prints 3
	ctr.increaseBy(5);				//increase by 5
	cout << ctr.getCount() << endl;	//prints 8 

	
	class Passenger {
	public:
		Passenger(); //default constructor
		bool isFrequentFlyer() const; //Given values of the members variable to intialize

		void makeFrequentFlyer(const string& newFreqFlyerNo);//copy constructor: given a Passegner Reference

	private:
		string name;
		MealType mealPref;
		bool isFreqFlyer;
		string freFlyerNo;
	};





	return 0;
}