#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct PersonalRecord{
string name;
string dob;
string phoneNumber;
};
void displayRecord(const PersonalRecord& record){
cout<<"Name:"<<record.name<<"\nDOB:"<<record.dob<<"\nTelephone :"<<record.phoneNumber<<endl;
}
 bool compareByName(const PersonalRecord& record1,const PersonalRecord& record2){
 return record1.name<record2.name;
 }
  bool searchByName(const PersonalRecord& record1,const string& name){
  return record1.name==name;
  }
  int main()
  {
  vector<PersonalRecord>records;
  records.push_back({"jidnya kale","1990-05-15","555-1234"});
  records.push_back({"vaish karle","1990-05-15","777-1234"});
  records.push_back({"neha patil","1990-05-15","888-1234"});
  cout<<"Original Records:\n";
  for(const auto& record:records){
  displayRecord(record);
   }
   sort(records.begin(),records.end(),compareByName);
   cout<<"\nSorted Records by Name:\n";
    for(const auto& record:records){
     displayRecord(record);
  }
  string searchName="jidnyasa kale";
  auto it=find_if(records.begin(),records.end(),[&searchName](const PersonalRecord& record){
   return searchByName(record,searchName);
   });
  if(it !=records.end()){
   cout<<"\nRecord found:\n";
   displayRecord(*it);
   }
   else
   {
   cout<<"\nRecord not found for name:"<<searchByName<<endl;
   }
    return 0;
 }
