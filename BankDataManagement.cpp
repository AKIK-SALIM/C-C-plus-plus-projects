#include<bits/stdc++.h>
using namespace std;

class Bank{
    int accNo;
    string name, Fname,cnic,P_no,email;
    float amount;
    int newAmount;
    fstream file,file1;

public:
    int s; ///s for search

    void createAccount();
    void depositAmount();
    void withDrawAmount();
    void checkInfo();


}B;

int main(void)
{
    system("color 0A");
    char choice;

    while(true){
    cout<<"\n\n\t\t.......Akik's Bank.......";
    cout<<"\n\t\t Press 1 to Login Account ";
    cout<<"\n\t\t Press 2 to Create Account ";
    cout<<"\n\t\t Press 0 to Exit            ";
    cout<<"\n\t\t ..........................\n\t\t\t\t";
       cin>>choice;

       switch(choice){
      case '1':
        cout<<"Enter your account no.: ";
        cin>>B.s;
        while(true){
            cout<<"\n\n\n\t\t.......Akik's Bank.......";
            cout<<"\n\t\t Press 1 to Deposit Amount ";
            cout<<"\n\t\t Press 2 to Withdraw Amount ";
            cout<<"\n\t\t Press 3 to Check Info      ";
            cout<<"\n\t\t Press  0 to Exit Menu       ";
            cout<<"\n\t\t.............................\n\t\t\t\t";
            cin>>choice;

            switch(choice){
            case '1':
                B.depositAmount();
                break;
            case '2':
                B.withDrawAmount();
                break;
            case '3':
                cout<<"Enter your account number to check info:";
                cin>>B.s;
                B.checkInfo();
                break;
            case '0':
                return 0;
                break;
            default:
                cout<<"Invalid Choice..!";
                break;

            }
        }
        break;
            case '2':
                B.createAccount();
                break;
            case '0':
                return 0;
            default:
                cout<<"\nInvalid Choice...!";
       }

    }
}

void Bank::createAccount(){

   srand(time(0));
   accNo=rand()%100000+10000;

   cout<<"Enter your name:";
   cin>>ws; ///skips whitespace
   getline(cin,name);

   cout<<"Enter you Father name:";
   getline(cin,Fname);

   cout<<"Enter your cnic:";
   getline(cin,cnic);

   cout<<"Enter your phone number:";
   getline(cin,P_no);

   cout<<"Enter your Email:";
   getline(cin,email);

   cout<<"Enter your Amount:"<<endl;
   cin>>amount;

   cout<<accNo<<"This is your account number. Please save it"<<endl;

   file.open("data.txt",ios::out|ios::app);
   file<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<cnic<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
   file.close();

}

void Bank:: depositAmount(){

    cout<<"Enter amount to deposit:";
    cin>>newAmount;

    ifstream file("data.txt");
    ofstream file1("data1.txt");
    string line;
    bool f=false;
    while(getline(file,line)){
        stringstream ss(line);
        ss>>accNo;
        ss.ignore();
        getline(ss,name,'\t');
        getline(ss,Fname,'\t');
        getline(ss,cnic,'\t');
        getline(ss,P_no,'\t');
        getline(ss,email,'\t');
        ss>>amount;

        if(accNo==s){
                f=true;
            cout<<"\n Current Amount: "<<amount;
            amount=amount+newAmount;
            cout<<"\n Updated Amount: "<<amount<<endl;
        }
            file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<cnic<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
    }

    if(!f)
        cout<<"Account not found"<<endl;

    file.close();
    file1.close();

    remove("data.txt");
    rename("data1.txt","data.txt");
}
void Bank :: withDrawAmount(){

    cout<<"Enter amount to WithDraw:";
    cin>>newAmount;

    ifstream file("data.txt");
    ofstream file1("data1.txt");
    string line;

    bool f=false;


    while(getline(file,line)){
        stringstream ss(line);
        ss>>accNo;
        ss.ignore();
        getline(ss,name,'\t');
        getline(ss,Fname,'\t');
        getline(ss,cnic,'\t');
        getline(ss,P_no,'\t');
        getline(ss,email,'\t');
        ss>>amount;

        if(accNo==s){
                f=true;
            cout<<"\n Current Amount: "<<amount;
            amount=amount-newAmount;
            cout<<"\n Updated Amount: "<<amount<<endl;
        }
            file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<cnic<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
    }

    if(!f){
        cout<<"Account not found"<<endl;
    }

    file.close();
    file1.close();

    remove("data.txt");
    rename("data1.txt","data.txt");

}
void Bank :: checkInfo(){

    ifstream fi("data.txt");

    if(!fi){
        cout<<"File opening error!"<<endl;
        return;
    }

    string line;
    bool f=false;
    while(getline(fi,line)){
        stringstream ss(line);
        ss>>accNo;
        ss.ignore();
        getline(ss,name,'\t');
        getline(ss,Fname,'\t');
        getline(ss,cnic,'\t');
        getline(ss,P_no,'\t');
        getline(ss,email,'\t');
        ss>>amount;

        if(accNo==s){
          f=true;
        cout<<"\n-----------------------------\n";

        cout<<endl<<"\t Account Number: ";
        cout<<"\t "<<accNo<<endl;
        cout<<"\t User Name: ";
        cout<<"\t "<<name<<"\n";
        cout<<"\t Father Name: ";
        cout<<"\t "<<Fname<<"\n";
        cout<<"\t CNIC number: ";
        cout<<"\t "<<cnic<<"\n";
        cout<<"\t Phone Number: ";
        cout<<"\t "<<P_no<<"\n";
        cout<<"\t Email: ";
        cout<<"\t "<<email<<"\n";
        cout<<"\t Current Amount: ";
        cout<<"\t "<<amount<<endl;
        cout<<"\n-----------------------------\n";

        }
    }

    if(!f){
        cout<<"Account not Found!"<<endl;
    }
    fi.close();
}
