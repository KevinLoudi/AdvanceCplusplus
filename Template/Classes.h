#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template<class T>
class Stack
{
	 vector<T> elems;
	public:
	 void push(T const&);
	 void pop();
	 T top() const;
	 bool empty() const {return elems.empty();}
	protected:
};

template<class T>
void Stack<T>::pop()
{
	if(elems.empty())
	{
		throw out_of_range("Stack<>::pop(): empty stack"); 
	}
	//remove last element
	elems.pop_back();
}

template<class T>
T Stack<T>::top() const
{
	if(elems.empty())
	{
		throw out_of_range("Stack<>::top(): empty stack"); 
	}
	//return copy of last element
	return elems.back();
}

#endif
