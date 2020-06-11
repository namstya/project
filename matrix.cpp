#include "matrix.h"
#include <QDebug>
#include <QTime>

std::matrix::matrix()
{

}

// Генерация рандомного числа
int std::matrix::randInt(int low, int high) {
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    return qrand() % ((high + 1) - low) + low;
}

// Проверка уникальности в столбце
bool std::matrix::UnicCol(int j, int num) {
    for (int x = 0; x < 9; x++) {
        if (grid[x][j] == num)
            return true;
    }
    return false;
}

// Проверка уникальности в строке
bool std::matrix::UnicRow(int i, int num) {
    for(int y = 0; y < 9; y++) {
        if (grid[i][y] == num)
            return true;
    }
    return false;
}

// Проверка уникальности в блоке 3х3
bool std::matrix::UnicSq(int i, int j, int num) {
    int x = (i/3)*3;
    int y =  (j/3)*3;
    for (int xx = x; xx < x + 3; xx++) {
        for (int yy = y; yy < y + 3; yy++) {
            if (grid[xx][yy] == num)
                return true;
        }
    }
    return false;
}

// Считывание
int std::matrix::read(int i, int j) {
    return grid[i][j];
}

// Запись числа в массив
void std::matrix::add(int i, int j, int n) {
    grid[i][j] = n;
}

// Очистка массива
void std::matrix::clean() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = 0;
        }
    }
}

// Удаление элементов массива
void std::matrix::remove() {
    for (int k = 0; k < 31; ++k) {
        int i = rand()%9;
        int j = rand()%9;
        grid[i][j] = 0;
    }
}

// Генерация массива
void std::matrix::gen() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // Проверка на переполнение циферок
            count = 9;
            for (int dig = 1; dig < 10; dig++) {
                if (UnicRow (i, dig) || UnicCol(j, dig) || UnicSq(i, j, dig)) {
                    count--;
                }
            }
            if (count == 0) {
                clean();
                gen();
                return;
            }
            num = randInt(1,9);
            while (UnicCol(j, num) || UnicRow(i, num) || UnicSq(i, j, num))
                num = randInt(1, 9);
            grid[i][j] = num;
            check[i][j] = num;
            qDebug() << num;
        }
    }
}

// Проверка на победу
bool std::matrix::win() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] != check[i][j])
                return false;
        }
    }
    return true;
}

// Генерация новой игры
void std::matrix::new_game() {
   clean();
   gen();
   remove();
}
