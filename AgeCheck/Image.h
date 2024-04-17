//creating my own image storage structure
#pragma once
#include <vector>
#include <stdexcept>
#include <cstdint>

template <typename T>
class Image {
public:
	//constructor
	Image(std::size_t width, std::size_t height, std::size_t channels);

	//destructor
	~Image();

	//copy constructor
	Image(const Image& other);

	//copy assignment operator 
	Image& operator=(const Image& other);

	//move constructor
	Image(Image&& other) noexcept;

	//move assignment operator
	Image& operator=(Image&& other) noexcept;


	//accessors
	T& at(std::size_t x, std::size_t y, std::size_t channel);
	const T& at(std::size_t x, std::size_t y, std::size_t channel) const;

	//getters
	std::size_t getWidth() const { return width; }
	std::size_t getHeight() const { return height; }
	std::size_t getChannels() const { return channels; }

private:
	std::vector<T> data;
	std::size_t width;
	std::size_t height;
	std::size_t channels;
};
