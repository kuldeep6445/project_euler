#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

void print(vector<char> &num){
	for(int i=0;i<num.size();i++){
		cout<<(int)num[i]<<" ";
	}
}

int string_to_int(string a){
	int num=0;
	int pow=1;
	for(int i=a.size()-1;i>=0;i--){
		num+=(a[i]-'0')*pow;
		pow*=10;
	}
	
	return num;
}

void decrypt(vector<char> &t,char a,char b,char c){
	for(int i=0;i<t.size();i+=3){
		t[i] ^= a;
		t[i+1] ^= b;
		t[i+2] ^= c;
	}
}

bool check(vector<char> t){
	for(int i=0;i<t.size();i++){
		if(t[i]>='a'&&t[i]<='z'){}
		else if(t[i]>='A'&&t[i]<='Z'){}
		else if(t[i]==' '||t[i]=='\n'){}
		else if(t[i]>='0'&&t[i]<='9'){}
		else{return false;}
	}
	return true;
}




int main(){
	ifstream f("p059_cipher.txt");
	string buffer;
	vector<char> data;
	while(!f.eof()){
		getline(f,buffer,',');
		data.push_back(string_to_int(buffer));
	}
	f.close();
	
	vector<char> t = data;
	for(char i='a';i<='z';i++){
		for(char j='a';j<='z';j++){
			for(char k='a';k<='z';k++){
				//cout<<i<<" "<<j<<" "<<k<<"\n";
				decrypt(t,i,j,k);
				if(check(t))
					print(t);
				else
					t = data;
			}
		}
	}
}
