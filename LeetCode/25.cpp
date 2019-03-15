/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rh;
    ListNode* last = NULL;
    ListNode* rev(ListNode* head, int k) {
        if (!k) {
            if (last) {
                last->next = head;
            } else {
                rh = head;
            }
            return head;
        }
        ListNode* n = rev(head->next, k - 1);
        n->next = head;
        return head;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        rh = head;
        
        while (true) {
            bool ok = true;
            ListNode *curh = head;
            for (int i = 1; i < k && ok; i++) {
                if (curh == NULL) {
                    ok = false;
                    break;
                }
                if (curh->next == NULL) {
                    ok = false;
                    break;
                } else {
                    curh = curh->next;
                }
            }
            if (!ok) break;
            ListNode *nhead = (!(curh->next)) ? NULL : curh->next;
            head = rev(head, k - 1);
            last = head;
            head->next = nhead;
            if (!nhead) break;
            head = nhead;
        }
        return rh;
    }
};
