/*------------------------------RAILWAY TICKET BOOKING------------------------------*/
//Concepts of class-objects, inline functions, constructor, this pointer, inheritence(multi-level inh), try-catch exceptions, methods in STL, files
#include<bits/stdc++.h>
using namespace std; 
class BookTicket{
public:
    long long bearthNo,age,phNo;
    float fare;
    string name,email,arrival,depart,type;
public:
    void selectBearth(){
        cout<<"\t\tSelect your Bearth Number (1-72) : ";
        cin>>bearthNo;
        cout<<endl;
        if(bearthNo % 8 == 1 || bearthNo % 8 == 4)
            type="LOWER";
        else if(bearthNo % 8 == 2 || bearthNo % 8 == 5)
            type="MIDDLE";
        else if(bearthNo % 8 == 3 || bearthNo % 8 == 6)
            type="UPPER";
        else if(bearthNo % 8 == 7)
            type="SIDE LOWER";
        else
            type="SIDE UPPER";
    } 
    void getDetails(string, string, float);
};
void BookTicket::getDetails(string arrival, string depart, float fare){
        cout<<"\n\tEnter your Name, Age, Contact No, Email : ";
        cin>>name>>age>>phNo>>email;
        this->arrival=arrival;
        this->depart=depart;
        this->fare=fare;
}
class Verify : public BookTicket{
protected:
    bool com=false,at=false;
    bool mobileNo=false,Email=false;
public:
    bool verifyMobile(){
        long long pNo=phNo,c=0;
        while(pNo!=0){
            pNo=pNo/10;
            c++;
        }
        try{
            if(c==10){
                cout<<"\t\tMobile number verified....."<<endl;
                mobileNo=true;
                return mobileNo;
            }
            else
                throw phNo;
        }
        catch(...){
            cout<<"\t\tInvalid Mobile Number.....(ex :- 984xxxx89)"<<endl;
            return mobileNo;
        }
    }
    bool verifyEmail(){
        int size=email.length();
        try{
            if(count(email.begin(),email.end(),'@')==1)
                at=true;
            if(email.substr(size-4, size)==".com"){
                if(count(email.begin(),email.end(),'.')==1)
                    com=true;
            }
            if(at & com){
                cout<<"\t\tEmail ID verified....."<<endl;
                Email=true;
                return Email;
            }
            else
                throw email;
        }
        catch(...){
            cout<<"\t\tInvalid Email Id.....(ex :- xxxxx@gmail.com)"<<endl;
            return Email;
        }
    } 
};
class Print : public Verify{
public:
    Print(Verify obj){
        name=obj.name;
        age=obj.age;
        phNo=obj.phNo;
        email=obj.email;
        arrival=obj.arrival;
        depart=obj.depart;
        bearthNo=obj.bearthNo;
        type=obj.type;
        fare=obj.fare;
    }
    inline float evaluate(float);
    void printTicket(){
        time_t ticket_time=time(NULL);
        fstream fileObj; 
        fileObj.open("Ticket.txt",ios::out);
        fileObj<<"\t\t\t*********************************************"<<endl;
        fileObj<<"\t\t\t               ACKNOWLEDGEMENT               "<<endl;
        fileObj<<"\t\t\t*********************************************"<<endl;
        fileObj<<"\t\t\t\tName : "<<name<<endl<<endl<<"\t\t\t\tAge : "<<age<<endl<<endl;
        fileObj<<"\t\t\t\tMobile No : "<<phNo<<endl<<endl<<"\t\t\t\tEmail ID : "<<email<<endl<<endl;
        fileObj<<"\t\t\t\tArrival : "<<arrival<<endl<<endl<<"\t\t\t\tDeparture : "<<depart<<endl<<endl;
        fileObj<<"\t\t\t\tCoach : AC"<<endl<<endl<<"\t\t\t\tBearth No : "<<bearthNo<<endl<<endl;
        fileObj<<"\t\t\t\tBearth Type : "<<type<<endl<<endl<<"\t\t\t\tTotal Fare : "<<fare<<"/-"<<endl<<endl;
        fileObj<<"\t\tStatus : Booking Confirmed on "<<ctime(&ticket_time)<<endl<<endl;
        fileObj.close();
    }
    void cancellTicket(){
        time_t cancelTicket_time=time(NULL);
        fstream fileObj;
        fileObj.open("CancelTicket.txt",ios::app);
        if(fileObj.is_open()){
            fileObj<<"\t\t\t*********************************************"<<endl;
            fileObj<<"\t\t\t             CANCELLATION RECIPT             "<<endl;
            fileObj<<"\t\t\t*********************************************"<<endl;
            fileObj<<"\t\t\t\tName : "<<name<<endl<<endl<<"\t\t\t\tAge : "<<age<<endl<<endl;
            fileObj<<"\t\t\t\tMobile No : "<<phNo<<endl<<endl<<"\t\t\t\tEmail ID : "<<email<<endl<<endl;
            fileObj<<"\t\t\t\tRefund : "<<evaluate(fare)<<"/-"<<endl<<endl<<"\t\t\t\tCancellation Charges : "<<fare-evaluate(fare)<<"/-"<<endl<<endl;
            fileObj<<"\t\tStatus : Booking Cancelled on "<<ctime(&cancelTicket_time)<<endl<<endl;
            fileObj.close();
        }
    }
};
inline float Print::evaluate(float fare){
    return (fare-(fare*0.050));
}
int main(){
    int route;
    char ch;
    cout<<"\t\t--------Railway Ticket Booking--------\n";
    cout<<"\t\t-----------Deccan Railways------------\n";
    cout<<"\t\t**************************************\n";
    cout<<"\t\t           Available Routes           \n";
    cout<<"\t\t**************************************\n\n";
    cout<<"\t\t-----------AC sleeper Coach-----------\n\n";
    cout<<"\t\t1) Mysore - Srinagar : 3000/-"<<endl;
    cout<<"\t\t2) Bangalore - KolKata : 2500/-"<<endl;
    cout<<"\t\t3) Delhi - Bombay : 2000/-"<<endl;
    cout<<"\t\t4) Secundrabad - Madras : 1750/-"<<endl;
    cout<<"\t\t5) Vijayawada - Vizag : 1500/-"<<endl;
    cout<<"\t\t\tSelect your route no : ";
    cin>>route;
    Verify V;
    switch(route)
    {
        case 1 : V.getDetails("Mysore","Srinagar",3000);
                 break;
        case 2 : V.getDetails("Bangalore","Kolkata",2500);
                 break;
        case 3 : V.getDetails("Delhi","Bombay",2000);
                 break;
        case 4 : V.getDetails("Secundrabad","Madras",1750);
                 break;
        case 5 : V.getDetails("Vijayawada","Vizag",1500);
                 break;
        default: cout<<"\t\t\tInvalid Route\n";
    }
    bool mobile = V.verifyMobile();
    bool mail = V.verifyEmail();
    if(mobile == false | mail == false)
        return 0;
    V.selectBearth();
    Print P(V);
    P.printTicket();
    cout<<"\t\tTicket printed into text file.....\n";
    cout<<"\t\tDo you want to cancel your ticket or not [y/n] : ";
    cin>>ch;
    if(ch=='y'){
        P.cancellTicket();
        cout<<"\t\tCancelation recipt printed into text file.....\n";
    }
}