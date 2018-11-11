#include "Random.h"

namespace math
{
	Generator::Generator(int min, int max)
	{
		m_Redistributor = std::uniform_int_distribution<int>(min, max);
	}

	Generator::Generator(const Generator& copy)
		: m_Redistributor(copy.m_Redistributor)
	{
	}

	int Generator::value()
	{
		m_TwisterGen = std::mt19937(m_DeviceGen());
		return m_Redistributor(m_TwisterGen);
	}

	int Generator::seededValue(unsigned int seed)
	{
		m_TwisterGen = std::mt19937(seed);
		return m_Redistributor(m_TwisterGen);
	}

	void Generator::setRange(int min, int max)
	{
		m_Redistributor = std::uniform_int_distribution<int>(min, max);
	}
}