#include <boost/asio.hpp>
#include "cares_service/cares_service.hpp"

void handle_resolve(const boost::system::error_code & ec)
{
	std::cout << ec.message() << std::endl;
}

int
main(int argc, char * argv[])
{
	boost::asio::io_service io_service;
	services::cares::cares cares(io_service);
	for (int i = 1; i < argc; ++i)
	{
		cares.resolve(argv[i], &handle_resolve);
	}
	io_service.run();
}