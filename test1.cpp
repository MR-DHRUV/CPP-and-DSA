// it will merge the list on the basis of bottom pointers
struct Node *mergeList(struct Node *A, struct Node *B)
{
    // base case
    if (A == NULL && B == NULL)
    {
        return A;
    }
    else if (A == NULL)
    {
        return B;
    }
    else if (B == NULL)
    {
        return A;
    }

    // points to first element of new mergerd list
    struct Node *third;

    // it will point at last of merged list at every iteration , and will be used for linking further nodes in the list
    struct Node *last;

    // A

    if (A->data > B->data)
    {
        // list starts from 1st element of B in this case
        third = B;
        last = B;
        B = B->bottom;
        last->bottom = NULL;
    }
    else
    {
        third = A;
        last = A;
        A = A->bottom;
        last->bottom = NULL;
    }

    while (A != NULL && B != NULL)
    {
        if (A->data > B->data)
        {
            // pervious block ka bottom ko new block par le aao , then last ko uss block pr le aao
            last->bottom = B;
            // last ab b par aajana chahiye na , tabhi list aage badhegi
            last = B;
            B = B->bottom;
            last->bottom = NULL;
        }
        else
        {
            last->bottom = A;
            last = A;
            A = A->bottom;
            last->bottom = NULL;
        }
    }

    if (A != NULL)
    {
        last->bottom = A;
    }
    if (B != NULL)
    {
        last->bottom = B;
    }

    return third;
}
