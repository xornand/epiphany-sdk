/*
  File: e_coreid_coreid_from_address.c

  This file is part of the Epiphany Software Development Kit.

  Copyright (C) 2013 Adapteva, Inc.
  Contributed by Oleg Raikhman, Jim Thomas, Yaniv Sapir <support@adapteva.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License (LGPL)
  as published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  and the GNU Lesser General Public License along with this program,
  see the files COPYING and COPYING.LESSER.  If not, see
  <http://www.gnu.org/licenses/>.
*/

#include <machine/epiphany_config.h>
#include "e_coreid.h"

e_coreid_t e_coreid_from_address(const void *ptr)
{
	e_coreid_t coreid;

	coreid = ((e_coreid_t) ptr >> 20);
	/* If a local address is given, return the caller's coreid. */
	coreid = (coreid) ? coreid : e_get_coreid();

	return coreid;
}
