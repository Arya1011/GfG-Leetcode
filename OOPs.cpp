// OOP
#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
	int price;

public:
	int model_No;
	char *name;
	const int msp;

	// this is example of init list

	Car() : msp(99)
	{

		// Default Constructor
		name = NULL;
		cout << "Default Constructor Called!!" << endl;
	}

	// Parameterized Constructor

	Car(int p, int mn, char *n)
	{
		price = p;
		model_No = mn;
		int l = strlen(n);
		name = new char[l + 1];
		strcpy(name, n);
	}

	// Deep Copy Constructor
	// Default copy constructor uses shallow copy in which we cant retain values of dynamically allocated memories(like arrays)
	// We cannot pass a copy in the copy constructor for the object since it will result in a dependency(kyoki copy banane ke liye bhi copy constructor chaiye) so we pass by reference
	Car(Car &X)
	{
		price = X.price;
		model_No = X.model_No;
		int l = strlen(X.name);
		name = new char[l + 1];
		strcpy(name, X.name);
	}

	// Defined Copy assignment operator for Define deep Copy.
	void operator=(Car &X)
	{
		price = X.price;
		model_No = X.model_No;
		int l = strlen(X.name);
		// deep copy(we create new dynamic memory so that original memory is not overwritten)
		name = new char[l + 1];
		strcpy(name, X.name);
	}

	void setName(char *n)
	{
		if (name == NULL)
		{
			name = new char[strlen(n) + 1];
			strcpy(name, n);
		}
		else
		{
			// Delete old Array and assign new name.
		}
	}
	void print()
	{
		cout << price << endl;
		cout << model_No << endl;
		cout << name << endl;
	}
	void setPrice(const int p) // Acts as a setter.
	{
		if (p >= 1000)
		{
			price = p;
		}
		else
		{
			price = 1000;
		}
	}
	// exmaple of const function
	int showPrice() const
	{ // Acts as a getter.
		return price;
	}
	~Car()
	{
		cout << "Destroying Car " << name << endl;
		if (name != NULL)
		{
			delete[] name;
		}
	}
};

int main()
{
	Car c;
	cout << sizeof(c) << endl;
	cout << sizeof(Car) << endl; // A class takes up memory only when an object of that class is created.
	c.setPrice(1000);
	c.setName("Lamborgini");
	c.model_No = 2010;
	// cout<<c.showPrice()<<endl;
	c.print();
	Car d(c);
	d.print();
	Car e(100, 2001, "BMW");
	Car f(e);
	f.name[0] = 'G'; // In this case both f and e objects will print GMW since the pointer used to point to the array in which the string is stored,the name of both objects is updated(Shallow Copy)
	e.print();
	f.print(); // Default Constructor gives Shallow Copy.

	// Car d; //Default Constructor Called,whenever object is created of given class.
	// Car e(1000,200,"Bentley");
	// e.print();
	// Car f(e);  //Default copy Constructor is called.
	// f.print();
	Car g(100, 200, "Ford");
	Car h(190, 200, "Merc");
	g = h; // Copy Assignment Operator.
	// g=e;
	h.print();
	g.print();

	Car *D = new Car(1000, 2500, "Tesla"); // Dynamic Class,which remains unaffected by Destructor,we need to explicitly delete it using delete keyword.
	delete D;
	return 0;
}

// Operator Overloading
#include <iostream>
using namespace std;

class Complex
{
private:
	int real;
	int img;

public:
	Complex()
	{
		real = 0;
		img = 0;
	}
	Complex(int r, int i)
	{
		real = r;
		img = i;
	}

	void setReal(int r)
	{
		real = r;
	}
	void setImg(int i)
	{
		img = i;
	}

	void Print()
	{
		if (img > 0)
		{
			cout << real << "+ " << img << "i" << endl;
		}
		else
		{
			cout << real << "- " << img << "i" << endl;
		}
	}

	void add(const Complex &X)
	{
		real += X.real;
		img += X.img;
	}

	void operator+(const Complex &X) // overloading + operator.
	{
		real += X.real;
		img += X.img;
	}

	int operator[](const string s)
	{
		if (s == "real")
		{
			return real;
		}
		else
		{
			return img;
		}
	}
};

istream &operator>>(istream &is, Complex &X) // Overloading the >>operator.
{
	int r1, i1;
	is >> r1 >> i1;
	X.setReal(r1);
	X.setImg(i1);
	X.Print();
	return is; // We are not returning void value so we can save this istream object
}

