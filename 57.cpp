#include<iostream>
#include<vector>
using namespace std;



vector<int> add(vector<int> num,vector<int> a){
	if(a.size()>num.size()){
		vector<int> t=num;
		num=a;
		a=t;
	}
	for(int i=0;i<a.size();i++)
		num[i] += a[i];
	for(int i=0;i<num.size()-1;i++){
		if(num[i]>9){
			num[i+1]+=num[i]/10;
			num[i]=num[i]%10;
		}
	}
	int x = num[num.size()-1],p=0;
	num[num.size()-1]= x%10;
	x=x/10;
	while(x!=0){
		num.push_back(x%10);
		x/=10;
	}
	return num;
}

vector<int> int_to_vector(int i){
	vector<int> num;
	while(i){
		num.push_back(i%10);
		i/=10;
	}
	return num;
}

void print(vector<int> &num){
	for(int i=num.size()-1;i>=0;i--){
		cout<<num[i]<<" ";
	}
}

int main(){
	vector<int> num,den,t;
	num.push_back(1);
	den.push_back(1);
	int count=0;
	for(int i=0;i<1000;i++){
		t = num;
		num = add(add(den,den),num);
		den = add(t,den);
		if(num.size()>den.size())
			count++;
	}
	cout<<count;

}
