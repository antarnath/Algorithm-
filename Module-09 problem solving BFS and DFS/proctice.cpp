#include<bits/stdc++.h>
using namespace std;


int main(){
    int arr[10] = {1, 3, 4, 5, 7, 8, 9 ,19, 11, 30};
    int *ptr = arr;
    // printf("%d", *ptr);
    // printf("%d", (++(*ptr))++);
    // printf("%d", arr[0]);
    printf("%d\n", *(ptr++));
    printf("%d\n", *ptr);

}