#include <imgui.h>
#include <UVector.h>


extern void ImGui_DrawLine(Vector2 point1, Vector2 point2, float lineColor[3], float lineThickness = 1.f); 

extern void ImGui_DrawLine(Vector2 point1, Vector2 point2, ImColor color, float lineThickness = 1.f); 

extern void ImGui_DrawBox(Vector2 topRight, Vector2 bottomLeft, float boxColor[3], float boxRounding = 0.f, float boxThickness = 1.f); 

extern void ImGui_DrawBox(Vector2 topRight, Vector2 bottomLeft, ImColor color, float boxRounding = 0.f, float boxThickness = 1.f); 

extern void ImGui_DrawCircle(Vector2 center, float CircleRadius, ImColor color, float lineThickness); 

extern void ImGui_DrawFilledCircle(Vector2 center, float circleRadius, ImColor color); 


