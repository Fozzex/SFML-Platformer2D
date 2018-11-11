#pragma once
#include <SFML/Graphics.hpp>
#include <exception>
#include <string>
#include <unordered_map>

class ResourceExcept : public std::exception
{
public:

	virtual const char* what() const throw()
	{
		return "Failed to access resource.";
	}

};

template<typename _Rty>
class ResourceManager
{
public:

	ResourceManager(const std::string& folder);
	~ResourceManager();

	bool loadResource(const std::string& name);
	const _Rty& getResource(const std::string& name);

private:

	std::unordered_map<std::string, _Rty> m_Resources;
	std::string m_Folder;

};

#include "ResourceManager.inl"