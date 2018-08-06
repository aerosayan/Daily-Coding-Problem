STILL SOME ERRORS ARE PRESENT
/*
DISCLAIMER : I don't own the problem, I only own the solution
//------------------------------------------------------------------------------
//                                  PROBLEM
//------------------------------------------------------------------------------
Daily Coding Problem: Problem #6
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list. Instead of
each node holding next and prev fields, it holds a field named both, which is 
an XOR of the next node and the previous node. Implement an XOR linked list; 
it has an add(element) which adds the element to the end, and a get(index) 
which returns the node at index.

If using a language that has no pointers (such as Python), you can assume you 
have access to get_pointer and dereference_pointer functions that converts 
between nodes and memory addresses.
*/
/* 
//------------------------------------------------------------------------------
//                                  SOLUTION
//------------------------------------------------------------------------------
AUTH  : Sayan Bhattacharjee (aerosayan)
EMAIL : aero.sayan@gmail.com
*/
// HINT : let n1 = 0 xor a; let n2 = a xor b; therefore, b = a xor n2

int total = 0;
class node
{
public:
	node(_val): val(_val),both(prev^0) {}
	virtual ~node(){}

	int val;
	int both;
};

node* current = 0;
node* prev = 0;

class xorllist
{
public:
	xorllist(){}
	virtual ~xorllist(){}

	void add(int _val)
	{
		node * x = new node(_val);
		prev->both = (prev->both) ^ x;
		prev = x;
		total++;
		if(total == 1)
			head = x;
	}

	xorllist*  get(index)
	{

	}

	node * head ;
}



int main()
{
	xorllist * x = new xorllist();

	x->add(0);
	x->add(1);
	x->add(2);
	x->add(3);

	return 0;
}
