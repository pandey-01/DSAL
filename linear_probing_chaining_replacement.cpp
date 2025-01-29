#include<iostream>
using namespace std;
class hash_table{
    int arr[10][2];
    public:
    hash_table(){
        for(int i=0;i<10;i++){
            arr[i][0]=-1;
            arr[i][1]=-1;
        }
    }
    void insert(){
        int num;
        cout<<"Enter the number you want to insert : ";
        cin>>num;
        int key=num%10;
        if(arr[key][0]==-1){
            cout<<"Case 1"<<endl;
            arr[key][0]=num;
            cout<<"Number inserted successfully."<<endl;
            return;
        }
        else if(arr[key][0]!=-1 && arr[key][1]==-1 && arr[key][0]%10==key){
            cout<<"Case 2"<<endl;
            int count=0;
            int p=key;
            while(count<=10 && arr[key][0]!=-1){
                count++;
                key=(key+1)%10;
            }
            if(arr[key][0]==-1){
                arr[key][0]=num;
                arr[p][1]=key;
                cout<<"Number inserted successfully."<<endl;
                return;
            }
            cout<<"Hash Table is full."<<endl;
        }
        else if(arr[key][0]!=-1 && arr[key][0]%10==key){
            cout<<"Case 3"<<endl;
            key=arr[key][1];
            while(arr[key][1]!=-1){
                key=arr[key][1];
            }
            int curr=key;
            int count=0;
            while(count <=10 && arr[key][0]!=-1){
                key=(key+1)%10;
                count++;
            }
            if(arr[key][0]==-1){
                arr[key][0]=num;
                arr[curr][1]=key;
                cout<<"Number inserted successfully."<<endl;
                return;
            }
            cout<<"Hash table is full."<<endl;
        }
        else if(arr[key][0]!=-1 && arr[key][1]%10!=key){
            cout<<"Case 4"<<endl;
            int rep=arr[key][0],count=0;
            int c=key-1;
            while(count<=10 && arr[c][0]%10!=arr[key][0]%10){
                count++;
                c--;
            }
            int p=key;
            count=0;
            while(count<=10 && arr[key][0]!=-1){
                count++;
                key=(key+1)%10;
            }
            if(arr[key][0]==-1){
                arr[key][0]=arr[p][0];
                arr[p][0]=num;
                arr[p][1]=-1;
                cout<<"Number inserted successfully."<<endl;
                //return;
            }
            if(arr[c][0]%10==arr[key][0]%10){
                arr[c][1]=key;

            }
        }
        cout<<"Hash Table is full."<<endl;
    }
    void display(){
        cout<<"The hash table is : "<<endl;
        for(int i=0;i<10;i++){
            cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
        }
        cout<<"\n\n";
    }
};
int main(){
    hash_table h;
    int choice;
    while(1){
        cout<<"Enter choice :\n1.Insert Number\n2.Display Hashtable\n3.Exit\n";
        cin>>choice;
        if(choice==1){
            h.insert();
        }
        else if(choice==2){
            h.display();
        }
        else{
            return 0;
        }
    }
    return 0;
}