//https://www.geeksforgeeks.org/move-constructors-in-c-with-examples/
// C++ program without declaring the
// move constructor
#include <iostream>
#include <vector>
using namespace std;

// Move Class
class Move {
private:
	// Declaring the raw pointer as
	// the data member of the class
	int* data;

public:
	// Constructor
	Move(int d)
	{
		// Declare object in the heap
		data = new int;
		*data = d;

		cout << "Constructor is called for "
			<< d << endl;
	};

	// Copy Constructor to delegated
	// Copy constructor
	Move(const Move& source)
		: Move{ *source.data }
	{

		// Copying constructor copying
		// the data by making deep copy
		cout << "Copy Constructor is called - "
			<< "Deep copy for "
			<< *source.data
			<< endl;
	}
	// Move Constructor
	Move(Move&& source) noexcept
		: data{ source.data }
	{
		cout << "Move Constructor for "
			<< *source.data << endl;
		std::cout << "In Move Constructor, rValue address: " << source.data << std::endl;
		std::cout << "In Move Constructor, member variable data address: " << data << std::endl;
		source.data = nullptr;
	}

	// Destructor
	~Move()
	{
		if (data != nullptr)

			// If the pointer is not
			// pointing to nullptr
			cout << "Destructor is called for "
			<< *data << endl;
		else

			// If the pointer is
			// pointing to nullptr
			cout << "Destructor is called"
			<< " for nullptr"
			<< endl;

		// Free the memory assigned to
		// data member of the object
		delete data;
	}
};

// Driver Code
int main()
{
	// Create vector of Move Class
	vector<Move> vec;

	// Inserting object of Move class
	vec.push_back(Move{ 10 });
	vec.push_back(Move{ 20 });
	return 0;
}
// output without move contructor

//Constructor is called for 10
//Constructor is called for 10
//Copy Constructor is called - Deep copy for 10
//Destructor is called for 10
//Constructor is called for 20
//Constructor is called for 20
//Copy Constructor is called - Deep copy for 20
//Constructor is called for 10
//Copy Constructor is called - Deep copy for 10
//Destructor is called for 10
//Destructor is called for 20
//Destructor is called for 10
//Destructor is called for 20

//第一个 vec.push_back(Move{ 10 })：
//
//构造函数被调用，输出 "Constructor is called for 10"。
//向 vec 中插入一个 Move 对象，由于没有定义移动构造函数，会调用复制构造函数。
//复制构造函数被调用，输出 "Copy Constructor is called - Deep copy for 10"。
//插入操作完成后，临时对象被销毁，析构函数被调用，输出 "Destructor is called for 10"。

//第二个 vec.push_back(Move{ 20 })：
//
//构造函数被调用，输出 "Constructor is called for 20"。
//向 vec 中插入一个 Move 对象，由于没有定义移动构造函数，会调用复制构造函数。
//复制构造函数被调用，输出 "Copy Constructor is called - Deep copy for 20"。
//复制构造函数被调用，输出 "Copy Constructor is called - Deep copy for 10"，这是因为在插入之前，vec 已经有一个元素，因此需要复制现有的元素。
//插入操作完成后，临时对象被销毁，析构函数被调用，输出 "Destructor is called for 20"。
//原始的 Move 对象被销毁，析构函数被调用，输出 "Destructor is called for 10"。

// output with move destructor
//Constructor is called for 10
//Move Constructor for 10
//Destructor is called for nullptr
//Constructor is called for 20
//Move Constructor for 20
//Move Constructor for 10
//Destructor is called for nullptr
//Destructor is called for nullptr
//Destructor is called for 10
//Destructor is called for 20