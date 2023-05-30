#include <d3dx9.h>
#include <imgui.h>
#include <imgui_impl_dx9.h>
#include <imgui_impl_win32.h>
#include <IconsFontAwesome4.h>
#include <UConfigs.h>

bool showMenu = false;
ImFont* arialFont = nullptr; 
ImFont* calibrilFont = nullptr; 
ImFont* iconFont = nullptr; 

bool selected = false; 
void RenderMenu()
{
	if (showMenu)
	{
		ImGui::SetNextWindowSize(ImVec2{ 600, 400 });
		ImGui::Begin("Csgo Internal | Pasted by Applejuice#0002", &showMenu, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar);
		{
			ImGui::PushFont(arialFont); 
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.0f, 0.1f, 0.1f, 0.7f));
			ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 10.f);
			ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 2);

			ImGui::BeginChild("##LeftSide", ImVec2(70, 380), true, ImGuiWindowFlags_NoScrollbar);
			{
				ImGui::PushFont(iconFont);
				ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 3);
				ImGui::SetWindowFontScale(1.5f);

				if (ImGui::Button(ICON_FA_CROSSHAIRS, { 60, 50 }))
					MenuConfig::option = 1;

				ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 3);
				if (ImGui::Button(ICON_FA_EYE, ImVec2{ 60, 50 }))
					MenuConfig::option = 2;

				ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 3);
				if (ImGui::Button(ICON_FA_COG, { 60, 50 }))
					MenuConfig::option = 3;

				ImGui::PopFont(); 
				ImGui::SetWindowFontScale(1.f);
			}
			ImGui::EndChild();
			//=====================================================================================================//
			//=====================================================================================================//
			//=====================================================================================================//

			ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 80);
			ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 384);
			
			ImGui::BeginChild("##RightSide", ImVec2{ 500, 380 }, true);
			{
				
				if (MenuConfig::option == MenuConfig::aim)
				{
					ImGui::BeginTabBar("##Aim"); 

					if(ImGui::BeginTabItem("Aimbot"))
					{
						ImGui::Checkbox("Aimbot", &AimbotConfig::aimbot);

						static char aimKeyBind[2];
						ImGui::SetNextItemWidth(22.f);
						ImGui::InputText("Aimbot KeyBind", aimKeyBind, sizeof(aimKeyBind));
						AimbotConfig::keyBind = toupper(aimKeyBind[0]);

						const char* Mode[] = { "Toggle", "Hold" };
						static int selectedMode = 0;
						ImGui::SetNextItemWidth(100.f); 
						ImGui::Combo("##Mode", &selectedMode, Mode, IM_ARRAYSIZE(Mode));
						AimbotConfig::mode = selectedMode;

						ImGui::SliderFloat("X Smoothness", &AimbotConfig::Xsmoothness, 1.f, 50.f, "%.1f");
						ImGui::SliderFloat("Y Smoothness", &AimbotConfig::Ysmoothness, 1.f, 50.f, "%.1f");

						ImGui::EndTabItem(); 
					}

					if (ImGui::BeginTabItem("Triggerbot"))
					{
						ImGui::Checkbox("Triggerbot", &TriggerConfig::triggerbot); 

						ImGui::EndTabItem(); 
					}

					ImGui::EndTabBar(); 

				}

				if (MenuConfig::option == MenuConfig::visuals)
				{
					ImGui::BeginTabBar("##Visual Tabs");

					if (ImGui::BeginTabItem("Boxes"))
					{
						ImGui::Checkbox("Enemy Boxes", &VisualConfig::enemyBox); 
						ImGui::Checkbox("Enemy Corner Boxes", &VisualConfig::enemyCornerBox);

						ImGui::Checkbox("Team Boxes", &VisualConfig::teamBox); 
						ImGui::Checkbox("Team Corner Boxes", &VisualConfig::teamCornerBox); 
						
						ImGui::Spacing(); 

						ImGui::SliderFloat("Box Thickness", &VisualConfig::boxThickness, 1.f, 10.f, "%.1f");

						ImGui::Spacing();

						ImGui::SliderFloat("CornerBox Thickness", &VisualConfig::cornerBoxThickness, 1.f, 10.f, "%.1f");

						ImGui::Spacing();

						ImGui::SliderFloat("Corner Box Side Space", &VisualConfig::cornerBox_sideSpace, 1.1f, 2.f, "%.1f");

						ImGui::Spacing();

						ImGui::SliderFloat("Corner Box Top/Bototm space", &VisualConfig::cornerBox_topbottomSpace, 1.4f, 2.f, "%.1f");

						ImGui::EndTabItem();

					}

					if (ImGui::BeginTabItem("Skeleton"))
					{
						ImGui::Checkbox("Enemy Skeleton", &VisualConfig::enemySkeleton); 
						ImGui::Checkbox("Team Skeleton", &VisualConfig::teamSkeleton); 
						ImGui::SliderFloat("Skeleton Thickness", &VisualConfig::skeletonThickness, 1.f, 10.f, "%.1f");
						ImGui::EndTabItem(); 
						
					}

					if (ImGui::BeginTabItem("Traceline")) {

						ImGui::Checkbox("Enemy Tracelines", &VisualConfig::enemyTracelines);
						ImGui::Checkbox("Team Tracelines", &VisualConfig::teamTracelines);

						const char* tracelineTargets[] = { "Head", "Torso", "Feet" };
						const char* tracelineOrigin[] = { "Top", "Center", "Bottom" };
						static int selectedTarget = 0;
						static int selectedOrigin = 0;

						VisualConfig::tracelineTarget = selectedTarget;
						VisualConfig::tracelineOrigin = selectedOrigin;

						ImGui::SetNextItemWidth(100.f);
						ImGui::Combo("Traceline Target", &selectedTarget, tracelineTargets, IM_ARRAYSIZE(tracelineTargets));

						ImGui::SetNextItemWidth(100.f);
						ImGui::Combo("Traceline Origin", &selectedOrigin, tracelineOrigin, IM_ARRAYSIZE(tracelineOrigin));

						ImGui::SliderFloat("Traceline Thickness", &VisualConfig::tracelineThickness, 1.f, 10.f, "%.1f");
						ImGui::EndTabItem();

					}

					if (ImGui::BeginTabItem("Healthbar"))
					{

						ImGui::Checkbox("Enemy Healthbar", &VisualConfig::enemyHealthbar);
						ImGui::Checkbox("Team Healthbar", &VisualConfig::teamHealthbar);

						const char* healthbarLocation[] = { "Left", "Right", "Top", "Bottom" };
						static int selectedLocation = 0;
						VisualConfig::healthbarLocation = selectedLocation;

						ImGui::Text("HealthBar Locaiton");
						ImGui::SameLine();
						ImGui::SetNextItemWidth(100.f);
						ImGui::Combo("##bar Location", &selectedLocation, healthbarLocation, IM_ARRAYSIZE(healthbarLocation));

						ImGui::EndTabItem();
					}
				
					if (ImGui::BeginTabItem("Other"))
					{
						ImGui::Checkbox("Enemy Names", &VisualConfig::enemyNames);
						ImGui::Checkbox("Team Names", &VisualConfig::teamNames);

						ImGui::Checkbox("Enemy Head Circle", &VisualConfig::enemyHeadCircle);
						ImGui::Checkbox("Enemy Filled Head Cirlce", &VisualConfig::enemyFilledHeadCircle);
						ImGui::Checkbox("Team Head Circle", &VisualConfig::teamHeadCircle);
						ImGui::Checkbox("Team Filled Head Circle", &VisualConfig::teamFilledHeadCircle);

						ImGui::SliderFloat("Circle Thickness", &VisualConfig::circleThickness, 1.f, 3.f, "%.1f");
						ImGui::SliderFloat("Filled Circle Opacity", &VisualConfig::filledCircleOpacity, 0.1f, 1.f, "%.1f");


						ImGui::EndTabItem();
					}

					if (ImGui::BeginTabItem("Chams"))
					{
						ImGui::Checkbox("Player Chams", &VisualConfig::playerChams); 
						ImGui::Checkbox("Player WireFrame", &VisualConfig::playerWireFrame); 

						ImGui::Checkbox("Enemy Chams", &VisualConfig::enemyChams); 
						ImGui::Checkbox("Enemy WireFrame", &VisualConfig::enemyWireFrame); 
						ImGui::Checkbox("Team Chams", &VisualConfig::teamChams); 
						
						ImGui::ColorEdit3("Visible Color", VisualConfig::chamsVisibleColor, ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_NoInputs); 
						ImGui::ColorEdit3("Hidden Color", VisualConfig::chamsHiddenColor, ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_NoInputs);
						
						ImGui::EndTabItem(); 
					}

					if (ImGui::BeginTabItem("Color"))
					{ 
						ImGui::Text("Enemy Visual Color Color"); ImGui::SameLine(); 
						ImGui::ColorEdit3("##Enemy Colors", VisualConfig::enemyColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel); 

						ImGui::Text("Enemy Visual Color Color"); ImGui::SameLine();
						ImGui::ColorEdit3("##Team Colors", VisualConfig::teamColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
						ImGui::EndTabItem(); 
					}

					ImGui::EndTabBar();
				}


				if (MenuConfig::option == MenuConfig::misc)
				{
					
					ImGui::Checkbox("BHop", &MiscConfig::bHop);

				}

			}
			
			ImGui::EndChild();


			ImGui::PopStyleVar();
			ImGui::PopStyleVar();
			ImGui::PopStyleColor();
			ImGui::PopFont(); 

		}
		ImGui::End();
	}
}

