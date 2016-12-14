#include <iostream>
#include "Tree.h"

int main()
{
	std::cout << "Red Black Tree" << std::endl;
	Tree redBlack(7);
	redBlack.traversePreOrder();
	std::cout << std::endl;

	redBlack.insert(3);
	redBlack.traversePreOrder();
	std::cout << std::endl;

	redBlack.insert(10);
	redBlack.traversePreOrder();
	std::cout << std::endl;

	redBlack.insert(5);
	redBlack.traversePreOrder();
	std::cout << std::endl;
	redBlack.traversePostOrder();
	std::cout << std::endl;

	redBlack.insert(6);
	redBlack.traversePreOrder();
	std::cout << std::endl;
	redBlack.traversePostOrder();
	std::cout << std::endl;

	redBlack.insert(20);
	redBlack.traversePreOrder();
	std::cout << std::endl;
	redBlack.traversePostOrder();
	std::cout << std::endl;


	std::cin.get();
	return 0;
}