#include <iostream>
//reading from standard input and writing to standard output respectively
#include <fstream>
#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	char data[100];
	
	//open a file in write mode
	//used to create files and to write information to files
	ofstream outfile;
	outfile.open("afile.txt");
	
    cout << "Writing to the file" << endl;
    cout << "Enter your name: "; 
    cin.getline(data,100);
    
    //write inputted data into the file
    outfile<<data<<endl;
    
    cout<<"Enter your age:";
	cin>>data;
	cin.ignore();
	
	//again write inputted data into the file
    outfile<<data<<endl;
	
	//close the opened file.
	outfile.close();
	
	//open a file in read mode
	//used to read information from files
	ifstream infile;
	infile.open("afile.txt");
	
	//write the data at the screen
	cout<<"Reading from the file"<<endl;
	infile>>data;
    
    //again read the data from the file and display it
	cout<<data<<endl;
	
	//closr the opened file
	infile.close();
	
	return 0;
}
