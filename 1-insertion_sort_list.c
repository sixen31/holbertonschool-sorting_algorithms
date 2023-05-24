#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;
	while (current != NULL)
	{
		listint_t *temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			// Étape 1: Déconnexion du nœud temp du reste de la liste
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;

			// Étape 2: Insertion du nœud temp à la bonne position
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			// Étape 3: Mise à jour des liens avec les nœuds adjacents
			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;

			// Affichage de la liste après chaque swap
			print_list(*list);
		}
		current = current->next;
	}
}
