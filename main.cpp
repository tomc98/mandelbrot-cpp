		//Mandelbrot set by Thomas Csere

#include <iostream>
#include <complex>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include "Image.h"
#include <stdlib.h>

using namespace std;

//variables

int heighta = 1;
int n;
int count_W=0;
int i, c = 0; //i for iterator
int part;
double Re;
double Im;
int value;
float SizeMinX;
float SizeMinY;
float SizeMaxX;
float SizeMaxY;
double DPN;
int upto;

int main()
{
   cout << "Create new Mandelbrot set(1)" << endl << "Render new Mandelbrot set (2)" << endl << "Check certain values (3)     >";
   cin >> part;


    if(part==1){

        ofstream myfile;

        cout << "Enter Min value X: >";
        cin >> SizeMinX;
        cout << "Enter Min value Y: >";
        cin >> SizeMinY;
        cout << "Enter Max value X: >";
        cin >> SizeMaxX;
        cout << "Enter Max value Y: >";
        cin >> SizeMaxY;
        cout << "Enter Distance Per number (quality; lower is better): >";
        cin >> DPN;

        Im=SizeMinY;

        complex<double> Min (SizeMinX,SizeMinY);
        complex<double> Max (SizeMaxX,SizeMaxY);

        myfile.open ("example.txt");

        while(Im<SizeMaxY){
                Re=SizeMinX;
            while(Re<SizeMaxX){
                value=0;
                complex<double> C (Re,Im);
                complex<double> Z (Re,Im);
                while(real(Z)>=-2&&real(Z)<=2&&imag(Z)>=-2&&imag(Z)<=2&&value<1000){
                    Z = (Z*Z)+C;
                    value+=1;
                }
                myfile << value << " ";
                Re+=DPN;
            }
            cout << Im;
            Im+=DPN;
            myfile << endl;
        }

        myfile.close();
    }
    if(part==2){
        ifstream myfile;
    myfile.open ("example.txt");

    string str;
    getline(myfile, str);
    c = str.length();
    for ( i=0; i<c; i++){
        if ( str[i] == ' '  )
        count_W++;
    }
    //cout << count_W;

    str = "";

    while (getline(myfile, str)){
       heighta+=1;
    }
    myfile.close();
            ifstream myfileb;
    myfileb.open 
