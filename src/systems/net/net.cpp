/*
net.cpp - network interface
Copyright (C) 2018 Elektro-Volk
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/
#include "net.h"
#include "socket.h"
#include "console.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Callbacks
callback net::onClientCommand;// Server -> Client
callback net::onServerCommand;// Client -> Server

Nextlist<pid, net::client> net::clients;
// Sockets
int net::sv = -1;
int net::cl = -1;

struct sockaddr_in svaddr; // Server adress (sendto)

void net::init()
{

}

void net::frame()
{
  if(sv != -1) net::readSocket(sv, onServerCommand);
  //if(cl != -1) net::readSocket(cl, onClientCommand);
}

void net::createServer(int port)
{
  net::sv = sockets::create();
  if(sockets::listen(net::sv) < 0) console::log("Crerror");

  net::connectToServer("localhost", 10001);
  console::log("Created server.");
}

void net::connectToServer(char* ip, int port)
{
  net::cl = sockets::create();
  if(sockets::connect(net::cl) < 0) console::log("Conerror");
  console::log("Connected to server.");

  sendto(cl, "lol", sizeof("lol"), 0, (struct sockaddr *)&svaddr, sizeof(svaddr));
}

void net::readSocket(int sock, callback cb)
{
  struct sockaddr addr;
  socklen_t slen = sizeof(addr);
  char buf[1024];

  int recv_len = recvfrom(sock, buf, 1024, 0, &addr, &slen);
  if(recv_len >= 0) console::log(buf);
}
