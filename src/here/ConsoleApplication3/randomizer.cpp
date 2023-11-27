#include "randomizer.h"

void genericRandomizer(const char* data) {
	std::istringstream inputStream(data);
	
	std::string item;
	int numOfItems = 0;

	while (std::getline(inputStream, item)) {
		++numOfItems;
	}

	inputStream.clear();
	inputStream.seekg(0, std::ios::beg);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, numOfItems);

	int random = dis(gen);

	int currentItem = 0;

	while (std::getline(inputStream, item)) {
		++currentItem;
		if (currentItem == random) {
			std::cout << item << "\n";
		}
	}
}