#include<iostream>
#include<string>
using namespace std;
class triNode
{
  public:
  char data;
  triNode **children;
  bool terminal;
  triNode(char data)
  {
    this->data= data;
    children = new triNode*[26];
    for(int i=0;i<26;i++)
    {
      children[i]=NULL;
    }
    terminal = false;
  }
};
class trie
{
  triNode *root;
  public:
  trie()
  {
    root = new triNode('\0');
  }
  void insert(string word)
  {
  	int l = word.length();
    insert(root,word);
    for(int i=1;i<l;i++)
    {
    	insert(root,word.substr(i));
	}
  }
  void insert(triNode *root,string word)
  {
    if(word.length() == 0)
    root->terminal = true;
    else
    {
      int index=word[0]-'a';
      triNode *child;
      if(root->children[index]!=NULL)
      {
        insert(root->children[index],word.substr(1));
      }
      else
      {
        child = new triNode(word[0]);
        root->children[index] = child;
        insert(child,word.substr(1));
      }
    }
  }
  bool search2(string word)
  {
  	return search2(root,word);
  }
  bool search2(triNode *root,string word)
  {
  	if(word.length() == 0)
    return true;
    else
    {
      int index = word[0]-'a';
      triNode *child;
      if(root->children[index]!=NULL)
      return search2(root->children[index],word.substr(1));
      else
      return false;
    }
  }
  bool search(string word)
  {
    return search(root,word);
  }
  bool search(triNode *root,string word)
  {
    if(word.length() == 0)
    return root->terminal;
    else
    {
      int index = word[0]-'a';
      triNode *child;
      if(root->children[index]!=NULL)
      return search(root->children[index],word.substr(1));
      else
      return false;
    }
  }
  void removeWord(string word){
  removeWord(root,word);
  }
  void removeWord(triNode *root,string word)
  {
    if(word.length()==0&&root->terminal==true)
    {
      root->terminal=false;
      return;
    }
    else
    {
      int index = word[0]-'a';
      triNode *child;
      if(root->children[index]!=NULL)
      {
        child = root->children[index];
        removeWord(child,word.substr(1));
      }
      else
      return;
      if(child->terminal==false)
      {
        for(int i=0;i<26;i++)
        {
          if(child->children[i]!=NULL)
          return;
        }
        delete child;
        root->children[index]= NULL;
      }
    }
  }
};
int main()
{
  trie t;
  t.insert("aakash");
  t.insert("madhav");
  t.insert("abhinav");
  t.removeWord("aakash");
  cout<<t.search("kash");
  return 0;
}