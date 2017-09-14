/*
 *  This file is part of FH8620 BSP for RT-Thread distribution.
 *
 *	Copyright (c) 2016 Shanghai Fullhan Microelectronics Co., Ltd.
 *	All rights reserved
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *	Visit http://www.fullhan.com to get contact with Fullhan.
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include <msh.h>

int main(int argc, char** argv)
{
	int fd;
	char cmd[] = "/init.sh";

	char author[] = "baojun.fu";
	char e_mail[] = "fubaojun2006@139.com";
	printf("******************************************************************************************\n");
	printf("                                                                                            \n");
	printf("   Hello      Compiled by %s      \n", author);           
	printf("   IOT        E-mail: %s       \n", e_mail);              
	printf("   Camera     Compile at: %s %s \n", __DATE__, __TIME__); 
	printf("------======Startup Sucess======--------                                                            \n");
	printf("******************************************************************************************\n");

	fd = open("/init.sh", O_RDONLY, 0);
	if (fd >= 0)
	{
		close(fd);

		printf("exec %s ...\n", cmd);
		msh_exec(cmd, sizeof(cmd));
	}
	else
	{
		printf("Can not exec %s. Something is ERROR!\n\n", cmd);
	}

	return 0;
}
