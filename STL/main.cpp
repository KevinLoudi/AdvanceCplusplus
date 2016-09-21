////C++ STL (Standard Template Library)
////vectors, lists, queues, and stacks
////well-structures components like containers, algorithms
////iterators
//#include <iostream>
//#include <vector>
//using namespace std;
// 
//int main()
//{
//   // create a vector to store int
//   vector<int> vec; 
//   int i;
//
//   // display the original size of vec
//   cout << "vector size = " << vec.size() << endl;
//
//   // push 5 values into the vector
//   for(i = 0; i < 5; i++){
//      vec.push_back(i);
//   }
//
//   // display extended size of vec
//   cout << "extended vector size = " << vec.size() << endl;
//
//   // access 5 values from the vector
//   for(i = 0; i < 5; i++){
//      cout << "value of vec [" << i << "] = " << vec[i] << endl;
//   }
//
//   // use iterator to access the values
//   vector<int>::iterator v = vec.begin();
//   while( v != vec.end()) {
//      cout << "value of v = " << *v << endl;
//      v++;
//   }
//   
//
//   cout<<"Use loop"<<endl;
//   for(v=vec.begin();v!=vec.end();v++)
//   {
//   	  cout << "value of v = " << *v << endl;
//   }
//
//   return 0;
//}

#include<fstream>
#include<string>
#include<iostream>
#include <list>
#include <cctype>
#include <algorithm>
#include <iomanip>
using namespace std;

void get_word(istream &in_stream,string &w);
void insert_word(string words,list<string>&wordlist);
void display_list(ofstream &out_stream,list<string>wordlist);

int main()
{
	ifstream in_stream;
	ofstream out_stream;

	string infile,outfile;
	string words;

	outfile="D:\\Code\\C++\\VS\\FileContentAnalysis\\Debug\\Div.txt";
	infile="D:\\Code\\C++\\VS\\FileContentAnalysis\\Debug\\Sentence.txt";
	in_stream.open(infile.c_str(),ios::in);
	
    if(in_stream.fail())
	{
		cout<<"Cannot open the file "<<infile<<endl;
	}else{
		out_stream.open(outfile.c_str(),ios::out);
		list<string> wordlist;
		list<string>::iterator iter;
		get_word(in_stream,words);

		while(words.size())
		{
			insert_word(words,wordlist);
			get_word(in_stream,words);
		}
		wordlist.sort();
		out_stream<<"There were "<<wordlist.size()<<" distinct words. \n";
		out_stream<<"\nHere is the ordered list of words:\n";
		for(iter=wordlist.begin();iter!=wordlist.end();iter++)
		{
			cout<<(*iter)<<" "; 
		} 
		display_list(out_stream,wordlist);
	}
   return 0;
}

//loss a reference mark could be deadly
void insert_word(string words,list<string>&wordlist)
{
	list<string>::iterator iter;

	//find a matcher in the list to the input word
	iter=find(wordlist.begin(),wordlist.end(),words);

	if (iter==wordlist.end())
	{
		//word is not in the list
		wordlist.insert(iter,words);
	}
}

void get_word(istream &in_stream,string &w)
{
	char ch;
	w="";

	in_stream.get(ch);
	//skip noalpha
	while(!isalpha(ch)&&!in_stream.eof())
	{
		in_stream.get(ch);
	}

	//read and store alpha
	while(isalpha(ch)&&!in_stream.eof())
	{
		ch=tolower(ch);
		w+=ch;
		in_stream.get(ch);
	}

}

void display_list(ofstream &out_stream,list<string>wordlist)
{
	int column(3),counter(0);
	list<string>::iterator iter;
	out_stream<<setiosflags(ios::left);

	iter=wordlist.begin();
	while(iter!=wordlist.end())
	{
		out_stream<<setw(20)<<(*iter).c_str();
		iter++;
		counter++;
		if (counter%column==0)
		{
			out_stream<<endl;
		}
	}
}
