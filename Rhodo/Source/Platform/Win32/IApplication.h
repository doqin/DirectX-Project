#pragma once

#define ENTRYAPP(x) Win32::IApplication* EntryApplication() { return new x(); }

namespace Win32 {

	class RHODO_API IApplication {

		// Application

	public:
		// Application Contructor
		IApplication();

		// Application Deconstructor
		virtual ~IApplication() {};

	public:
		// Called to Setup Per Game Settings
		virtual VOID SetupPerGameSettings() = 0;

		// Called to PreInitialize the Application
		virtual VOID PreInitialize() = 0;

		// Called to Initialize the Application
		virtual VOID Initialize() = 0;

		// Game Loop - Called on a Loop While the Application is Running
		virtual VOID Update() = 0;
	};

	IApplication* EntryApplication();

}