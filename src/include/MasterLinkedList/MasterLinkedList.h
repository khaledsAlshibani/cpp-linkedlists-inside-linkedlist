#pragma once
#include <iostream>
#include <string>
#include "../Node/Node.h"
#include "../LineLinkedList/LineLinkedList.h"
using namespace std;

class MasterLinkedList
{
    Node *HEAD;

    bool isNotLastNode(Node *node)
    {
        return (node != nullptr);
    }

    bool isNotLastNodeByNext(Node *node)
    {
        return (node->NEXT != nullptr);
    }

public:
    MasterLinkedList()
    {
        HEAD = nullptr;
    }

    bool isEmpty()
    {
        return (HEAD == nullptr);
    }

    void insertLine(string *words, int count)
    {
        Node *newNode = new Node;
        newNode->NEXT = nullptr;

        for (int i = 0; i < count; i++)
        {
            newNode->DATA += words[i];

            if (i != count - 1)
            {
                newNode->DATA += " ";
            }
        }

        if (isEmpty())
        {
            HEAD = newNode;
        }
        else
        {
            Node *TEMP_HEAD = HEAD;
            while (isNotLastNodeByNext(TEMP_HEAD))
            {
                TEMP_HEAD = TEMP_HEAD->NEXT;
            }
            TEMP_HEAD->NEXT = newNode;
        }
    }

    int getLinesCount()
    {
        if (isEmpty())
        {
            return 0;
        }

        int count = 0;

        Node *TEMP_HEAD = HEAD;
        while (isNotLastNode(TEMP_HEAD))
        {
            count++;
            TEMP_HEAD = TEMP_HEAD->NEXT;
        }
        
        return count;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nNo lines added yet to the linked list" << endl;
            return;
        }

        cout << "The inserted lines are:\n";

        Node *TEMP_HEAD = HEAD;
        while (isNotLastNode(TEMP_HEAD))
        {
            cout << TEMP_HEAD->DATA << endl;
            TEMP_HEAD = TEMP_HEAD->NEXT;
        }
        cout << endl;
    }

    void displayByLineIndex(int index)
    {
        int loopIndex = 0;
        bool isFound = false;

        if (isEmpty())
        {
            cout << "\nNo lines added yet to the linked list" << endl;
            return;
        }

        Node *TEMP_HEAD = HEAD;
        while (isNotLastNode(TEMP_HEAD))
        {
            loopIndex++;

            if (loopIndex == index)
            {
                cout << TEMP_HEAD->DATA;
                isFound = true;
            }

            TEMP_HEAD = TEMP_HEAD->NEXT;
        }

        if (!isFound)
        {
            cout << "\nThere is no line with index: " << index << endl;
        }

        cout << endl;
    }
};