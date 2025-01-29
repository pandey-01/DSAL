#include<iostream>
using namespace std;
class hash_table{
    int size=10;
    int arr[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    public:
    void insert(){
        int number;
        cout<<"Enter the number you want to insert : ";
        cin>>number;
        int loc=number%size;
        int count=0;
        while(arr[loc]!=-1 && arr[loc]!=-2 && count<=10){
            count+=1;
            loc=(loc+1)%size;
        }
        if(arr[loc]==-1 || arr[loc]==-2){
            arr[loc]=number;
            cout<<"Number successfully inserted."<<endl;
            return;
        }
        cout<<"Hash table already full."<<endl;
    }
    void get(){
        cout<<"Enter the number which you want to search : ";
        int number;
        cin>>number;
        int loc=number%size;
        int count=0;
        while(arr[loc]!=-1 && arr[loc]!=number && count<=10){
            count++;
            loc=(loc+1)%size;
        }
        if(arr[loc]==number){
            cout<<number<<" found at location "<<loc <<" in the hash table."<<endl;
            return; 
        }
        cout<<number<<" not found in the hash table."<<endl;
    }
    void print(){
        cout<<"Hash Table is : ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void dlt(){
        cout<<"Enter the data you want to delete : ";
        int number;
        cin>>number;
        int loc=number%size;
        int count=0;
        while(arr[loc]!=-1 && arr[loc]!=number && count<=10){
            count++;
            loc=(loc+1)%size;
        }
        if(arr[loc]!=number){
            cout<<number<<" not found in the hash table."<<endl;
            return; 
        }
        arr[loc]=-2;
        cout<<number<<" deleted successfully."<<endl;
    }
};
int main(){
    hash_table h;
    int choice;
    while(true){
        cout<<"Enter your choice :\n1.Insert Number\n2.Search Number\n3.Display Hash Table\n4.Delete Number\n5.Exit\n";
        cin>>choice;
        if(choice==1){
            h.insert();
        }
        else if(choice==2){
            h.get();
        }
        else if(choice==3){
            h.print();
        }
        else if(choice==4){
            h.dlt();
        }
        else{
            return 0;
        }
    }
    return 0;
}