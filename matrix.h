#ifndef MATRIX_H
#define MATRIX_H

namespace std {
    class matrix {
        public:
            void add(int i, int j, int n);
            void new_game();
            int randInt(int low, int high);
            void gen();
            void remove();
            int read(int i, int j);
            void clean();
            bool win();
            matrix();

        private:
            int num;
            int count;
            int check[9][9];
            int grid[9][9];
            bool UnicCol(int b, int num);
            bool UnicRow(int a, int num);
            bool UnicSq(int a, int b, int num);
    };
}
#endif // MATRIX_H
