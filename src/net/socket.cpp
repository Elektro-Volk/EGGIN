/*
socket.cpp - socket interface
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
#include "socket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "string.h"
#include <fcntl.h> /* Added for the nonblocking socket */

struct sockaddr_in svaddr;

int sockets::create()
{
  int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  fcntl(sock, F_SETFL, O_NONBLOCK);
  return sock;
}

int sockets::listen(int sock)
{
  struct sockaddr_in addr;

  memset((char *) &addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(10001);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  return bind(sock, (struct sockaddr *)&addr, sizeof(addr));
}

int sockets::connect(int sock)
{
  memset((char *) &svaddr, 0, sizeof(svaddr));

  svaddr.sin_family = AF_INET;
  svaddr.sin_port = htons(10001);
  svaddr.sin_addr.s_addr = inet_addr ("localhost");
  int c = connect(sock, (struct sockaddr *)&svaddr, sizeof(svaddr));
  printf("Error: %i", errno);
  return c;
}

/*int sockets::send(int sock, char *data, int len, struct sockaddr *addr)
{
  socklen_t len = sizeof(addr);
  return sendto(sock, data, len, 0, addr, &len);
}*/
