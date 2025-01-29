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
        cout<<"Enter the number you want : ";
        int num;
        cin>>num;
        int key=num%10,count=0;
        if(arr[key][0]==-1){
            cout<<"Case 1"<<endl;
            arr[key][0]=num;
            cout<<"Number inserted successfully."<<endl;
            return;
        }
        else if(arr[key][0]!=-1 && arr[key][0]%10==key){
            while(arr[key][1]!=-1){
                key=arr[key][1];
            }
            int prev=key,count=0;
            while(count<=10 && arr[key][0]!=-1){
                key=(key+1)%10;
                count+=1;
            }
            if(arr[key][0]==-1){
                arr[key][0]=num;
                arr[prev][1]=key;
                cout<<"Number inserted successfully."<<endl;
                return;
            }
        }
        else if(arr[key][0]!=-1 && arr[key][0]%10!=key){
            int k=key;
            int count=0;
            int p;
            while(count<=10 && arr[key][0]!=-1){
                count+=1;
                if(arr[key][0]%10==k){
                    p=k;
                }
                key=(key+1)%10;
            }
            if(arr[key][0]==-1){
                arr[key][0]=num;
                arr[p][1]=k;
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
    while(true){
        cout<<"Enter choice : \n1.Insert Number\n2.Display\n3.Exit\n";
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