ostream &operator<<(ostream &os, Complex &X) // Overloading <<operator.
{
	X.Print();
	return os;
}

int main()
{
	Complex c1(3, 4);
	Complex c2;
	c2.setReal(4);
	c2.setImg(7);
	c1.Print();
	c2.Print();
	// c1.add(c2);
	// c1.Print();
	c1 + c2; // c1 is calling object.
	c1.Print();
	cout << c1["real"] << endl;
	Complex c3, c4;
	cin >> c3 >> c4;  // Cascading of Operators
	cout << c3 << c4; // Cascading of Operators
	return 0;
}

// Vectors and C++ STL
#include <iostream>
#include <vector>
#include "vector.h"

using namespace std;

// User Defined Vector Class

class Vector
{
	// Some Data Members And Functions.

	int maxSize;
	int cs;
	int *arr;

public:
	Vector(int defSize = 4)
	{
		maxSize = defSize;
		cs = 0;
		int *arr = new int[maxSize];
	}

	void push_back(int data)
	{
		if (cs == maxSize)
		{
			// Doubling The Size of The Array.
			int *oldarr = arr;
			arr = new int[2 * maxSize];
			maxSize *= 2;
			for (int i = 0; i < cs; i++)
			{
				arr[i] = oldarr[i];
			}
			delete[] oldarr;
		}
		arr[cs] = data;
		cs++;
	}

	bool empty()
	{
		return cs == 0;
	}

	void pop_back()
	{
		if (!empty())
		{
			cs--;
		}
	}

	void print()
	{
		for (int i = 0; i < cs; i++)
		{
			cout << arr[i] << " ";
		}
	}

	int at(int i)
	{
		return arr[i];
	}

	int getCurrentSize()
	{
		return cs;
	}

	int getMaxSize()
	{
		return maxSize;
	}
	// Overloading the () operator.
	void operator()(string s)
	{

		cout << s << endl;
	}
	// Overloading the [] operator.
	int &operator[](int i) // If we return by reference we can make changes.
	{
		return arr[i];
	}
};
// Overloading << operator ,since cout is a global object of ostream class we overload << operator outside the Vector CLass,cout is a special object so we should not pass it by value
ostream &operator<<(ostream &os, Vector &v)
{
	cout << "In << operator" << endl;
	v.print();
	return os;
}

int main()
{
	Vector v(1000);
	for (int i = 0; i < 4; i++)
	{
		v.push_back(i * i);
	}

	// v("Mumbai");
	Vector fun;
	Vector arya;
	arya("Chitu"); // Whenever we overload () on any object it is called a functor or a function object.

	// cout<<v.getMaxSize()<<endl;
	// v.push_back(25);
	// cout<<v.getMaxSize()<<endl;
	// v.print();
	/*for(int i=0;i<v.getCurrentSize();i++)
	{
		cout<<v[i]<<" ";
	}*/
	cout << endl;
	// cout<<v[2]<<endl;
	cout << v; //<< operator is overloaded.
	fun = v;   // Shallow Copy
	cout << endl;
	cout << fun;
	v[2] = 8;
	v[2] += 8;
	cout << v[2] << endl;
	return 0;
}

// Function Overriding(Example of run time polymorphism)

// #include<iostream>
// using namespace std;

// class Parent
// {
//    public:
//     void print()
//     {
//         cout<<"This is the parent print function"<<endl;
//     }
// };

// class Child:public Parent{

// public:
//     void print()
//     {
//         cout<<"This is the child print function"<<endl;
//     }
// };

// int main()
// {
//    Parent obj1;
//    Child obj2;
//    obj1.print();
//    obj2.print();
//    return 0;

// }

// Concept of Virtual Functions

// CPP program to illustrate
// concept of Virtual Functions

// #include <iostream>
// using namespace std;

// class base {
// public:
//     virtual void print()
//     {
//         cout << "print base class" << endl;
//     }

//     void show()
//     {
//         cout << "show base class" << endl;
//     }
// };

// class derived : public base {
// public:
//     void print()
//     {
//         cout << "print derived class" << endl;
//     }

//     void show()
//     {
//         cout << "show derived class" << endl;
//     }
// };

// int main()
// {
//     base* bptr;
//     derived d;
//     bptr = &d;

//     // virtual function, binded at runtime
//     bptr->print();

//     // Non-virtual function, binded at compile time
//     bptr->show();
// }

// Concept of friend class and function

