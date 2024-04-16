#include "Image.h"

//constructor 
template<typename T>
Image<T>::Image(std::size_t width, std::size_t height, std::size_t channels):
	width(width), height(height), channels(channels), data(width * height * channels) {}

//destructor
template<typename T>
Image<T>::~Image() {}

//Accessor method
template<typename T>
T& Image<T>::at(std::size_t x, std::size_t y, std::size_t channel) {
	if (x >= width || y >= height || channel >= channels) {
		throw std::out_of_range("Coordinates out of bounds!")
	return data[x + y * width + channel * width * height];
	}
}

//read-only access
template<typename T>
const T& Image<T>::at(std::size_t x, std::size_t y, std::size_t channel) const {
	if (x >= width || y >= height || channel >= channels) {
		throw std::out_of_range("Coordinates out of bounds!")
	return data[x + y * width + channel * width * height];
	}
}
