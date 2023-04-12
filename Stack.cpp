/*
 * Stack.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: J. Alex Burke
 */

#include "Stack.h"
#include <string.h>
Stack::Stack()//constructor
{
	top=NULL;
	count=0;
}
Stack::~Stack()//destructor
{
	Position x;
	while(pop(x));
}
void Stack::clear()
{
	Position x;
	while(pop(x));
}
bool Stack::push(Position dataIn)
{
	Node<Position>* pNew=new Node<Position>;
	if(pNew==NULL)
		return false;
	else
	{
		pNew->data=dataIn;
		pNew->next=top;
		top=pNew;
	count++;
	return true;
	}
}
bool Stack::pop(Position& dataOut)
{
	if(top==NULL)
		return false;
	dataOut=top->data;
	Node<Position>* temp=top;
	top=top->next;
	delete temp;
	temp=0;
	count--;
	return true;
}

bool Stack:: isEmpty()
{
	return(top==NULL);
}

/*
bool Stack::stacktop(Position& dataOut)
{

	if(top==NULL)
		return false;
	dataOut=top->data;
	return true;
}
int Stack::getCount()
{
return count;
}
*/
