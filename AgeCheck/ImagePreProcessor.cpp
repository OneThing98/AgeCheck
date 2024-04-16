// ImagePreprocessor.cpp
#include "ImagePreprocessor.h"

cv::Mat ImagePreprocessor::preprocessImage(const cv::Mat& inputImage) const {
    auto grayImage = convertToGrayscale(inputImage);
    auto noiseReducedImage = reduceNoise(grayImage);
    auto thresholdedImage = applyThresholding(noiseReducedImage);
    return correctPerspective(thresholdedImage);
}

cv::Mat ImagePreprocessor::convertToGrayscale(const cv::Mat& inputImage) {
    cv::Mat grayImage;
    cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);
    return grayImage;
}

cv::Mat ImagePreprocessor::reduceNoise(const cv::Mat& grayImage) {
    cv::Mat blurredImage;
    cv::GaussianBlur(grayImage, blurredImage, cv::Size(5,5), 0);
    return blurredImage;

}

cv::Mat ImagePreprocessor::applyThresholding(const cv::Mat& blurredImage) {
    cv::Mat thresholdedImage;
    cv::adaptiveThreshold(blurredImage, thresholdedImage, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 11, 2);
    return thresholdedImage;
}

cv::Mat ImagePreprocessor::correctPerspective(const cv::Mat& thresholdedImage) {
    // This function is placeholder, as perspective correction would require more information
    // about the points to correct, which could vary for each image.
    return thresholdedImage;
}