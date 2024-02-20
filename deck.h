#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - card kind
 * @Spade: spade kind
 * @Heart: heart kind
 * @Club: club kind
 * @Diamond: diamond kind
 */
typedef enum kind_e
{
	Spade = 0,
	Heart,
	Club,
	Diamond,
} kind_t;

/**
 * stuct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif
