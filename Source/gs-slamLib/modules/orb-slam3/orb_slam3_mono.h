#pragma once

#include "engine/core/scene/node.h"
#include "System.h"

namespace Echo
{
	class OrbSlam3Mono : public Node
	{
		ECHO_CLASS(OrbSlam3Mono, Node)

	public:
		OrbSlam3Mono();
		virtual ~OrbSlam3Mono();

		// Start
		virtual void start();

	public:
		ORB_SLAM3::System* m_slamSystem = nullptr;
	};
}
