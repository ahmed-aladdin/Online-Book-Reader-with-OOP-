# Online Book Reader

An object-oriented programming (OOP) project designed to implement an online book reading system. 
The system interacts with users through console-based input/output operations, allowing users to view profiles, read books, and perform other relevant actions. 

## Features

- **User Authentication:**
   - Users can sign up with a unique username and password.
   - Admins can only be added manualy.
   - Existing users or admins can log in to the system.
   
- **Saving sessions**
   - When user starts a new session, after finishing reading some details is saved
      - Book.
      - Page number.
      - Finishing time.
- **Reading a book**
   - User can choose a book from books list.
   - User can choose a book from his recent opened sessions.
- **Data Persistence:**
   - User, user sessions and book data are saved to files for persistence among program executions.

## OOP Concepts

- **Encapsulation**
- **Abstraction**

## classes
- User
- UserManager
- UserView
- AdminView
- Book
- BookManager
- BookSession

## Hints
- To enter **admin view** you can longin using [username=admin,password=123].
- You can only use **spaces** between words only when entering page content for a book.
- To enter **user view** you can easily signup new user.
