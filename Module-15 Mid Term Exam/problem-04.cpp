#include<bits/stdc++.h>
using namespace std;

void printCombination(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void printAllCombination(int i, int n, vector<int> &v){
    if(n==0){
        printCombination(v);
        return;
    }

    for(int j=i; j<=n; j++){
        v.push_back(j);
        printAllCombination(j, n-j, v);
        v.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    printAllCombination(1, n, v);

    return 0;
}













/* 

1, 1, 1, 1, 1
1, 1, 1, 2
1, 1, 3
1, 2, 2
1, 4
2, 3
5

i=5, n=5

j n
1 5
    v=1
    1 4     
        v=1, 1
        1 3     
            v=1, 1, 1
            1 2     
                v=1, 1, 1, 1
                1 1     
                    v=1, 1, 1, 1, 1
                    1 0 print(1, 1, 1, 1, 1) return
                v=1, 1, 1, 1
            v=1, 1, 1
            2 2
                v=1, 1, 1, 2
                2, 0 print (1, 1, 1, 2) return
            v=1, 1, 1    
        v=1, 1
        2 3
            v = 1, 1, 2
            2 1 return
        v = 1, 1
        3 3
            v = 1, 1, 3
            3 0 print (1, 1, 3) return
        v = 1, 1
    v=1
    2 4
        v = 1 ,2
        2 2
            v = 1, 2, 2
            2 0 print(1, 2, 2) return
        v = 1, 2
    v = 1
    3 4
        v=1, 3
        3 1 return
    v = 1
    4 4
        v = 1, 4
        4 0 print(1, 4) return
    v = 1
v
2 5
    v = 2
    2 3
        v = 2 3
        2 1 return
    v = 2
    3 3
        v = 2 3
        3 0 pirnt(2, 3) return
v
3 5
    v = 3
    3 2 return
v
4 5
    v = 4
    4 1 return
v
5 5
    v = 5
    5 0
    print(5) return
v
return main

        









 */