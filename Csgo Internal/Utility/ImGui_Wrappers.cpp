
#include <imgui.h>
#include <UVector.h>

void ImGui_DrawLine(Vector2 point1, Vector2 point2, float lineColor[3], float lineThickness = 1.f)
{
	ImGui::GetBackgroundDrawList()->AddLine({ point1.x, point1.y }, { point2.x, point2.y }, ImColor{ lineColor[0], lineColor[1], lineColor[2] }, lineThickness);
}

void ImGui_DrawLine(Vector2 point1, Vector2 point2, ImColor color, float lineThickness = 1.f)
{
	ImGui::GetBackgroundDrawList()->AddLine({ point1.x, point1.y }, { point2.x, point2.y }, color, lineThickness);
}

void ImGui_DrawBox(Vector2 topRight, Vector2 bottomLeft, float boxColor[3], float boxRounding = 0.f, float boxThickness = 1.f)
{
	ImGui::GetBackgroundDrawList()->AddRect({ topRight.x, topRight.y }, { bottomLeft.x, bottomLeft.y }, ImColor{ boxColor[0], boxColor[1], boxColor[2] }, boxRounding, 0, boxThickness);
}
void ImGui_DrawBox(Vector2 topRight, Vector2 bottomLeft, ImColor color, float boxRounding = 0.f, float boxThickness = 1.f)
{
	ImGui::GetBackgroundDrawList()->AddRect({ topRight.x, topRight.y }, { bottomLeft.x, bottomLeft.y }, color, boxRounding, 0, boxThickness);
}

void ImGui_DrawCircle(Vector2 center, float CircleRadius, ImColor color, float lineThickness)
{
	ImGui::GetBackgroundDrawList()->AddCircle({ center.x, center.y }, CircleRadius, color, 0, lineThickness); 
}

void ImGui_DrawFilledCircle(Vector2 center, float circleRadius, ImColor color)
{
	ImGui::GetBackgroundDrawList()->AddCircleFilled({ center.x, center.y }, circleRadius, color); 
}