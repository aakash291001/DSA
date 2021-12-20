#include<iostream>
#include<string>
using namespace std;
int main()
{

  string s1("Hello");
  string s2 = "hello world";
  string s3(s2);
  string s4 = s3;
  char a[] = {'a','b','c',' ','d','\0'};
  string s0(a);
  string s5;
  cout<<s0<<"\n";
  cout<<s1<<"\n";
  cout<<s2<<"\n";
  cout<<s3<<"\n";
  cout<<s4<<"\n";
  cout<<s0.empty()<<"\n";
  cout<<s5.empty()<<"\n";
  s1.append(" Aji lund mera");
  s2+=" Delhi se hu bc";
  cout<<s1<<"\n";
  cout<<s2<<"\n";
  cout<<s0.length()<<"\n";
  s0.clear();
  cout<<s0.length()<<"\n";
  cout<<s3.compare(s1)<<"\n";https://www.onlinegdb.com/online_c++_compiler#tab-stdin
  if(s1>s2)
  {
    cout<<"s1 is greater\n";
  }
  else
  cout<<"s2 is greater\n";
  string s6 = "i am the best\n";
  int ind = s6.find("the");
  cout<<ind<<"\n";
  string word = "the";
  int lenght = word.length();
  s6.erase(ind,lenght+1);
  cout<<s6<<"\n";
  for(auto it = s6.begin();it!=s6.end();it++)
  {
    cout<<(*it)<<":";
  }
  return 0;
}