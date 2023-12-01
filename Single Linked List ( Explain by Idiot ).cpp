#include <iostream>

#pragma region Customizations
// Text Coloring
#define RED_TEXT "\033[1;31m" << "[ Debug ] "
#define GREEN_TEXT "\033[1;32m" << "[ Debug ] "
#define RESET_TEXT "\033[0m"

//Clear Console
#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif


#pragma endregion


struct Node {
    int data;
    Node* next;
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }


    void AddStartValue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        std::cout << GREEN_TEXT << "Inserted at the beginning : " << value << RESET_TEXT << std::endl;
    }


    void AddEndValue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        std::cout << GREEN_TEXT << "Inserted at the end : " << value << RESET_TEXT << std::endl;
    }


    void AddMiddleValue(int value) {
        if (!head) {
            AddStartValue(value);
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        newNode->next = slow->next;
        slow->next = newNode;
        std::cout << GREEN_TEXT << "Inserted at the middle : " << value << RESET_TEXT << std::endl;
    }


    void DeleteStartValue() {
        if (!head) {
            std::cout << RED_TEXT << "List is empty. Nothing to delete." << RESET_TEXT << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        std::cout << GREEN_TEXT << "Successfully Deleted from the beginning. " << RESET_TEXT << std::endl;
    }


    void DeleteEndValue() {
        if (!head) {
            std::cout << RED_TEXT << "List is empty. Nothing to delete." << RESET_TEXT << std::endl;
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            std::cout << GREEN_TEXT << "Successfully Deleted from the end. " << RESET_TEXT << std::endl;
            return;
        }

        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
        std::cout << GREEN_TEXT << "Successfully Deleted from the end. " << RESET_TEXT << std::endl;
    }

    void DeleteMidValue() {
        if (!head) {
            std::cout << RED_TEXT << "List is empty. Nothing to delete." << RESET_TEXT << std::endl;
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            std::cout << GREEN_TEXT << "Successfully Deleted from the middle. " << RESET_TEXT << std::endl;
            return;
        }

        Node* slow = head;
        Node* fast = head->next;
        Node* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) {
            prev->next = slow->next;
        }
        else {
            head = head->next;
        }

        delete slow;
        std::cout << GREEN_TEXT << "Successfully Deleted from the middle. " << RESET_TEXT << std::endl;
    }


    void DisplayNodes() {
        std::cout << "\n=======================================================\n";
        Node* temp = head;
        std::cout << GREEN_TEXT << "Linked List: ";
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << RESET_TEXT << std::endl;
        std::cout << "=======================================================\n";
        system("pause");
    }
};

LinkedList linkedList;
int64_t value;

void DeleteNode()
{
    int user_choice;
    system(CLEAR_SCREEN);
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "                  Delete Node                      " << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "[ 1. ] Delete at Start" << std::endl;
    std::cout << "[ 2. ] Delete at Middle " << std::endl;
    std::cout << "[ 3. ] Delete at End " << std::endl;
    std::cout << "Enter your choice :";
    std::cin >> user_choice;
    switch (user_choice) {
    case 1:
        linkedList.DeleteStartValue();
        std::cout << std::endl << std::endl;
        break;
    case 2:
        linkedList.DeleteMidValue();
        std::cout << std::endl << std::endl;
        break;
    case 3:
        linkedList.DeleteEndValue();
        std::cout << std::endl << std::endl;
        break;
    default:
        std::cout << RED_TEXT << "Invalid choice!" << RESET_TEXT << std::endl;
        std::cout << std::endl << std::endl;
    }
}
void InsertNode()
{
    int choice;
    system(CLEAR_SCREEN);
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "                  Insert Node                      " << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "1. Insert at Start\n2. Insert at Mid\n3. Insert at End\nEnter insert choice: ";
    std::cin >> choice;
    std::cout << "Enter value to insert: ";
    std::cin >> value;
    switch (choice) {
    case 1:
        linkedList.AddStartValue(value);
        break;
    case 2:
        linkedList.AddMiddleValue(value);
        break;
    case 3:
        linkedList.AddEndValue(value);
        break;
    default:
        std::cout << "Invalid choice!" << std::endl;
    }
}
int main() {

    int64_t user_choice;

    do {
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "            SLL - Sorted (Ascending)               " << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "[ 1. ] Insert Node " << std::endl;
        std::cout << "[ 2. ] Delete Node " << std::endl;
        std::cout << "[ 3. ] Display Node " << std::endl;
        std::cout << "[ 4. ] Exit " << std::endl;
        std::cout << "Enter your choice :";
        std::cin >> user_choice;
        switch (user_choice) {
        case 1:
            InsertNode();
            std::cout << std::endl << std::endl;
            break;
        case 2:
            DeleteNode();
            break;
        case 3:
            linkedList.DisplayNodes();
            std::cout << std::endl << std::endl;
            break;
        case 4:
            std::cout << "Exiting program. Bye!" << std::endl;
            std::cout << std::endl << std::endl;
            break;
        default:
            std::cout << RED_TEXT << "Invalid choice! Please enter a valid choice." << RESET_TEXT;
            std::cout << std::endl << std::endl;
        }
    } while (user_choice != 4);
    return 0;
}
