#include <string>
#include <iostream>
#include <fstream>
using namespace std;
string keyword[]={"auto","break","case","char","const","continue","default","do",
				  "double","else","enum","extern","float","for","goto","if",
				  "int","long","register","return","short","signed","sizeof","stastic",
				  "struct","switch","typedef","union","unsigned","void","volatile","while"};

int main(){
	int con=0;//����level 
	string root; //�ļ�������ͬһ�ļ��У� 
	cout<<"the .cpp file name you wanna in the same folder"<<endl;
	cin>>root;
	cout<<"what level of stastic you want(from 1 to 4)"<<endl;
	cin>> con;
	ifstream inFile,s1,s2;
	inFile.open(root.c_str(),ios::in);
	s1.open(root.c_str(),ios::in);
	s2.open(root.c_str(),ios::in);
	if(!inFile|| !s1 ||!s2){
        cout <<"Check the Path of File !" << endl;
        exit(0); 
    }
	string str;
	int total=32,numt=0; ;//1.�������� 20-34
	int count[total] = {0}; //���ʼ��� 
	while (getline (inFile, str)){//һ��һ�ж�ȡ
		for(int i=0;i<total;i++){
		int pos;//���ʵ�λ��
		for(;;){
				if(str.find(keyword[i]) != -1){//����-1��ʾ������û�иõ���
					if(str.find("//") != -1) break;//����ע�� 
					else{
						pos = str.find(keyword[i]);//�ҵ��״γ��ֵ���λ��
						count[i]++;
						str = str.substr(pos + keyword[i].length(),str.length() - pos - keyword[i].length());//��ȡ�Ӵ�����substr
					}
				} 
				else break;
			}	
		}
	}
	for(int j=0;j<total;j++){//ȫ����� 	
		if(count[j]!=0){
			numt+=count[j];	
		}
	}
	int num[5]={25,2,6,15,9},x[3]={0,0,-1};// num:��keyword�����еĵ��ʴ��룻x:���账��int��������ɵ�����  
	int struc[count[num[0]]]={0};//2.��case���� ��ÿ��switch��case�������Ӧ����Ԫ�� 
	string pick[3]={"else if", "if","else"};//Ҫ��3��4���ж����� 
	while (getline (s1, str)){//һ��һ�ж�ȡ
		int pos;//���ʵ�λ��
		for(;;){
			if(str.find(keyword[num[1]]) != -1){
				if(str.find("//") != -1) break;//����ע�� 
				else{
					struc[x[0]]++;
					break;
				}
			}
			if(str.find(keyword[num[2]]) != -1){
				if(str.find("//") != -1) break;//����ע�� 
				else{
					x[0]++;
					break;
				}
			}
			if(str.find(pick[0]) != -1){
				pos = str.find(pick[0]);
				str = str.substr(pos + pick[0].length(),str.length() - pos - pick[0].length());
			}
			if(str.find(pick[1]) != -1){
				if(str.find("//") != -1) break;//����ע�� 
				else{
					x[1]++;//ȷ���ܹ��м�����Чif 
					break;
				}
			}
			else break;
		}	
	}
	int divide[x[1]]={0}, ely=0,eln=0;//3.4����ÿ��if-else��else if�������Ӧ����Ԫ��,0��ֻ��if-else 
	while (getline (s2, str)){
		int pos;
		for(;;){
			if(str.find(pick[0]) != -1){
				if(str.find("//") != -1) break;//����ע�� 
				else{
					divide[x[2]]++;
					break;
				} 
			}
			if(str.find(keyword[num[3]]) != -1){
				if(str.find("//") != -1) break;//����ע�� 
				else{
					x[2]++;
					break;
				}
			}
			else break;
		}
	}
	for(int m=0;m<x[1];m++){
		if(divide[m]==0){
			eln++;
		}
		else{
			ely++;				
		}	
	}
	for(int o=1; o<con+1; o++){
		switch(o){
		case 1:
			cout<<"total num is: "<<numt<<endl;
			for(int j=0;j<total;j++){//ȫ����� 	
				if(count[j]!=0){
				cout<<keyword[j]<<" num: "<<count[j]<<endl;
				}
			}
			break;
		case 2:
			if(count[num[0]]!=count[num[2]]){
				cout<<" wrong switch structure"<<endl;
			}
			else{
				cout<<"The number of switch structure is:"<<count[num[0]]<<endl;
				for(int k=0;k<count[num[0]];k++){
				cout<<"switch "<<k+1<<" number of case is: "<<struc[k]<<endl;
			}
			}
			break;
		case 3:
			cout<<"the number of if-else: "<<eln<<endl;
			break;
		case 4:
			cout<<"the number of if-else if-else: "<<ely<<endl;
			break;
		default:
			cout<<"wrong"<<endl;
		}
	}
	inFile.close();
	s1.close();
	s2.close();
    return 0;
}
