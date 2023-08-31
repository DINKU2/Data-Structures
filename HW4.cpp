
#include <iostream>
using namespace std;
#include <fstream>
#include <string>


void threePeg(int n,char from,char to,char aux_rod,ofstream& output)
{
  if (n >0){
    threePeg(n - 1,from,aux_rod,to,output);
    output << n <<" "<<from<<" "<<to<<endl;
    threePeg(n - 1,aux_rod,to,from,output); 
  }
}


void fourPeg(int n, char start, char intermed1, char intermed2, char end,ofstream& output)
{
  if(n<1)
    return;  
  if ( n == 1 )
    output << n <<" "<<start << " " << end << endl;

  else
  {
    fourPeg(n - 2, start, intermed2, end, intermed1,output);
    output << n -1<<" "<<start << " " << intermed2 << endl;
    output << n <<" "<<start << " " << end << endl;
    output << n -1<<" "<<intermed2 << " "  << end << endl;
    fourPeg(n - 2, intermed1, start, intermed2, end,output);
  }
}


int main(int argc, char* argv[])
{
  
  string pegCount = argv[1];
  string diskCount = argv[2];
  string outputName = argv[3];
  

  //string pegCount = "3";
  //string diskCount = "1";
  //string outputName = "ligma";
  
  int diskNum = stoi(diskCount);
  ofstream output; output.open(outputName);
  
  if(pegCount == "3"){
    threePeg(diskNum,'A','C','B',output);
    output<<"1 C B"<<endl;
    output<<"1 B C"<<endl; 
  }

  else if(pegCount == "4"){
    fourPeg(diskNum,'A','B','C','D',output);
    output<<"1 D C"<<endl;
    output<<"1 C B"<<endl;
    output<<"1 B D"<<endl;
  }

  return 0;
}
/*
  else if ( n == 2 )
  {
    output << n <<" "<< start << " " << intermed1 << endl;
    output << n <<" "<<start << " " << end << endl;
    output << n <<" "<<intermed1 << " " << end << endl;
  }*/
