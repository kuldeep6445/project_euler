#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void show_vector(vector<string> &a){
    for(int i=0;i<a.size();i++){
        cout<<i+1<<". "<<a[i]<<"\n";
    }
    cout<<"\n\n\n";
}

void get_combn(vector<string> &combn,int level,int size){
    if(level==size){
        combn.pop_back();
        return;
    }
    int size1 = combn.size();
    for(int i=0;i<size1;i++){
        string t = combn[i];
        combn[i] = combn[i]+"x";
        combn.push_back(t+"y");
    }
    get_combn(combn,level+1,size);
}

void append_y(vector<string> &a){
    for(int i=0;i<a.size();i++){
        a[i] = a[i]+"y";
    }
}

bool prime(long long x){
	if(x%2==0)
	return false;
	for(int i=2;i<=sqrt(x);i++){
		i++;
		if(x%i==0){
			return false;
		}
	}
	return true;
}

int number_of_y(string a){
    int count=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='y'){
            count++;
        }
    }
    return count;
}

bool y_at_first(string a){
    if(a[0]=='y')
    return true;
    return false;
}

void put_y_values(vector<string> combn,vector<string> &comb1){
    for(int i=0;i<combn.size();i++){
        int size = number_of_y(combn[i]);
        if(y_at_first(combn[i])){
            size
        }
    }
}

int main(){
    int digit_length = 3;
    vector<string> combn;
    combn.push_back("");
    get_combn(combn,0,2);
	append_y(combn);
    show_vector(combn);
    vector<string> comb1;
    put_y_values(combn,comb1);
}
