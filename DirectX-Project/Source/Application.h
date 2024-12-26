#pragma once

#include "Engine/Simulation.h"

class Application : public Rhodo::Simulation {

	// Application

public:
	// Application Contructor
	Application();

	// Application Deconstructor
	~Application();

public:

	// Called to Setup Per Game Settings
	VOID SetupPerGameSettings();

	// Called to Initialize the Application
	VOID Initialize();

	// Game Loop - Called on a Loop While the Application is Running
	VOID Update();
};