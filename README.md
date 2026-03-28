# Nav stack Browser History Engine (C++)

A lightweight C++ simulation of a web browser's navigation system. This project demonstrates the practical application of **Stacks** and **Doubly Linked Lists** to manage URL history and forward-navigation states.



## 🚀 Features

- **Real Browser Integration:** Automatically opens URLs in your system's default web browser using native OS commands.
- **Dual-Stack Navigation:** Uses a `backStack` and `forwardStack` to provide seamless "Back" and "Forward" functionality.
- **Metadata Storage:** Stores a description/content snippet for each visited site using a Hash Map (`unordered_map`).
- **Cross-Platform:** Works on Windows (`start`), macOS (`open`), and Linux (`xdg-open`).

## 🛠️ Data Structures Used

1.  **Doubly Linked List:** Used to build the custom Stack class, allowing for efficient memory allocation of history nodes.
2.  **Stack (LIFO):** * `backStack`: Stores the history of pages you can return to.
    * `forwardStack`: Stores pages you've gone back from, which are cleared upon a new `visit`.
3.  **Hash Map:** Maps URLs to their descriptions for $O(1)$ average time complexity retrieval during history lookups.

## 💻 How It Works

| Command | Action |
| :--- | :--- |
| `visit` | Navigates to a new URL, pushes the current page to the `backStack`, and clears the `forwardStack`. |
| `back` | Pops the top of the `backStack` and moves the current page to the `forwardStack`. |
| `forward` | Pops the top of the `forwardStack` and moves the current page to the `backStack`. |
| `history` | Displays all unique URLs visited during the session and their descriptions. |

## ⚙️ Installation & Usage

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/yourusername/browser-history-engine.git](https://github.com/yourusername/browser-history-engine.git)
   cd browser-history-engine
