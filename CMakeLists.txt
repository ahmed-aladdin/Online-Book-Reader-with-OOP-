cmake_minimum_required(VERSION 3.25)
project(Online_Book_Reader_with_OOP_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Online_Book_Reader_with_OOP_
        AdminView.cpp
        AdminView.h
        Book.cpp
        Book.h
        BookManager.cpp
        BookManager.h
        BookSession.cpp
        BookSession.h
        main.cpp
        OnlineBookSystem.cpp
        OnlineBookSystem.h
        User.cpp
        User.h
        UserManager.cpp
        UserManager.h
        UserView.cpp
        UserView.h)
