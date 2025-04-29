module;

#include "pugixml.hpp"

export module XMLData;

import Includes;

namespace UnorderedMap
{
	std::unordered_map<std::string, std::string> nodes;
}

export namespace XMLData
{
	pugi::xml_parse_result result;
	pugi::xml_document doc;

	void CompleteUnorderedMap ( const std::string _type_,
		const std::string& _description_ )
	{
		UnorderedMap::nodes.emplace ( _type_, _description_ );
	}


	auto IsEmpty ( )
	{
		return UnorderedMap::nodes.size ( );
	}

	auto GetUnorderedMap ( ) noexcept -> const decltype( UnorderedMap::nodes )
	{
		return UnorderedMap::nodes;
	}
}