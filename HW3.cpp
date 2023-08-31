#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <cmath>     
#include <time.h>
#include <iomanip>






// x: input array
// n: length of array
double* prefixAverage1(double* x, int len){
	double* a = new double[len];
	for(int j = 0; j < len; j++){
		double total = 0;
		for(int i = 0; i <= j; i++){
			total += x[i];
		}
		a[j] = total/(j+1);
	}
	return a;
}


// x: input array
// n: length of array
double* prefixAverage2(double* x, int len){
	double* a = new double[len];
	double total = 0;
	for(int j = 0; j < len; j++){
		total += x[j];
		a[j] = total/(j+1);
	}
	return a;
}


// x: input array
// n: length of array
int example1(int* x, int len){
	int total = 0;
	for(int i = 0; i < len; i++){
		total += x[i];
	}
	return total;
}


// x: input array
// n: length of array
int example2(int* x, int len){
	int total = 0;
	for(int i = 0; i < len; i+=2){
		total += x[i];
	}
	return total;
}


// x: input array
// n: length of array
int example3(int* x, int len){
	int total = 0;
	for(int i = 0; i < len; i++){
		for(int k = 0; k <= i; k++){
			total += x[i];
		}
	}
	return total;
}


// x: input array
// n: length of array
int example4(int* x, int len){
	int prefix = 0;
	int total = 0;
	for(int i = 0; i < len; i++){
		prefix += x[i];
		total += prefix;
	}
	return total;
}


// x: input array
// n: length of array
int example5(int* first, int* second, int len){
	int count = 0;
	for(int i = 0; i < len; i++){
		int total = 0;
		for(int j = 0; j < len; j++){
			for(int k = 0; k <= j; k++){
				total += first[k];
			}
		}
		if(second[i] == total){
			count++;
		}
	}
	return count;
}



int main(int argc, char* argv[]){

  
  string arg = argv[1];
  ofstream output; output.open(argv[2]);
  string up = argv[3];
  int myNum = stoi(up);

  /*
  string arg = "e5";
  ofstream output; output.open("hello");
  int myNum = 6;*/
  
  output<< fixed << setprecision(5);

  if(arg=="p1"){
    for(int i=0;i<myNum;i++){
      int num = pow(10,i+1);
      double* array= new double[num];
      for(int j=0;j<num;j++)
        array[j] = 0.0;

      
      clock_t p1= clock();
      double* value = prefixAverage1(array,num);
      double duration = (double(clock()-p1)/(double) CLOCKS_PER_SEC)*1000;
      duration = log10(duration);
      
      output<<duration<<endl;
      delete []array; 
    }
  }

  else if(arg=="p2"){
    for(int i=0;i<myNum;i++){
      int num = pow(10,i+1);
      double* array= new double[num];
      for(int j=0;j<num;j++)
        array[j] = 0.0;
    
      
      clock_t p2= clock();
      double* value = prefixAverage2(array,num);
      double duration = (double(clock()-p2)/(double) CLOCKS_PER_SEC)*1000;
      duration = log10(duration);
      
      output<<duration<<endl;
      delete []array; 
    }
  }

  else if(arg=="e1"){
    for(int i=0;i<myNum;i++){
      int num = pow(10,i+1);
      int* array= new int[num];
      for(int j=0;j<num;j++)
        array[i]=0;

      clock_t e1= clock();
      int value = example1(array,num);
      double duration = (double(clock()-e1) / (double) CLOCKS_PER_SEC)*1000;
      duration = log10(duration);
      
      output<<duration<<endl;
      delete []array; 
    }
  }

  else if(arg=="e2"){
    for(int i=0;i<myNum;i++){
      int num = pow(10,i+1);
      int* array= new int[num];
      for(int j=0;j<num;j++)
        array[i]=0;

      clock_t e2= clock();
      int value = example2(array,num);
      double duration = (double(clock()-e2) / (double) CLOCKS_PER_SEC)*1000;
      duration = log10(duration);
      
      output<<duration<<endl;
      delete []array; 
    }
  }  
  
  else if(arg=="e3"){
    for(int i=0;i<myNum;i++){
      int num = pow(10,i+1);
      int* array= new int[num];
      for(int j=0;j<num;j++)
        array[i]=0;

      clock_t e3= clock();
      int value = example3(array,num);
      double duration = (double(clock()-e3) / (double) CLOCKS_PER_SEC)*1000;
      duration = log10(duration);
      
      output<<duration<<endl;
      delete []array; 
    }
  }

  else if(arg=="e4"){
    for(int i=0;i<myNum;i++){
      int num = pow(10,i+1);
      int* array= new int[num];
      for(int j=0;j<num;j++)
        array[i]=0;

      clock_t e4= clock();
      int value = example4(array,num);
      double duration = (double(clock()-e4) / (double) CLOCKS_PER_SEC)*1000;
      duration = log10(duration);
      
      output<<duration<<endl;
      delete []array; 
    }
  }

  else if(arg=="e5"){
    for(int i=0;i<myNum;i++){
      int num = pow(10,i+1);
      int* array= new int[num];
      int* arrayTwo = new int[num];
      for(int i=0;i<num;i++){
        array[i]=0;
        arrayTwo[i]=0;
      }

      clock_t e5 = clock();
      int value = example5(array,arrayTwo,num);
      double duration=(double(clock()-e5) / (double) CLOCKS_PER_SEC)*1000;
      duration = log10(duration);
      
      output<<duration<<endl;
      delete []array;
    }
  }
	return 0;
}