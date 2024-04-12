#include "orb_slam3_mono.h"
#include "engine/core/main/engine.h"
#include <string>

namespace Echo
{
	OrbSlam3Mono::OrbSlam3Mono()
	{

	}

	OrbSlam3Mono::~OrbSlam3Mono()
	{
	}

	void OrbSlam3Mono::bindMethods()
	{

	}

	void OrbSlam3Mono::start()
	{
		if (!m_slamSystem)
		{
			std::string vocabulary_file;
			std::string settings_file;
			m_slamSystem = new ORB_SLAM3::System(vocabulary_file, settings_file, ORB_SLAM3::System::MONOCULAR);
		}
	}
}