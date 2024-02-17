#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	if (head == NULL) {
		return 0;
	}
	int count = 0;
	node* curr = head;
	while (curr != NULL) {
		curr = curr->next;
		count++;
	}
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	if (head == NULL) {
		return;
	}
	int size = length(head);
	node* curr = head;
	char* combined = (char*)malloc((size + 1) * sizeof(char));
	int num = 0;

	while (curr != NULL) {
		combined[num] = curr->letter;
		num++;
		curr = curr->next;
	}
	combined[num] = '\0';

	return combined;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->letter = c;
	newNode->next = NULL;
	node* curr = *pHead;

	if (*pHead == NULL) {
		*pHead = newNode;
	}
	else {
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
	}


}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	if (pHead == NULL) {
		return;
	}
	node* curr = *pHead;
	node* temp = curr;

	while (curr->next != NULL) {
		curr = curr->next;
		free(temp);
		temp = curr;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt", "r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile, " %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}