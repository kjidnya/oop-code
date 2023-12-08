#include<iostream>
#include<string>
using namespace std;
class Publication{
protected:
	string title;
	float price;
	
public:
	Publication():title(""),price(0.0){}
	
	virtual void getData(){
	cout<<"Jidnaysa kale:";
	cout<<"\nEnter title:";
	getline(std::cin,title);
	cout<<"Enter price:";
	cin>>price;
	}
	virtual void displayData()const{
	cout<<"Title:"<<title<<endl;
	cout<<"Price:$"<<price<<endl;
	}
};
class Book:public Publication{
private:
	int pageCount;
	
public:
	Book():pageCount(0){}
	
	void getData()override{
	   Publication::getData();
cout<<"Enter page count:";
cin>>pageCount;
}
	void displayData()const override{
	   Publication::displayData();
cout<<"Page Count:"<<pageCount<<"pages";
}
};

class Tape:public Publication{
private:
	float playingTime;
	
public:
	Tape():playingTime(0.0){}
	
	void getData()override{
	   Publication::getData();
cout<<"Enter playing time(in minutes):";
cin>>playingTime;
}

	void displayData()const override{
	   Publication::displayData();
cout<<"Playing Time:"<<playingTime<<"minutes"<<std::endl;
}
};
int main(){
  try{
     Book book;
     Tape tape;
     
cout<<"Enter data for the book:\n";
     book.getData();
cout<<"Enter data for the tape:\n";
     tape.getData();
     
cout<<"\nBook Information:\n";
     book.displayData();
     
  
cout<<"\nTape Information:\n";
     tape.displayData();
}catch(...){

cerr<<"An exception occured.Setting all values to zero.\n";
}
  return 0;
}
