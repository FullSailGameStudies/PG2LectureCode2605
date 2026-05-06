#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include <Console.h>
#include <Input.h>

//int Increment(int n) //pass-by-value (COPY)
//{
//
//}
void Increment(int& num)//pass-by-reference (ALIAS)
{
	num++;
}
void Print(int num)
{

}

void Print(std::vector<int> nums)
{

}

void MinMaxAvg(const std::vector<int>& nums, int& min, int& max, int& avg)
{
	min = max = avg = 0;
	if (nums.empty()) return;

	int sum = 0;
	min = max = sum = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		sum += nums.at(i);
		if (nums[i] < min) min = nums[i];
		if (nums[i] > max) max = nums[i]; 
	}
	avg = sum / nums.size();
}
// why use pass-by-reference?
//  1) to prevent a copy
//  2) to allow one scope to access variables in another scope
// 
// rules to use pass-by-reference:
// 1) if the parameter is a class (not a basic data type)
// 2) when you need to change a variable in a different scope
// 3) when I need more than 1 return value
void Print(const std::vector<int>& nums)
{

}

float Increment(float copyOfPI)
{
	copyOfPI++;
	return copyOfPI;
}

const float PI = 3.14159265f;

int main(int argc, char* args[])
{
	Increment(PI);
	std::vector<int> nummies{ 1,2,3,4,5,6,7,8,9 };
	int minNum, maxNum, avgNum;
	MinMaxAvg(nummies, minNum, maxNum, avgNum);
	std::cout << "Min: " << minNum << "\n";
	std::cout << "Max: " << maxNum << "\n";
	std::cout << "Avg: " << avgNum << "\n";
	int bruce = 5;
	Increment(bruce);//int& num = bruce;
	std::cout << "Bruce: " << bruce << "\n";
	int& batman = bruce;
	batman = 100;
	std::cout << "Bruce: " << bruce << "\n";

	Day2 day2;

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1.0: Calling static methods",
		"2. Part A-1.1: calling non-static methods",
		"3. Part A-1.2: calling non-static methods",
		"4. Part A-1.3: calling non-static methods",
		"5. Part A-1.4: Return Values",
		"6. Part A-1.5: Passing arguments",
		"7. Part A-2: Creating methods\n",
		"8. Part B-1: Pass by reference",
		"9. Part B-2: Const",
		"10. Part B-3: Erasing in a loop\n",
		"11. Part C-1: Default Parameters",
		"12. Part C-2: Copying Vectors\n",
		"13. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			//
			// part A-1.0: calling methods on the Console class to print messages.
			//
			//	Use Console::Write and Console::WriteLine to print several lines of text (whatever you want to say)
			//  Experiment with changing the colors.
			//  Open the Console.h file (look in Misc/Console in Solution Explorer) to see how the methods are declared.
			//
			Console::Write("Hello Gotham!");
			Console::WriteLine("Hello Gotham!");
			Console::WriteLine("Batman is the best (obviously)!", ConsoleColor::Cyan);
			break;
		}
		case 2:
		{
			Day1::PartA_1_1();
			break;
		}
		case 3:
		{
			Day1::PartA_1_2();
			break;
		}
		case 4:
		{
			Day1::PartA_1_3();
			break;
		}
		case 5:
		{
			//
			// part A-1.4: Getting return values
			//	Ask the user to enter their name. Print the name.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetString.
			//	Store the result in a string variable.
			//	Print the name that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetString is declared.
			//
			break;
		}
		case 6:
		{
			//
			// part A-1.5: passing arguments
			//	Ask the user for their age. A minimum age would be 0 and a maximum age would be 120.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetInteger.
			//	Store the result in an int variable.
			//	Print the age that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetInteger is declared.
			//
			const int age = Input::GetInteger("What is your age?", 0, 120);
			std::cout << "Your age is " << age << ". weird.\n";
			break;
		}
		case 7:
		{
			Day1::PartA_2();
			break;
		}
		case 8:
		{
			day2.PartB();
			break;
		}
		case 9:
		{
			day2.PartB(2);
			break;
		}
		case 10:
		{
			day2.PartB(3);
			break;
		}
		case 11:
		{
			Day3::PartC_1();
			break;
		}
		case 12:
		{
			Day3::PartC_2();
			break;
		}
		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}

