
import Includes;

import Run;

auto main ( int argc, char* argv [ ] ) -> int
{
	Run::GetConnectionDetails ( argc == 2 ?
		std::string { argv [ 1 ] } : 
		std::string {} );
}