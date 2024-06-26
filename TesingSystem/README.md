# Документация программной системы

## Введение

Эта программная система представляет собой систему тестирования знаний, включающую в себя различные классы для представления таких сущностей как тесты, студенты, преподаватель, оценки, обратная связь;
и операций: операция проведения тестирования, операция выставления оценок, операция анализа результатов, операция обратной связи, операция администрирования системы тестирования.

## Классы и методы

### Класс Teacher

Класс для представление преподавателя в системе.

#### Методы

- `def test_student(self, student, test)`: Операция проведения тестирования и выставления оценки студенту.
- `def add_test(self, tests, new_test)`: Операция добавления теста.
- `def remove_test(self, tests, test_name)`: Возвращает удаления теста.
- `def analyze_results(self, students, tests)`: Операция анализа результатов теста.

### Класс Student

Класс для представления студентов.

#### Методы

- `def __init__(self, name)`: Инициализация объекта класса Student.
- `def take_test(self, test)`: Операция выполнения теста.
- `def get_name(self)`: Операция получения имени студента.
- `def add_feedback(self, feedback)`: Добавление фидбека.
- ` def create_feedback(self)`: Создание фидбека.
- `def get_feedbacks(self)`: Получение списка фидбеков у студентов
- `def get_info(self)`: Получение всей информации о студенте.
- `def get_marks(self, test_name)`: Получение всех оценок студента.
- `def add_grade(self, test_name, grade)`: Добавление оценки студенту.

### Класс Marks

Класс для представления оценок.

#### Методы

- `def __init__(self)`: Инициализация объекта класса Marks.
- `def add_grade(self, grade)`: Добавляет оценку.
- `def get_grades(self)`: Получение списка оценок.


### Класс Feedback

Класс для представления обратной связи.

#### Методы

- `def __init__(self, message)`: Инициализация объекта класса Feedback.
- `def get_message(self)`: Получение конкретного фидбека.

### Класс Test

Класс для представления тестов.

#### Методы

- `def __init__(self, name, questions, correct_answers)`: Инициализация объекта класса Test.
- `def get_name(self)`: Получение названия теста.
- `def get_questions(self)`: Получение вопросов к тесту.
- `def get_answers(self)`: Получение ответов на тест.

### Класс TestException

Класс для обработки исключительных ситуаций.

#### Методы

- `def __init__(self, message)`: Инициализация объекта класса TestException.
- `def handle_exception(self)`: Обработка исключения.
