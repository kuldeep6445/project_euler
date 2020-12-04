#include<iostream>
#include<vector>
using namespace std;

void multiply(vector<int> &num , int num1){
	for(int i=0;i<num.size();i++)
		num[i]*=num1;
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
}

void solve(vector<int> &num,int num1,int pow){
	num.push_back(num1);
	for(int i=1;i<pow;i++){
		multiply(num,num1);
	}
}

void print(vector<int> &num){
	for(int i=num.size()-1;i>=0;i--){
		cout<<num[i]<<" ";
	}
}

int sum(vector<int> &num){
	int sum=0;
	for(int i=0;i<num.size();i++)
		sum+=num[i];
	return sum;
}

int main(){
	int max=0,t=0;
	int a,b;
	for(int i=99;i>0;i--){
		for(int j=99;j>0;j--){
			vector<int> num;
			solve(num,i,j);
			t = sum(num);
			if(t>max){
				max = t;
				a =  i;
				b=j;
			}
		}
	}
	cout<<max<<endl;
	cout<<a<<"\n"<<b;
	
}
