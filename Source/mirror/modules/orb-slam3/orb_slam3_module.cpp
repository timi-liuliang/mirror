#include "orb_slam3_module.h"
#include "orb_slam3_mono.h"
#include "orb_slam3_stereo.h"

namespace Echo
{
	DECLARE_MODULE(OrbSlam3Module, __FILE__)

	OrbSlam3Module::OrbSlam3Module()
	{

	}

	OrbSlam3Module::~OrbSlam3Module()
	{
	}

	OrbSlam3Module* OrbSlam3Module::instance()
	{
		static OrbSlam3Module* inst = EchoNew(OrbSlam3Module);
		return inst;
	}

	void OrbSlam3Module::bindMethods()
	{
	}

	void OrbSlam3Module::registerTypes()
	{
		Class::registerType<OrbSlam3Mono>();
		Class::registerType<OrbSlam3Stereo>();
	}
}
