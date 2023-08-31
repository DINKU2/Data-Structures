#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;


class Node{
  public:
    int row;
    int col;
    float value;
    Node *next; 
};

void insert(Node** root, float item,int x,int y){
  Node* temp = new Node;
  Node* ptr;
  temp->value = item*1.0;
  temp->next = NULL;
  temp->row = x;
  temp->col = y;
  if (*root == NULL)
      *root = temp;
  else {
      ptr = *root;
      while (ptr->next != NULL)
          ptr = ptr->next;
      ptr->next = temp;
  }
} 

void display(Node* root){
    cout<<setprecision(1)<<fixed;
    while(root != NULL){
      //int rowHolder=1;
      if(root->value<9){
        cout<<" ";
      }
      if(root->col==1 &&  root->row>=2){
        cout<<endl<<root->value<<" ";
      }
      else{
        cout<<root->value<<" ";
      }
      root = root->next;
    }
}

Node* addFunction(Node* rootA, Node* rootB ){
  Node *rootAdd = NULL;
  while (rootA != NULL && rootB != NULL) {
    float total = (rootA->value + rootB->value)*1.0;
    int addX = rootA->row;
    int addY = rootA->col;
    insert(&rootAdd,total,addX,addY);
    rootA = rootA->next;
    rootB = rootB->next;
    }
    return rootAdd;
  }

Node* subFunction(Node* rootA, Node* rootB ){
  Node *rootSub = NULL;
  while (rootA != NULL && rootB != NULL) {
    float total = (rootA->value - rootB->value)*1.0;
    int subX = rootA->row;
    int subY = rootA->col;
    insert(&rootSub,total,subX,subY);
    rootA = rootA->next;
    rootB = rootB->next;
    }
    return rootSub;
  }

void traFunctionOne(Node* myRoot,string s,int max ){

  ofstream output;
  output.open(s);
  output<<setprecision(1)<<fixed;
  int hold = 1;
  while(hold != max+1){
    Node* cu = myRoot;
  
    while(cu!=NULL){
      if(cu->col == hold)
        output<<setw(4)<<cu->value<<" ";
      cu= cu->next;
    }
    output<<endl;
    hold++;
  }
}

void traFunctionTwo(Node* myRoot,string s,int max ){

  ofstream output;
  output.open(s);
  output<<setprecision(1)<<fixed;
  int hold = 1;
  while(hold != max+1){
    Node* cu = myRoot;
  
    while(cu!=NULL){
      if(cu->col == hold)
        output<<setw(4)<<cu->value<<" ";
      cu= cu->next;
    }
    output<<endl;
    hold++;
  }
}

int rowCol(int rowA,int colB, Node* rootA , Node* rootB){
  Node* tempA =rootA;
  Node* tempB =rootB;
  Node* aRow=NULL;
  Node* bCol=NULL;
  Node* beforeSummation=NULL;
  int total = 0;
  //grab rowA into a new linked list
  while(rootA!=NULL){
    if(rootA->row==rowA){
      insert(&aRow,rootA->value,rootA->row,rootA->col);
    } 
    rootA=rootA->next;
  }
  //grab colB into a new linked list
  while(rootB!=NULL){
    if(rootB->col==colB){
      insert(&bCol,rootB->value,rootB->row,rootB->col);
    }
    rootB=rootB->next;
  }
  // makes a list before summation of these numbers
  while(aRow!=NULL){
    int value=aRow->value * bCol->value;
    insert(&beforeSummation,value,0,0);
    aRow = aRow->next;
    bCol= bCol->next;
  }
  //time to add it up
  while(beforeSummation!=NULL){
    total= total+beforeSummation->value;
    beforeSummation=beforeSummation->next;
  }
  return total;
}

Node* multiplyMatrix(Node* rootA,Node* rootB, int rowACount, int colBCount){
  Node* rootMultiply =NULL;
  int rowHold =1;
  int colHold =1;
  for(int i =0;i<rowACount;i++){
    for(int j=0;j<colBCount;j++){
      float value = rowCol(rowHold,colHold,rootA,rootB);
      insert(&rootMultiply,value,rowHold,colHold);
      colHold++;
    }
    colHold=1;
    rowHold++;
  }
  
  return rootMultiply;
}

