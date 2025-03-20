#include<bits/stdc++.h>
using namespace std;

// DFS function
void dfs_nr(int i,int a,int G[][100],int visited[]) {
    stack<int> s;
    s.push(i);
    while(!s.empty()) {
        int i=s.top();
        s.pop();
        if(visited[i] != 1) {
            cout<<i<<" ";
            visited[i] = 1;
            for(int j=0;j<a;j++) {
                if(visited[j]!=1&&G[i][j]==1) {
                    s.push(j);
                }
            }
        }
    }
    cout<<endl;
}

void BFT(int i, int a, int G[][100], int visited[]) {
    queue<int> Q;
    visited[i] = 1;
    Q.push(i);
    while (!Q.empty()) {
        i = Q.front();
        Q.pop();
        cout << i << " ";
        for (int j = 0; j < a; j++) {
            if (visited[j] != 1 && G[i][j] == 1) {
                visited[j] = 1;
                Q.push(j);
            }
        }
    }
}


int main() {
    cout << "Enter the number of nodes in the graph: ";
    int a;cin >> a;
    int G[100][100];
    int visited[100] = {0};
    cout << "Enter matrix : ";
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < a; j++) {
            cin >> G[i][j];
        }
    }
    cout<<endl;
    dfs_nr(0, a, G, visited);
    BFT(0,a,G,visited);
    cout<<endl;
}
