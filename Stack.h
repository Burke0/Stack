/*
 * Stack.h
 *
 *  Created on: Oct 29, 2019
 *      Author: J. Alex Burke
 */
#ifndef STACK_H_
#define STACK_H_
struct Position
{
	int row,col;
};
template <class T>
struct Node
{
	T data;
	Node* next;
};
class Stack {
private:
	int count;
	Node<Position>* top;
public:
	Stack();
	~Stack();
	bool pop(Position& dataOut);
	bool push(Position dataIn);
	bool isEmpty();
	void clear();
	//bool stacktop(Position& dataOut);
	//int getCount();
};

#endif /* STACK_H_ */
