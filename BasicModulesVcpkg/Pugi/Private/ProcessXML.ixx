module;

#include "pugixml.hpp"

export module PugiXML:ProcessXML;

import Files;
import XMLData;
import Errors;

export import Includes;

namespace PugiXML
{
	void ProcessXML ( const std::string& _ = std::string {} )
	{
		std::unique_ptr <Error::Errors> errors;

		XMLData::doc = pugi::xml_document ( );
		XMLData::result = XMLData::doc.load_file (
			ConnectionFiles::AsConstChar ( ) );

		switch ( XMLData::result )
		{
		case false:
			errors = std::make_unique<Error::Errors> (
				"XML File Error", XMLData::result.description ( ) );
			XMLData::CompleteUnorderedMap (
				errors->GetErrorType ( ),
				errors->GetErrorDescription ( ) );
			break;
		default:
			auto details = XMLData::doc.
				child ( "Databases" ).
				child ( "Details" ).
				child ( "Type" );

			for ( auto& detail : details )
			{
				bool isEmpty {
					strnlen_s ( detail.child_value ( ),
						sizeof detail.child_value ( ) ) == 0 };

				if ( isEmpty )
					errors = std::make_unique<Error::Errors> (
						"", "No Value Found" );

				XMLData::CompleteUnorderedMap ( detail.name ( ),
					isEmpty ?
					errors->GetErrorDescription ( ) :
					detail.child_value ( ) );
			}
		}
	}
}
