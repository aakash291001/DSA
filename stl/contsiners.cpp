//Types of container
//1. Sequence container(Sequence containers implement data structures which can be accessed sequentially.)
//->Vector
//->list(double linked list)
//->deque
//->arrays
//->forward-List(single linked list)
//2. Containe Adaptors:(container adapters provide a diff. interface for sequential containers).
//stack(LIFO)
//queue(FIFO)
//priority_queue
//stack
//3. Associative containers:(stores the data in a sorted manner and elements can be quickly searched(O logn)).
//set
//multiset 
//map
//multimap
//4. Unordered Associative Containers:Implement unordered data structures that can be quickly searched\
//unordered set
//umordered multiset
//unordered map
//muordered multimap

//Iterators 
//iterators is an entity that helps us to access the data within a container with certain restrictions
//Input Iterator->AN itterator through which you can read data and move ahead
//Output Iterator->An entity through which you can write into thr container and move ahead
//Forward Iterator->Iterator with functionality of  input and output interator in single direction
//Bidirectional Iterator-> Forward iterator which can move in both the direction
//Random Access Itertor->Random Access Iterator is an iterator that can read/write in both the direction and can also take jumps

#include<iostream>
#include<list>
using namespace std;
template<typename T>
template<class forwardIterator,class T>

int search(T a[],int n,T key)
{
	for(int pos = 0;pos<n;pos++)
	{
		if(a[pos]==key)
		return pos;
	}
	return n;
}
forwardIterator search2(forwardIterator start,forwardIterator end,T key)
{
	while(start!=end){
		if(*start == key)
		return start;
		start++;
	}
	return end;
}
int main()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	auto it=search2(l.begin(),l.end(),4);
	if(it == l.end())
	cout<<-1;
	else
	cout<<*it;
//	int  a[]={1,2,3,4,10,12};
//	int key = 10;
//	cout<<"Position of key :"<<search(a,6,key)<<"\n";
//	float t[]={10.1,20.2,30.3};
//	float key2 =20.2;
//	cout<<"Position of key :"<<search(t,6,key2);
	return 0;
}