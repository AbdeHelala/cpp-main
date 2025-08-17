    #include <bits/stdc++.h>
    using namespace std;
    void max_min(int arr[], int size){
        sort(arr, arr+size);
    }
    int main() {
    	int size;
    	cin>>size;
    	int arr[size];
    	for(int i =0; i <size; i++){
    	    cin>>arr[i];
    	}
    	max_min(arr, size);
    	cout<<arr[0]<<" "<<arr[size-1];
    	        return 0;
    }