#include <iostream>
#include "Console.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include <Input.h>

//a recursive LOOP
// they need to be determinant loops
//we use recursion when...
//1) we know how times it will loop
//2) and the depth of the recursion is manageable
//good for problems you can break down into smaller versions
void PrintMessage(int i = 0)
{
	//we need some kind of EXIT condition (base case) to stop the loop
	//if we don't it WILL crash
	if (i < 5)
	{
		std::cout << "Batman is the best.\n";
		i++;
		PrintMessage(i);//recursive case. when the method calls itself.
		std::cout << "Robin is expendable.\n";
	}
}

int main(int argc, char* args[])
{
	for (int i = 0; i < 5; i++)
	{

	}
	PrintMessage();
	srand(static_cast<unsigned int>(time(NULL)));

	std::string hello = "Hello Week 2!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Recursion Example\n",
		"2. Part A-1.1: Recursion (Bats)",
		"3. Part A-1.2: Recursion (Reverse Word)",
		"4. Part A-1.3: Recursion (Reverse words in a sentence)\n",
		"5. Part A-2: Sorting\n",
		"6. Part B-1: Linear Search\n",
		"7. Part B-2: Maps",
		"8. Part B-3: Find in Maps",
		"9. Part C-1: Erase from Maps",
		"10. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day4::RecursionExample();
			break;
		}
		case 2:
		{
			Day4::PartA_1_1();
			break;
		}
		case 3:
		{
			Day4::PartA_1_2();
			break;
		}
		case 4:
		{
			Day4::PartA_1_3();
			break;
		}
		case 5:
		{
			Day4::PartA_2();
			break;
		}
		case 6:
		{
			Day5::PartB_1();
			break;
		}
		case 7:
		{
			Day5::PartB_2(1);
			break;
		}
		case 8:
		{
			Day5::PartB_2(2);
			break;
		}
		case 9:
		{
			Day6::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}