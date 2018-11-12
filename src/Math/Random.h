#pragma once
#include <random>

namespace math
{
	class Generator
	{
	public:

		Generator(int min = 0, int max = 10);
		Generator(const Generator& copy);
		~Generator() {}

		// Sets the range of the int redistributor
		void setRange(int min, int max);

		// Generates a random value between the set min and max
		// Uses std::random_device as seed
		int value();

		// Generates a random value between the set min and max
		// Uses parameter as seed
		int seededValue(unsigned int seed);

	private:

		// Device generator is used to generate the seed
		// Random enough for a seed, however,
		// Not random enough to be the main generator.
		std::random_device m_DeviceGen;

		// A standard typedef of the mersenne twister generator
		// Takes seed from device gen and outputs the random value
		std::mt19937 m_TwisterGen;

		// Redistributes the random value from the twister gen
		// To be between the min and max
		std::uniform_int_distribution<int> m_Redistributor;

	};
}