#include "postMethod.hpp"

PostMethod::PostMethod(/* args */)
{
}

PostMethod::PostMethod(PostMethod const & copy)
{
	(void)copy;
}

PostMethod::~PostMethod()
{
}

PostMethod& PostMethod::operator=(PostMethod const & ope)
{
	(void)ope;
	return(*this);
}

void PostMethod::handlePost(ClientSocket &client, Config &config,Request &request, Response &response)
{
	
    (void)client;
	(void)config;
	(void)response;

	std::cout << "\nPOST POST\n";
	File filePost;

	if(config.getUploadDir(client.getServerName()).state == true) 
	{
		std::cout << "\nI AM HERE IN POST \n";
		File myupload(WORKPATH + config.getDirectoryPage(client.getServerName(), request.getUrl()).value);
		filePost = myupload;
	}
	else
	{
		File filenormal(WORKPATH + request.getUrl());
		filePost = filenormal;
	}
	

	

	if (filePost.isPresent()) {
		if(filePost.isFile())
		{
			std::cout << "APPEND present\n";
			filePost.fileAppend(WORKPATH + request.getUrl(), request.getBody());
		}
		//o create o append	
	}
	else {
		std::cout << "CREATION\n";
		filePost.fileCreate(WORKPATH + request.getUrl());
		if(filePost.isFile())
		{
			std::cout << "APPEND create\n";
			filePost.fileAppend(WORKPATH + request.getUrl(), request.getBody());
		}
	}
		
}