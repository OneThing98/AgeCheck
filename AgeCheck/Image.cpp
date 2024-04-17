#include "Image.h"

//constructor 
template<typename T>
Image<T>::Image(std::size_t width, std::size_t height, std::size_t channels):
	width(width), height(height), channels(channels), data(width * height * channels) {}

//destructor
template<typename T>
Image<T>::~Image() = default;

//copy constructor implementation
template<typename T>
Image<T>::Image(const Image<T>& other):
	data(other.data), width(other.width), height(other.height), channels(other.channels) {}

//copy assignment operator implementation
template<typename T>
Image<T>& Image<T>::operator=(const Image<T>& other) {
	if (this != &other) {
		data = other.data;
		width = other.width;
		height = other.height;
		channels = other.channels;
	}
	return *this;
}

//move constructor
template<typename T>
Image<T>::Image(Image<T>&& other) noexcept :
	data(std::move(other.data)), width(other.width), height(other.height), channels(other.channels) {
	other.width = 0;
	other.height = 0;
	other.channels = 0;
}

//move assignment operator
template<typename T>
Image<T>& Image<T>::operator=(Image<T>&& other) noexcept {
	if (this != &other) {
		data = std::move(other.data);
		width = other.width;
		height = other.height;
		channels = other.channels;

		other.width = 0;
		other.height = 0;
		other.channels = 0;
	}
	return *this;
}

//Accessor method
template<typename T>
T& Image<T>::at(std::size_t x, std::size_t y, std::size_t channel) {
	if (x >= width || y >= height || channel >= channels) {
		throw std::out_of_range("Coordinates out of bounds!");
	}
	return data[x + y * width + channel * width * height];
}

//read-only access
template<typename T>
const T& Image<T>::at(std::size_t x, std::size_t y, std::size_t channel) const {
	if (x >= width || y >= height || channel >= channels) {
		throw std::out_of_range("Coordinates out of bounds!");
	}
	return data[x + y * width + channel * width * height];
}
