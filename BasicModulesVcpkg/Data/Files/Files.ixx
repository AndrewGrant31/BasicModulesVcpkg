export module Files;

import Errors;
import XMLData;
import Includes;

namespace Files
{
	std::string file_ { };
}

export namespace ConnectionFiles
{
	auto AsConstChar ( ) noexcept -> const char*
	{
		return Files::file_.c_str ( );
	}

	bool FileExists ( const std::string& _ = std::string {} )
	{
		if ( not _.empty ( ) )
		{
			Files::file_.clear ( );
			Files::file_.assign ( _ );
		}
		return std::filesystem::exists ( Files::file_ );
	}

	auto GetFileIdentifier ( ) noexcept -> const std::string
	{
		return Files::file_;
	}
	
	auto FileNotFound ( )
	{
		std::unique_ptr<Error::Errors> errors;

		errors = std::make_unique<Error::Errors> (
			"Cannot Find Input File: ",
			ConnectionFiles::GetFileIdentifier ( ) );
		XMLData::CompleteUnorderedMap ( 
			errors->GetErrorType ( ), 
			errors->GetErrorDescription ( ) );

		return XMLData::GetUnorderedMap ( ); 
	}
}