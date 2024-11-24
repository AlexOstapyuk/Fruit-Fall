#pragma once

namespace ow 
{
	class PowerApp
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