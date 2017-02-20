// delete node in a linked list

void deleteNode(ListNode *node)
{
    *node = *(node->next);
}