#include "ListeningSocket.hpp"

// ListeningSocket::ListeningSocket(int fd, sockaddr_in addr) : ASocket(fd), _addr(addr) {}

ListeningSocket::ListeningSocket(int fd) : ASocket(fd){}

ListeningSocket::~ListeningSocket(){}

ListeningSocket::ListeningSocket(const ListeningSocket & other) : ASocket(){
	*this = other;
}

ListeningSocket & ListeningSocket::operator=(const ListeningSocket & other){
	if (this != &other)
	{
		ASocket::operator=(other);
	}
	return (*this);
}

int	ListeningSocket::getFd(void) const{
	return (_fd);
}

void ListeningSocket::read(Config *datas, FDList *listFD)
{
	(void)datas;
	socklen_t i = 0;

	std::cout << "adding client" << std::endl;
	int fd = accept(_fd, NULL, &i);
	ClientSocket *tmp = new ClientSocket(fd);
	listFD->addSocket(tmp);

	// struct sockaddr_in from;
	// socklen_t addrlen = sizeof(_addr);
	// std::string clientAddress;
	// std::string clientPort;

	// int newClient = accept(_fd, (struct sockaddr*)(&from), &addrlen);
	// if (newClient != -1)
	// {
	// 	char buff[INET6_ADDRSTRLEN] = { 0 };
	// 	std::ostringstream s;

	// 	clientAddress = inet_ntop(_addr.sin_family, (void*)&(_addr.sin_addr), buff, INET6_ADDRSTRLEN);
	// 	s << _addr.sin_port;
	// 	clientPort = s.str();
	// 	std::cout << "Connexion de " << clientAddress << ":" << clientPort << std::endl;
	// }
	// ClientSocket *tmp = new ClientSocket(newClient, clientAddress, clientPort);
	// listFD->addSocket(tmp);
}

void ListeningSocket::write(Config *datas, FDList *listFD)
{
	(void)datas;
	(void)listFD;
}