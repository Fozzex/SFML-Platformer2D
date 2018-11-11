template<typename _Rty>
ResourceManager<_Rty>::ResourceManager(const std::string& folder) :
	m_Folder(folder)
{
}

template<typename _Rty>
ResourceManager<_Rty>::~ResourceManager()
{
}

template<typename _Rty>
bool ResourceManager<_Rty>::loadResource(const std::string& name)
{
	if (m_Resources.find(name) != m_Resources.end())
	{
		return true;
	}
	else
	{
		_Rty resource;
		if (!resource.loadFromFile(m_Folder + "/" + name))
		{
			return false;
		}
		else
		{
			m_Resources.insert({ name, resource });
			return true;
		}
	}
}

template<typename _Rty>
const _Rty& ResourceManager<_Rty>::getResource(const std::string& name)
{
	if (m_Resources.find(name) != m_Resources.end())
	{
		return m_Resources.at(name);
	}
	else
	{
		if (this->loadResource(name))
		{
			return m_Resources.at(name);
		}
		else
		{
			throw ResourceExcept();
		}
	}
}