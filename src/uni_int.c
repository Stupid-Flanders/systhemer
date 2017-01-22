#include <string.h>
/* #include "uni_int.h" */
#include "memory.h"
#include "utils.h"
#include "unitheme.h"

memory_address g_int_attrs_add(const memory_address a, const memory_address b);
memory_address g_int_attrs_subtract(const memory_address a, const memory_address b);
memory_address g_int_attrs_multiply(const memory_address a, const memory_address b);
memory_address g_int_attrs_divide(const memory_address a, const memory_address b);

type_attrs g_int_attrs = {
  .esc_char                = '\0',
  .escaped                 = {NULL},   /* escaped   */
  .unescaped               = {NULL},   /* unescaped */
  .num_escs                = 0,
  .delim_char              = '\0',
  .allow_unrecognized_escs = false,
  .add                     = g_int_attrs_add,
  .subtract                = g_int_attrs_subtract,
  .multiply                = g_int_attrs_multiply,
  .divide                  = g_int_attrs_divide,
  .is_string_type          = false,
  .s_type                  = T_INTEGER,
  .t_type                  = t_int
};

memory_address g_int_attrs_add(const memory_address a, const memory_address b) {
  memory_item *result_item = malloc(sizeof(memory_item));
  result_item->integer = memoryGetRootItem(g_memory, a)->integer +
    memoryGetRootItem(g_memory, b)->integer;
  return memoryInsert(g_memory, result_item, t_int);
}

memory_address g_int_attrs_subtract(const memory_address a, const memory_address b) {
  memory_item *result_item = malloc(sizeof(memory_item));
  result_item->integer = memoryGetRootItem(g_memory, a)->integer -
    memoryGetRootItem(g_memory, b)->integer;
  return memoryInsert(g_memory, result_item, t_int);
}

memory_address g_int_attrs_multiply(const memory_address a, const memory_address b) {
   memory_item *result_item = malloc(sizeof(memory_item));
  result_item->integer = memoryGetRootItem(g_memory, a)->integer *
    memoryGetRootItem(g_memory, b)->integer;
  return memoryInsert(g_memory, result_item, t_int);
}

memory_address g_int_attrs_divide(const memory_address a, const memory_address b) {
  memory_item *result_item = malloc(sizeof(memory_item));
  result_item->integer = memoryGetRootItem(g_memory, a)->integer /
    memoryGetRootItem(g_memory, b)->integer;
  return memoryInsert(g_memory, result_item, t_int);
}
