import unittest
from ctypes import *

file = open("./Array/libs/libarray.so", "rb")
print(file)

class InitailTest(unittest.TestCase):
    def test_init(self):
        self.assertEqual(1, 1)