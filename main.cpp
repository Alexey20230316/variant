#include<iostream>
#include<vector>
#include<string>
#include<variant>
#include<cstdlib>

std::variant<int, std::string, std::vector<int>> get_variant()
{
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	
	return result;
}

int main() {


	std::variant<int, std::string, std::vector<int>> age;
	age = get_variant();
	std::vector<int>agu;

	if (std::holds_alternative<std::string>(age))
	{
		std::cout << std::get<std::string>(age);
	}
	else if (std::holds_alternative<int>(age))
	{
		int a = std::get<int>(age) * 2;
		std::cout << a;
	}
	else
	{
		agu = std::get<std::vector<int>>(age);

		for (std::vector<int>::iterator it = agu.begin(); it != agu.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		
	}

	return 0;
}