int valueAt(Node*rootA,int row,int col){
  int value;
  while(rootA!=NULL){
    if(rootA->row==row && rootA->col==col){
      value= rootA->value;
    }
    rootA=rootA->next;
  }
  return value;
}

Node* matrixWithoutRowCol(Node* rootA,int thisCol){
  
  Node* newRoot = NULL;
  int thisNum =  rootA->value;
  int col = thisCol;
  //int value = rootA->value;
  while(rootA!=NULL){
    if((rootA->row != thisNum) || (rootA->col != col)){
      insert(&newRoot,rootA->value,rootA->row,rootA->col);
    }
    rootA=rootA->next;
  }
  return newRoot;
}





//performs math on 2x2
int twoByTwo(Node* rootA){
  Node* rootAR = rootA->next;
  Node* rootADL = rootA->next->next;
  Node* rootADR = rootA->next->next->next;
  int value = (rootA->value * rootADR->value)-(rootAR->value*rootADL->value);
  return value;
  }

//is it 2x2 ?
bool isTwoByTwo(Node* rootA){
  bool status = false;
  int counter=0;
  while(rootA!=NULL){
    counter++;
    rootA=rootA->next;
  }
  if(counter==4){
    status=true;
  }
  return status;
}



/*int determinateMatrix(Node* oldM,int nCol){
  //copy matrix
  Node* newM = NULL;

  int charge =0;
  int det=0;
  
  for(int i=0;i<nCol;i++){
    newM=oldM;
    int temp=1;
    while(isTwoByTwo(newM)!=true){


      temp*=valueAt(newM,1,i+1);
      newM = matrixWithoutRowOneAndACol(newM,i+1);
      //newM=newM->next;
    }   
    if(charge%2==0){
      det+= temp*twoByTwo(newM);
    }
    else{
      det-=temp*twoByTwo(newM);
    }
    charge++;
      }
  }
  return det;
}*/


//is it 3x3?
bool isThreeByThree(Node* rootA){
  bool status = false;
  int counter=0;
  while(rootA!=NULL){
    counter++;
    rootA=rootA->next;
  }
  if(counter==9){
    status=true;
  }
  return status;
}

int threeByThree(Node* rootA){
  int a = rootA->value;rootA=rootA->next;
  int b = rootA->value;rootA=rootA->next;
  int c = rootA->value;rootA=rootA->next;
  int d = rootA->value;rootA=rootA->next;
  int e = rootA->value;rootA=rootA->next;
  int f = rootA->value;rootA=rootA->next;
  int g = rootA->value;rootA=rootA->next;
  int h = rootA->value;rootA=rootA->next;
  int i = rootA->value;rootA=rootA->next;

  int ei = e*i;
  int fh = f*h;
  int di = d*i;
  int fg = f*g;
  int dh = d*h;
  int eg = e*g;

  int det= (a*(ei-fh))-(b*(di-fg))+(c*(dh-eg));
  return det;
}




//is 4x4

bool isFourByFour(Node* rootA){
  bool status = false;
  int counter=0;
  while(rootA!=NULL){
    counter++;
    rootA=rootA->next;
  }
  if(counter==16){
    status=true;
  }
  return status;
}