// Friend Function
//  #include<iostream>
//  using namespace std;
//  class B;
//  class A
//  {
//  private:
//      int a;
//  public:
//       void showB(B&X);

// };

// class B
// {
//   private:
//     int b;

// public:
//     B()
//     {
//         b=0;
//     }
//     friend void A::showB(B&X) ; //Friend Function of class B

// };

// void A::showB(B&X)
// {
//     cout<<X.b<<endl;
// }

// int main()
// {
//    A a;
//    B b;
//    a.showB(b);
//    return 0;

// }

// #include<iostream>
// using namespace std;

// class A
// {
// private:
//     int a;
// public:
//     A()
//     {
//         a=1000;
//     }
//      friend class B;
// };

// class B
// {
// public:

//     void showA(A&x)
//     {
//         cout<<x.a<<endl;
//     }
// };
// int main()
// {
//     A a;
//     B b;
//     b.showA(a);
//     return 0;

// }

// Ways of printing vectors(or a set or any ds of STL library)
/*for(vector<int> iterator it=v.begin();it!=v.end();it++)  //Iterator for pointing to different element of the vector.

for(auto x:v)
{
	cout<<x<<endl;
}*/

// Abstract Classes(a class is an abstract Class if it has atleast one pure virtual function)
//  #include<iostream>
//  using namespace std;

// class Base
// {
//    int x;
// public:
//     virtual void fun() = 0;
//     int getX() { return x; }
// };

// // This class inherits from Base and implements fun()
// class Derived: public Base
// {
//     int y;
// public:
//     void fun() { cout << "fun() called"; }
// };

// int main(void)
// {
//     Derived d;
//     d.fun();
//     return 0;
// }

////////Data structures/////////

/*
->Vectors
->Arrays
->Stacks
->Queues
->Hash Table
->Graphs
->Linked List
->Trees

All are used to store data.
*/

// Deque

// Deque STL(Maximum element in sliding window of size k)

/*
#include<iostream>
#include<deque>
using namespace std;

int main(){
	deque<int> Q;
	int *arr=new int[5];
	int k;
	for(int i=0;i<5;i++){
		cin>>arr[i];
	}
	cout<<"Enter value of k"<<endl;
	cin>>k;
	//First we evaluate the first k elements
	for(i=0;i<k;i++){
	  while(!Q.empty() && a[i]>a[Q.back()]){
		Q.pop_back()
	  }
	  Q.push_back();
	}


	for(;i<5;i++){
		cout<<a[Q.front()]<<" ";
		//1.Delete elements which are no longer part of the window
	   while(!Q.empty() && Q.front()<=i-k){
		  Q.pop_front();
	   }

	   //2.Remove elements which are part of window but are not useful
	   while(!Q.empty() && a[i]>=Q.back()){
		  Q.pop_back();
	   }

	   //3.Add new element(when window expands)
	   Q.push_back(i);
	}
	return 0;
}
*/

/*
//Maximum Length Unique Character Substring(Sliding Window)
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  char a[]="abchefgh";
  int curr_len=1;
  int max_len=1;
  int n=strlen(a);
  int visited[256];
  for(int i=0;i<256;i++){
	visited[i]=-1;
  }
  visited[a[0]]=0;
  for(int i=1;i<n;i++){
	int last_occur=visited[a[i]];
	//Expansion
	if(last_occur==-1 || i-curr_len>last_occur){
		 curr_len+=1;
		 max_len=max(max_len,curr_len);
	}
	//Expansion+Contraction
	else{
		curr_len=i-last_occur;
		max_len=max(curr_len,max_len);
	}
	visited[a[i]]=i;

  }
  cout<<max_len<<endl;
  return 0;
}
*/

// Map STL
// Simple map(Maintains a self balancing BST) and Unordered Map(Hashmap) are the two types of maps

// Unordered maps for user defined keys
//  #include <bits/stdc++.h>
//  using namespace std;

// class student
// {
// public:
// 	string first_name;
// 	string second_name;
// 	int roll_no;
// 	student(string fn, string sn, int rno)
// 	{
// 		this->first_name = fn;
// 		this->second_name = sn;
// 		this->roll_no = rno;
// 	}

// In map when we search we need to overload the == operator for finding a key
// If two keys are equal by any chance then we compare based on roll no

// 	bool operator==(const student &s) const    //This is used for defining how to keys are equal we are comparing by roll no
// 	{
// 		return s.roll_no == roll_no;
// 	}
// };

// class HashFn
// {

