#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
        {
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;
        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                while (slow != entry)
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }

        return NULL;
    }
};