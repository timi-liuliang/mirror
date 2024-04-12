#include "features2d.h"
#include "orb.h"
#include <opencv2/highgui/highgui.hpp>

namespace Echo
{
	Features2D::Features2D()
	{
	}

	Features2D::~Features2D()
	{

	}

	void Features2D::detect(const std::string& path, Type type, int nfeatures)
	{
		m_nfeatrues = nfeatures;
		m_type = type;

		if (m_type == ORB)
		{
			m_image = cv::imread(path.c_str(), 0);

			// Step1 : detect FAST keypoints using threshold
			cv::FAST(m_image, m_keypoints, 40);

			// Step2 : compute descriptors 
			ORB::compute(m_image, m_keypoints, m_descriptorsORB);
		}
		else if (m_type == CV_ORB)
		{
			m_image = cv::imread(path.c_str(), cv::IMREAD_COLOR);

			// Step1 : detect key points
			cv::Ptr<cv::FeatureDetector> detector = cv::ORB::create(m_nfeatrues);
			detector->detect(m_image, m_keypoints);

			// Step2
			cv::Ptr<cv::DescriptorExtractor> descriptor = cv::ORB::create();
			descriptor->compute(m_image, m_keypoints, m_descriptorsCVORB);
		}
	}

	void Features2D::debugShow()
	{
		cv::Mat debugImage;
		cv::drawKeypoints(m_image, m_keypoints, debugImage, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);

		std::string title = "";//std::string(magic_enum::enum_name(m_type)) + " Features";
		cv::imshow(title.c_str(), debugImage);
	}
}
