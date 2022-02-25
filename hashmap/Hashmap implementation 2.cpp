#include<iostream>
#include<vector>
#include<string>
using namespace std;
template <typename V>
class mapNode
{
	public:
		string key;
		V value;
		mapNode *next;
		mapNode(string key,V value)
		{
			this->key = key;
			this->value = value;
			next = NULL;
		}
		~mapNode()
		{
			delete next;
		}
};
template <typename V>
class ourmap
{
	private:
		int getBucketIndex(string key)
		{
			int hashCode;
			int coff=1;
			for(int i =key.length();i>=0;i--)
			{
				hashCode+=key[i]*coff;
				hashCode=hashCode%numBuckets;
				coff = coff*37;
				coff = coff%numBuckets;
			}
			return hashCode%numBuckets;
		}
		void rehash()
		{
			mapNode<V> **temp;
			temp = buckets;
			buckets = new mapNode<V>*[2*numBuckets];
			for(int i = 0;i<(2*numBuckets);i++)
			{
				buckets[i] = NULL;
			}
			int oldBuckets = numBuckets;
			numBuckets = 2 *numBuckets;
			for(int i = 0;i<oldBuckets;i++)
			{
				mapNode<V> *head = temp[i];
				while(head!=NULL)
				{
					insert(head->key,head->value);
					head=head->next;
				}
			}
			for(int i = 0;i<oldBuckets;i++)
			{
				delete temp[i];
			}
			delete[] temp;
		}
	public:
		mapNode<V> **buckets;
		int count;//No. of elements
		int numBuckets;
		ourmap()
		{
			count=0;
			numBuckets = 5;
			buckets = new mapNode<V>*[numBuckets];
			for(int i = 0;i<numBuckets;i++)
			{
				buckets[i]=NULL;
			}
		}
		~ourmap()
		{
			for(int i = 0;i<numBuckets;i++)
			{
				delete buckets[i];
			}
			delete[] buckets;
		}
		int size()
		{
			return count;
		}
		void insert(string key,V value)
		{
			int bucketIndex = getBucketIndex(key);
			mapNode<V> *head;
			head = buckets[bucketIndex];
			while(head!=NULL)
			{
				if(head->key == key)
				{
					head->value = value;
					return;
				}
				head = head->next;
			}
			mapNode<V> *node;
			node = new mapNode<V>(key,value);
			node->next = buckets[bucketIndex];
			buckets[bucketIndex] = node;
			count++;
			double loadFactor = (1.0*count)/numBuckets;
			if(loadFactor>0.7)
			{
				rehash();
			}
		}
		V getValue(string key)
		{
			int bucketIndex = getBucketIndex(key);
			mapNode<V> *head= buckets[bucketIndex];
			while(head!=NULL)
			{
				if(head->key == key)
				{
					return head->value;
				}
				head=head->next;
			}
			return 0;
		}
		V remove(string key)
		{
			int bucketIndex = getBucketIndex(key);
			mapNode<V> *head = buckets[bucketIndex];
			mapNode<V> *prev = NULL;
			while(head == NULL)
			{
				if(head->key == key)
				{
					if(prev==NULL)
					{
						buckets[bucketIndex]= head->next;
						head->next = NULL;
						V thisValue = head->value;
						delete head;
						count--;
						return thisValue;
					}
					else
					{
						prev->next = head->next;
						head->next = NULL;
						V thisValue = head->value;
						delete head;
						count--;
						return thisValue;
					}
				}
				prev = head;
				head=head->next;
			}
			return 0;
		}
};
int main()
{
	ourmap<string> map;
	for(int i=0;i<10;i++)
	{
		char c='A'+i;
		string key = "1";
		key+=c;
		char b = '0'+i;
		string value = "abc";
		value+=b;
		map.insert(key,value);
	}
	for(int i =0;i<10;i++)
	{
		char c='A'+i;
		string key = "1";
		key+=c;
		cout<<key<<":"<<map.getValue(key)<<"\n";
	}
	return 0;
}