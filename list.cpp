int count()
{
    int res = 0;
    Node* temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        res++;
    }
    return res;
}