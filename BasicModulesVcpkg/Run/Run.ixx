export module Run;

import Files;
import XMLData;
import PugiXML;

export import Includes;

namespace ProcessXML
{
	void ProcessXMLData ( const std::string& _ = 
		std::string {} )
	{
		if ( ConnectionFiles::FileExists ( _ ) )
			PugiXML::GetXMLData ( _ );
		else
			ConnectionFiles::FileNotFound ( );
	}
}

export namespace Run
{
	void GetConnectionDetails (
		const std::optional<std::string>& _ = 
		std::nullopt )
	{
		ProcessXML::ProcessXMLData ( 
			_.has_value ( ) ? 
			_.value() : 
			std::string { } );

		for ( auto& node : XMLData::GetUnorderedMap() )
		{
			std::println ( "{0} : {1}", node.first, node.second );
		}
	}
}