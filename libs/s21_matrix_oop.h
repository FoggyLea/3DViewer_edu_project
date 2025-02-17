/**
 * @file matrix_oop.h
 * @brief Заголовочный файл для класса Matrix
 *
 * Этот файл содержит объявление класса Matrix, который реализует
 * основные операции с матрицами, включая создание, преобразование и
 * матричные вычисления. Класс предоставляет удобный API для работы
 * с матрицами, включая стандартные арифметические операции, трансформации
 * и вычисления определителей и обратных матриц.
 */

#ifndef MATRIX_OOP_H
#define MATRIX_OOP_H

#include <cmath>
#include <iostream>

namespace s21 {

/**
 * @class Matrix
 * @brief Класс для представления матрицы
 *
 * Этот класс реализует основные операции с матрицами,
 * включая создание, преобразование и матричные вычисления.
 * Класс предоставляет удобный интерфейс для работы с матрицами,
 * позволяя выполнять различные операции, такие как сложение, вычитание,
 * умножение и другие матричные вычисления.
 */
class Matrix {
 protected:
  int rows_;         ///< Количество строк матрицы
  int cols_;         ///< Количество столбцов матрицы
  double **matrix_;  ///< Указатель на двумерный массив элементов матрицы

 public:
  /**
   * @brief Конструктор по умолчанию
   *
   * Создает объект Matrix с размером 1x1.
   */
  Matrix();

  /**
   * @brief Конструктор с заданными размерами
   * @param rows Количество строк матрицы
   * @param cols Количество столбцов матрицы
   * @throws std::invalid_argument Если количество строк или столбцов <= 0
   */
  Matrix(int rows, int cols);

  /**
   * @brief Конструктор копирования
   * @param other Ссылка на объект для копирования
   */
  Matrix(const Matrix &other);

  /**
   * @brief Конструктор перемещения
   * @param other Объект для перемещения
   */
  Matrix(Matrix &&other);

  /**
   * @brief Деструктор
   *
   * Освобождает память, выделенную под внутреннюю структуру матрицы.
   */
  ~Matrix();
  /**
   * @brief Устанавливает количество строк матрицы
   * @param rows Новое количество строк
   * @throws std::invalid_argument Если количество строк <= 0
   */
  void SetRows(int rows);
  /**
   * @brief Устанавливает количество столбцов матрицы
   * @param cols Новое количество столбцов
   * @throws std::invalid_argument Если количество столбцов <= 0
   */
  void SetCols(int cols);
  /**
   * @brief Получает количество строк матрицы
   * @return Количество строк матрицы
   */
  int GetRows() const;

  /**
   * @brief Получает количество столбцов матрицы
   * @return Количество столбцов матрицы
   */
  int GetCols() const;

  // Операторы
  /**
   * @brief Перегрузка оператора присваивания
   * @param other Ссылка на объект для присваивания
   * @return Ссылка на текущий объект после присваивания
   */
  Matrix &operator=(const Matrix &other);

  /**
   * @brief Перегрузка оператора сравнения на равенство
   * @param other Ссылка на объект для сравнения
   * @return true, если матрицы равны, иначе false
   */
  bool operator==(const Matrix &other);
  // Методы для матричных операций
  /**
   * @brief Выполняет сложение двух матриц
   * @param other Ссылка на вторую матрицу для сложения
   * @return Новый объект Matrix с результатом сложения
   */
  Matrix operator+(const Matrix &other);

  /**
   * @brief Выполняет вычитание двух матриц
   * @param other Ссылка на вторую матрицу для вычитания
   * @return Новый объект Matrix с результатом вычитания
   */
  Matrix operator-(const Matrix &other);

  /**
   * @brief Выполняет умножение двух матриц
   * @param other Ссылка на вторую матрицу для умножения
   * @return Новый объект Matrix с результатом умножения
   */
  Matrix operator*(const Matrix &other);

  /**
   * @brief Выполняет умножение матрицы на число
   * @param number Число для умножения
   * @return Новый объект Matrix с результатом умножения
   */
  Matrix operator*(double number) const;

  /**
   * @brief Перегружает оператор присваивания сложения
   * @param other Ссылка на объект для сложения
   * @return Ссылка на текущий объект после сложения
   */
  Matrix &operator+=(const Matrix &other);

  /**
   * @brief Перегружает оператор присваивания вычитания
   * @param other Ссылка на объект для вычитания
   * @return Ссылка на текущий объект после вычитания
   */
  Matrix &operator-=(const Matrix &other);

  /**
   * @brief Перегружает оператор присваивания умножения
   * @param other Ссылка на объект для умножения
   * @return Ссылка на текущий объект после умножения
   */
  Matrix &operator*=(const Matrix &other);

  /**
   * @brief Перегружает оператор присваивания умножения на число
   * @param number Число для умножения
   * @return Ссылка на текущий объект после умножения
   */
  Matrix &operator*=(const double number);

  /**
   * @brief Получает элемент матрицы по указанным индексам
   * @param i Индекс строки
   * @param j Индекс столбца
   * @return Ссылка на элемент матрицы
   */
  double &operator()(int i, int j) const;
  /**
   * @brief Суммирует две матрицы
   * @param other Ссылка на вторую матрицу для суммирования
   */
  void SumMatrix(const Matrix &other);

  /**
   * @brief Вычитает одну матрицу из другой
   * @param other Ссылка на вторую матрицу для вычитания
   */
  void SubMatrix(const Matrix &other);

  /**
   * @brief Умножает две матрицы
   * @param other Ссылка на вторую матрицу для умножения
   */
  void MulMatrix(const Matrix &other);

  /**
   * @brief Умножает матрицу на число
   * @param number Число для умножения
   */
  void MulNumber(const double number);
  /**
   * @brief Проверяет, равны ли две матрицы
   * @param other Ссылка на вторую матрицу для сравнения
   * @return true, если матрицы равны, false в противном случае
   */
  bool EqMatrix(const Matrix &other);
  // Методы для вычислений
  /**
   * @brief Вычисляет транспонированную матрицу
   * @return Новый объект Matrix с транспортированной матрицей
   */
  Matrix Transpose();
  /**
   * @brief Вычисляет матрицу обратных миноров
   * @return Новый объект Matrix с матрицей обратных миноров
   */
  Matrix CalcComplements();

  /**
   * @brief Вычисляет определитель матрицы
   * @return Значение определителя матрицы
   * @throws std::range_error Если матрица не квадратная или имеет нулевой
   * определитель
   */
  double Determinant();

  /**
   * @brief Вычисляет обратную матрицу
   * @return Новый объект Matrix с обратной матрицей
   * @throws std::invalid_argument Если определитель матрицы равен нулю
   */
  Matrix InverseMatrix();
  /**
   * @brief Создает матрицу минора
   * @param row_i Индекс строки для создания минора
   * @param column_j Индекс столбца для создания минора
   * @return Новый объект Matrix с матрицей минора
   */
  Matrix CreateMinor(const int row_i, const int column_j);
  /**
   * @brief Реализует этап raw-rearrangement
   * @param k Индекс строки для перестановки
   * @param sign Указатель на переменную для хранения знака перестановки
   *
   * Метод выполняет raw-rearrangement, который является частью
   * Он находит строку с максимальным
   * значением в столбце k и меняет местами эту строку с текущей
   * строкой k, если они различаются. Также обновляется знак
   * перестановки в sign.
   *
   * Эта операция помогает уменьшить вероятность появления
   * плавающей точки в процессе вычислений.
   */
  void RawRearrange(int k, double *sign);
};
}  // namespace s21
#endif
