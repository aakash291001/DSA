#include<iostream>
using namespace std;
struct element {
	int key;
	int value;
};
typedef struct element* elements;
struct list
{
	elements data;
	struct list* next;
};
typedef struct list* lists;
struct chain
{
	lists lists;
};
typedef struct chain* chains;
struct table 
{
	int capacity;
	int size;
	chains *buckests; 
};
typedef struct table* tables;
tables newHashTable (int capacity);
elements put(tables H,elements e);

int main()
{
	return 0;
}