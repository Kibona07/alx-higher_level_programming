#include "lists.h"
#include <stdlib.h>

/**
 *check_cycle-checks the presence of cycle
 *@list: pointer to listint_t
 *Return: int
 */

int check_cycle(listint_t *list)
{
listint_t *jmp, *node;

if (!list || !list->next)
return (0);

node = list;
jmp = list->next;

while (jmp && jmp->next && node && node->next)
{
if (jmp == node)
return (1);
jmp = jmp->next->next;
if (!jmp)

break;
node = node->next;
}
return (0);
}
