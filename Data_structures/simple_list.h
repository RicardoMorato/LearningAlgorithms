#ifndef LIST_H_
#define LIST_H_

#include <bits/stdc++.h>

using namespace std;

namespace lists {
  template <class T> class List {
    private:
      class Cell {
        friend class List<T>;
        private:
          T *item;
          Cell *next;

          // Cell constructor
          Cell () {
            item = 0;
            next = 0;
          }

          // Cell deconstructor
          ~Cell () {
            if (item != 0) delete item;
          }
      };

      Cell *first, *last, *position;

    public:
      List () { // Creates an empty list
        this->first = new Cell();
        this->position = this->first;
        this->last = this->first;
        this->first->next = 0;
      }

      bool empty () const { // Returns if the list is empty
        return (this->first == this->last);
      }

      T *search(const T &key) const { // Searchs through the list looking for a given key
        if (this->empty()) return 0;

        Cell *aux = this->first;

        while (aux->next != 0){
          if (*(aux->next->item) == key) return aux->next->item;
          aux = aux->next;
        }

        return 0;
      }

      void push (T &value) { // Inserts a new Cell in the end of the list
        this->last->next = new Cell();
        this->last = this->last->next;
        this->last->item = new T(value);
        this->last->next = 0;
      }

      T *pop (const T &key)  { // Deletes a cell in the list
        if (this->empty()) return 0;

        Cell *aux = this->first;
        while (aux->next != 0 && *(aux->next->item) != key) aux = aux->next;
        if (aux->next == 0) return 0; // The key wasn't found on the list.

        Cell *cell_to_withdraw = aux->next;
        T *item = cell_to_withdraw->item;
        aux->prox = cell_to_withdraw->prox;
        cell_to_withdraw->item = 0;

        if (aux->next == 0) this->last = aux;
        delete cell_to_withdraw;
        return item;
      }

      T *pop_head () { // Deletes the first cell of the list
        if (this->empty) return 0;

        Cell *aux = this->first;
        Cell *head = aux->next;
        T *item = head->item;
        aux->next = head->next;
        head->item = 0;

        if (aux->next == 0) this->last = aux;
        delete head;
        return item;
      }

      T *next () {
        this->position = this->position->next;

        if (this->position == NULL) return NULL;
        else return this->position->item;
      }

      T *_first() {
        this->position = this->first;
        return this->next;
      }

      void print () const {
        Cell *aux = this->first->next;

        while (aux != 0) {
          cout << *(aux->item) << endl;
          aux = aux->next;
        };
      }

      ~List () {
        Cell *aux = this->first;

        while (aux != 0) {
          this->first = this->first->next;
          delete aux;
          aux = this->first;
        }
      }
  };
}

#endif
