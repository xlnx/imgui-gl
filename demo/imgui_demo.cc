#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>

int main()
{
	glfwInit();

	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 2 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0 );
	glfwWindowHint( GLFW_RESIZABLE, GLFW_FALSE );

	auto window = glfwCreateWindow( 512, 512,
									"imgui demo", NULL, NULL );

	glfwMakeContextCurrent( window );
	gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress );

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	(void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL( window, true );
	ImGui_ImplOpenGL2_Init();

	while ( !glfwWindowShouldClose( window ) ) {
		glfwPollEvents();

		glClear( GL_COLOR_BUFFER_BIT );

		bool my_tool_active;
		float my_color[ 4 ];

		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin( "My First Tool", &my_tool_active, ImGuiWindowFlags_MenuBar );
		if ( ImGui::BeginMenuBar() ) {
			if ( ImGui::BeginMenu( "File" ) ) {
				if ( ImGui::MenuItem( "Open..", "Ctrl+O" ) ) { /* Do stuff */
				}
				if ( ImGui::MenuItem( "Save", "Ctrl+S" ) ) { /* Do stuff */
				}
				if ( ImGui::MenuItem( "Close", "Ctrl+W" ) ) { my_tool_active = false; }
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}

		// Edit a color (stored as ~4 floats)
		ImGui::ColorEdit4( "Color", my_color );

		// Plot some values
		const float my_values[] = { 0.2f, 0.1f, 1.0f, 0.5f, 0.9f, 2.2f };
		ImGui::PlotLines( "Frame Times", my_values, IM_ARRAYSIZE( my_values ) );

		// Display contents in a scrolling region
		ImGui::TextColored( ImVec4( 1, 1, 0, 1 ), "Important Stuff" );
		ImGui::BeginChild( "Scrolling" );
		for ( int n = 0; n < 50; n++ )
			ImGui::Text( "%04d: Some text", n );
		ImGui::EndChild();
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL2_RenderDrawData( ImGui::GetDrawData() );

		glfwMakeContextCurrent( window );
		glfwSwapBuffers( window );
	}

	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow( window );
	glfwTerminate();
}