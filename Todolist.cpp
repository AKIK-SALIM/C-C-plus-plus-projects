#include<bits/stdc++.h>
using namespace std;

struct todoList{

    int id;
    string task;
};

int ID=0;
void banner();
void addTask();
void showTask();
int searchTask();
void deleteTask();
void updateTask();
void initializeID();

int main(void)
{
    system("cls");
    system("color 0A");
    while(true){
            banner();
        cout<<"\n\t1.Add Task";
        cout<<"\n\t2.Show Task";
        cout<<"\n\t3.Search Task";
        cout<<"\n\t4.Delete Task";
        cout<<"\n\t5.Update Task";

        int choice;
        cout<<"\n\tEnter Choice: ";
        cin>>choice;

        switch(choice){

        case 1:
            addTask();
            break;
        case 2:
            showTask();
            break;
        case 3:
            searchTask();
            break;
        case 4:
            deleteTask();
            break;
        case 5:
            updateTask();
            break;
        default:
            cout<<"Invalid Choices..."<<endl;
            break;
        }
    }
}
void banner(){

   cout<<"_________________________"<<endl;
   cout<<"\tMy Todo  "<<endl;
   cout<<"_________________________"<<endl;
}
void initializeID(){

    ifstream fin("todo.txt");
    todoList todo;

    while(!fin.eof()){
        fin>>todo.id
        fin.ignore();
        getline(fin,todo.task);
        ID=max(ID,todo.id);
    }
    fin.close();
}
void addTask(){

    system("cls");
    banner();
    todoList todo;
    cout<<"Enter new task: "<<endl;
    cin.get();
    getline(cin,todo.task);
    char s;
    cout<<"Save?(y/n):";
    cin>>s;
    if(s=='y'){
        ID++;
        ofstream fout;
        fout.open("todo.txt",ios::app);
        fout<<"\n"<<ID;
        fout<<"\n"<<todo.task;
        fout.close();

        char more;
        cout<<"Add More task?(y/n):";
        cin>>more;
        if(more=='y'){
            addTask();
        }
        else{
            system("cls");
            cout<<"Added Successfully!"<<endl;
            return;
        }

    }
   system("cls");
}
void showTask(){

    system("cls");
    banner();

    todoList todo;

    ifstream fin;

    fin.open("todo.txt");
    cout<<"Task: "<<endl;

    while(!fin.eof()){
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.task!=""){
            cout<<"\t"<<todo.id<<":"<<todo.task<<endl;
        }
        else{
            cout<<"\tEmpty!"<<endl;
        }
    }
    fin.close();
    char ex;
    cout<<"Exit?(y/n):";
    cin>>ex;
    if(ex!='y'){
        showTask();
    }
    system("cls");
}

int searchTask(){

     system("cls");
     banner();

     int id;
     cout<<"Enter task id:";
     cin>>id;
     todoList todo;

     ifstream fin("todo.txt");
     while(!fin.eof()){
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.id==id){
            system("cls");
            cout<<"\t"<<todo.id<<": "<<todo.task<<endl;
            return id;
        }
     }
     fin.close();
     system("cls");
     cout<<"Not found!"<<endl;
     return 0;
}

void deleteTask(){
   system("cls");
   int id=searchTask();
   if(id!=0){
      char d;
      cout<< "\n\tDelete?(y/n):";
      cin>>d;

      if(d=='y'){
         todoList todo;
         ofstream temp;

         temp.open("temp.txt");
         ifstream fin;
         fin.open("todo.txt");
         int i=1;
         while(!fin.eof()){
            fin>>todo.id;
            fin.ignore();
            getline(fin,todo.task);

            if(todo.id!=id){
                temp<<"\n"<<i;
                temp<<"\n"<<todo.task;
                i++;
                ID--;

            }
         }
         fin.close();
         temp.close();
         remove("todo.txt");
         rename("temp.txt","todo.txt");
         system("cls");
         cout<<"\n\tDeleted Successfully!"<<endl;

      }
      else{
          system("cls");
          cout<<"Not Deleted!"<<endl;
      }
   }
}

void updateTask(){

     system("cls");

     int id=searchTask();

     if(id==0) return;

     char u;

     cout<<"\n\tUpdate!(y/n):";
     cin>>u;

     if(u!='y')return;

     cin.ignore();

     string newTask;
     cout<<"Enter new Task:";
     getline(cin,newTask);

     ifstream fin("todo.txt");
     ofstream fout("temp.txt");

     todoList todo;

     while(!fin.eof()){
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);

        if(todo.id==id){
            fout<<todo.id<<endl<<newTask<<endl;
        }
        else{
            fout<<todo.id<<endl<<todo.task<<endl;
        }
     }
     fin.close();
     fout.close();

     remove("todo.txt");
     rename("temp.txt","todo.txt");
     system("cls");
     cout<<"\n\tUpdated Successfully!"<<endl;
}
