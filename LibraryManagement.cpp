#include<bits/stdc++.h>
using namespace std;

class Library{

     string id,name,author,s;
     fstream f;

 public:
    void addBook();
    void showAll();
    void extractBook();

}lib;

int main(void)
{
    system("color 0A");
    char choice;
    cout<<"-------Akik Library-------"<<endl;
    cout<<"1.Show All Books"<<endl;
    cout<<"2.Extract Book"<<endl;
    cout<<"3.Add Books(ADMIN)"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){

   case '1':
       cin.ignore();
       lib.showAll();
     break;
   case '2':
       cin.ignore();
       lib.extractBook();
    break;
   case '3':
       cin.ignore();
       lib.addBook();
      break;
   case '4':
       cin.ignore();
       return 0;
     break;
   default:
      cout<<"Invalid Choices....!"<<endl;
      break;
    }

}

void Library::addBook(){
   cout<<endl;

   cout<<"Enter Book ID:";
   getline(cin,id);
   cout<<"Enter Book Name:";
   getline(cin,name);
   cout<<"Enter Book's Author Name:";
   getline(cin,author);

   cout<<endl;

   cout<<"Book Added successfully"<<endl;

   f.open("bookData.txt",ios::out| ios::app);
   f<<id<<"*"<<name<<"*"<<author<<endl;
   f.close();
}

void Library :: showAll(){

    f.open("bookData.txt",ios::in);
    getline(f,id,'*');
    getline(f,name,'*');
    getline(f,author,'\n');

        cout<<"\n\n";
        cout<<"\t\tBook Id\t\t\tBook Name\t\t\tAuthor's Name"<<endl;
    while(!f.eof()){
       cout<<"\t\t"<<id<<"\t\t\t"<<name<<"\t\t\t"<<author<<endl;
    getline(f,id,'*');
    getline(f,name,'*');
    getline(f,author,'\n');
    }
    f.close();
}

void Library :: extractBook(){

    showAll();
    cout<<"Enter Book Id:";
    getline(cin,s);


    f.open("bookData.txt",ios:: in);
    getline(f,id,'*');
    getline(f,name,'*');
    getline(f,author,'\n');
    cout<<"\n\n";
    cout<<"\t\tBook Id\t\t\tBook Name\t\t\tAuthor's Name"<<endl;

    while(!f.eof()){

    if(s==id){
        cout<<"\t\t"<<id<<"\t\t\t"<<name<<"\t\t\t"<<author<<endl;
        cout<<"Book Extracted Successfully!"<<endl;
    }
    getline(f,id,'*');
    getline(f,name,'*');
    getline(f,author,'\n');
    }

 f.close();
}
