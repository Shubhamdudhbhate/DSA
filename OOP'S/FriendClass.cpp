#include<iostream> 
using namespace std;


class complex{



int a,b;

public:

void setno(int n1,int n2){

a=n1;
b=n2;

}


void getno(){

cout<< a <<" + "<<b<<"i"<<endl;

}


friend complex sumC(complex o1,complex o2);


};

complex sumC(complex o1,complex o2){

complex o3;
o3.setno(o1.a+o2.a , o1.b+o2.b);

return o3;

}

int main(){


complex c1,c2,sum;

c1.setno(1,2);
c1.getno();


c2.setno(3,4);
c2.getno();

sum = sumC(c1,c2);
sum.getno();



return 0;

}