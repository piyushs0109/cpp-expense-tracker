#include<bits/stdc++.h>
using namespace std;

 struct expense {
    string name ;
    float amount ;
    string category ;
    string date ;
} ;


void addexpenses(vector<expense>& exp){

     expense e1 ;

     cout<<"Enter expense name:  ";
     cin.ignore();
    getline(cin, e1.name);

    cout<<"enter amount: ";
    cin>>e1.amount;
    cin.ignore();

    cout<<"Enter category: ";
    getline(cin, e1.category);

    cout << "Enter date (DD-MM-YYYY): ";
    getline(cin, e1.date);

    exp.push_back(e1);

    ofstream file("expenses.txt",ios::app);
        file<<e1.name<<"|"<<e1.amount<<"|"<<e1.category<<"|"<<e1.date<<endl;

        file.close();
    
        cout<<"\n expense added successfully "<<endl;


}

void viewexpenses(const vector<expense>& exp){
     for(int i =0 ; i<exp.size() ; i++){
            cout<<"   Exepnse Details   "<<endl;
        cout<<"Name : "<<exp[i].name<<endl;
        cout<<"Amount: "<<exp[i].amount<<endl;
        cout<<"Category : "<<exp[i].category<<endl;
        cout<<"date : " <<exp[i].date<<endl;

        if(exp.empty()) {
    cout << "\nNo expenses found." << endl;
    return;
}

}
}

void viewtotalexpenses(const vector<expense>& exp){
     float total = 0 ;
        for(int i=0;i<exp.size();i++){
            total = total + exp[i].amount ;
        }
        cout << "\nTotal Expense: Rs. " << total << endl;


}
void searchByCategory(const vector<expense>& exp){
    string searchcategory ;
         
        cout<<"enter category :";
        cin.ignore();
        getline(cin, searchcategory);

        bool found = false ;

        for(int i =0;i<exp.size();i++){ 

            if(searchcategory == exp[i].category){
                found = true ;  
                cout<<"Name :"<<exp[i].name<<endl;
                cout<<"Amount :"<<exp[i].amount<<endl;
            }

        } 
         if(!found){
                cout<<"No expense category found"; 
            }

}


int main(){

    vector<expense> exp;

    ifstream file("expenses.txt");

    string line ;

    while(getline(file, line)){
        stringstream ss(line);
        expense e1 ;
        string amount ;

        getline(ss, e1.name,'|');
        getline(ss, amount,'|');
        getline(ss, e1.category,'|');
        getline(ss,e1.date);


        e1.amount =stof(amount);

        exp.push_back(e1);
    }

    while(true){
    cout << "\n==================================" << endl;
cout << "        EXPENSE TRACKER" << endl;
cout << "==================================" << endl;
cout << "1. Add Expense" << endl;
cout << "2. View All Expenses" << endl;
cout << "3. View Total Expense" << endl;
cout << "4. Search By Category" << endl;
cout << "5. Exit" << endl;
cout << "==================================" << endl;
cout << "Enter your choice: ";

    int choice ;

    cin>>choice ;

 
    switch (choice) {
        case 1:
               addexpenses(exp);
               break ;
        case 2:
               viewexpenses(exp);
               break;
        case 3:
               viewtotalexpenses(exp);
               break;
        case 4:
               searchByCategory(exp);
               break;
        case 5:
               cout<<"exited";
               break;

        default :
               cout<<"invalid choice";
    }
       
    }
}
    
