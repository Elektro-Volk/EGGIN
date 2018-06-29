/*
net.h - network interface
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
#pragma once
#include "common.h"
#include "utils/nextlist.hpp"

typedef int pid;
typedef void (*callback)(int, char*, int);
namespace net
{
  struct client {

  };


  extern callback onClientCommand;
  extern callback onServerCommand;

  extern Nextlist<pid, client> clients;

  extern int sv;
  extern int cl;

	void init();
	void frame();
  void createServer(int port = 10001);
  void connectToServer(char* ip, int port = 10001);
  void readSocket(int sock, callback);
}
