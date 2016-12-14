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

	redBlack.insert(8);
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

	redBlack.insert(9);
	redBlack.traversePreOrder();
	std::cout << std::endl;
	redBlack.traversePostOrder();
	std::cout << std::endl;

	redBlack.insert(15);
	redBlack.traversePreOrder();
	std::cout << std::endl;
	redBlack.traversePostOrder();
	std::cout << std::endl;

	redBlack.insert(18);
	redBlack.traversePreOrder();
	std::cout << std::endl;
	redBlack.traversePostOrder();
	std::cout << std::endl;

	redBlack.insert(0);
	redBlack.traversePreOrder();
	std::cout << std::endl;
	redBlack.traversePostOrder();
	std::cout << std::endl;

	redBlack.insert(1);
	redBlack.traversePreOrder();
	std::cout << std::endl;
	redBlack.traversePostOrder();
	std::cout << std::endl;
	redBlack.traverseInOrder();
	std::cout << std::endl;


	std::cin.get();
	return 0;
}