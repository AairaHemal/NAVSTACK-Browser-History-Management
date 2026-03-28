#include <bits/stdc++.h>
using namespace std;
// Defining of  Linked list nodes 
class Node
{
public:
    string url;
    Node *next;
    Node *prev;
    Node(string url1)
    {
        url = url1;
        next = nullptr;
        prev = nullptr;
    }
    Node(string url1, Node *next1)
    {
        url = url1;
        next = next1;
        prev = nullptr;
    }
};
// Implementation of basic stack features using linked list nodes
class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }
    void push(string url)
    {
        Node *newNode = new Node(url);
        if (top == nullptr)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top->prev = newNode;
            top = newNode;
        }
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "No history to go back to." << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        if (top != nullptr)
        {
            top->prev = nullptr;
        }
        delete temp;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    string peek()
    {
        if (top == nullptr)
        {
            return "";
        }
        return top->url;
    }
    void clear()
    {
        while (!isEmpty())
            pop();
    }
};
// Browser Engine 
class BrowserHistory
{
private:
    Stack backStack; //For the operations of backward using stack
    Stack forwardStack; //For the operations of forward using stack
    string currentUrl;

public:
    unordered_map<string, string> history;

    BrowserHistory(string homepage)
    {
        currentUrl = homepage;
        history[homepage] = "Homepage";
    }

    void visit(string url, string pagecontent)
    {

        history[url] = pagecontent;
        backStack.push(currentUrl);
        currentUrl = url;
        forwardStack.clear();
        openInBrowser(url);
    }
    void openInBrowser(string url)
    {
        if (url.find("http") == string::npos)
        {
            url = "https://" + url;
        }

        string command;
         #ifdef _WIN32
        // Wrap in quotes so & in URLs doesn't break the command
        command = "start \"\" \"" + url + "\"";
        #elif __APPLE__
        command = "open \"" + url + "\"";
         #else
        command = "xdg-open \"" + url + "\"";
        #endif

        system(command.c_str());
    }
    string backward()
    {
        if (backStack.isEmpty())
        {
            cout << "No history to go back to." << endl;
            return currentUrl;
        }
        forwardStack.push(currentUrl);
        currentUrl = backStack.peek();
        backStack.pop();
        openInBrowser(currentUrl);
        return currentUrl;
    }
    string forward()
    {
        if (forwardStack.isEmpty())
        {
            cout << "No history to go forward to." << endl;
            return currentUrl;
        }
        backStack.push(currentUrl);
        currentUrl = forwardStack.peek();
        forwardStack.pop();
        openInBrowser(currentUrl);
        return currentUrl;
    }
    void exitpage()
    {
        currentUrl = "";
        openInBrowser(currentUrl);
    }
    void printhistory()
    {
        unordered_map<string, string>::iterator it;
        cout << "Browser History: " << endl;
        for (it = history.begin(); it != history.end(); it++)
        {
            cout << it->first << "-----" << it->second << endl;
        }
    }
};
//Main function with all commands
int main()
{
    string home;
    cout << "Enter Homepage: ";
    cin >> home;

    BrowserHistory browser(home);
    string command;

    while (true)
    {
        cout << "\n[visit, back, forward, history, exit]\n> ";
        cin >> command;

        if (command == "visit")
        {
            string url, content;
            cout << "URL: ";
            cin >> url;
            cout << "Description: ";
            cin >> content;
            browser.visit(url, content);
        }
        else if (command == "back")
        {

            cout << "Now at: " << browser.backward() << endl;
        }
        else if (command == "forward")
        {
            cout << "Now at: " << browser.forward() << endl;
        }
        else if (command == "history")
        {
            browser.printhistory();
        }
        else if (command == "exit")
        {
            break;
        }
    }
    return 0;
}
