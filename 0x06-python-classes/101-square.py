#!/usr/bin/python3
"""Module containing the Square class"""

class Square:
    def __init__(self, size=0, position=(0, 0)):
     
        self.size = size
        self.position = position

    def __str__(self):

        __my_string = ""
        if self.__size is not 0:
            for h in range(self.__position[1]):
                __my_string += '\n'
            for j in range(self.__size):
                for y in range(self.__position[0]):
                    __my_string += ' '
                for k in range(self.__size):
                    __my_string += '#'
                if j is not self.__size - 1:
                    __my_string += '\n'
        return __my_string

    @property
    def size(self):
        return self.__size

    @size.setter
    def size(self, size):
        if not isinstance(size, int):
            raise TypeError("size must be an integer")
        if size < 0:
            raise ValueError("size must be >= 0")

        self.__size = size

    @property
    def position(self):

        return self.__position

    @position.setter
    def position(self, position):
        if (not isinstance(position, tuple) or len(position) is not 2 or
            not isinstance(position[0], int) or
                not isinstance(position[1], int) or position[0] < 0 or
                position[1] < 0):
            raise TypeError("position must be a tuple of 2 positive integers")

        self.__position = position

    def area(self):
        return self.__size ** 2

    def my_print(self):

        if self.__size is not 0:
            for h in range(self.__position[1]):
                print()
            for j in range(self.__size):
                for y in range(self.__position[0]):
                    print(" ", end="")
                for k in range(self.__size):
                    print("#", end="")
                print()
        else:
            print()
