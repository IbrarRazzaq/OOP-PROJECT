# 🎮 Mini Game Console — OOP Project (C++)

A console-based mini game application built in **C++** using **Object-Oriented Programming (OOP)** concepts such as inheritance, polymorphism, and abstract base classes.

---

## 📁 Project Structure

```
project/
│
├── main.cpp        # Main source file containing all classes and game logic
└── README.md       # Project documentation (this file)
```

---

## ⚙️ How to Compile & Run

### Compile
```bash
g++ main.cpp -o game
```

### Run
```bash
./game        # Linux / macOS
game.exe      # Windows
```

---

## 🕹️ How to Play

### Step 1 — Game Menu

When you run the program, you will see the **main game menu**:

```
========== GAME MENU ==========
1. Number Ninja
2. Guess Number

Enter Choice:
```

Type `1` and press **Enter** to play **Number Ninja**, or type `2` and press **Enter** to play **Guess Number**.

---

### 🥷 Game 1 — Number Ninja

> A math quiz game with levels and a 10-second timer per question.

#### How It Works:

1. The game starts at **Level 1**.
2. Each level has **3 math questions**.
3. Questions use **random operations**: `+`, `-`, `*`, `/`.
4. You have **10 seconds** to answer each question.
   - At **5 seconds**, a warning beep sounds: `⚠ 5 sec warning!`
   - At **10 seconds**, time runs out: `⛔ Time up!`

#### Scoring:
| Result       | Points |
|--------------|--------|
| Correct Answer | +10  |
| Wrong / Time Up | -5  |

#### Level Progression:
- Answer **all 3 questions correctly** → 🎉 Level Completed! → Move to next level
- Answer **less than 3 correctly** → ❌ Level Failed!

#### Sample Gameplay:
```
--- Number Ninja ---

======================
LEVEL 1
======================

Q1: 7 + 3 = 10
Correct!

Q2: 5 * 4 = 18
Wrong! Answer = 20

Q3: 9 - 2 = 7
Correct!

❌ Level Failed!
Continue? (y/n): y
```

After each level, you are asked:
```
Continue? (y/n):
```
- Type `y` → Continue playing
- Type `n` → End the game and display your **Final Score**

---

### 🔢 Game 2 — Guess Number

> A simple number guessing game.

#### How It Works:

1. The computer picks a **random number between 1 and 10**.
2. You enter your guess.
3. The program tells you if you were **correct or wrong**.

#### Scoring:
| Result       | Points |
|--------------|--------|
| Correct Guess | +10  |
| Wrong Guess   | -5   |

#### Sample Gameplay:
```
--- Guess Number ---

Guess a number between 1 to 10: 7
❌ Wrong Guess!
Correct Number was: 3

Current Score: -5

Play Again? (y/n): y

Guess a number between 1 to 10: 5
🎉 Correct Guess!

Current Score: 5

Play Again? (y/n): n

Final Score: 5
```

After each round, you are asked:
```
Play Again? (y/n):
```
- Type `y` → Play another round
- Type `n` → End the game and display your **Final Score**

---

## 🧱 OOP Concepts Used

| Concept | Where Used |
|---|---|
| **Abstract Base Class** | `Game` class with pure virtual `play()` |
| **Inheritance** | `NumberNinja` and `GuessNumber` extend `Game` |
| **Polymorphism** | `game->play()` calls the correct game at runtime |
| **Encapsulation** | `score` is private inside each game class |
| **Dynamic Memory** | `Game* game = new NumberNinja()` / `delete game` |

---

## 🛠️ Requirements

- C++ compiler (g++ / MSVC / clang++)
- C++11 or later
- Terminal / Command Prompt

---

## 👨‍💻 Author

Developed as an **OOP Lab Project** in C++.
