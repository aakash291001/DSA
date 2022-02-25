//For Strings as a key
// buckets will be the array which stores addresses of the node
#include<iostream>
#include<vector>
#include<string>
using namespace std;
template <typename V>
class Mapnode//Mapnode consists of Value, key, next
{
	public:
		string key;
		V value;
		Mapnode *next;
		Mapnode(string key,V value)
		{
			this->key = key;
			this->value = value;
			next = NULL;
		}
		~Mapnode(){
			delete next;
		}
};
template <typename V>
class ourmap{
	int getBucketIndex(string key)
	{
		//Example for "abc" hascode is  (a*p^2) + (b*p) + (c*p^0) 
		
		int hashCode;
		int currentCoff = 1;
		for(int i = key.length();i>=0;i--)
		{
			hashCode += key[i]*currentCoff;
			hashCode = hashCode%numBuckets;
			currentCoff = currentCoff*37 ;
			currentCoff = currentCoff%numBuckets;
			
		}
		return hashCode%numBuckets;
	}
	void rehash(){
		Mapnode<V>** temp = buckets;
		buckets = new Mapnode<V>*[2*numBuckets];
		for(int i = 0;i<2*numBuckets;i++)
		{
			buckets[i]=NULL;//this is to remove the garbage value;
		}
		int oldBucketCount = numBuckets;
		numBuckets= 2*numBuckets;
		count =0;
		for(int i =0;i<oldBucketCount;i++)
		{
			Mapnode<V>* head = temp[i];
			while(head!=NULL)
			{
				string key = head->key;
				V value = head->value;
				insert(key,value);
				head = head->next;
			}
		}
		for(int i =0;i<oldBucketCount;i++)
		{
//			Mapnode<V>* head = temp[i];
			delete temp[i];
		}
		delete[] temp;
	}
	public:
		double getLoadFactor(){
			return (1.0*count)/numBuckets;
		}
		Mapnode<V>** buckets; //Buckets is the array pointer. this array stores the address of Mapnode;
		int count;//This will keep the total no. of elements
		int numBuckets;//This is the size of bucket array this will be equal to the no. of head pointer of the linked list it can store
		ourmap()
		{
			count = 0;
			numBuckets = 5;
			buckets = new Mapnode<V>*[numBuckets];
			for(int i= 0;i<numBuckets;i++)
			{
				buckets[i]=NULL;
			}
		}
		~ourmap()
		{
			for(int i= 0;i<numBuckets;i++)
			{
				delete buckets[i];//to delete head of each linked list or you can say to delete each element of buckets array
			}
			delete[] buckets;//to delete bucket array;
		}
		int size()
		{
			return count;
		}
		void insert(string key,V value)
		{
			//When we get the key we have to pass it through the hash function from which we get the bucket index
			//getBucketIndex is the hash function
			int bucketIndex = getBucketIndex(key);
			Mapnode<V>* head = buckets[bucketIndex];
			while(head!=NULL)
			{
				if(head->key==key)
				{
					head->value = value;//if there is already some value at that key than change it with the new value
					return;
				}
				head=head->next;
			}
			//now if it doesn't return there than it means we have to create a new node and insert it in the Linked list 
			Mapnode<V> *node;
			node = new Mapnode<V>(key,value);
			node->next = buckets[bucketIndex];
			buckets[bucketIndex] = node;
			count++;
			double loadFactor = (1.0*count)/numBuckets;//int/int is interger but load factor should be in decimal that is why we multiply count with 1.0
			if(loadFactor>0.7)
			{
				rehash();
			}
		} 
		V getValue(string key){
			int bucketIndex = getBucketIndex(key);
			Mapnode<V>* head = buckets[bucketIndex];
			while(head!=NULL)
			{
				if(head->key==key)
				{
					return head->value;
				}
				head=head->next;
			}
			return 0;
		}
		//remove can return value or it can return void also as V is used
		V remove(string key){
			//we have to delete it across a key so first we have to generate a bucket Index using hash function
			int bucketIndex = getBucketIndex(key);
			Mapnode<V> *head = buckets[bucketIndex];
			V value = NULL;
			Mapnode<V> *prev = NULL;
			while(head!=NULL)
			{	
				if(head->key == key)
				{
					if(prev==NULL)
					{
						buckets[bucketIndex] = head->next;
						head->next = NULL;
						value = head->value;
						delete head;
						count--;
						return value;
					}
					else
					{
						prev->next = head->next;
						head->next = NULL;
						value = head->value;
						delete head;
						count--;
						return value;
					}
				}
				prev = head;
				head= head->next;
			}
			return 0;
		}
};

int main()
{
	ourmap<int> map;
	for(int i =0;i<10;i++)
	{
		char c='0'+i;
		string key = "abc";
		key = key+c;
		int value = i+1;
		map.insert(key,value);
//		cout<<"load factor is "<<map.getLoadFactor()<<"\n";
	}
	map.remove("abc1");
	map.remove("abc5");
	cout<<map.size()<<"\n";
	for(int i =0;i<10;i++)
	{
		char c='0'+i;
		string key = "abc";
		key = key+c;
		int value = i+1;
		cout<<key<<":"<<map.getValue(key)<<"\n";
	}
	return 0;
}