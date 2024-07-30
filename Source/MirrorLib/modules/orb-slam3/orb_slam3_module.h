#pragma once

#include "engine/core/main/module.h"

namespace Echo
{
	class OrbSlam3Module : public Module
	{
		ECHO_SINGLETON_CLASS(OrbSlam3Module, Module)

	public:
		OrbSlam3Module();
		virtual ~OrbSlam3Module();

		// instance
		static OrbSlam3Module* instance();

		// register all types of the module
		virtual void registerTypes() override;

	protected:
	};
}
