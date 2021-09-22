#include <string>
#include <iostream>
#include <fstream>
using namespace std;
string keyword[]={"auto","break","case","char","const","continue","default","do",
				  "double","else","enum","extern","float","for","goto","if",
				  "int","long","register","return","short","signed","sizeof","stastic",
				  "struct","switch","typedef","union","unsigned","void","volatile","while"};

int main(){
	int con=0;//输入level 
	string root; //文件名（在同一文件夹） 
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
	int total=32,numt=0; ;//1.总体数数 20-34
	int count[total] = {0}; //单词计数 
	while (getline (inFile, str)){//一行一行读取
		for(int i=0;i<total;i++){
		int pos;//单词的位置
		for(;;){
				if(str.find(keyword[i]) != -1){//返回-1表示句子里没有该单词
					pos = str.find(keyword[i]);//找到首次出现单词位置
					count[i]++;
					str = str.substr(pos + keyword[i].length(),str.length() - pos - keyword[i].length());//截取子串存入substr
				} 
				else break;
			}	
		}
	}
	for(int j=0;j<total;j++){//全部输出 	
		if(count[j]!=0){
			numt+=count[j];	
		}
	}
	int num[5]={25,2,6,15,9},x[3]={0,0,-1};// num:在keyword数组中的单词代码；x:由需处理int型数据组成的数组  
	int struc[count[num[0]]]={0};//2.数case数； 将每个switch的case数存入对应数组元素 
	string pick[3]={"else if", "if","else"};//要求3、4的判断依据 
	while (getline (s1, str)){//一行一行读取
		int pos;//单词的位置
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
				str = str.substr(pos + pick[0].length(),str.length() - pos - pick[0].length());
			}
			if(str.find(pick[1]) != -1){
				x[1]++;//确认总共有几个if 
				break;
			}
			else break;
		}	
	}
	int divide[x[1]]={0}, ely=0,eln=0;//3.4：将每个if-else的else if数存入对应数组元素,0就只是if-else 
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
	for(int o=1; o<con+1; o++){
		switch(o){
		case 1:
			cout<<"total num is: "<<numt<<endl;
			for(int j=0;j<total;j++){//全部输出 	
				if(count[j]!=0){
				cout<<keyword[j]<<" num: "<<count[j]<<endl;
				}
			}
			break;
		case 2:
			cout<<"The number of switch structure is:"<<count[num[0]]<<endl;
			for(int k=0;k<count[num[0]];k++){
			cout<<"switch "<<k+1<<" number of case is: "<<struc[k]<<endl;
			}
			break;
		case 3:
			for(int m=0;m<x[1];m++){
			if(divide[m]==0){
				eln++;
				}
			else{
				ely++;				
				}	
			}
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
