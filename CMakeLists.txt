cmake_minimum_required(VERSION 3.14)
project(Uno)

set(CMAKE_CXX_STANDARD 11)

add_executable(Uno main.cpp Game.cpp Game.h CommandLineArgument.cpp CommandLineArgument.h Player.cpp Player.h Rules.cpp Rules.h Card.cpp Card.h Move.cpp Move.h File.cpp File.h Deck.cpp Deck.h Random.cpp Random.h Display.h Display.cpp InputVal.cpp InputVal.h DiscardPile.cpp DiscardPile.h Utility.cpp Utility.h)
target_compile_options(Uno PRIVATE -Wall -Wextra -Werror -Wno-unused-parameter)#-Wno-unused-parameter