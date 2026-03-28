# NAVSTACK: Browser History Management System

**NAVSTACK** is a C++ based simulation of a web browser's navigation engine. It utilizes a custom **Stack** data structure (implemented via Singly Linked Lists) to manage the complex logic of moving backward and forward through web history.

Unlike a simple simulation, NAVSTACK integrates with your operating system to actually open the URLs in your default web browser.

---

## 🛠️ Data Structures & Logic

The project demonstrates the practical application of **Linear Data Structures** and **Hash Maps**:

* **Custom Stack Class:** Built using a **Singly Linked List**. Each `Node` stores the URL and a pointer to the next page in the stack. 
    * *Efficiency:* Push, Pop, and Peek operations all run in **O(1)** time.
* **Dual-Stack Architecture:** * `backStack`: Stores the history of pages visited.
    * `forwardStack`: Stores pages moved away from via the "back" command.
* **Unordered Map:** Acts as a persistent history log, mapping unique URLs to user-provided descriptions for instant retrieval.

## 🚀 Key Features

* **Live Browser Integration:** Uses system-level commands (`start`, `open`, or `xdg-open`) to launch URLs in Chrome, Firefox, Safari, etc.
* **Smart Protocol Injection:** Automatically detects if a URL is missing a protocol and prepends `https://` for valid browsing.
* **Navigation Sync:** Visiting a new page automatically clears the `forwardStack`, mimicking real browser behavior.
* **Cross-Platform Compatibility:** Optimized for Windows, macOS, and Linux.

---

## 💻 Command Reference

| Command | Action | Logic |
| :--- | :--- | :--- |
| `visit` | Go to a new URL | Push current to `backStack`, clear `forwardStack` |
| `back` | Go to previous page | Pop from `backStack`, push current to `forwardStack` |
| `forward` | Revisit a page | Pop from `forwardStack`, push current to `backStack` |
| `history` | View session log | Display all URL-Description pairs from the Map |
| `exit` | Quit | Close the application |

---

## 🔧 Installation & Usage

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/AairaHemal/NAVSTACK-Browser-History-Management.git](https://github.com/AairaHemal/NAVSTACK-Browser-History-Management.git)
    cd NAVSTACK-Browser-History-Management
    ```

2.  **Compile the source code:**
    ```bash
    g++ main.cpp -o navstack
    ```

3.  **Run the application:**
    ```bash
    ./navstack
    ```

## 📝 Example Session

```text
Enter Homepage: google.com

[visit, back, forward, history, exit]
> visit
URL: github.com
Description: Development_Platform

[visit, back, forward, history, exit]
> back
Now at: google.com
