#include<iostream>
#include<fstream>
using namespace std;
int main(){
    cout<<"Jidnyasa Kale"<<endl;
    ofstream outputFile("example.txt");

    if(outputFile.is_open()){
        outputFile<<"Hello,this is a sample file.\n";
        outputFile<<"This is the second line of the file.\n";
        outputFile.close();
   
        cout<<"Data written to the file successfully.\n";
   }
    else{
       cerr<<"Error opening the file for writing.\n";
       return 1;
   }
   
   ifstream inputFile("example.txt");
   if(inputFile.is_open()) {
      cout<<"\nReading data from the file:\n";
   
      string line;
      while(getline(inputFile,line)){
         cout<<line<<"\n";
   }
   inputFile.close();
   }
   else
   {
   cerr<<"Error opening the file for reading.\n";
   return 1;
   }
  return 0;
}
