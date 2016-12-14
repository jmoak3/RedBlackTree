#include "Tree.h"

bool Tree::handleRedness(pNode node)
{
	std::cout << "handling redness" << std::endl;
	if (node == nullptr)
	{
		std::cout << "Hmm handleredness got a null?" << std::endl;
	}
	bool hasParent = node->hasParent();
	bool hasGrandparent = node->hasGrandparent();
	bool hasUncle = node->hasUncle();
	if (!hasParent)
	{
		node->setRed(false);
		return true;
	}

	if (!node->getParent()->getRed())
		node->setRed(true);

	if (!hasParent || !hasGrandparent || !hasUncle) return true; // done here
	std::cout << "have parents"<< std::endl;

	if (node->getParent()->getRed() && node->getUncle()->getRed())
	{
		node->getParent()->setRed(false);
		node->getUncle()->setRed(false);
		node->getGrandparent()->setRed(true);
		std::cout << "We done here, come through again tho" << std::endl;
		return handleRedness(node->getGrandparent());
	}
	
	
	std::cout << "Should we rotate left?" << std::endl;
	if (node->isRight() && node->getParent()->isLeft())
	{
		std::cout << "Rotating left" << std::endl;
		node = rotateLeft(node->getParent());
	}
	else if (node->isLeft() && node->getParent()->isRight())
	{
		node = rotateRight(node->getParent());
	}
	node->getParent()->setRed(false);
	node->getGrandparent()->setRed(true);
	if (node->isLeft())
		node = rotateRight(node->getGrandparent());
	else if (node->isRight())
		node = rotateLeft(node->getGrandparent());

	return true;
}

pNode Tree::newNodeHelper(int value, pNode parent)
{
	pNode newNode = std::shared_ptr<Node>(new Node(value, nullptr, nullptr, parent, true));
	handleRedness(newNode);
	return newNode;
}

bool Tree::insertHelper(pNode node, int value)
{
	//add to left side
	if (node->getValue() > value)
	{
		if (node->hasLeft())
		{
			return insertHelper(node->getLeft(), value);
		}
		else
		{
			pNode newNode = newNodeHelper(value, node);
			node->setLeft(newNode);
			return true;
		}
	}
	else // add to right side
	{
		if (node->hasRight())
		{
			return insertHelper(node->getRight(), value);
		}
		else
		{
			pNode newNode = newNodeHelper(value, node);
			node->setRight(newNode);
			return true;
		}
	}
}
bool Tree::insert(int value)
{
	if (root == nullptr)
	{
		pNode newNode = newNodeHelper(value, nullptr);
		root = newNode;
		handleRedness(root);
		return true;
	}
	else
	{
		return insertHelper(root, value);
	}
}

bool Tree::containsHelper(pNode node, int value)
{
	if (node == nullptr) return false;
	if (node->getValue() == value) return true;
	else if (node->getValue() > value) return containsHelper(node->getLeft(), value);
	else return containsHelper(node->getRight(), value);
}
bool Tree::contains(int value)
{
	return containsHelper(root, value);
}

int Tree::removeHelper(pNode node, int value)
{
	if (node == nullptr)
	{
		std::cout << "Node not found!" << std::endl;
		return -1;
	}
	else if (node->getValue() > value && node->hasLeft())
	{
		pNode leftNode = node->getLeft();
		if (leftNode->getValue() == value)
		{
			if (leftNode->hasRight())
			{
				node->setLeft(leftNode->getRight());
				return value;
			}
			else if (leftNode->hasLeft())
			{
				node->setLeft(leftNode->getLeft());
				return value;
			}
			else
			{
				node->setLeft(nullptr);
				return value;
			}
		}
		else
		{
			return removeHelper(leftNode, value);
		}
	}
	else if (node->hasRight())
	{
		pNode rightNode = node->getRight();
		if (rightNode->getValue() == value)
		{
			if (rightNode->hasRight())
			{
				node->setRight(rightNode->getRight());
				return value;
			}
			else if (rightNode->hasLeft())
			{
				node->setRight(rightNode->getLeft());
				return value;
			}
			else
			{
				node->setRight(nullptr);
				return value;
			}
		}
		else
		{
			return removeHelper(rightNode, value);
		}
	}
	else
	{
		std::cout << "Node not found!" << std::endl;
		return -1;
	}
}
int Tree::remove(int value)
{
	return INT_MIN;//implement me later
	if (root == nullptr) return INT_MIN;
	if (root->getValue() == value)
	{
		if (root->hasRight())
		{
			int newValue = remove(getMin(root->getRight()));
			root->setValue(newValue);
			return value;
		}
		else if (root->hasLeft())
		{
			int newValue = remove(getMax(root->getLeft()));
			root->setValue(newValue);
			return value;
		}
		else
		{
			root = nullptr;
			return value;
		}
	}
	else return removeHelper(root, value);
}

