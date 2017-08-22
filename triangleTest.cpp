#include <iostream>

using namespace std;

//Function Prototypes
void isoTri(double, double, double);
void scalTri(double, double, double);
void equilTri(double, double, double);
bool isItTriangle(double, double, double);

//Main Function
int main()
{
    double side1, side2, side3; //Three sides
    bool triangle = 0; //Boolean which decides if sides entered form a triangle

    cout<<"Identify the type of triangle based on the lengths of its sides"<<endl;
    cout<<"Enter 3 numbers"<<endl;
    cin>>side1;
    cin>>side2;
    cin>>side3;

    //Checks to make sure no sides are 0
    if (side1 == 0 || side2 == 0 || side3 == 0) {
        triangle = 0;
        cout<<"These sides do not form a triangle."<<endl;
        cout<<"All sides must be greater than zero."<<endl;
    }

    //Otherwise, continues on with program
    else {
        triangle = isItTriangle(side1, side2, side3); //Calls isItTriangle function

        if (triangle == 0) {
            cout<<"This is not triangle because the sum of the\ntwo smaller sides is not greater than or equal to the largest side."<<endl;
        }

        //Calls each function to see which kind of triangle it is
        else if (triangle == 1) {
            cout<<"It is "<<endl;
            isoTri(side1, side2, side3);
            scalTri(side1, side2, side3);
            equilTri(side1, side2, side3);
        }


    }
    return 0;
}

//Function checks if sides entered form a triangle by using geometry
bool isItTriangle(double side1, double side2, double side3)
{
    double bigSide = 0, sumLittleSides = 0;

    if (side1 > side2 && side1 > side3) {
        bigSide = side1;
        sumLittleSides = side2 + side3;
    }
    else if (side2 > side1 && side2 > side3) {
        bigSide = side2;
        sumLittleSides = side1 + side3;
    }
    else if (side3 > side1 && side3 > side2) {
        bigSide = side3;
        sumLittleSides = side2 + side1;
    }

    //Checks if the sum of the little sides is greater than or equal to the big side
    if (bigSide > sumLittleSides) {
        return 0;
    }
    else if (sumLittleSides >= bigSide) {
        return 1;
    }
}

void isoTri(double side1,double side2,double side3)

{

   if((side1 == side2 && side2 != side3) || (side1 == side3 && side2 != side3) || (side2 == side3 && side1 != side2)) //Checks if any two sides are equal and checks to make sure it is not an equilateral
        cout<<"an isosceles triangle because two side are equal."<<endl;

}

void scalTri(double side1, double side2, double side3)

{
   if (side1 != side2 && side1 != side3 && side2 != side3) //if all input lengths dont equal each other display that it's a scalene triangle
        cout<<"a scalene triangle because no sides are equal."<<endl;
}

void equilTri(double side1,double side2,double side3)
{

    if (side1==side2 && side1==side3) //Checks if all sides are equal
    {
        cout<<"an equilateral triangle because all sides are equal."<<endl;//Declaration
    }

}
