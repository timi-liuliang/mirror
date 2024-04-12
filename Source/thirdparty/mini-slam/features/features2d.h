#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include "orb.h"

namespace Echo
{
	class Features2D
	{
	public:
		enum Type
		{
			ORB,
			CV_ORB,
		};

		friend class DescriptorMatcher;

	public:
		Features2D();
		~Features2D();

		// Detector key points
		void detect(const std::string& path, Type type, int nfeatures = 500);

		// Debug show
		void debugShow();

	protected:
		Type						m_type;
		cv::Mat						m_image;
		int							m_nfeatrues = 0;
		std::vector<cv::KeyPoint>	m_keypoints;
		ORB::Descriptors			m_descriptorsORB;
		cv::Mat						m_descriptorsCVORB;
	};
}