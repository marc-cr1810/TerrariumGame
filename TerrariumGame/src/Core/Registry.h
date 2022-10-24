#pragma once

#include <Terrarium.h>

#include <string>
#include <map>

template<class T>
class Registry
{
public:
	Registry(std::string name)
		: m_Name(name)
	{}
	~Registry() = default;

	T Register(std::string name, T value)
	{
		m_Resources[name] = value;
		return value;
	}

	T GetValue(std::string name) const
	{
		auto pos = m_Resources.find(name);
		if (pos == m_Resources.end())
		{
			TE_ERROR("Could not find resource \"{0}\" in {1}", name, this->ToString());
			return T();
		}
		return pos->second;
	}

	std::string GetName() const { return m_Name; }
	std::string ToString() const { return "Registry[" + m_Name + "]"; }
private:
	std::string m_Name;
	std::map<std::string, T> m_Resources;
};