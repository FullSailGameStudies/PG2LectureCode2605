#include <iostream>
#include "Console.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include <Input.h>
#include <map>
#include <iomanip>

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
	std::map<std::string,float> grades;
	//2 ways to add data
	// 1) "easy" way - map[key] = value
	// 2) "not-easy" way - map.insert(keyvaluepair)

	grades["Bruce"] = 100.0f;
	grades["Robin"] = 65.0f;
	grades["Robin"] = 70.0f;//overwrites the old value

	std::pair<std::string, float> itemToInsert =
		std::make_pair("Alfred", 75.0f);
	auto wasInserted = grades.insert(itemToInsert);
	//pair objects have 2 parts: first and second
	itemToInsert.second = 80.0f;
	wasInserted = grades.insert(itemToInsert);//will NOT overwrite an existing value
	if (wasInserted.second == false)
		std::cout << "Student is already in the course. Do you want to change their grade?\n";

	//how to access a value using the key
	float aGrade = grades["Robin"];
	std::cout << "Robin has a grade of " << aGrade << "\n";

	//call the find method to lookup a key
	auto foundStudent = grades.find("Joker");
	//if it returns the end(), it did NOT find it
	if (foundStudent == grades.end())
	{
		std::cout << "Joker is not in the class.\n";
	}
	else //it found the key
	{
		aGrade = grades["Joker"];//will add Joker with a default value
		std::cout << "Joker has a grade of " << aGrade << "\n";
	}

	//Looping
	// use a range-based loop OR an iterator loop
	for (auto it = grades.begin(); it != grades.end(); it++)
	{
		//the iterator points to the key-value PAIR
		std::cout << it->first << " " << it->second << "\n";
	}
	for (auto& student : grades)
	{
		std::cout << student.first << " " << student.second << "\n";
	}
	grades.clear();	
	std::vector<std::string> students{
		"Garrett","Christian","Tevin","Zion","Paul","Michael","Byron","Brical","Carson","Darian","Emily","Troy"
	};
	srand(time(NULL));
	for (auto& s : students)
	{
		grades[s] = rand() % 10001 / 100.0f;
	}

	//use structured bindings
	std::cout << "\n\nPG2 2506\n";
	for (auto& [studentName,studentGrade] : grades)
	{
		std::cout << std::setw(10) << std::left << studentName << " ";
		Console::SetForegroundColor(
			(studentGrade < 59.5) ? ConsoleColor::Red :
			(studentGrade < 69.5) ? ConsoleColor::Yellow :
			(studentGrade < 79.5) ? ConsoleColor::Magenta :
			(studentGrade < 89.5) ? ConsoleColor::Cyan :
			ConsoleColor::Green);
		std::cout << std::setw(7) << std::right << studentGrade << "\n";
		Console::Reset();
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