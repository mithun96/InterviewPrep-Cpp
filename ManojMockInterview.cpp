#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>


int FindLength(int arr[], int n);

void main (){


	int a [] = {1,2,1,2,7,1,2,1};

	int result = FindLength (a, 5);

	//cout << result << endl;

	return;

}



int FindLength(int arr[], int n){

    int len = -1;
    int cur;
    int val =0 ;
    
    for (int i = 0; i < 8; i ++){
        cur = i; 
        while (cur < 8 && val < n ){
            if (val + arr[cur] <= n){
                val = val + arr[cur];
                cur++;
            }
            
        }
        if (val == n){
            len = cur - i + 1;
            break;
        }
            
    }
    
    return len;
}

