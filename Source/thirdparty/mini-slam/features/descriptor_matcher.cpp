#include "descriptor_matcher.h"
#include <opencv2/highgui/highgui.hpp>

namespace Echo
{
	DescriptorMatcher::DescriptorMatcher()
	{

	}

	DescriptorMatcher::~DescriptorMatcher()
	{

	}

	void DescriptorMatcher::match(const Features2D& f1, const Features2D f2)
	{
		m_features1 = f1;
		m_features2 = f2;

		if (f1.m_type == Features2D::ORB && f2.m_type == Features2D::ORB)
		{
			ORB::bfMatch(f1.m_descriptorsORB, f2.m_descriptorsORB, m_matches);
		}
		else if (f1.m_type == Features2D::CV_ORB && f2.m_type == Features2D::CV_ORB)
		{
			cv::Ptr<cv::DescriptorMatcher> matcher = cv::BFMatcher::create(cv::NORM_HAMMING);
			matcher->match(f1.m_descriptorsCVORB, f2.m_descriptorsCVORB, m_matches);
		}

		// Calculate min and max distance
		auto minMax = minmax_element(m_matches.begin(), m_matches.end(), [](const cv::DMatch& m1, const cv::DMatch& m2)
			{
				return m1.distance < m2.distance;
			});

		m_minDistance = minMax.first->distance;
		m_maxDistance = minMax.second->distance;

		// Store good matches
		for (size_t i = 0; i < m_matches.size(); i++)
		{
			if (m_matches[i].distance <= std::max<double>(2 * m_minDistance, 30))
			{
				m_matchesGood.emplace_back(m_matches[i]);
			}
		}
	}

	void DescriptorMatcher::debugShow()
	{
		cv::Mat imageGoodMatch;
		cv::drawMatches(m_features1.m_image, m_features1.m_keypoints, m_features2.m_image, m_features2.m_keypoints, m_matchesGood, imageGoodMatch);

		cv::imshow("Good Matches", imageGoodMatch);
	}
}