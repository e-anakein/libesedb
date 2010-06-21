/*
 * Page tree functions
 *
 * Copyright (c) 2009-2010, Joachim Metz <jbmetz@users.sourceforge.net>
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

#if !defined( _LIBESEDB_PAGE_TREE_H )
#define _LIBESEDB_PAGE_TREE_H

#include <common.h>
#include <types.h>

#include <liberror.h>

#include "libesedb_data_definition.h"
#include "libesedb_io_handle.h"
#include "libesedb_libbfio.h"
#include "libesedb_libfdata.h"
#include "libesedb_list_type.h"
#include "libesedb_page.h"
#include "libesedb_page_tree_values.h"
#include "libesedb_table_definition.h"
#include "libesedb_tree_type.h"

#if defined( __cplusplus )
extern "C" {
#endif

enum LIBESEDB_PAGE_TREE_FLAGS
{
	LIBESEDB_PAGE_TREE_FLAG_READ_CATALOG		= 0x01
};

typedef struct libesedb_page_tree libesedb_page_tree_t;

struct libesedb_page_tree
{
	/* The table definition
	 */
	libesedb_table_definition_t *table_definition;

	/* The template table definition
	 */
	libesedb_table_definition_t *template_table_definition;

	/* The table definition list
	 */
	libesedb_list_t *table_definition_list;

	/* The value definition page tree root node
	 */
	libesedb_tree_node_t *value_definition_tree_root_node;
};

int libesedb_page_tree_initialize(
     libesedb_page_tree_t **page_tree,
     libesedb_table_definition_t *table_definition,
     libesedb_table_definition_t *template_table_definition,
     liberror_error_t **error );

int libesedb_page_tree_free(
     libesedb_page_tree_t **page_tree,
     liberror_error_t **error );

int libesedb_page_tree_get_number_of_table_definitions(
     libesedb_page_tree_t *page_tree,
     int *number_of_table_definitions,
     liberror_error_t **error );

int libesedb_page_tree_get_table_definition(
     libesedb_page_tree_t *page_tree,
     uint32_t table_definition_index,
     libesedb_table_definition_t **table_definition,
     liberror_error_t **error );

int libesedb_page_tree_get_table_definition_by_identifier(
     libesedb_page_tree_t *page_tree,
     uint32_t identifier,
     libesedb_table_definition_t **table_definition,
     liberror_error_t **error );

int libesedb_page_tree_get_table_definition_by_utf8_name(
     libesedb_page_tree_t *page_tree,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libesedb_table_definition_t **table_definition,
     liberror_error_t **error );

int libesedb_page_tree_get_number_of_value_definitions(
     libesedb_page_tree_t *page_tree,
     int *number_of_value_definitions,
     liberror_error_t **error );

int libesedb_page_tree_node_get_value_definition_by_index(
     libesedb_tree_node_t *value_definition_tree_node,
     uint32_t value_definition_index,
     libesedb_data_definition_t **value_definition,
     liberror_error_t **error );

int libesedb_page_tree_get_value_definition(
     libesedb_page_tree_t *page_tree,
     uint32_t value_definition_index,
     libesedb_data_definition_t **value_definition,
     liberror_error_t **error );

int libesedb_page_tree_node_get_value_definition_by_key(
     libesedb_tree_node_t *value_definition_tree_node,
     uint8_t *key,
     size_t key_size,
     libesedb_data_definition_t **value_definition,
     uint8_t flags,
     liberror_error_t **error );

int libesedb_page_tree_get_value_definition_by_key(
     libesedb_page_tree_t *page_tree,
     uint8_t *key,
     size_t key_size,
     libesedb_data_definition_t **value_definition,
     uint8_t flags,
     liberror_error_t **error );

int libesedb_page_tree_read(
     libesedb_page_tree_t *page_tree,
     libesedb_io_handle_t *io_handle,
     libbfio_handle_t *file_io_handle,
     uint32_t father_data_page_number,
     uint8_t flags,
     liberror_error_t **error );

int libesedb_page_tree_read_root_page_value(
     libesedb_page_tree_t *page_tree,
     libesedb_tree_node_t *value_definition_tree_node,
     libesedb_page_t *page,
     libesedb_page_value_t *page_value,
     libesedb_io_handle_t *io_handle,
     libbfio_handle_t *file_io_handle,
     uint8_t flags,
     liberror_error_t **error );

int libesedb_page_tree_read_branch_page_values(
     libesedb_page_tree_t *page_tree,
     libesedb_tree_node_t *value_definition_tree_node,
     libesedb_page_t *page,
     libesedb_io_handle_t *io_handle,
     libbfio_handle_t *file_io_handle,
     uint8_t flags,
     liberror_error_t **error );

int libesedb_page_tree_read_space_tree_page_values(
     libesedb_page_tree_t *page_tree,
     libesedb_tree_node_t *value_definition_tree_node,
     libesedb_page_t *page,
     liberror_error_t **error );

int libesedb_page_tree_read_leaf_page_values(
     libesedb_page_tree_t *page_tree,
     libesedb_tree_node_t *value_definition_tree_node,
     libesedb_page_t *page,
     libesedb_io_handle_t *io_handle,
     libbfio_handle_t *file_io_handle,
     uint8_t flags,
     liberror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