int Tree::getMax() const
{
	pNode temp = root;
	if (temp == nullptr) return INT_MIN;
	//Get most right guy
	while (temp->getRight()) temp = temp->getRight();
	return temp->getValue();
}

int Tree::getMin() const
{
	pNode temp = root;
	if (temp == nullptr) return INT_MIN;
	//Get most left guy
	while (temp->getLeft()) temp = temp->getLeft();
	return temp->getValue();
}

int Tree::getMax(pNode node) const
{
	//Get most right guy 
	while (node->getRight()) node = node->getRight();
	return node->getValue();
}

int Tree::getMin(pNode node) const
{
	//Get most left guy
	while (node->getLeft()) node = node->getLeft();
	return node->getValue();
}

void Tree::preOrderHelper(pNode node)
{
	if (node == nullptr) return;
	std::cout << node->getValue();
	node->getRed() ?
		std::cout << "red "
		: std::cout << "black ";
	preOrderHelper(node->getLeft());
	preOrderHelper(node->getRight());
}
void Tree::traversePreOrder()
{
	std::cout << "PreOrder: ";
	return preOrderHelper(root);
}

void Tree::inOrderHelper(pNode node)
{
	if (node == nullptr) return;
	inOrderHelper(node->getLeft());
	std::cout << node->getValue();
	node->getRed() ?
		std::cout << "red "
	  : std::cout << "black ";
	inOrderHelper(node->getRight());
}
void Tree::traverseInOrder()
{
	std::cout << "InOrder: ";
	return inOrderHelper(root);
}

void Tree::postOrderHelper(pNode node)
{
	if (node == nullptr) return;
	postOrderHelper(node->getLeft());
	postOrderHelper(node->getRight());
	std::cout << node->getValue();
	node->getRed() ?
		std::cout << "red "
		: std::cout << "black ";
}
void Tree::traversePostOrder()
{
	std::cout << "PostOrder: ";
	return postOrderHelper(root);
}

//parent
//      node

//      node
//parent
pNode Tree::rotateLeft(pNode parent)
{
	//swap values and color
	swapNodeValueAndRed(parent, parent->getRight());
	
	//swap parent's children
	pNode temp = parent->getLeft();
	parent->setLeft(parent->getRight());
	parent->setRight(temp);
	
	//swap children's children
	pNode left = parent->getLeft();
	temp = left->getRight();
	left->setRight(left->getLeft());
	left->setLeft(temp);

	//swap child's left with parent's rights
	temp = parent->getRight();
	parent->setRight(left->getLeft());
	left->setLeft(temp);

	//Make sure we didn't goof parenting up
	if (left->hasLeft())
		left->getLeft()->setParent(left);
	if (left->hasRight())
		left->getRight()->setParent(left);

	if (parent->hasLeft())
		parent->getLeft()->setParent(parent);
	if (parent->hasRight())
		parent->getRight()->setParent(parent);

	return parent->getLeft();
}
pNode Tree::rotateRight(pNode parent)
{
	//swap vales	
	swapNodeValueAndRed(parent, parent->getLeft());

	//swap parent's children
	pNode temp = parent->getRight();
	parent->setRight(parent->getLeft());
	parent->setLeft(temp);

	//swap children's children
	pNode right = parent->getRight();
	temp = right->getLeft();
	right->setLeft(right->getRight());
	right->setRight(temp);

	//swap child's left with parent's rights
	temp = parent->getLeft();
	parent->setLeft(parent->getRight()->getRight());
	parent->getRight()->setRight(temp);

	//Make sure we didn't goof parenting up
	if (right->hasLeft())
		right->getLeft()->setParent(right);
	if (right->hasRight())
		right->getRight()->setParent(right);

	if (parent->hasLeft())
		parent->getLeft()->setParent(parent);
	if (parent->hasRight())
		parent->getRight()->setParent(parent);

	return parent->getRight();
}

void Tree::swapNodeValueAndRed(pNode n1, pNode n2)
{
	int value = n1->getValue();
	bool red = n1->getRed();
	n1->setValue(n1->getRight()->getValue());
	n2->setValue(value);
	n1->setRed(n1->getRight()->getRed());
	n2->getRight()->setRed(red);
}