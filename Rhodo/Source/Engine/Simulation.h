#pragma once

#include "Platform/Win32/IApplication.h"

namespace Rhodo {

	class RHODO_API Simulation : public Win32::IApplication {

	public:
		Simulation();
		~Simulation();
		
	};

};