#include "PowerApp.h"


namespace ow
{
	void PowerApp::Run()
	{
		Initialize();

		while (ShouldContinue) {
			Update();
		}

		Shutdown();
	}

	void PowerApp::Initialize()
	{
	}

	void PowerApp::Update()
	{
	}

	void PowerApp::Shutdown()
	{
	}


}