void SetupMenuStyle()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.Alpha = 1.0;
	style.WindowRounding = 3;
	style.GrabRounding = 1;
	style.GrabMinSize = 20;
	style.FrameRounding = 3;
	style.Colors[ImGuiCol_Text] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.00f, 0.40f, 0.41f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.44f, 0.80f, 0.80f, 0.18f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.44f, 0.80f, 0.80f, 0.27f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.44f, 0.81f, 0.86f, 0.66f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.14f, 0.18f, 0.21f, 0.73f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.27f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.22f, 0.29f, 0.30f, 0.71f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.44f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 1.00f, 1.00f, 0.68f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.36f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.76f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.1f, 0.1f, 0.0f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.01f, 1.00f, 1.00f, 0.43f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.62f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.00f, 1.00f, 1.00f, 0.33f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.42f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 1.00f, 1.00f, 0.22f);
	style.Colors[ImGuiCol_Tab] = { 0.0f, 0.f, 0.f, 0.f }; 
	style.Colors[ImGuiCol_TabActive] = { 0.f, 1.f, 1.f, 0.3f }; 
}


void SetupMenuFont()
{
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	ImFontAtlas* fontAtlas = new ImFontAtlas();

	ImFontConfig arialConfig;
	arialConfig.FontDataOwnedByAtlas = false;
	arialFont = fontAtlas->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 16.f, &arialConfig);

	ImFontConfig calibrilConfig;
	calibrilConfig.FontDataOwnedByAtlas = false;
	calibrilFont = fontAtlas->AddFontFromFileTTF("C:\\Windows\\Fonts\\Calibri.ttf", 10.f, &calibrilConfig);


	ImFontConfig iconConfig;
	static const ImWchar iconRanges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
	iconConfig.MergeMode = true;
	iconConfig.GlyphRanges = iconRanges;
	iconConfig.FontDataOwnedByAtlas = false;
	iconFont = fontAtlas->AddFontFromMemoryTTF((void*)rawData, sizeof(rawData), 20.f, &iconConfig, iconRanges);
	io.Fonts = fontAtlas;

}