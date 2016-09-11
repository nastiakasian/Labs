#include <iostream> 
#include <string> 


class OutOfBoundError
{
public:
	OutOfBoundError(
		std::string _functionName,
		int _arraySize,
		int _attemptIndex) :
		functionName_(_functionName),
		arraySize_(_arraySize),
		attemptIndex_(_attemptIndex)
	{
	}

	std::string getMessage()
	{
		return "ERROR \"out of array bound\" in function " + functionName_ + ". Array size: " + std::to_string(arraySize_) + ", but YOU use index " + std::to_string(attemptIndex_) + "\n";
	}

private:

	std::string functionName_;

	int arraySize_,
		attemptIndex_;
};

class DivideByZeroError
{
public:
	DivideByZeroError(std::string _functionName, int _numerator) :
		functionName_(_functionName),
		numerator_(_numerator)
	{
	}

	std::string getMessage()
	{
		return "ERROR \"division by zero\" in function " + functionName_ + ". You attempt divide " + std::to_string(numerator_) + " by zero!\n";
	}

private:

	std::string functionName_;

	int numerator_;
};

int get1(int n)
{
	int r[8] = { 15, 16, 17, 18, 19, 20, 21, 22 };

	if (n >= 8) throw OutOfBoundError("get1", 8, n);

	return r[n];
}

int get2(int n)
{
	int r[5] = { 15, 16, 17, 18, 19 };

	if (n >= 5) throw OutOfBoundError("get2", 5, n);

	return r[n];
}

int divide1(
	int x,
	int y)
{
	if (y == 0) throw DivideByZeroError("divide1", x);

	return x / y;
}


int main()
{
	int r;

	try
	{
		//r = get2(1024); 

		r = divide1(17, 0);

		std::cout << r << "\n";
	}
	catch (OutOfBoundError &error)
	{
		std::cout << error.getMessage() << "\n";
	}
	catch (DivideByZeroError &error)
	{
		std::cout << error.getMessage() << "\n";
	}

	system("pause");
}