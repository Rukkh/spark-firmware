/**
 ******************************************************************************
 * @file    network.cpp
 * @authors Matthew McGowan
 * @date    13 January 2015
 ******************************************************************************
  Copyright (c) 2015 Particle Industries, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */


#include "testapi.h"

test(api_ip_address) {

    API_COMPILE(IPAddress(HAL_IPAddress()));



}


test(api_tcpserver) {

    TCPServer server(80);
    int available = 0;
    API_COMPILE(server.begin());
    API_COMPILE(available = server.available());
    API_COMPILE(server.stop());
    
}