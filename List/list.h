#pragma once

class List {
        public:
        virtual void addFirst(int num) = 0;
        virtual void addLast(int num) = 0;
        virtual int removeFirst() = 0;
        virtual int removeLast() = 0;

        virtual void addAt(int num, int pos) = 0;
        //virtual int removeNum(int num) = 0;
        //virtual int removePos(int pos) = 0;
        //virtual int removeAll(int num) = 0;
        virtual int get(int num) = 0;
        virtual int getMiddle() = 0;

        virtual int getSize() = 0;
        virtual void print() = 0;
        virtual void reset() = 0;
};