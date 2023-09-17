#include<iostream>
#include<vector>
#include<string>
#include<variant>

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
	auto age = get_variant();
	

	if (std::holds_alternative<std::string>(age))
	{
		std::cout << std::get<std::string>(age);
	}
	else if (std::holds_alternative<int>(age))
	{
		int a = std::get<int>(age) * 2;
		std::cout << a;
	}

	// Problemma!! 
	else
	{
		std::vector<int> aga;
		
		std::vector<int>::iterator it;
		
	    aga = std::get<int>(&age);
	}

	return 0;
}