#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int cellSize = 15;
const int cellCount = 42;
const int targetFPS = 30;
const double deltaTime = 0.01;


void updatePosition(vector<Rectangle> &illm, map<int,int> floor)
{

    for(int i=0;i<illm.size();i++)
    {
        cout<<floor[illm[i].x/cellSize]<<endl;
        if(illm[i].y + cellSize <= floor[illm[i].x/cellSize]) illm[i].y +=cellSize;
    }
}


int main()
{
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Sand");
    SetTargetFPS(targetFPS);

    vector<Rectangle> illuminated;
    map<int,int> colFloor;
    for(int i=0;i<cellCount;i++) colFloor[i] = cellSize * cellCount;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        for (auto x : illuminated)
        {
            DrawRectangleRec(x, WHITE);
        }

        updatePosition(illuminated,colFloor);

        for (int i = 0; i <= cellCount; i++)
        {
            DrawLine(0, i * cellSize, cellCount * cellSize, i * cellSize, WHITE);
            DrawLine(i * cellSize, 0, i * cellSize, cellCount * cellSize, WHITE);
        }

        if (IsMouseButtonDown(0))
        {
            Vector2 mouse = GetMousePosition();
            int x = mouse.x / cellSize;
            int y = mouse.y / cellSize;
            Rectangle rec = {(float)x * cellSize, (float)y * cellSize, cellSize, cellSize};
            colFloor[x] -= cellSize;
            illuminated.push_back(rec);
        }

        ClearBackground(BLACK);
        EndDrawing();
    }
}
