#pragma once

#include <vector>
#include <opencv2/opencv.hpp>

namespace Echo
{
	class ORB
	{
	public:
		typedef std::vector<uint32_t> DescriptorType;
		typedef std::vector<DescriptorType> Descriptors;

	public:
		// Compute keypoints and descriptors
		static void compute(const cv::Mat& image, std::vector<cv::KeyPoint>& keyPoints, std::vector<DescriptorType>& descriptors);

		// Brute-force match two sets of descriptors
		static void bfMatch(const std::vector<DescriptorType>& desc1, const std::vector<DescriptorType>& desc2, std::vector<cv::DMatch>& matches);
	};
}