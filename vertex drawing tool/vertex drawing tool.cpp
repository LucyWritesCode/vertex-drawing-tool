#include <iostream>
#include <vector>
#include <raylib.h>

struct Window {
    int x;
    int y;
};

void vertexPlace(std::vector<Vector2>& vertices , Vector2 position) {
    vertices.push_back(position);
}

int main()
{
    Window window = { 3200 , 1800 };
    InitWindow(window.x, window.y, "");
    std::vector<Vector2> vertices;
    int vertexSize = 10;
    Color vertexColor = RED;
    Color lineColor = BLUE;
    bool joinVertices = false;

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            vertexPlace(vertices, mousePos);
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            vertices.clear();
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) {
            joinVertices = !joinVertices;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (Vector2 vertex : vertices) {
            DrawCircle(vertex.x, vertex.y, vertexSize, vertexColor);
            if (joinVertices) {
                for (Vector2 vertexNext : vertices) {
                    DrawLine(vertex.x, vertex.y, vertexNext.x, vertexNext.y, lineColor);
                }
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

