export module PugiXML;

import :ProcessXML;

export import Includes;

export namespace PugiXML
{
	void GetXMLData ( const std::string& _ = std::string {} )
	{
		PugiXML::ProcessXML ( _ );
	}
}