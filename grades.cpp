#include <iostream>
using namespace std;

int main()
{

    int pupils = 45;
    int boys = 25;
    int boysWithGradeA = 17;
    float percentageWithGradeA = 0.8;

    int totalWithGradeA = boysWithGradeA / percentageWithGradeA;
    int girlsWithGradeA = totalWithGradeA - boysWithGradeA;

    cout << "Number of girls who received grade A: " << girlsWithGradeA;

    return 0;
}