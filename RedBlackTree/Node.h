#pragma once
#include "Util.h"

class Node {
public:
	Node() : value(0), left(nullptr), right(nullptr), parent(nullptr) {}
	Node(int value) : value(value), left(nullptr), right(nullptr), parent(nullptr), isRed(true) {}
	Node(int value, pNode newLeft, pNode newRight, pNode newParent, bool newRed) : value(value), left(newLeft), right(newRight), parent(newParent), isRed(newRed) {}
	~Node() {}

	bool operator==(const pNode & node) { return node->value == value; }
	bool operator!=(const pNode & node) { return node->value != value; }

	pNode getLeft() const { return left; }
	pNode getRight() const { return right; }
	pNode getParent() const { return parent; }
	pNode getGrandparent() const { return parent->parent; }
	pNode getUncle() const { return getGrandparent()->left != parent ? getGrandparent()->left : getGrandparent()->right; }
	bool getRed() const { return isRed; }
	int getValue() const { return value; }
	bool hasLeft() const { return left!=nullptr; }
	bool hasRight() const { return right != nullptr; }
	bool hasParent() const { return parent != nullptr; }
	bool hasGrandparent() const { return hasParent() && parent->hasParent(); }
	bool hasUncle() const { return hasGrandparent() && getGrandparent()->hasLeft() && getGrandparent()->hasRight(); }
	bool isUncleRight() const { return getGrandparent()->left == parent; }
	bool isLeft() const { return hasParent() && parent->hasLeft() && parent->left->value == value; }
	bool isRight() const { return hasParent() && parent->hasRight() && parent->right->value == value; }

	bool setLeft(pNode newLeft) { left = newLeft; return true; }
	bool setRight(pNode newRight) { right = newRight; return true; }
	bool setParent(pNode newParent) { parent = newParent; return true; }
	bool setValue(int newValue) { value = newValue; return true; }
	bool setRed(bool newRed) { isRed = newRed; return true; }

private:
	int value;
	pNode left;
	pNode right;
	pNode parent;
	bool isRed;
};