// public:
// 	size_t operator()(const student &s) const    //size_t is unsigned integer return type
// 	{
// 		return s.first_name.length() + s.second_name.length();
// 	}
// };

// int main()
// {
// 	//Implicitly it uses a hashing function but we can also pass our own hash function
// 	unordered_map<student, int, HashFn> um;
// 	student s1("Aryamaan", "Kumar", 120);
// 	student s2("Aryan", "Singh", 130);
// 	student s3("Arya", "Rajesh", 124);
// 	student s4("Arhan", "Kumar", 125);
// 	student s5("Ary", "Gupta", 121);

// 	//Adding student marks to the unordered maps
// 	um[s1] = 100;
// 	um[s2] = 90;
// 	um[s3] = 120;
// 	um[s4] = 130;
// 	um[s5] = 10;

// 	cout << um[s1] << endl;

// 	for (auto s : um)
// 	{
// 		cout << s.first.first_name << " " << s.first.roll_no << " "
// 			 << "Marks " << s.second << endl;
// 	}
// 	return 0;
// }

// Phone book implementation using maps
//  #include <bits/stdc++.h>
//  using namespace std;

// int main()
// {
// 	unordered_map<string, vector<int>> phonebook;
// 	phonebook["Aryamaan"].push_back(100);
// 	phonebook["Aryamaan"].push_back(101);
// 	phonebook["Aryamaan"].push_back(102);
// 	phonebook["Aryan"].push_back(200);
// 	phonebook["Aryan"].push_back(201);
// 	phonebook["Aryan"].push_back(202);

// 	for (auto p : phonebook)
// 	{
// 		cout << p.first << "->";
// 		for (auto n : p.second)
// 		{
// 			cout << n << " ";
// 		}
// 		cout << endl;
// 	}

// 	//Querying Phonebook
//    string name;
//    cin>>name;
//    if(phonebook.count(name)==0){
// 	   cout<<"Absent"<<endl;
//    }else{
//         for(auto p:phonebook[name]){
// 		      cout<<p<<"->"";
// 		}
//    }

// 	return 0;
// }

// Recursion Quick Thinking

// int stringToInt(char *a,int n){
// 	if(n==0){
// 		return 0;
// 	}
// 	 int last_digit=a[n-1]-'0';
// 	 int small_ans=stringToInt(a,n-1);
// 	 return small_ans*10+digit;
// }

// void replacePi(char*a,int i){
// 	if(a[i]=="\0" or a[i+1]=="\0"){
// 		return;
// 	}

//     //look for pi in current location
// 	if(a[i]=="p" && a[i+1]=="i"){
// 		//Shifting + replacement with 3.14
//     int j=i+2;
// 	//take j to the end of the array
// 	while(a[j]!="\0"){
// 		j++;
// 	}
// 	//shifting right to left
// 	while(j>=i+2){
// 		a[j+2]=a[j];
// 		j--;
// 	}
// 	//Replacement + recursive call for rest of the array
// 	a[i]='3';
// 	a[i+1]='.';
// 	a[i+2]='1';
// 	a[i+3]='4';
// 	replacePi(a,i+4);
//  }
//  else{
// 	 replacePi(a,i+1);
//  }
//  return;
// }

// void generate_subsequence(char *in,char* out,,int i,int j){
// 	if(in[i]=='\0'){
// 		out[j]='\0';
//         cout<<out;
// 		return;
// 	}
// Considering Character
// 	out[j]=in[i];
// 	generate_subsequence(in,out,i+1,j+1);
// 	//Ignoring character
// 	generate_subsequence(in,out,i+1,j);
//   return;
// }

#include <bits/stdc++.h>
using namespace std;

// int numberOfWaysOfSteps(int n)
// {
// 	if (n == 0 or n == 1)
// 	{
// 		return 1;
// 	}
// 	if (n == 2)
// 	{
// 		return numberOfWaysOfSteps(n - 1) + numberOfWaysOfSteps(n - 2);
// 	}
// 	return numberOfWaysOfSteps(n - 1) + numberOfWaysOfSteps(n - 2) + numberOfWaysOfSteps(n - 3);
// }

// int numberOfWaysOnBikes(int n)
// {
// 	if (n == 0 || n == 1)
// 	{
// 		return 1;
// 	}
// 	return numberOfWaysOnBikes(n - 1) + (n - 1) * numberOfWaysOnBikes(n - 2);
// }

