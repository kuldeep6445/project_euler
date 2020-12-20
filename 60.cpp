#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int limit = 100000;
vector<int> prime1,prime2,prime3,prime4,prime5;

bool get_prime(){
	bool arr[limit];
    memset(arr,true,sizeof(arr));
    for(int i=2;i*i<=limit;i++){
        if(arr[i]){
            for(int j=i*i;j<=limit;j+=i)
                arr[j]=false;
        }
    }
    for(int i=2;i<=limit;i++){
        if(arr[i]){
            if(i!=2 && i!=5)
                prime1.push_back(i);
        }
    }
    
}


int main(){
    
    get_prime();
    for(int i=0;i<100;i++)
        cout<<prime1[i]<<" ";
}