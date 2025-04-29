export module Errors;

export import Includes;

export namespace Error
{
	class Errors
	{
	private:
		std::tuple<std::string, std::string> errors;

		auto Set ( const std::string& type_, 
			const std::string& description_ ) noexcept -> std::tuple<std::string, std::string>
		{
			return std::make_tuple ( type_, description_ );
		}

	public:
		explicit Errors ( const std::string& _type_, 
			const std::string& _description_ ) :
			errors { Set ( _type_, _description_ ) }
		{

		}

		auto GetErrors ( ) noexcept -> decltype( errors )
		{
			return errors;
		}

		auto GetErrorType ( ) noexcept -> const std::string
		{
			return std::get<0> ( errors );
		}

		auto GetErrorDescription ( ) noexcept -> const std::string
		{
			return std::get<1> ( errors );
		}

	};
}