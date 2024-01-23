#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

class Node{
    public:
    string task;
    string mark;
    Node *next;
    Node(){
        this->mark="     -       ";
        this->next=NULL;
    }
};

void add(Node* &head,Node* &tail){
    Node* New=new Node();
    if(head==NULL){
        New->next=head;
        head=New;
        tail=New;
    }
    else{
        tail->next=New;
        tail=New;
    }
    cout<<"Enter Your Task : ";
    cin.ignore();
    getline(cin,New->task);
    cout<<"\nTask Added Successfully....\n";
}

void doneundone(Node* &head,int tno){
    Node* temp=head;
    if(temp==NULL){
        cout<<"\nTO-DO List is Empty\nAdd A Task First\n\n";
    }else if(tno==1){
        if(temp->mark=="     -       ")
            temp->mark="     *       ";
            else if(temp->mark=="     *       ")
            temp->mark="     -       ";
    }else{
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(cnt==tno){
            temp=head;
            for(int i=1;i<cnt;i++){
                temp=temp->next;
            }
            if(temp->mark=="     -       ")
            temp->mark="     *       ";
            else if(temp->mark=="     *       ")
            temp->mark="     -       ";
        }else if(tno>cnt){
            cout<<"\nTask No. Invalid\nEnter Correct Input\n";
        }else{
            temp=head;
            for(int i=1;i<tno;i++){
                temp=temp->next;
            }
            if(temp->mark=="     -       ")
            temp->mark="     *       ";
            else if(temp->mark=="     *       ")
            temp->mark="     -       ";
        }
    }
}

void removetask(Node* &head,Node* &tail,int tno){
    Node* temp=head;
    Node* temp2;
    if(tno==1){
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
    if(cnt<tno){
        cout<<"\nInvalid Task No. !\nEnter Correct Input\n";
        return;
    }
    else if(tno==cnt){
        temp=head;
        for(int i=1;i<cnt;i++){
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=NULL;
        tail=temp2;
        delete temp;
    }else{
        temp=head;
        for(int i=1;i<tno;i++){
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=temp->next;
        temp->next=NULL;
        delete temp;
    }
    cout<<"\nTask removed Successfully...\n";
}

void print(Node* &head,int &num){
    Node* print=head;
    if(print==NULL){
        cout<<"\nTO-DO List is Empty\nAdd A Task First\n\n";
        return;
    }
    cout<<"\nTABLE ------------>>>\n";
    cout<<"No.  Done/Undone    Task";
    num=0;
    while(print!=NULL){
        num++;
        cout<<"\n"<<num<<"    "<<print->mark<<"  "<<print->task;
        print=print->next;
    }
    cout<<endl;
}

int main(){
    int num,choice1,tno;
    bool a = true;
        cout<<"\n   <````````````````````````\n";
        cout<<"          ---->  TO-DO LIST  <----\n";
        cout<<"             BY--> <codercastor/>\n";
        cout<<"              ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,/>\n";
    Node* head=NULL;
    Node* tail=NULL;

    do{ 
        srand(time(NULL));
        int random = rand() % 10 + 1;
        cout<<"\n#Quote -> ";
        if(random==1)
            cout<<"Don't let the fear of striking out keep you from playing the game. - Babe Ruth\n";
        else if(random==2)
            cout<<"The most difficult thing is the decision to act, the rest is merely tenacity. - Amelia Earhart\n";
        else if(random==3)
            cout<<"You are never too old to set another goal or to dream a new dream. - C.S. Lewis\n";
        else if(random==4)
            cout<<"Success is not final, failure is not fatal: it is the courage to continue that counts. - Winston Churchill\n";
        else if(random==5)
            cout<<"Believe you can and you're halfway there. - Theodore Roosevelt\n";
        else if(random==6)
            cout<<"The secret of getting ahead is getting started. - Mark Twain\n";
        else if(random==7)
            cout<<"Dream big and dare to fail. - Norman Vaughan\n";
        else if(random==8)
            cout<<"It always seems impossible until it's done. - Nelson Mandela\n";
        else if(random==9)
            cout<<"If you can dream it, you can do it. - Walt Disney\n";
        else if(random==10)
            cout<<"A goal without a plan is just a wish. - Antoine de Saint-Exupery\n";
        cout<<"\nOptions --->>>\n 1.Add Task\n 2.Mark Done/Undone\n 3.Remove Task\n 4.Table of Tasks\n 5.Exit\nEnter Here -->";
        cin>>choice1;
        switch(choice1){
            case 1:{
                add(head,tail);
                break;
            }

            case 2:
                cout<<"Enter No. of Task : ";
                cin>>tno;
                doneundone(head,tno);
                break;

            case 3:
                if(head==NULL){
                    cout<<"\nTO-DO List is Empty\nAdd A Task First\n";
                    break;
                }
                cout<<"Enter No. of Task : ";
                cin>>tno;
                removetask(head,tail,tno);
                break;

            case 4:
                print(head,num);
                break;

            case 5:
                a = false;
                break;

            default:
                cout<<"\nInvalid Input !\nEnter Correct Option Between 1-5\n";
                break;
            }
    }while(a);
    return 0;
}