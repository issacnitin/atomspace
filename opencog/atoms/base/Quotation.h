/*
 * opencog/atoms/base/Quotation.h
 *
 * Copyright (C) 2016 OpenCog Foundation
 * All Rights Reserved
 *
 * Written by Nil Geisweiller
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _OPENCOG_QUOTATION_H
#define _OPENCOG_QUOTATION_H

#include <opencog/atoms/base/atom_types.h>

namespace opencog
{

/** \addtogroup grp_atomspace
 *  @{
 */

/**
 * Quotation data and methods. See http://wiki.opencog.org/w/QuoteLink.
 */
class Quotation
{
	int _quotation_level;
	bool _local_quote;

public:
	Quotation(int ql=0, bool lq=false);

	int quotation_level() const;
	bool is_locally_quoted() const;
	bool is_quoted() const;

	/**
	 * Increment, decrement or change local quote given the type of
	 * the current atom before handing the quotation to the outgoing.
	 */
	void update(Type t);

	/**
	 * Check whether the current atom would be consumed as quotation
	 * operator or not. More specifically:
	 *
	 * 1. An unquoted QuoteLink would be consumed, passing the
	 * quotation state from unquoted to quoted.
	 *
	 * 2. An UnquoteLink with quotation level of 1 would be consumed,
	 * passing the quotation state from quoted to unquoted.
	 *
	 * 3. An unquoted LocalQuoteLink would be consumed, passing
	 * temporarily the quotation state from unquoted to quoted.
	*/
	bool consumable_quotation(Type t);
};

/** @}*/
} // namespace opencog

#endif // _OPENCOG_QUOTATION_H