// Generate Balanced Brackets using N pairs of Brackets
// At any index i igf we put '(' then we need to ensure number_of_open<N
// If we decide to put ')' then number_of _close<open

void generateBrackets(char *out, int idx, int n, int open, int close)
{
	// Bsse Case
	if (idx == 2 * n)
	{
		out[idx] = '\0';
		cout << out << endl;
		return;
	}
	// Recursive Case
	// Put open if open<n
	if (open < n)
	{
		out[idx] = '(';
		generateBrackets(out, idx + 1, n, open + 1, close);
	}
	// Put close if close<open
	if (close < open)
	{
		out[idx] = ')';
		generateBrackets(out, idx + 1, n, open, close + 1);
	}
	return;
}

// The question will give us the weights of items,the prices and we are also given capacity of bag and total items.Find max profit which can be made by the thief
// Question mei prices aur weights dono ke arrays sorted de rkhe hai
int profitKnapsack(int *weights, int *prices, int N, int C)
{
	// Base case is when bag is full or when there are no items left
	if (N == 0 || C == 0)
	{
		return 0;
	}
	// Recursive Case
	int profit1, profit2;
	profit1 = 0;
	profit2 = 0;
	// Include item
	if (C >= weights[N - 1])
	{
		profit1 = prices[N - 1] + profitKnapsack(weights, prices, N - 1, C - weights[N - 1]);
	}
	// Exclude item
	profit2 = profitKnapsack(weights, prices, N - 1, C);
	int ans = max(profit1, profit2);
	return ans;
}

void generate_string_from_number(char *in, char *out, int i, int j)
{
	if (in[i] == '\0')
	{
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	// Take one character
	int digit = in[i] - '0';
	char ch = digit + 'A' - 1;
	out[j] = ch;
	generate_string_from_number(in, out, i + 1, j + 1);

	// Take two chars
	if (in[i + 1] != '\0')
	{
		int second_digit = in[i + 1] - '0';
		// Convert to 2 digit number
		int no = digit * 10 + second_digit;
		if (no <= 26)
		{
			char ch1 = no + 'A' - 1;
			out[j] = ch1;
			// j+1 since we are using two inputs to create a single output
			generate_string_from_number(in, out, i + 2, j + 1);
		}
	}
	return;
}

int main()
{
	// int n;
	// cin >> n;
	// char out[1000];
	// generateBrackets(out, 0, n, 0, 0);
	// cout << "No of ways are " << numberOfWaysOnBikes(n);
	int weights[] = {1, 2, 3, 5};
	int prices[] = {40, 20, 30, 100};
	int N = 4;
	int C = 7; // Capacity of the bag
	cout << "Max profit is " << profitKnapsack(weights, prices, N, C);
	return 0;
}

/*
Given a long vector of strings, print the strings that contain the strings generated by numeric string str.

string searchIn [] = {
			"prateek", "sneha", "deepak", "arnav", "shikha", "palak",
			"utkarsh", "divyam", "vidhi", "sparsh", "akku"
	};

For example, if the input is 26 and the string is coding, then output should be coding since 26 can produce co which is contained in coding.
Input Format

A numeric string str
Constraints

len(str) < 10
No of strings in the vector < 10
Output Format

Each matched string from the given vector.
Sample Input

34

Sample Output

vidhi
divyam
sneha

Explanation

34 will result into combinations :

*dg         *eg         *fg
*dh            *eh         *fh
*di            *ei         *fi

Corresponding strings are output.

	vidhi contains dh
	divyam contains di
	sneha contains eh
*/

#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
char ch[][11] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void solve(vector<string> arr, char *in, char *out, int i, int j)
{
	if (in[i] == '\0')
	{
		// string terminated
		out[j] = '\0';
		string s(out);
		int len = s.length();
		for (auto st : arr)
		{
			for (int i = 0; i < st.length() - len; i++)
			{
				if (st.substr(i, len) == s)
				{
					ans.push_back(st);
				}
			}
		}
		return;
	}

	int digit = in[i] - '0';
	for (int k = 0; ch[digit][k] != '\0'; k++)
	{

		out[j] = ch[digit][k];
		solve(arr, in, out, i + 1, j + 1);
	}
}

int main()
{

	vector<string> arr = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak",
						  "utkarsh", "divyam", "vidhi", "sparsh", "akku"};

	char in[100], out[100];
	cin.getline(in, 100);
	int i = 0, j = 0;
	solve(arr, in, out, i, j);
	for (auto s : ans)
	{
		cout << s << endl;
	}
}
