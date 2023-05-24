#include "sort.h"

/**
 * insertion_sort_list - Trie une liste doublement chaînée par insertion
 * @list: Un double pointeur vers le début de la liste
 *
 * Description: Trie une liste doublement chaînée en utilisant l'algorithme de
 * tri par insertion. La liste est triée par ordre croissant.
 */
void insertion_sort_list(listint_t **list)
{
        listint_t *current = (*list)->next;
        listint_t *temp = NULL;

        if (list == NULL || *list == NULL || (*list)->next == NULL)
                return;


        while (current != NULL)
        {
                temp = current;
                while (temp->prev != NULL && temp->n < temp->prev->n)
                {
                        if (temp->next != NULL)
                                temp->next->prev = temp->prev;
                        temp->prev->next = temp->next;

                        temp->next = temp->prev;
                        temp->prev = temp->prev->prev;
                        temp->next->prev = temp;

                        if (temp->prev == NULL)
                                *list = temp;
                        else
                                temp->prev->next = temp;

                        print_list(*list);
                }
                if (current->next != NULL)  // Ajout de cette condition
                        current = current->next;
       		else
			break;
       	}
}
