#ifndef IMIDDLEWARE_HPP
# define IMIDDLEWARE_HPP

class IMiddleware;

# include <iostream>
# include "ClientSocket.hpp"
# include "Config.hpp"
# include "request.hpp"
# include "response.hpp"
# include "MiddlewareChain.hpp"

class IMiddleware {

	public:
		virtual ~IMiddleware();

		virtual void handle(ClientSocket &client, Config &config, Request &request, Response &response, MiddlewareChain &next) = 0;

};

# include "deleteMethod.hpp"
# include "postMethod.hpp"
# include "getMethod.hpp"
# include "cgiHandler.hpp"

#endif