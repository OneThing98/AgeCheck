#pragma once

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

class ImagePreprocessor {
public:
	[[nodiscard]] cv::Mat preprocessImage(const cv::Mat& inputImage) const;
private:
	[[nodiscard]] static cv::Mat convertToGrayscale(const cv::Mat& inputImage);
	[[nodiscard]] static cv::Mat reduceNoise(const cv::Mat& inputImage);
	[[nodiscard]] static cv::Mat applyThresholding(const cv::Mat& inputImage);
	[[nodiscard]] static cv::Mat correctPerspective(const cv::Mat& inputImage);
};

