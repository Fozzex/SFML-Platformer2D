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

		void setRange(int min, int max);
		int value();
		int seededValue(unsigned int seed);

	private:

		std::random_device m_DeviceGen;
		std::mt19937 m_TwisterGen;
		std::uniform_int_distribution<int> m_Redistributor;

	};
}