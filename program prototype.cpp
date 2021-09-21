#include <string>
#include <iostream>
#include <fstream>
using namespace std;
string keyword[]={"auto","break","case","char","const","continue","default","do",
				  "double","else","enum","extern","float","for","goto","if",
				  "int","long","register","return","short","signed","sizeof","stastic",
				  "struct","switch","typedef","union","unsigned","void","volatile","while"};

int main(){
	ifstream inFile,s1,s2;
	inFile.open("sample.cpp",ios::in);
	s1.open("sample.cpp",ios::in);
	s2.open("sample.cpp",ios::in);
	if(!inFile){
        cout <<"Check the Path of File !" << endl;
        exit(0); 
    }
	string str;
	int total=32;//1.�������� 20-34
	int count[total] = {0}; //���ʼ��� 
	while (getline (inFile, str)){//һ��һ�ж�ȡ
		for(int i=0;i<total;i++){
		int pos;//���ʵ�λ��
		for(;;){
				if(str.find(keyword[i]) != -1){//����-1��ʾ������û�иõ���
					pos = str.find(keyword[i]);//�ҵ��״γ��ֵ���λ��
					count[i]++;
					str = str.substr(pos + keyword[i].length(),str.length() - pos - keyword[i].length());//��ȡ�Ӵ�����substr
				} 
				else break;
			}	
		}
	}
	int num[5]={25,2,6,15,9},x[3]={0,0,0};// num:��keyword�����еĵ��ʴ��룻x:���账��int��������ɵ�����  
	int struc[count[num[0]]]={0};//��ÿ��switch��case�������Ӧ����Ԫ�� 
	string pick[3]={"else if", "if","else"};//Ҫ��3��4���ж����� 
	while (getline (s1, str)){//һ��һ�ж�ȡ
		int pos;//���ʵ�λ��
		for(;;){
			if(str.find(keyword[num[1]]) != -1){
				struc[x[0]]++;
				break;
			}
			if(str.find(keyword[num[2]]) != -1){
				x[0]++;
				break;
			}
			if(str.find(pick[0]) != -1){
				pos = str.find(pick[0]);
				str = str.substr(pos + pick[0].length(),str.length() - pos - pick[1].length());
			}
			if(str.find(pick[1]) != -1){
				x[1]++;//ȷ���ܹ��м���if 
				break;
			}
			else break;
		}	
	}
	int divide[x[1]]={0}, ely=0,eln=0;//��ÿ��if-else��else if�������Ӧ����Ԫ��,0��ֻ��if-else 
	while (getline (s2, str)){
		int pos;
		for(;;){
			if(str.find(pick[0]) != -1){
				divide[x[2]]++;
				break;
			}
			if(str.find(keyword[num[3]]) != -1){
				x[2]++;
				break;
			}
			else break;
		}
	}
	
	for(int j=0;j<total;j++){//ȫ����� 	
		if(count[j]!=0){
			cout<<keyword[j]<<" "<<count[j]<<endl;
		}
	}
	cout<<"The number of switch structure is:"<<count[num[0]]<<endl;
	for(int k=0;k<count[num[0]];k++){
		cout<<"switch "<<k+1<<" number of case is: "<<struc[k]<<endl;
	} 
	for(int m=0;m<x[1];m++){
		if(divide[m]==0){
			eln++;
		}
		else{
			ely++;				
		}	
	}
	cout<<"the number of if-else: "<<eln<<endl;
	cout<<"the number of if-else if-else: "<<ely<<endl;
    return 0;
}