int fourByFour(Node* rootA){
  int a = rootA->value;rootA=rootA->next;
  int b = rootA->value;rootA=rootA->next;
  int c = rootA->value;rootA=rootA->next;
  int d = rootA->value;rootA=rootA->next;
  int e = rootA->value;rootA=rootA->next;
  int f = rootA->value;rootA=rootA->next;
  int g = rootA->value;rootA=rootA->next;
  int h = rootA->value;rootA=rootA->next;
  int i = rootA->value;rootA=rootA->next;
  int j = rootA->value;rootA=rootA->next;
  int k = rootA->value;rootA=rootA->next;
  int l = rootA->value;rootA=rootA->next;  
  int m = rootA->value;rootA=rootA->next;
  int n = rootA->value;rootA=rootA->next;
  int o = rootA->value;rootA=rootA->next;
  int p = rootA->value;rootA=rootA->next;

  int kp=k*p;
  int lo=l*o;
  int jp=j*p;
  int ln=l*n;
  int jo=j*o;
  int kn=k*n;

  int detOne = (f*(kp-lo))-(g*(jp-ln))+(h*(jo-kn));

  int ip=i*p;
  int lm=l*m;
  int io=i*o;
  int km=k*m;

  int detTwo = (e*(kp-lo))-(g*(ip-lm))+(h*(io-km));

  int in=i*n;
  int jm=j*m;
  
  int detThree = (e*(jp-ln))-(f*(ip-lm))+(h*(in-jm));

  int detFour = (e*(jo-kn))-(f*(io-km))+(g*(in-jm));
  
  int det =(a*detOne) - (b*detTwo) + (c*detThree) - (d*detFour);
    
  return det;
  
}




