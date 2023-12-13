#include <iostream>
#include <stdlib.h>

class Transversal {
private:
int** Map;
int xAxis;
int yAxis;
int arrSize;
int Door;

public:
// constructor
Transversal() {
};

void initArray(int arrSize){
        Map = new int*[arrSize];
        for(int i = 0; i < arrSize; ++i) {
                Map[i] = new int[arrSize];
        }
}

Transversal(int **passMap,int size,int x,int y,int door) {
        initArray(size);
        Map = passMap;
        xAxis = x;
        yAxis = y;
        arrSize = size;
        Door = door;
};

bool Solve(int X, int Y) {
        Map[Y][X] = 2;
        if (X == Door && Y == 0) {
                return true;
        }
        if (X > 0 && Map[Y][X-1] == 0 && Solve(X - 1, Y)) {
                return true;
        }
        if (X < arrSize-1 && Map[Y][X+1]== 0 && Solve(X + 1, Y)){
                return true;
        }
        if (Y > 0 && Map[Y-1][X] == 0 && Solve(X, Y - 1)){
                return true;
        }
        if (Y < arrSize-1 && Map[Y+1][X] == 0 && Solve(X, Y + 1)){
                return true;
        }
        Map[Y][X] = 0;
        return false;
}

void rint()
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            std::cout << Map[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void doTransit(){
        //rint();
        if (!Solve(xAxis,yAxis)) {
                std::cout << "Dont Have Way" << '\n';
        }
        //rint();
}
int** getMap() {
  return Map;
};
};