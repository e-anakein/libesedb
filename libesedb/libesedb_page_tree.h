/*
 * Page (B+) tree functions
 *
 * Copyright (c) 2009, Joachim Metz <forensics@hoffmannbv.nl>,
 * Hoffmann Investigations. All rights reserved.
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBPFF_PAGE_TREE_H )
#define _LIBPFF_PAGE_TREE_H

#include <common.h>
#include <types.h>

#include <liberror.h>

#include "libesedb_io_handle.h"
#include "libesedb_list_type.h"
#include "libesedb_page.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libesedb_page_tree libesedb_page_tree_t;

struct libesedb_page_tree
{
	/* The table definition list
	 */
	libesedb_list_t *table_definition_list;

	/* The column definition list
	 */
	libesedb_list_t *column_definition_list;

	/* The index definition list
	 */
	libesedb_list_t *index_definition_list;

	/* The long value definition list
	 */
	libesedb_list_t *long_value_definition_list;
};

int libesedb_page_tree_initialize(
     libesedb_page_tree_t **page_tree,
     liberror_error_t **error );

int libesedb_page_tree_free(
     libesedb_page_tree_t **page_tree,
     liberror_error_t **error );

int libesedb_page_tree_read(
     libesedb_page_tree_t *page_tree,
     libesedb_io_handle_t *io_handle,
     uint32_t father_data_page_number,
     liberror_error_t **error );

int libesedb_page_tree_read_father_data_page_values(
     libesedb_page_tree_t *page_tree,
     libesedb_page_t *page,
     libesedb_io_handle_t *io_handle,
     liberror_error_t **error );

int libesedb_page_tree_read_space_tree_page_values(
     libesedb_page_tree_t *page_tree,
     libesedb_page_t *page,
     liberror_error_t **error );

int libesedb_page_tree_read_leaf_page_values(
     libesedb_page_tree_t *page_tree,
     libesedb_page_t *page,
     liberror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

