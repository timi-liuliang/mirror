#pragma once

#include "features2d.h"

namespace Echo
{
	class DescriptorMatcher
	{
	public:
		DescriptorMatcher();
		~DescriptorMatcher();

		// Match
		void match(const Features2D& f1, const Features2D f2);

		// Debug show
		void debugShow();

	private:
		Features2D				m_features1;
		Features2D				m_features2;
		std::vector<cv::DMatch>	m_matches;
		double					m_minDistance = 1e30;
		double					m_maxDistance = -1e30;
		std::vector<cv::DMatch>	m_matchesGood;
	};
}