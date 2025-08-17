    #include <bits/stdc++.h>
    using namespace std;
    void print(int times, char c){
        for(int i=1; i <= times; i++){
            cout<<c<<" ";
        }
        
        
    }
    int main() {
        int lines;
        cin>>lines;
        while(lines--){
            int t;
            cin>>t;
            char c;
            cin>>c; 
            print(t, c);
            cout<<endl;
        }
	    return 0;
    }