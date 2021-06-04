#include "ClientSocket.hpp"

ClientSocket::ClientSocket(int fd) : ASocket(fd), _bareRequest(0), _bareAnswer(0){}

ClientSocket::~ClientSocket(){}
//en fonction, probable delete[] a faire ou pas si vector

ClientSocket::ClientSocket(const ClientSocket & other) : ASocket(){
	*this = other;
}

ClientSocket & ClientSocket::operator=(const ClientSocket & other){
	if (this != &other)
	{
		ASocket::operator=(other);
		_bareAnswer = other._bareAnswer;
		_bareRequest = other._bareRequest;
	}
	return (*this);
}

int	ClientSocket::getFd(void) const{
	return (_fd);
}