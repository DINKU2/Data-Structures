#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include<sstream>
#include <cmath>
#include <iomanip>

template <class T>
class stack{
  public:
    vector<T> myVector;
    bool empty(){return myVector.empty();}
    void add(T n){myVector.push_back(n);}
    T top(){return myVector.back();}
    T size(){return myVector.size();}
    T pop(){
      T num =myVector.back();
      myVector.pop_back();
      return num;
    }
    void print(){
      for(int i=0;i<myVector.size();i++)
        cout<< myVector[i]<<" ";
      cout<<endl;
    }
};

bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
		return true;
	else
		return false;
}

int precedence(char c) 
{ 
  if(c == '^') 
  return 3; 
  else if(c == '*' || c == '/') 
  return 2; 
  else if(c == '+' || c == '-') 
  return 1; 
  else
  return -1; 
} 

string InfixToPostfix(stack<char> s, string infix)
{
	string postfix;
	for(int i=0;i<infix.length();i++)
	{
		if((infix[i] >= '0' && infix[i] <= '9'))
			postfix+=infix[i];
		else if(infix[i] == '(')
			s.add(infix[i]);
		else if(infix[i] == ')')
		{
			while((s.top()!='(') && (!s.empty()))
			{
				char temp=s.top();
				postfix+=temp;
				s.pop();
			}
			if(s.top()=='(')
				s.pop();
		}
		else if(isOperator(infix[i]))
		{
			if(s.empty())
				s.add(infix[i]);
			else
			{
				if(precedence(infix[i])>precedence(s.top()))
					s.add(infix[i]);
				else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^'))
					s.add(infix[i]);
				else
				{
					while((!s.empty())&&( precedence(infix[i])<=precedence(s.top())))
					{
						postfix+=s.top();
						s.pop();
					}
					s.add(infix[i]);
				}
			}
		}
	}
	while(!s.empty())
	{
		postfix+=s.top();
		s.pop();
	}
	return postfix;
}

float Compute(char c, float a, float b)
{
  switch (c) {  
  case '+': return ((a*1.0)+(b*1.0));
  case '-': return ((a*1.0)-(b*1.0));
  case '*': return ((a*1.0)*(b*1.0));
  case '/': return ((a*1.0)/(b*1.0));
  case '^': return pow(a,b);
  default: throw std::runtime_error("No such operator");
  }
}

float postfixAnswer(string postfix,stack<float> stack){
  for(int i=0;i<postfix.size();i++){
    char character= postfix[i];
    if(isdigit(character)==true){
      float num = postfix[i] - '0';
      stack.add(num);
    }
    else{
      float n1=stack.pop();
      float n2=stack.pop();
      float result = Compute(character,n2,n1);
      stack.add(result);
    }
  }
  float answer = 1.0*stack.top();
  return answer;
}

bool postfixValid (string postfix){
  int valueCount = 0;
  int operatorCount = 0;
  bool truth = false;
  int size = postfix.size();
  
  for(int i=0;i<size;i++){
    if(isdigit(postfix[i])==true)
      valueCount++;
    else
      operatorCount++;
  }
  if(isdigit(postfix[0])==true && isdigit(postfix[1])==true){
    if(isdigit(postfix[size-1])==false){
      if(valueCount-1==operatorCount){
        truth = true;
      }
    }
  }
  return truth;
}

int main(int argc, char* argv[]) {

  //string arg = argv[1];
  //string input = argv[2];
  //ofstream output; 
  //output.open(argv[3]);

  string arg = "3";
  string input = "23+4^5*";
  ofstream output;
  output.open("mytest");
  
  if(arg == "2"){
    stack<char> stack;
    string answer = InfixToPostfix(stack,input);
    output<<answer<<endl;
  }
  else{
    if(postfixValid(input)==true){
      stack<float> stack;
      output<< fixed << setprecision(1);
      output<<postfixAnswer(input,stack);
    }
    else
      output<<"nv"<<endl;
  }
  return 0;
}
