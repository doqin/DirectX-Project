#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() { return new x(); }

class RHODO_API IApplication {

	// Application

public:
	// Application Contructor
	IApplication();

	// Application Deconstructor
	virtual ~IApplication() {};

public:
	// Called to Initialize the Application
	virtual VOID Initialize() = 0;

	// Game Loop - Called on a Loop While the Application is Running
	virtual VOID Update() = 0;
};

IApplication* EntryApplication();