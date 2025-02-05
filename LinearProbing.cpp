#include<iostream>
using namespace std;
int main(){
        int arr[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        int a=10;
        while(a--){
                cout<<"Enter element : ";
                int u;
                cin>>u;
                if(arr[u%10]==-1){
                        arr[u%10]=u;
                }
                else{
                        int yu=(u%10)+1;
                        while(arr[yu%10]!=-1){
                                yu=(yu+1)%10;
                        }
                        arr[yu]=u;
                }

                cout<<endl;
                for(int i=0;i<10;i++){
                        cout<<arr[i]<<" ";
                }
                cout<<endl;
        }
}