/*
 * Print diamond
 *
 * Given a number N. Print diamond of 2N rows as in.
 *
 */
#include<iostream>
using namespace std;

int main() {
	
	int n;
    
    cin>>n;
    int row = 1;
    while(row <= n){
        int stars_count = 1;
        while(stars_count <= n -row){
            cout<<" ";
            stars_count++;
        }
        stars_count = 1;
        while(stars_count <= 2 * row - 1){
            cout<<"*";
            stars_count++;
        }
        cout<<endl;
        row++;
    }
    row = n;
    while(row >= 1){
        int stars_count = 1;
        while(stars_count <= n - row){
            cout<<" ";
            stars_count++;
        } 
        stars_count = 1;
        while(stars_count <= 2 * row - 1){
            cout<<"*";
            stars_count++;
        }
        cout<<"\n";
        row--;
    }
    
    
    
    
    
    return 0;
}

