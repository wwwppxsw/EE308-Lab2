# EE308-Lab2
#Indentation
Use 1 Tab for indentation.

Rule of naming variables
All variables are written in lowercase, every word is separated by "_" . The names of variables should be clear, which means readers can easily know what variables represent.
 int keyword_num;  //right
 int keywordNum;  //wrong
 int KeywordNum; //wrong
 int system_user_id;  //right
 
Numbers of characters in every line
They had better not surpass 80(including comment).
Maximum lines in a function
They had better not surpass 40.

Name of function
Use CamelCase and the first letter should be lowercase.

 void myFunction() {  }  //right
 void MyFunction() {  } //wrong
 void myfunction() {  } //wrong
Rule of definition of function
There is always space before the opening brace.
 void myFunction() {    }  //right
 void myFunction(){    }   //wrong
The parameters should be separated by "," . There is a space behind "," .
There is no space between parentheses and arguments.
void myFuntion(int i, int j) {    } //right

void myFunction( int i,int j) {    }  //wrong
Return type on the same line as function name, parameters on the same line if they fit. Wrap parameter lists which do not fit on a single line as you would wrap arguments in a function call.

The opening brace ("{") is always at the end of the same line as the last argument, not a new line .

The closing brace ("}") is always placed on the last line of the function alone, or on the same line as the opening brace

If I have too much text to fit on one line:

ReturnType ClassName::ReallyLongFunctionName(Type par_name1, Type par_name2,
                                             Type par_name3) {
	DoSomething();
  	...
}
or if I cannot fit even the first parameter:

ReturnType LongClassName::ReallyReallyReallyLongFunctionName(
		  Type par_name1,  
    	Type par_name2,
    	Type par_name3) {
  	DoSomething();  
  	...
}
Reference parameters
The reference parameters of functions had better be added const in the front.

The input parameters are advised to be used as reference.

The output parameters are advised to be used as pointer.

 void myFunction(const int &in, int *out) { }
Class
Name of class
Use CamelCase and the first letter should be upper case. There is a space between the end of name and the first "{" .

 class Person {   }  //right

 class person{   }   //wrong
Class or Struct ?
When there are only data members, use struct. Otherwise, use class.

Other format
There is no space before the semicolon.
   int num;  //right
  
   int num ;  //wrong
Assignment operators are always preceded by a space, unary operators are preceded by no space
   a + b
   ++x; //unary operator