int main(int argc,char *argv[]) {
  
  string instruction = argv[1];
  
  ifstream input1;
  ifstream input2;
  
  ofstream outputAdd;
  ofstream outputSub;
  ofstream outputMul;
  ofstream outputTra1;
  ofstream outputTra2;
  ofstream outputDet;

  if(instruction=="add"){
    input1.open(argv[2]);
    input2.open(argv[3]);
    string aRowString;
    string aNumString;
    string bRowString;
    string bNumString;
    int aX,aY,bX,bY =0;
    aX=aY=bX=bY=0;
    Node *rootA = NULL;
    Node *rootB =NULL;
    while(getline(input1 ,aRowString) && getline(input2,bRowString)){
      aX++;
      aY=0;
      bX++;
      bY=0;
      stringstream aRowToStream(aRowString);
      stringstream bRowToStream(bRowString);
      while(getline(aRowToStream,aNumString,' ')){
        aY++;
        int num;
        num=stoi(aNumString);
        insert(&rootA,num,aX,aY);
      }
      while(getline(bRowToStream,bNumString,' ')){
        bY++;
        int num;
        num=stoi(bNumString);
        insert(&rootB,num,bX,bY);
      }    
    }

    if(aX==bX && aY==bY){
      outputAdd.open(argv[4]);
      Node* rootAdd = addFunction(rootA,rootB);
      outputAdd<<setprecision(1)<<fixed;
      while(rootAdd != NULL){
        //int rowHolder=1;
        if(rootAdd->value<9){
          outputAdd<<" ";
        }
        if(rootAdd->col==1 && rootAdd->row>=2){
          outputAdd<<endl<<rootAdd->value<<" ";
        }
        else{
          outputAdd<<rootAdd->value<<" ";
        }
        rootAdd = rootAdd->next;
      }
    }
  }
    
  else if(instruction=="sub"){

    input1.open(argv[2]);
    input2.open(argv[3]);
    
    string aRowString;
    string aNumString;
    string bRowString;
    string bNumString;
    int aX,aY,bX,bY =0;
    aX=aY=bX=bY=0;
    Node *rootA = NULL;
    Node *rootB =NULL;
    while(getline(input1 ,aRowString) && getline(input2,bRowString)){
      aX++;
      aY=0;
      bX++;
      bY=0;
      stringstream aRowToStream(aRowString);
      stringstream bRowToStream(bRowString);
      while(getline(aRowToStream,aNumString,' ')){
        aY++;
        int num;
        num=stoi(aNumString);
        insert(&rootA,num,aX,aY);
      }
      while(getline(bRowToStream,bNumString,' ')){
        bY++;
        int num;
        num=stoi(bNumString);
        insert(&rootB,num,bX,bY);
      }    
    }

    if(aX==bX && aY==bY){
      outputSub.open(argv[4]);
      
      Node* rootSub =subFunction(rootA,rootB);
      outputSub<<setprecision(1)<<fixed;
      while(rootSub != NULL){
        if(rootSub->col==1 && rootSub->row==1){
          outputSub<<setw(4)<<rootSub->value;
        }
        else if(rootSub->col==1 && rootSub->row>1){
          outputSub<<endl<<setw(4)<<rootSub->value;
        }
        else{
          outputSub<<setw(6)<<rootSub->value;
        }
        rootSub = rootSub->next;
      } 
    }
  }

  else if(instruction=="mul"){
    
    input1.open(argv[2]);
    input2.open(argv[3]);

    string aRowString;
    string aNumString;
    string bRowString;
    string bNumString;
    int aX,aY,bX,bY =0;
    aX=aY=bX=bY=0;
    Node *rootA = NULL;
    Node *rootB =NULL;
    while(getline(input1 ,aRowString) && getline(input2,bRowString)){
      aX++;
      aY=0;
      bX++;
      bY=0;
      stringstream aRowToStream(aRowString);
      stringstream bRowToStream(bRowString);
      while(getline(aRowToStream,aNumString,' ')){
        aY++;
        int num;
        num=stoi(aNumString);
        insert(&rootA,num,aX,aY);
      }
      while(getline(bRowToStream,bNumString,' ')){
        bY++;
        int num;
        num=stoi(bNumString);
        insert(&rootB,num,bX,bY);
      }    
    }

    if(aY==bX){
      outputMul.open(argv[4]);
      Node* mulMatrix = multiplyMatrix(rootA,rootB,aX,bY);
      outputMul<<setprecision(1)<<fixed;
    
      //display(mulMatrix);
      while(mulMatrix != NULL){
        if(mulMatrix->col==1 && mulMatrix->row==1){
          outputMul<<setw(5)<<mulMatrix->value;
        }
        else if(mulMatrix->col==1 && mulMatrix->row>1){
          outputMul<<endl<<setw(5)<<mulMatrix->value;
        }
        else{
          outputMul<<setw(7)<<mulMatrix->value;
        }
        mulMatrix = mulMatrix->next;
      }
    }



      
  }

  else if(instruction=="tra"){

    input1.open(argv[2]);
    string aRowString;
    string aNumString;
    string bRowString;
    string bNumString;
    int aX,aY,bX,bY =0;
    aX=aY=bX=bY=0;
    Node *rootA = NULL;
    Node *rootB =NULL;
    while(getline(input1 ,aRowString)){
      aX++;
      aY=0;
      bX++;
      bY=0;
      stringstream aRowToStream(aRowString);
      stringstream bRowToStream(bRowString);
      while(getline(aRowToStream,aNumString,' ')){
        aY++;
        int num;
        num=stoi(aNumString);
        insert(&rootA,num,aX,aY);
      }
    }  

    string s = argv[3];
    traFunctionOne(rootA,s,aX);

    
  }
  


  else if(instruction=="det"){

    input1.open(argv[2]);
    string aRowString;
    string aNumString;
    string bRowString;
    string bNumString;
    int aX,aY,bX,bY =0;
    aX=aY=bX=bY=0;
    Node *rootA = NULL;
    Node *rootB =NULL;
    while(getline(input1 ,aRowString)){
      aX++;
      aY=0;
      bX++;
      bY=0;
      stringstream aRowToStream(aRowString);
      stringstream bRowToStream(bRowString);
      while(getline(aRowToStream,aNumString,' ')){
        aY++;
        int num;
        num=stoi(aNumString);
        insert(&rootA,num,aX,aY);
      }
    }  

    outputDet.open(argv[3]);
    outputDet<<setprecision(1)<<fixed;
    if(isTwoByTwo(rootA)==true){
      outputDet<<twoByTwo(rootA);
    }
    else if(isThreeByThree(rootA)==true){
      outputDet<<threeByThree(rootA);
    }
    else if(isFourByFour(rootA)==true){
      outputDet<<fourByFour(rootA);
    } 
    
  }



  
  
}
