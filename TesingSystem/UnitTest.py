from Marks import Marks
from Test import Test
from Student import Student
from Feedback import Feedback
from Teacher import Teacher
import unittest

class TestStudent(unittest.TestCase):
    def setUp(self):
        self.student = Student("John")
        self.test = Test("Math", ["What is 2+2?", "What is the square root of 16?"], ["4", "4"])

    def test_take_test(self):
        self.assertEqual(self.student.take_test(self.test), 10)

    def test_get_name(self):
        self.assertEqual(self.student.get_name(), "John")

    def test_get_marks(self):
        self.student.add_grade(self.test.get_name(), 10)
        self.assertEqual(self.student.get_marks(self.test.get_name()).get_grades(), [10])

class TestMarks(unittest.TestCase):
    def setUp(self):
        self.marks = Marks()

    def test_add_grade(self):
        self.marks.add_grade(5)
        self.assertEqual(self.marks.get_grades(), [5])

class TestTest(unittest.TestCase):
    def setUp(self):
        self.test = Test("Math", ["What is 2+2?", "What is the square root of 16?"], ["4", "4"])

    def test_get_name(self):
        self.assertEqual(self.test.get_name(), "Math")

    def test_get_questions(self):
        self.assertEqual(self.test.get_questions(), ["What is 2+2?", "What is the square root of 16?"])

    def test_get_answers(self):
        self.assertEqual(self.test.get_answers(), ["4", "4"])

class TestTeacher(unittest.TestCase):
    def setUp(self):
        self.student = Student("John")
        self.test = Test("Math", ["What is 2+2?", "What is the square root of 16?"], ["4", "4"])
        self.teacher = Teacher()

    def test_test_student(self):
        self.teacher.test_student(self.student, self.test)
        self.assertEqual(self.student.get_marks(self.test.get_name()).get_grades(), [10])


if __name__ == "__main__":
    unittest.main()
