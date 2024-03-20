namespace {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void deleteNodes(ListNode* start, ListNode* end) {
    while (start != end) {
        auto to_delete{ start };
        start = start->next;
        delete to_delete;
    }
    delete end;
}

}

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto front{ list1 };
        auto back{ list1 };
        auto result{ list1 };
        while (b >= 0) {
            if (1 == a) {
                front = list1;
            }
            if (0 == b) {
                back = list1;
            }
            list1 = list1->next;
            --a;
            --b;
        }

        auto toDelete{ back };
        back = back->next;
        deleteNodes(front->next, toDelete);

        front->next = list2;
        while (list2->next) {
            list2 = list2->next;
        }
        
        list2->next = back;
        return result;
    }
};