#pragma once

#include "Platform/WIN32/IApplication.h"

class Application : public IApplication {

	// Application

public:
	// Application Contructor
	Application();

	// Application Deconstructor
	~Application();

public:
	// Called to Initialize the Application
	VOID Initialize();

	// Game Loop - Called on a Loop While the Application is Running
	VOID Update();
};