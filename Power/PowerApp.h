#pragma once

#include "PowerUtil.h"

namespace ow 
{
	class POW_API PowerApp
	{
	public:
		void Run();
		virtual void Initialize();
		virtual void Update();
		virtual void Shutdown();

	private:
		bool ShouldContinue{ true };
	};
}